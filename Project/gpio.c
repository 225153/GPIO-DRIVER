/**
  ******************************************************************************
  * @file    Lab-Libraries/gpio.c
  * @author  CSF Team
  * @mail    formation@csf.tn
  * @Tel     (+216)92.039.433
  * @version V1.0.0
  * @date    28-04-2024
  *****************************************************************************
/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

// Ajouter define pour RCC clock 
volatile unsigned short int *rcc_enable =(volatile unsigned short int*)0x40023830;

// Ajouter define pour RCC  reste 
volatile unsigned short int  *rcc_reset  =(volatile unsigned short int*)0x40023810;
//...

/**
  * @brief  Enable the gpio_x peripheral clock.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @retval None
  */
void GPIO_ClockEnable (unsigned int * gpio_x)
{

  if (gpio_x == GPIO_A)
  {
    // activer le clock du GPIOA 
    *rcc_enable|=(1<<0);
    //...
  }
  else if (gpio_x == GPIO_B){
  *rcc_enable|=(1<<1);
  }
  else if (gpio_x == GPIO_C){
  *rcc_enable|=(1<<2);
  }
  else if (gpio_x == GPIO_D){
  *rcc_enable|=(1<<3);
  }
  
    else if (gpio_x == GPIO_E){
  *rcc_enable|=(1<<4);
  }
    else if (gpio_x == GPIO_F){
  *rcc_enable|=(1<<5);
  }
    else if (gpio_x == GPIO_G){
  *rcc_enable|=(1<<6);
  }
    else if (gpio_x == GPIO_H){
  *rcc_enable|=(1<<7);
  }
    else if (gpio_x == GPIO_I){
  *rcc_enable|=(1<<8);
  }
   else if (gpio_x == GPIO_J){
  *rcc_enable|=(1<<9);
  }
   else if (gpio_x == GPIO_K){
  *rcc_enable|=(1<<10);
  }
  
  
  
  // ajouter les autres gpio
  //...    
  //...
}
void GPIO_DeInit(unsigned int * gpio_x){//lezem reset naatiha 1 modda ou mbaaed naatiha 0 khater ken naatiha dima 1 bech tokood dima reset ou manajamch nekhdem beha
   if (gpio_x == GPIO_A)
  {
    // activer le clock du GPIOA 
    *rcc_reset |= (1<<0);
    *rcc_reset &= ~(1<<0);
    //...
  }
  else if (gpio_x == GPIO_B){
  *rcc_reset |= (1<<1);
  *rcc_reset &= ~ (1<<1);
  }
  else if (gpio_x == GPIO_C){
  *rcc_reset |= (1<<2);
  *rcc_reset &= ~(1<<2);
  }
  else if (gpio_x == GPIO_D){
  *rcc_reset |= (1<<3);
  *rcc_reset &= ~(1<<3);
  }
   
    else if (gpio_x == GPIO_E){
  *rcc_reset |= (1<<4);
  *rcc_reset &= ~(1<<4);
  }
    else if (gpio_x == GPIO_F){
  *rcc_reset |= (1<<5);
  *rcc_reset &= ~(1<<5);
  }
    else if (gpio_x == GPIO_G){
  *rcc_reset |= (1<<6);
  *rcc_reset &= ~(1<<6);
  }
    else if (gpio_x == GPIO_H){
  *rcc_reset |= (1<<7);
  *rcc_reset &= ~(1<<0);
  }
    else if (gpio_x == GPIO_I){
  *rcc_reset |= (1<<8);
  *rcc_reset &= ~(1<<8);
  }
   else if (gpio_x == GPIO_J){
  *rcc_reset |= (1<<9);
  *rcc_reset &= ~(1<<9);
  }
   else if (gpio_x == GPIO_K){
  *rcc_reset |= (1<<10);
  *rcc_reset &= ~(1<<10);
  }
  
  
  
  // ajouter les autres gpio
  //...    
  //...



}
//ki nalka des driver optimisées aal internet najem nalkahom yekhdmou bel structures mathalan structure gpio yhot feha l mod ou el speed ou el kol
void GPIO_Init(unsigned int * gpio_x, char Mode, char typeOutput, short int pin)
{
  //ken fama gpio_d bech tetaawedh fel gpio_x maneha maghir manaamel if
 unsigned int mask  =~(0x03<<(pin*2));                      //si pin 12 par exemple en ecrit sur bit 24
 
 //mettre a 0 la valeur du modeer
 *(gpio_x+(MODER)) &=(mask);
  
 
//appliquer le mode choisi
 *(gpio_x+MODER) |=(Mode<<(pin*2));// bech tzid des 1 
 //output type
  mask = ~(0x01<<pin);//on declare pas une autre variable khater fi c embarqué nestaamel le minimum de variable
  if(typeOutput==TYPE_PP){
  *(gpio_x+(OTYPER)) &= mask;
  }
  else{
   *(gpio_x+OTYPER) |= ~mask;
  
  }

}
unsigned  char GPIO_ReadInputDataBit(unsigned int *  gpio_x, unsigned  short int GPIO_Pin)
{
  unsigned char bit_status = 0x00;                             //regle de misra variable doit etre initialise
  if((*(gpio_x+IDR)&(GPIO_Pin))!=0x00)
{
  //declarina fel .h gpio_poin ken 5 mathalan maaneha 5 fel bit 5 kahaw mech 5 fel hexa maaneha temchy mrigla lahne
  
  bit_status=0x01;    
  }
  else
  {
  bit_status=0x00;
  }
  
  
  
 return bit_status;//fe c embarqué madhabeya naamel return marra bark maaneha manaamekch if return else return n declary variable ou naatiha les valeurs

}
unsigned  short int GPIO_ReadInputData(unsigned int *  gpio_x){
return (*(gpio_x+IDR));

}
void GPIO_WriteBit(unsigned int * gpio_x, unsigned  short int GPIO_Pin, char BitVal){
if(BitVal !=0){
*(gpio_x+ODR) |=GPIO_Pin;

}
else{
*(gpio_x+ODR) &= ~GPIO_Pin;
}

}
void GPIO_Write(unsigned int * gpio_x, unsigned  short int PortVal){
*(gpio_x+ODR)=PortVal;
}


























/******************* (C) COPYRIGHT 2024 CSF *****END OF FILE*******************/

