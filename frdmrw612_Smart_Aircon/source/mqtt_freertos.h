/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MQTT_FREERTOS_H
#define MQTT_FREERTOS_H

#include "lwip/netif.h"

/*!
 * @brief Create and run example thread
 *
 * @param netif  netif which example should use
 */

#define MQTT_SERVER_HOST "broker.hivemq.com"

void mqtt_freertos_run_thread(struct netif *netif);

uint8_t get_ext_cmd_flag (void);

void clear_ext_cmd_flag (void);

void set_ext_cmd_flag (void);

void set_mqtt_broker(char * URL);

/*!
 * @brief Returns true if the MQTT brocker is connected
 */
bool mqtt_freertos_connected(void);

/*!
 * @brief disconnects from mqtt server
 */
void disconnect_from_mqtt(void *ctx);

/*!
 * @brief Publishes to the connected MQTT broker
 *
 * @param topic Publish topic string
 * @param message Data to publish (NULL is allowed)
 * @param len Length of payload (0 is allowed)
 * @param qos Quality of service, 0 1 or 2
 * @param retain MQTT retain flag
 */
void mqtt_freertos_publish(char *topic, void *message, size_t len, u8_t qos, u8_t retain);


#endif /* MQTT_FREERTOS_H */
