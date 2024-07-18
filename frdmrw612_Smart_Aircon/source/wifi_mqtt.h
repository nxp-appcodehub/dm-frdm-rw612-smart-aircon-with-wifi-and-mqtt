/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef WIFI_MQTT_H_
#define WIFI_MQTT_H_

#define FILE_HEADER "wifi_credentials:"
/* @TEST_ANCHOR */

#define WIFI_SECURITY_LENGTH  63

#ifndef AP_SSID
#define AP_SSID "My_SSID"
#endif
//#define AP_SSID "NXP_Matter_Net"

#ifndef AP_PASSWORD
#define AP_PASSWORD "My_Password"
#endif

#define WIFI_NETWORK_LABEL "MyWifi"

/* Parameters that apply to AP mode only */
#ifndef WIFI_AP_CHANNEL
#define WIFI_AP_CHANNEL 1
#endif

#define MAX_RETRY_TICKS 50

#ifndef HTTPD_STACKSIZE
#define HTTPD_STACKSIZE 512
#endif
#ifndef HTTPD_PRIORITY
#define HTTPD_PRIORITY DEFAULT_THREAD_PRIO
#endif

#define CONNECTION_INFO_FILENAME ("connection_info.dat")

#define WEBCONFIG_DEBUG

#ifdef WEBCONFIG_DEBUG
#define WC_DEBUG(__fmt__, ...) PRINTF(__fmt__, ##__VA_ARGS__)
#else
#define WC_DEBUG(...)
#endif


/*Brief main function*/
void mqqt_principal_function(void);

/* Link lost callback */
void LinkStatusChangeCallback(bool linkState);

/* Connect to the external AP */
void ConnectTo();

/* Connect to the external AP with given credentials*/
void ConnectToManual(char * Network, char * Password, char * URL);

/*
 * @brief The main task function
 */
void main_task(void *arg);

/*!
 * @brief Returns true when connected to the WiFi network.
 */
bool WiFiConnected(void);

#endif /* WIFI_MQTT_H_ */
