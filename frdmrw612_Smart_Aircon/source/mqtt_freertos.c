/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2022, 2025 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "mqtt_freertos.h"
#include "FreeRTOS.h"
#include "task.h"
#include "event_groups.h"

#include "board.h"
#include "fsl_silicon_id.h"

#include "lwip/opt.h"
#include "lwip/api.h"
#include "lwip/apps/mqtt.h"
#include "lwip/tcpip.h"

#include "ui_Aircon.h"
#include "vit_proc.h"
#include "gui_guider.h"
#include "ui_Animations.h"
#include <stdio.h>


// FIXME cleanup

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief MQTT server port number. */
#ifndef EXAMPLE_MQTT_SERVER_PORT
#define EXAMPLE_MQTT_SERVER_PORT 1883
#endif

/*! @brief Stack size of the temporary lwIP initialization thread. */
#define INIT_THREAD_STACKSIZE 1024

/*! @brief Priority of the temporary lwIP initialization thread. */
#define INIT_THREAD_PRIO DEFAULT_THREAD_PRIO

/*! @brief Stack size of the temporary initialization thread. */
#define APP_THREAD_STACKSIZE 1024

/*! @brief Priority of the temporary initialization thread. */
#define APP_THREAD_PRIO DEFAULT_THREAD_PRIO

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

static void connect_to_mqtt(void *ctx);

/*******************************************************************************
 * Variables
 ******************************************************************************/
char * Manual_MQTT_SERVER_HOST = "Example";

/*! @brief MQTT client data. */
static mqtt_client_t *mqtt_client;

/*! @brief Indicates connection to MQTT broker. */
static volatile bool connected = false;

/*! @brief MQTT client ID string. */
static char client_id[(SILICONID_MAX_LENGTH * 2) + 5];

/*! @brief MQTT client information. */
static const struct mqtt_connect_client_info_t mqtt_client_info = {
    .client_id   = (const char *)&client_id[0],
    .client_user = NULL,
    .client_pass = NULL,
    .keep_alive  = 100,
    .will_topic  = NULL,
    .will_msg    = NULL,
    .will_qos    = 0,
    .will_retain = 0,
#if LWIP_ALTCP && LWIP_ALTCP_TLS
    .tls_config = NULL,
#endif
};

/*! @brief MQTT broker IP address. */
static ip_addr_t mqtt_addr;

extern VIT_Aircon_Command_t aircon_cmd;
VIT_Aircon_Command_t acmd;
extern EventGroupHandle_t GPH_Process;


uint8_t external_cmd_g = 0;
uint8_t cmd_published = 0;

/*! @brief Required arguments to publish to a topic. */
typedef struct _publishArguments_t {
	mqtt_client_t *client;
	char *topic;
	void *payload;
	u16_t payload_length;
	u8_t qos;
	u8_t retain;
	mqtt_request_cb_t cb;
	void *arg;
} publishArguments_t;

/*******************************************************************************
 * Code
 ******************************************************************************/
void set_mqtt_broker(char * URL)
{
	Manual_MQTT_SERVER_HOST = URL;
}

uint8_t get_ext_cmd_flag (void)
{
	return external_cmd_g;
}

void clear_ext_cmd_flag (void){
	external_cmd_g = 0;
}

void set_ext_cmd_flag (void){
	external_cmd_g = 1;
}

/*!
 * @brief Called when subscription request finishes.
 */
static void mqtt_topic_subscribed_cb(void *arg, err_t err)
{
    const char *topic = (const char *)arg;

    if (err == ERR_OK)
    {
        PRINTF("Subscribed to the topic \"%s\".\r\n", topic);
    }
    else
    {
        PRINTF("Failed to subscribe to the topic \"%s\": %d.\r\n", topic, err);
    }
}

/*!
 * @brief Called when there is a message on a subscribed topic.
 */
