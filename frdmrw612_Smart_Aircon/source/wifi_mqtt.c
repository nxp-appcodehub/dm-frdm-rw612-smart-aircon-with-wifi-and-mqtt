/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "lwip/tcpip.h"
#include "board.h"
#include "app.h"
#include "wpl.h"
#include "timers.h"
#include "wifi_mqtt.h"
#include "gui_guider.h"
#include "ui_Animations.h"
#include "cred_flash_storage.h"
#include "fsl_debug_console.h"
#include "mqtt_freertos.h"

#include <stdio.h>

#include "FreeRTOS.h"


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
static bool wifi_connected = false;
char ssid[MAX_SSID_LENGTH];
char password[WPL_WIFI_PASSWORD_LENGTH];
char broker[WIFI_SECURITY_LENGTH];

/*******************************************************************************
 * Code
 ******************************************************************************/

/* Link lost callback */
void LinkStatusChangeCallback(bool linkState)
{
    if (linkState == false)
    {
        /* -------- LINK LOST -------- */
        /* DO SOMETHING */
        PRINTF("-------- LINK LOST --------\r\n");
		if(lv_scr_act()== guider_ui.ui_Aircon)
		{
			lv_obj_set_state(guider_ui.ui_Aircon_Btn_Wifi, LV_STATE_DEFAULT, true);
		}
	    wifi_connected = false;
    }
    else
    {
        /* -------- LINK REESTABLISHED -------- */
        /* DO SOMETHING */
        PRINTF("-------- LINK REESTABLISHED --------\r\n");
		if(lv_scr_act()== guider_ui.ui_Aircon)
		{
			lv_obj_set_state(guider_ui.ui_Aircon_Btn_Wifi, LV_STATE_CHECKED, true);
		}
	    wifi_connected = true;
    }
}

void ConnectToManual(char * Network, char * Password, char * URL)
{
    int32_t result;

//    result = WPL_Init();
//    if (result != WPLRET_SUCCESS)
//    {
//        PRINTF("[!] WPL Init failed: %d\r\n", (uint32_t)result);
//        __BKPT(0);
//    }

    /* Add Wi-Fi network */
    result = WPL_AddNetwork(Network, Password, WIFI_NETWORK_LABEL);
    if (result == WPLRET_SUCCESS)
    {
    	do {
            PRINTF("[i] Connecting as client to ssid: %s with password %s\r\n", Network, Password);
            result = WPL_Join(WIFI_NETWORK_LABEL);
    		if (result != WPLRET_SUCCESS)
    		{
    			PRINTF("[!] Failed to connect to Wi-Fi - ssid: %s passphrase: %s\r\n", Network, Password);
    			vTaskDelay(5000);
    		}
    		else
    		{
    			PRINTF("[i] Connected to Wi-Fi - ssid: %s passphrase: %s\r\n", Network, Password);
    			if(lv_scr_act()== guider_ui.ui_Aircon)
    			{
    				lv_obj_set_state(guider_ui.ui_Aircon_Btn_Wifi, LV_STATE_CHECKED, true);
    			}
    		    wifi_connected = true;
    			char ip[16];
    			WPL_GetIP(ip, 1);
    		}
    	}while(result != WPLRET_SUCCESS);

    	set_mqtt_broker(URL);

        mqtt_freertos_run_thread(netif_default);


//        PRINTF("Connecting as client to ssid: %s with password %s\r\n", Network, Password);
//        result = WPL_Join(WIFI_NETWORK_LABEL);

    }

    else
    {
        PRINTF("[i] Connected to Wi-Fi\r\nssid: %s\r\n[!]passphrase: %s\r\n", Network, Password);
        char ip[16];
        WPL_GetIP(ip, 1);
    }
}

