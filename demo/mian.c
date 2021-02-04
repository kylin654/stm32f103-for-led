#include "stm32f10x.h"

void LED_Green(){

    *(unsigned int *)0x40010C00 |= ((1)<<(4*0));
    *(unsigned int *)0x40010C0C &= ~(1<<0);

}

void LED_Blue(){

    *(unsigned int *)0x40010C00 |= ((1)<<(4*1));
    *(unsigned int *)0x40010C0C &= ~(1<<1);
}

void LED_Red(){

    *(unsigned int *)0x40010C00 |= ((1)<<(4*5));
    *(unsigned int *)0x40010C0C &= ~(1<<5);
}

void LED_Blue_OFF(){
    *(unsigned int *)0x40010C0C |= (1<<1);
}

void LED_Red_OFF(){
    *(unsigned int *)0x40010C0C |= (1<<5);
}

void LED_Green_OFF(){
    *(unsigned int *)0x40010C0C |= (1<<0);
}

void LED_Off(){

    LED_Blue_OFF();
    LED_Green_OFF();
    LED_Red_OFF();

}


void delay(unsigned int xms) //xms代表需要延时的毫秒数
{
    unsigned int x,y;
    for(x=xms;x>0;x--)
       for(y=110;y>0;y--);
}


int main(void){

    //打开GPIOB的时钟
    *(unsigned int *)0x40021018 |= ((1) << 3);

    while(1){

    LED_Red();
    delay(10000);

    LED_Red_OFF();
    delay(10000);

    LED_Green();
    delay(10000);

//    LED_Off();
//    delay(10000);

//    LED_Blue();
//    delay(10000);

//    LED_Off();
//    delay(10000);

    }

}

void SystemInit(){ 


}

//void Delay_ms(uint64_t nms)
//{
//  if(nms == 0)
//  {
//    return;
//  }
//  
//  while(nms > 500)
//  {
//    RCC_ClocksTypeDef RCC_ClockFreq;
//    
//    RCC_GetClocksFreq(&RCC_ClockFreq);                            /* Get the frequencies of different on chip clocks. */
//    
//    if(RCC_ClockFreq.HCLK_Frequency < 8000000)
//    {
//      SysTick->CTRL |= SysTick_CLKSource_HCLK;                    /* Configures the SysTick clock source. */
//      SysTick->LOAD = RCC_ClockFreq.HCLK_Frequency / 1000 * 500;  /* Time load (SysTick-> LOAD is 24bit). */
//    }
//    else
//    {
//      SysTick->CTRL &= SysTick_CLKSource_HCLK_Div8;               /* Configures the SysTick clock source. */
//      SysTick->LOAD = RCC_ClockFreq.HCLK_Frequency / 8000 * 500;  /* Time load (SysTick-> LOAD is 24bit). */
//    }
//    
//    SysTick->VAL = 0;                                             /* Empty counter. */
//    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;                     /* Start the countdown. */
//    
//    while((SysTick->CTRL&(1UL<<16)) != (1UL<<16));                /* Wait time is reached. */
//    
//    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;                    /* Close counter. */
//    
//    nms -= 500;
//  }
//  
//  RCC_ClocksTypeDef RCC_ClockFreq;
//  
//  RCC_GetClocksFreq(&RCC_ClockFreq);                              /* Get the frequencies of different on chip clocks. */
//  
//  if(RCC_ClockFreq.HCLK_Frequency < 8000000)
//  {
//    SysTick->CTRL |= SysTick_CLKSource_HCLK;                      /* Configures the SysTick clock source. */
//    SysTick->LOAD = RCC_ClockFreq.HCLK_Frequency / 1000 * nms;    /* Time load (SysTick-> LOAD is 24bit). */
//  }
//  else
//  {
//    SysTick->CTRL &= SysTick_CLKSource_HCLK_Div8;                 /* Configures the SysTick clock source. */
//    SysTick->LOAD = RCC_ClockFreq.HCLK_Frequency / 8000 * nms;    /* Time load (SysTick-> LOAD is 24bit). */
//  }
//  
//  SysTick->VAL = 0;                                               /* Empty counter. */
//  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;                       /* Start the countdown. */
//  
//  while((SysTick->CTRL&(1UL<<16)) != (1UL<<16));                  /* Wait time is reached. */
//  
//  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;                      /* Close counter. */
//}