static void mqtt_incoming_publish_cb(void *arg, const char *topic, u32_t tot_len)
{
    LWIP_UNUSED_ARG(arg);

    PRINTF("[i][MQTT] Received %u bytes from the topic \"%s\": \"", tot_len, topic);

    memset(&acmd, 0, sizeof(acmd));

    if (!strcmp("aircon/power", topic)) {
    	acmd.intent = kVIT_AirconIntent_Power;
    }
    else if (!strcmp("aircon/temp_adjust", topic)) {
    	acmd.intent = kVIT_AirconIntent_TempAdjust;
    }
    else if (!strcmp("aircon/temperature", topic)) {
    	acmd.intent = kVIT_AirconIntent_Temperature;
    }
    else if (!strcmp("aircon/fan_speed", topic)) {
    	acmd.intent = kVIT_AirconIntent_FanSpeed;
    }
    else if (!strcmp("aircon/mode", topic)) {
    	acmd.intent = kVIT_AirconIntent_Mode;
    }
    else if (!strcmp("aircon/swing", topic)) {
		acmd.intent = kVIT_AirconIntent_Swing;
	}
    else if (!strcmp("aircon/timer", topic)) {
    	acmd.intent = kVIT_AirconIntent_Timer;
    }
}

/*!
 * @brief Called when recieved incoming published message fragment.
 */
static void mqtt_incoming_data_cb(void *arg, const u8_t *data, u16_t len, u8_t flags)
{
    int i;
    char tmp[8] = {0};
	char tmp2[8] = {0};
    char * data_ptr = (char*)data;

    LWIP_UNUSED_ARG(arg);

    for (i = 0; i < len; i++)
    {
        if (isprint(data[i]))
        {
            PRINTF("%c", (char)data[i]);
        }
        else
        {
            PRINTF("\\x%02x", data[i]);
        }
    }

    if (flags & MQTT_DATA_FLAG_LAST)
    {
        PRINTF("\"\r\n");
        *(data_ptr + i) = '\0';
//#if AIRCON_MQTT_APP_MODE == AIRCON_MQTT_SUBSCRIBER
   if(cmd_published == 0)
   {
        switch (acmd.intent)
        {
        case kVIT_AirconIntent_Power:
        	if(!strcmp((const char *)data, "On")) {
        		acmd.enabled = true;
        		set_cmd_id_value(VIT_CMD_1);
        	}
        	else if(!strcmp((const char *)data, "Off")) {
        		acmd.enabled = false;
        		set_cmd_id_value(VIT_CMD_2);
        	}
        	else {
        		PRINTF("[!][MQTT] Invalid data for topic: aircon/power\r\n");
        	}
            break;
        case kVIT_AirconIntent_TempAdjust:
        	if(!strcmp((const char *)data, "Down")) {
        		acmd.tempUpDown = kAIRCON_TempDown;
        		set_cmd_id_value(VIT_CMD_11);
        	}
        	else if(!strcmp((const char *)data, "Up")) {
        		acmd.tempUpDown = kAIRCON_TempUp;
        		set_cmd_id_value(VIT_CMD_10);
        	}
        	else {
        		PRINTF("[!][MQTT] Invalid data for topic: aircon/temp_adjust\r\n");
        	}
            break;
        case kVIT_AirconIntent_Temperature:
        	sscanf((const char *__restrict)data, "%s %d", tmp, &(acmd.temperature));
        	if(!strcmp(tmp, "Down")) {
        		acmd.tempUpDown = kAIRCON_TempDown;
        		set_cmd_id_value(VIT_CMD_11);
        	}
        	else if(!strcmp(tmp, "Up")) {
        		acmd.tempUpDown = kAIRCON_TempUp;
        		set_cmd_id_value(VIT_CMD_10);
        	}
        	else {
        		PRINTF("[!][MQTT] Invalid data for topic: aircon/temperature\r\n");
        	}
            break;
        case kVIT_AirconIntent_FanSpeed:
        	sscanf((const char *__restrict)data, "%s %d", tmp, &(acmd.fanSpeed));
        	if(!strcmp(tmp, "Low")) {
        		acmd.fanSpeed = kAIRCON_FanLow;
        		set_cmd_id_value(VIT_CMD_3);
        	}
        	else if(!strcmp(tmp, "Medium")) {
        		acmd.fanSpeed = kAIRCON_FanMedium;
        		set_cmd_id_value(VIT_CMD_4);
        	}
        	else if(!strcmp(tmp, "High")) {
        		acmd.fanSpeed = kAIRCON_FanHigh;
        		set_cmd_id_value(VIT_CMD_5);
        	}
        	else {
        		PRINTF("[!][MQTT] Invalid data for topic: aircon/fan_speed\r\n");
        	}
            break;
        case kVIT_AirconIntent_Mode:
        	sscanf((const char *__restrict)data, "%s %s", tmp, tmp2);
        	if(!strcmp(tmp, "Cool")) {
        		acmd.airconMode = kAIRCON_ModeCool;
        		set_cmd_id_value(VIT_CMD_6);
        		break;
        	}
        	else if(!strcmp(tmp, "Dry")) {
        		acmd.airconMode = kAIRCON_ModeDry;
        		set_cmd_id_value(VIT_CMD_7);
        		break;
        	}
        	else {
        		PRINTF("[!][MQTT] Invalid data (mode) for topic: aircon/mode\r\n");
        	}

        	if(!strcmp(tmp2, "On")) {
        		acmd.enabled = true;
        	}
        	else if(!strcmp(tmp2, "Off")) {
        		acmd.enabled = false;
        	}
        	else {
        		PRINTF("[!][MQTT] Invalid data (enabled) for topic: aircon/mode\r\n");
        	}
            break;
        case kVIT_AirconIntent_Swing:
        	sscanf((const char *__restrict)data, "%s %d", tmp, &(acmd.enabled));
        	if(!strcmp(tmp, "On"))
        	{
				acmd.enabled = kAIRCON_SwingOn;
				set_cmd_id_value(VIT_CMD_8);
			}
			else
			{
				acmd.enabled = kAIRCON_SwingOff;
				set_cmd_id_value(VIT_CMD_9);
			}
        	break;
        case kVIT_AirconIntent_Timer:
        	sscanf((const char *__restrict)data, "%s %d", tmp, &(acmd.timeUpDown));
        	if(!strcmp(tmp, "Up")) {
        		acmd.timeUpDown = kAIRCON_TimerUp;
        		set_cmd_id_value(VIT_CMD_12);
        	}
        	if(!strcmp(tmp, "Down")) {
        		acmd.timeUpDown = kAIRCON_TimerDown;
        		set_cmd_id_value(VIT_CMD_13);
        	}
            break;
        default:
        	break;
        }

        if(acmd.intent != kVIT_AirconIntent_Unknown) {
        	aircon_cmd = acmd;
            /*Set Event CMD detect*/
        	external_cmd_g = 1;
            xEventGroupSetBits(GPH_Process, VIT_CMD_DETECT);
        }
   }
   cmd_published = 0;
   //#endif
   }
}

