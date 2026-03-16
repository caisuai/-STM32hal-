#ifndef __MAINTASK_H__
#define __MAINTASK_H__
 
 #include "../oled/oled.h"
#include "../knob/knob.h"
#include "../rtc/my_rtc.h"
#include "../key/key.h"
#include "main.h"
#include <string.h>
#include <stdio.h>

void maintaskInit(void);
void maintask(void);
	
#endif
