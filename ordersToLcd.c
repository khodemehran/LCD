
void ordersToLcd(int CMD)
	// RS, HD7, HD6 , HD5, HD4, LD7, LD6 , LD5, LD4
{
		//RS
		if((CMD & 0x100) == 0x100)
			{
				HAL_GPIO_WritePin(GPIOE, RS_Pin, GPIO_PIN_SET);
			}
		else
			{
				HAL_GPIO_WritePin(GPIOE, RS_Pin, GPIO_PIN_RESET);
			}

		//High order D7
		if((CMD & 0x80) == 0x80)
			{
				HAL_GPIO_WritePin(GPIOD, D7_Pin, GPIO_PIN_SET);
			}
		else
			{
				HAL_GPIO_WritePin(GPIOD, D7_Pin, GPIO_PIN_RESET);
			}

		//High order D6
		if((CMD & 0x40) == 0x40)
			{
				HAL_GPIO_WritePin(GPIOD, D6_Pin, GPIO_PIN_SET);
			}
		else
			{
				HAL_GPIO_WritePin(GPIOD, D6_Pin, GPIO_PIN_RESET);
			}

		//High order D5
		if((CMD & 0x20) == 0x20)
			{
				HAL_GPIO_WritePin(GPIOE, D5_Pin, GPIO_PIN_SET);
			}
		else
			{
				HAL_GPIO_WritePin(GPIOE, D5_Pin, GPIO_PIN_RESET);
			}

		//High order D4
		if((CMD & 0x10) == 0x10)
			{
				HAL_GPIO_WritePin(GPIOE, D4_Pin, GPIO_PIN_SET);
			}
		else
			{
				HAL_GPIO_WritePin(GPIOE, D4_Pin, GPIO_PIN_RESET);
			}
		//Send Command by toggle EN pin
		HAL_Delay(1);
		HAL_GPIO_WritePin(GPIOE, E_Pin, GPIO_PIN_SET); //EN High
		HAL_Delay(2);
		HAL_GPIO_WritePin(GPIOE, E_Pin, GPIO_PIN_RESET); //EN Low
		HAL_Delay(10);

		//Turn off All GPIO Pins
		HAL_GPIO_WritePin(GPIOE, D5_Pin|D4_Pin|E_Pin|RS_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, D7_Pin|D6_Pin, GPIO_PIN_RESET);



		//RS
		if((CMD & 0x100) == 0x100)
			{
				HAL_GPIO_WritePin(GPIOE, RS_Pin, GPIO_PIN_SET);
			}
		else
			{
				HAL_GPIO_WritePin(GPIOE, RS_Pin, GPIO_PIN_RESET);
			}

		//Low order D7
		if((CMD & 0x08) == 0x08)
			{
				HAL_GPIO_WritePin(GPIOD, D7_Pin, GPIO_PIN_SET);
			}
		else
			{
				HAL_GPIO_WritePin(GPIOD, D7_Pin, GPIO_PIN_RESET);
			}

		//High order D6
		if((CMD & 0x04) == 0x04)
			{
				HAL_GPIO_WritePin(GPIOD, D6_Pin, GPIO_PIN_SET);
			}
		else
			{
				HAL_GPIO_WritePin(GPIOD, D6_Pin, GPIO_PIN_RESET);
			}

		//High order D5
		if((CMD & 0x02) == 0x02)
			{
				HAL_GPIO_WritePin(GPIOE, D5_Pin, GPIO_PIN_SET);
			}
		else
			{
				HAL_GPIO_WritePin(GPIOE, D5_Pin, GPIO_PIN_RESET);
			}

		//High order D4
		if((CMD & 0x01) == 0x01)
			{
				HAL_GPIO_WritePin(GPIOE, D4_Pin, GPIO_PIN_SET);
			}
		else
			{
				HAL_GPIO_WritePin(GPIOE, D4_Pin, GPIO_PIN_RESET);
			}
		//Send Command by toggle EN pin
		HAL_Delay(1);
		HAL_GPIO_WritePin(GPIOE, E_Pin, GPIO_PIN_SET); //EN High
		HAL_Delay(2);
		HAL_GPIO_WritePin(GPIOE, E_Pin, GPIO_PIN_RESET); //EN Low
		HAL_Delay(10);

		//Turn off All GPIO Pins
		HAL_GPIO_WritePin(GPIOE, D5_Pin|D4_Pin|E_Pin|RS_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, D7_Pin|D6_Pin, GPIO_PIN_RESET);

}

////////////////////////////////////////////////////////////////////////////////
//Turn off All GPIO Pins
		HAL_GPIO_WritePin(GPIOE, D5_Pin|D4_Pin|E_Pin|RS_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, D7_Pin|D6_Pin, GPIO_PIN_RESET);


		HAL_Delay(500);
		ordersToLcd(0x33);
		ordersToLcd(0x32);
		//Function set (set font and lines)
		ordersToLcd(0x28);

		//On off control
		ordersToLcd(0x0E);

		//Entry mode set
		ordersToLcd(0x06);

		//Clear
		ordersToLcd(0x01);

		//Return
		ordersToLcd(0x02);


		//Write text to lcd
		ordersToLcd(0x148); //H
		ordersToLcd(0x145); //E
		ordersToLcd(0x14C); //L
		ordersToLcd(0x14C); //L
		ordersToLcd(0x14F); //O
		ordersToLcd(0x1FE); //Space
		ordersToLcd(0x157); //W
		ordersToLcd(0x14F); //O
		ordersToLcd(0x152); //R
		ordersToLcd(0x14C); //L
		ordersToLcd(0x144); //D