/*!
 * @brief Subscribe to MQTT topics.
 */
static void mqtt_subscribe_topics(mqtt_client_t *client)
{
    static const char *topics[] = {"aircon/#"};
    int qos[]                   = {1};
    err_t err;
    int i;

//    if(Get_Mic_status() == true)
//    {
//    	return;
//        //err = mqtt_subscribe(client, topics[i], qos[i], mqtt_topic_subscribed_cb, LWIP_CONST_CAST(void *, topics[i]));
//    }
	mqtt_set_inpub_callback(client, mqtt_incoming_publish_cb, mqtt_incoming_data_cb,
                        LWIP_CONST_CAST(void *, &mqtt_client_info));

	for (i = 0; i < ARRAY_SIZE(topics); i++)
	{
    	err = mqtt_subscribe(client, topics[i], qos[i], mqtt_topic_subscribed_cb, LWIP_CONST_CAST(void *, topics[i]));
        if (err == ERR_OK)
        {
            PRINTF("Subscribing to the topic \"%s\" with QoS %d...\r\n", topics[i], qos[i]);
        }
        else
        {
            PRINTF("Failed to subscribe to the topic \"%s\" with QoS %d: %d.\r\n", topics[i], qos[i], err);
        }
	}

}

/*!
 * @brief Called when connection state changes.
 */
