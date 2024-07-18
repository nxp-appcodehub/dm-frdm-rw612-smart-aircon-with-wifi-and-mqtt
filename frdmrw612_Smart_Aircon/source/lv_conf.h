/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
 * @file lv_conf.h
 */

#ifndef LV_CONF_H
#define LV_CONF_H

/* clang-format off */

/*
 * COLOR DEPTH
 */

/* Swap the 2 bytes of RGB565 color.
 * Useful if the display has a 8 bit interface (e.g. SPI)*/
#define LV_COLOR_16_SWAP   0

#if defined(DEMO_BUFFER_BYTE_PER_PIXEL)

#if DEMO_BUFFER_BYTE_PER_PIXEL == 2
#define LV_COLOR_DEPTH     16
#elif DEMO_BUFFER_BYTE_PER_PIXEL == 3
#define LV_COLOR_DEPTH     24
#elif DEMO_BUFFER_BYTE_PER_PIXEL == 4
#define LV_COLOR_DEPTH     32
#elif DEMO_BUFFER_BYTE_PER_PIXEL == 1
#if (CONFIG_LV_COLOR_DEPTH == 1)
#define LV_COLOR_DEPTH     1 /* Can be 8 or 1. */
#else
#define LV_COLOR_DEPTH     8 /* Can be 8 or 1. */
#endif
#else
#error Unsupport color depth
#endif

#endif /* defined(DEMO_BUFFER_BYTE_PER_PIXEL) */

/* clang-format on */
#endif /*LV_CONF_H*/
