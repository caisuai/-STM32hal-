#include "knob.h"

#define COUNTER_INIT_VALUE 65535/2

void SetCounter(int value){
	__HAL_TIM_SET_COUNTER(&htim1,value);
}

uint32_t GetCounter(){
	return __HAL_TIM_GET_COUNTER(&htim1);
}

KnobCallbask onForwardCallbask=NULL;
KnobCallbask onBaskwardCallbask=NULL;

void Knob_setForwardCallbask(KnobCallbask callbask){
	onForwardCallbask=callbask;
}

void Knob_setBaskwardCallbask(KnobCallbask callbask){
	onBaskwardCallbask=callbask;
}

void Knob_Init(){
	HAL_TIM_Encoder_Start(&htim1,TIM_CHANNEL_ALL);
	SetCounter(COUNTER_INIT_VALUE);
}

void Knob_Loop(){
	uint32_t counter=GetCounter();
	if(counter>COUNTER_INIT_VALUE){
		if(onForwardCallbask!=NULL){
			onForwardCallbask();
		}
	}else if(counter<COUNTER_INIT_VALUE){
		if(onBaskwardCallbask!=NULL){
			onBaskwardCallbask();
		}
	}
	SetCounter(COUNTER_INIT_VALUE);
}