static void mqtt_connection_cb(mqtt_client_t *client, void *arg, mqtt_connection_status_t status)
{
    const struct mqtt_connect_client_info_t *client_info = (const struct mqtt_connect_client_info_t *)arg;

    connected = (status == MQTT_CONNECT_ACCEPTED);

    switch (status)
    {
        case MQTT_CONNECT_ACCEPTED:
            PRINTF("MQTT client \"%s\" connected.\r\n", client_info->client_id);
            mqtt_subscribe_topics(client);
            break;

        case MQTT_CONNECT_DISCONNECTED:
            PRINTF("MQTT client \"%s\" not connected.\r\n", client_info->client_id);
            /* Try to reconnect 1 second later */
            sys_timeout(1000, connect_to_mqtt, NULL);
            break;

        case MQTT_CONNECT_TIMEOUT:
            PRINTF("MQTT client \"%s\" connection timeout.\r\n", client_info->client_id);
            /* Try again 1 second later */
            sys_timeout(1000, connect_to_mqtt, NULL);
            break;

        case MQTT_CONNECT_REFUSED_PROTOCOL_VERSION:
        case MQTT_CONNECT_REFUSED_IDENTIFIER:
        case MQTT_CONNECT_REFUSED_SERVER:
        case MQTT_CONNECT_REFUSED_USERNAME_PASS:
        case MQTT_CONNECT_REFUSED_NOT_AUTHORIZED_:
            PRINTF("MQTT client \"%s\" connection refused: %d.\r\n", client_info->client_id, (int)status);
            /* Try again 10 seconds later */
            sys_timeout(10000, connect_to_mqtt, NULL);
            break;

        default:
            PRINTF("MQTT client \"%s\" connection status: %d.\r\n", client_info->client_id, (int)status);
            /* Try again 10 seconds later */
            sys_timeout(10000, connect_to_mqtt, NULL);
            break;
    }
}

/*!
 * @brief Starts connecting to MQTT broker. To be called on tcpip_thread.
 */
static void connect_to_mqtt(void *ctx)
{
    LWIP_UNUSED_ARG(ctx);

    PRINTF("Connecting to MQTT broker at %s...\r\n", ipaddr_ntoa(&mqtt_addr));

    mqtt_client_connect(mqtt_client, &mqtt_addr, EXAMPLE_MQTT_SERVER_PORT, mqtt_connection_cb,
                        LWIP_CONST_CAST(void *, &mqtt_client_info), &mqtt_client_info);
}

/*!
 * @brief Disconnects from MQTT broker. To be called on tcpip_thread.
 */
void disconnect_from_mqtt(void *ctx)
{
    LWIP_UNUSED_ARG(ctx);

    mqtt_disconnect(mqtt_client);
    connected = false;
    PRINTF("Disconnected from MQTT broker.\r\n");
}

/*!
 * @brief Called when publish request finishes.
 */
static void mqtt_message_published_cb(void *arg, err_t err)
{
    const char *topic = (const char *)arg;

    if (err == ERR_OK)
    {
        PRINTF("Published to the topic \"%s\".\r\n", topic);
    }
    else
    {
        PRINTF("Failed to publish to the topic \"%s\": %d.\r\n", topic, err);
    }
}

/*!
 * @brief Publishes a message. To be called on tcpip_thread.
 */
static void publish_message(void *ctx)
{
	publishArguments_t *pubArgs = (publishArguments_t*)ctx;

    PRINTF("[i][MQTT] Going to publish to the topic \"%s\"...\r\n", pubArgs->topic);

    mqtt_publish(pubArgs->client,
    		     pubArgs->topic,
				 pubArgs->payload,
				 pubArgs->payload_length,
				 pubArgs->qos,
				 0,
				 pubArgs->cb,
				 pubArgs->arg);
}


/*!
 * @brief Publishes to the connected MQTT broker
 *
 * @param topic Publish topic string
 * @param message Data to publish (NULL is allowed)
 * @param len Length of payload (0 is allowed)
 * @param qos Quality of service, 0 1 or 2
 * @param retain MQTT retain flag
 */
void mqtt_freertos_publish(char *topic, void *message, size_t len, u8_t qos, u8_t retain)
{
    static publishArguments_t pubArgs;
    err_t err;
    external_cmd_g = 1;
    cmd_published = 1;

    pubArgs.client = mqtt_client;
    pubArgs.topic = topic;
	pubArgs.payload = message;
	pubArgs.payload_length = len;
	pubArgs.qos = qos;
	pubArgs.retain = 0;
	pubArgs.cb = mqtt_message_published_cb;
	pubArgs.arg = (void *)topic;

	err = tcpip_callback(publish_message, &pubArgs);

	if (err != ERR_OK)
	{
		PRINTF("[!][MQTT] Failed to invoke publishing of a message on the tcpip_thread: %d.\r\n", err);
	}
}

/*!
 * @brief Application thread.
 */
