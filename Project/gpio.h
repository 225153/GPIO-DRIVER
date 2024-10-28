/**
  ******************************************************************************
  * @file    Lab-Libraries/gpio.h 
  * @author  CSF Team
  * @mail    formation@csf.tn
  * @Tel     (+216)92.039.433
  * @version V1.0.0
  * @date    23-04-2024
  *****************************************************************************

/* Includes ------------------------------------------------------------------*/
#define GPIO_A  (unsigned int*)  0x40020000
#define GPIO_B  (unsigned int*)  0x40020400
#define GPIO_C  (unsigned int*)  0x40020800
#define GPIO_D  (unsigned int*)  0x40020c00
#define GPIO_E  (unsigned int*)  0x40021000
#define GPIO_F  (unsigned int*)  0x40021400
#define GPIO_G  (unsigned int*)  0x40021800
#define GPIO_H  (unsigned int*)  0x40021c00
#define GPIO_I  (unsigned int*)  0x40022000
#define GPIO_J  (unsigned int*)  0x40022400
#define GPIO_K  (unsigned int*)  0x40022800
/*GPIO register offset*/
#define MODER 0x00
#define OTYPER 0X01                //ksamna les valeurs de l'offset par 4 khater l adreese gpio int maaneha bech tkadem b 4
#define OSPEEDR 0X02
#define PUPDR 0X03
#define IDR 0X04
#define ODR 0X05
#define BSRR 0X06
#define LCKR 0X07
#define AFRL 0X08
#define AFRH 0X09
/*MODE*/

#define MODE_INPUT        0x00  // Mode d'entrée
#define MODE_OUTPUT       0x01  // Mode de sortie
#define MODE_AF           0x02  // Mode de fonction alternative
#define MODE_ANALOG       0x03  // Mode analogique

/*OUTPUT TYPE*/
#define TYPE_PP           0x00  // Type de sortie push-pull
#define TYPE_OD           0x01  // Type de sortie open-drain

/*SPEED LEVEL*/
#define SPEED_low         0x00
#define SPEED_MEDIUM      0x01
#define SPEED_HIGH        0x02
#define SPEED_VERY_HIGH   0x03
/*PULL mode*/
#define PULL_NO 0x00
#define PULL_UP 0x01
#define PULL _DOWN 0x02
/*GPIO PIN*/
#define GPIO_PIN_0        ((unsigned short) 0x0001)  // Pin 0
#define GPIO_PIN_1        ((unsigned short) 0x0002)  // Pin 1
#define GPIO_PIN_2        ((unsigned short) 0x0004)  // Pin 2
#define GPIO_PIN_3        ((unsigned short) 0x0008)  // Pin 3
#define GPIO_PIN_4        ((unsigned short) 0x0010)  // Pin 4
#define GPIO_PIN_5        ((unsigned short) 0x0020)  // Pin 5
#define GPIO_PIN_6        ((unsigned short) 0x0040)  // Pin 6
#define GPIO_PIN_7        ((unsigned short) 0x0080)  // Pin 7
#define GPIO_PIN_8        ((unsigned short) 0x0100)  // Pin 8
#define GPIO_PIN_9        ((unsigned short) 0x0200)  // Pin 9
#define GPIO_PIN_10       ((unsigned short) 0x0400)  // Pin 10
#define GPIO_PIN_11       ((unsigned short) 0x0800)  // Pin 11
#define GPIO_PIN_12       ((unsigned short) 0x1000)  // Pin 12
#define GPIO_PIN_13       ((unsigned short) 0x2000)  // Pin 13
#define GPIO_PIN_14       ((unsigned short) 0x4000)  // Pin 14
#define GPIO_PIN_15       ((unsigned short) 0x8000)  // Pin 15
/*GPIO PIN*/
#define PIN_0  00
#define PIN_1  01
#define PIN_2  02
#define PIN_3  03
#define PIN_4  04 
#define PIN_5  05
#define PIN_6  06
#define PIN_7  07
#define PIN_8  08
#define PIN_9  09
#define PIN_10 10
#define PIN_11 11
#define PIN_12 12
#define PIN_13 13
#define PIN_14 14
#define PIN_15 15


/* -----------------ajouter les protopyes des fonctions----------------------*/


/* GPIO enable function */
void GPIO_ClockEnable (unsigned int * gpio_x);

/* GPIO Resete function */
void GPIO_DeInit(unsigned int * gpio_x);

/* Config function */
void GPIO_Init(unsigned int * gpio_x, char Mode, char typeOutput, short int pin);

/* Read functions */
unsigned  char GPIO_ReadInputDataBit(unsigned int *  gpio_x, unsigned  short int GPIO_Pin);
unsigned  short int GPIO_ReadInputData(unsigned int *  gpio_x);

/* Write functions */
void GPIO_WriteBit(unsigned int * gpio_x, unsigned  short int GPIO_Pin, char BitVal);
void GPIO_Write(unsigned int * gpio_x, unsigned  short int PortVal);
/******************* (C) COPYRIGHT 2019 CSF *****END OF FILE*******************/