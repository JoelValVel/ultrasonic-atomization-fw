/* 
 * File:   newfile.h
 * Author: erjo_
 *
 * Created on 15 de septiembre de 2025, 02:40 PM
 */

#ifndef NEWFILE_H
#define	NEWFILE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "../app_driverFlujometro.h"
#include "../app_driverServomotor.h"
#include "UltrasonicAtEventHandler.h"
#include "UltrasonicAtHAL.h"
#include "UltrasonicAtTypes.h"
#include "../mcc_generated_files/uart/uart1.h"
void pumpExecute(ua_event_t event, void (*pEvent));


#ifdef	__cplusplus
}
#endif

#endif	/* NEWFILE_H */

