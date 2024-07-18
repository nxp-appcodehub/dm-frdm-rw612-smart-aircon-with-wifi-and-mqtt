/*
 * Copyright 2022, 2025 NXP
 * 
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MIC_PROC_H_
#define MIC_PROC_H_

#define DEMO_CHANNEL_NUM        4
#define DEMO_MAX_CHANNEL_NUM    4
#define PDM_BYTE_DEPTH          2

void MIC_Init(void);
void MIC_Start();
void MIC_Close();
int MIC_Read(uint8_t *data, uint32_t size);
int MIC_GetStatus();

#endif /* MIC_PROC_H_ */
