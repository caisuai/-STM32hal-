#ifndef __KNOB_H__
#define __KNOB_H__

#include "tim.h"

typedef void (*KnobCallbask)(void);


void Knob_setForwardCallbask(KnobCallbask callbask);
void Knob_setBaskwardCallbask(KnobCallbask callbask);
void Knob_Init(void);
void Knob_Loop(void);
#endif