static void app_thread(void *arg)
{
    struct netif *netif = (struct netif *)arg;
    err_t err;

    PRINTF("\r\nIPv4 Address     : %s\r\n", ipaddr_ntoa(&netif->ip_addr));
    PRINTF("IPv4 Subnet mask : %s\r\n", ipaddr_ntoa(&netif->netmask));
    PRINTF("IPv4 Gateway     : %s\r\n\r\n", ipaddr_ntoa(&netif->gw));

    /*
     * Check if we have an IP address or host name string configured.
     * Could just call netconn_gethostbyname() on both IP address or host name,
     * but we want to print some info if goint to resolve it.
     */

    if (ipaddr_aton(Manual_MQTT_SERVER_HOST, &mqtt_addr) && IP_IS_V4(&mqtt_addr))
    {
        /* Already an IP address */
        err = ERR_OK;
    }
    else
    {
        /* Resolve MQTT broker's host name to an IP address */
        PRINTF("Resolving \"%s\"...\r\n", Manual_MQTT_SERVER_HOST);
        err = netconn_gethostbyname(Manual_MQTT_SERVER_HOST, &mqtt_addr);
    }

    if (err == ERR_OK)
    {
        /* Start connecting to MQTT broker from tcpip_thread */
        err = tcpip_callback(connect_to_mqtt, NULL);
        if (err != ERR_OK)
        {
            PRINTF("Failed to invoke broker connection on the tcpip_thread: %d.\r\n", err);
			if(lv_scr_act()== guider_ui.ui_Aircon)
			{
				lv_obj_set_state(guider_ui.ui_Aircon_Btn_Server, LV_STATE_DEFAULT, true);
			}
        }
        else
        {
			if(lv_scr_act()== guider_ui.ui_Aircon)
			{
				lv_obj_set_state(guider_ui.ui_Aircon_Btn_Server, LV_STATE_CHECKED, true);
			}
        }
    }
    else
    {
        PRINTF("Failed to obtain IP address: %d.\r\n", err);
    }

    vTaskDelete(NULL);
}

static void generate_client_id(void)
{
    uint8_t silicon_id[SILICONID_MAX_LENGTH];
    const char *hex = "0123456789abcdef";
    status_t status;
    uint32_t id_len = sizeof(silicon_id);
    int idx         = 0;
    int i;
    bool id_is_zero = true;

    /* Get unique ID of SoC */
    status = SILICONID_GetID(&silicon_id[0], &id_len);
    assert(status == kStatus_Success);
    assert(id_len > 0U);
    (void)status;

    /* Covert unique ID to client ID string in form: nxp_hex-unique-id */

    /* Check if client_id can accomodate prefix, id and terminator */
    assert(sizeof(client_id) >= (5U + (2U * id_len)));

    /* Fill in prefix */
    client_id[idx++] = 'n';
    client_id[idx++] = 'x';
    client_id[idx++] = 'p';
    client_id[idx++] = '_';

    /* Append unique ID */
    for (i = (int)id_len - 1; i >= 0; i--)
    {
        uint8_t value    = silicon_id[i];
        client_id[idx++] = hex[value >> 4];
        client_id[idx++] = hex[value & 0xFU];

        if (value != 0)
        {
            id_is_zero = false;
        }
    }

    /* Terminate string */
    client_id[idx] = '\0';

    if (id_is_zero)
    {
        PRINTF(
            "WARNING: MQTT client id is zero. (%s)"
#ifdef OCOTP
            " This might be caused by blank OTP memory."
#endif
            "\r\n",
            client_id);
    }
}

/*!
 * @brief Create and run example thread
 *
 * @param netif  netif which example should use
 */
void mqtt_freertos_run_thread(struct netif *netif)
{
    LOCK_TCPIP_CORE();
    mqtt_client = mqtt_client_new();
    UNLOCK_TCPIP_CORE();
    if (mqtt_client == NULL)
    {
        PRINTF("mqtt_client_new() failed.\r\n");
        while (1)
        {
        }
    }

    generate_client_id();

    if (sys_thread_new("app_task", app_thread, netif, APP_THREAD_STACKSIZE, APP_THREAD_PRIO) == NULL)
    {
        LWIP_ASSERT("mqtt_freertos_start_thread(): Task creation failed.", 0);
    }
}

/*!
 * @brief Returns true if the MQTT brocker is connected
 */
bool mqtt_freertos_connected(void)
{
	return connected;
}
