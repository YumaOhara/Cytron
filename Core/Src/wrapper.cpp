#include <main.h>

int flag = 0;
//memo PA8 = TIM1, PA9 = DIR
extern TIM_HandleTypeDef htim1;

extern "C" void main_cpp(){

	while(true
			){
		if(flag == 0){
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_RESET);
			HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
		}

		else if(flag == 1){
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);//+

			HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
			__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 70);
		}

		else if(flag == 2){
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_RESET);//-

			HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
			__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 70);
		}

	}
}
