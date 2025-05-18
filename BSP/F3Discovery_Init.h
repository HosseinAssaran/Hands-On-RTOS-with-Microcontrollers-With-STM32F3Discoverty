/*
 * F3Discovery_Init.h
 *
 *  Created on: May 17, 2025
 *      Author: Hossein Assaran
 */

#ifndef F3DISCOVERY_INIT_H_
#define F3DISCOVERY_INIT_H_

#include <stdint.h>
#ifdef __cplusplus
 extern "C" {
#endif

void HWInit( void );
uint8_t StmRand(uint8_t min, uint8_t max);

#ifdef __cplusplus
 }
#endif

#endif /* F3DISCOVERY_INIT_H_ */
