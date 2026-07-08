#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "inc/userFncFile.h"
#include "inc/systemTimer.h"
#include "inc/led_Led1.h"
#include "inc/led_Led2.h"
#include "inc/timer_api1.h"
#include "inc/conversionFunctions.h"
#include "inc/Graphics_OLED.h"
#include "inc/Edit_Edit1.h"
#include "inc/Keyboard_Pad.h"
#include "inc/Keyboard_Nav.h"
#include "inc/EMICBus.h"

/* User Variables */
char Teclado;
char Flechas;
uint16_t RPMVar;

void onReset()
{
    LEDs_Led1_blink(100, 200, 3);
    LEDs_Led2_blink(100, 200, 3);
    RPM();
    RPMVar = 0;
}


void RPM(void)
{
    Graphics_OLED_clear();
    Graphics_OLED_printAt(45, 7, 0, "Prueba");
    Graphics_OLED_rect(3, 43, 123, 18);
    Graphics_OLED_printAt(5, 17, 0, "RPM:");
    Graphics_OLED_printAt(5, 49, 0, "TECLADO:");
    Graphics_OLED_printAt(5, 28, 0, "FLECHAS");
    Graphics_OLED_bindAt(50, 28, 0, &Flechas, 9, "%4d");
    Graphics_OLED_bindAt(56, 49, 0, &Teclado, 9, "%4d");
    Graphics_OLED_bindAt(30, 17, 0, &RPMVar, 1, "%4u");
}


void eI2C(char* tag, const streamIn_t* const msg)
{
    RPMVar = streamIn_t_ptr_to_uint16_t((streamIn_t*)msg);
}


void Keyboard_Pad_onPress(uint8_t key)
{
    Teclado = (char)(key);
}


void Keyboard_Nav_onPress(uint8_t key)
{
    Flechas = (char)(key);
}