/* Connect to the external AP */
void ConnectTo()
{

    int32_t result;
    char *ssids = NULL;
    /* Initiate Scan */
    WC_DEBUG("[i] Trying to load data from mflash.\r\n");
    ssids = WPL_Scan();
    /* Clean up */
    vPortFree(ssids);

    result = get_saved_wifi_credentials(CONNECTION_INFO_FILENAME, ssid, password, broker);

    if (result == 0 && strcmp(ssid, "") != 0)
    {
        /* Credentials from last time have been found. The board will attempt to
         * connect to this network as a client */
        WC_DEBUG("[i] Saved SSID: %s, Password: %s, broker: %s\r\n", ssid, password, broker);
        set_mqtt_broker(broker);
    }
    else
    {
        /* No credentials are stored, the board will start its own AP */
        WC_DEBUG("[i] Nothing stored yet\r\n");
        PRINTF("\r\nScanning WiFi networks...\r\n");
        ssids = WPL_Scan();
        strncpy(ssid, AP_SSID, MAX_SSID_LENGTH);
        ssid[MAX_SSID_LENGTH - 1] = '\0'; // Ensure null termination
        strncpy(password, AP_PASSWORD, WPL_WIFI_PASSWORD_LENGTH);
        password[WPL_WIFI_PASSWORD_LENGTH - 1] = '\0'; // Ensure null termination
        set_mqtt_broker(MQTT_SERVER_HOST);
    }

    /* Add Wi-Fi network */
    result = WPL_AddNetwork(ssid, password, WIFI_NETWORK_LABEL);
    if (result == WPLRET_SUCCESS)
    {
    	do {
            PRINTF("\r\n[i] Connecting as client to ssid: %s with password %s\r\n", ssid, password);
            result = WPL_Join(WIFI_NETWORK_LABEL);
    		if (result != WPLRET_SUCCESS)
    		{
    			PRINTF("\r\n[!] Failed to connect to Wi-Fi - ssid: %s passphrase: %s\r\n", ssid, password);
    			vTaskDelay(5000);
    		}
    		else
    		{
    			PRINTF("\r\n[i] Connected to Wi-Fi - ssid: %s passphrase: %s\r\n", ssid, password);
    			if(lv_scr_act()== guider_ui.ui_Aircon)
    			{
    				lv_obj_set_state(guider_ui.ui_Aircon_Btn_Wifi, LV_STATE_CHECKED, true);
    			}
    			wifi_connected = true;
    			char ip[16];
    			WPL_GetIP(ip, 1);
    		}
    	}while(result != WPLRET_SUCCESS);
        PRINTF("Connecting as client to ssid: %s with password %s\r\n", ssid, password);
        result = WPL_Join(WIFI_NETWORK_LABEL);
    }

    else
    {
        PRINTF("[i] Connected to Wi-Fi\r\nssid: %s\r\n[!]passphrase: %s\r\n", ssid, password);
        char ip[16];
        WPL_GetIP(ip, 1);
    }
}

/*!
 * @brief Returns true when connected to the WiFi network.
 */
bool WiFiConnected(void)
{
	return wifi_connected;
}

/*!
 * @brief The main task function
 */
void main_task(void *arg)
{
    uint32_t result = 0;

    PRINTF(" MQTT init\r\n");

    /* Initialize Wi-Fi board */
    PRINTF("[i] Initializing Wi-Fi connection... \r\n");

    result = WPL_Init();
    if (result != WPLRET_SUCCESS)
    {
        PRINTF("[!] WPL Init failed: %d\r\n", (uint32_t)result);
        __BKPT(0);
    }

    result = WPL_Start(LinkStatusChangeCallback);
    if (result != WPLRET_SUCCESS)
    {
        PRINTF("[!] WPL Start failed %d\r\n", (uint32_t)result);
        __BKPT(0);
    }

    PRINTF("[i] Successfully initialized Wi-Fi module\r\n");

    ConnectTo();
    /// wait_dns


    mqtt_freertos_run_thread(netif_default);

    vTaskDelete(NULL);
}

/*!
 * @brief Main function.
 */
void mqqt_principal_function(void)
{
    /* Create the main Task */
    if (xTaskCreate(main_task, "main_task", 1024, NULL, configMAX_PRIORITIES - 3, NULL) != pdPASS)
    {
        PRINTF("[!] MAIN Task creation failed!\r\n");
        while (1)
            ;
    }
}
