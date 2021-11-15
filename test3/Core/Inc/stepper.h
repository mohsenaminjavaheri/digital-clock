/*
 * stepper.h
 *
 *  Created on: ۱۸ آبان ۱۴۰۰
 *      Author: mohse
 */

#ifndef INC_STEPPER_H_
#define INC_STEPPER_H_

void start_stepper(void);
void start_stepper_2(void);
void motor1 (uint8_t Direction, uint32_t Step);
void motor2 (uint8_t Direction, uint32_t step);
void motors(uint8_t Direction_1, uint32_t step_1 ,uint8_t Direction_2, uint32_t step_2);

#endif /* INC_STEPPER_H_ */
