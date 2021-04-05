#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"

#include <iostream>
#include <bitset>

#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <vector>

#define HIGH 1
#define LOW 0

#define	RS 0
#define RW 1
#define EN 2
#define D0 8
#define D1 9
#define D2 10
#define D3 11
#define D4 12
#define D5 13
#define D6 14
#define D7 15

/* PINOUT, USB port facing up, debug pins on bottom
    USB
0       VBUS
1       VSYS
GND     GND
2       3V3_EN
3       3V3_OUT
4       ADC_VREF
5       28 / ADC2
GND     GND / AGND
6       27 / ADC1
7       26 / ADC0
8       RUN
9       22
GND     GND
10      21
11      20
12      19
13      18
GND     GND
14      17
15      16
    DBG
*/

// 0 = input, 1 =  output
void InitPin(unsigned int pin, int direction)
{
    if (pin < 0 || pin > 40 || pin == 29 || pin == 24 || pin == 23) {
        return;
    }
    gpio_init(pin);
    gpio_set_dir(pin, direction);
}

void PulseEnable()
{
	gpio_put(EN, HIGH);
	sleep_ms(5);
	gpio_put(EN, LOW);
}

void DataWriteEX(char value)
{
	gpio_put(EN, LOW);
	gpio_put(RS, HIGH);
	gpio_put(RW, LOW);

	gpio_put(D7, (value & 0x80) >> 7);
	gpio_put(D6, (value & 0x40) >> 6);
	gpio_put(D5, (value & 0x20) >> 5);
	gpio_put(D4, (value & 0x10) >> 4);
	gpio_put(D3, (value & 0x08) >> 3);
	gpio_put(D2, (value & 0x04) >> 2);
	gpio_put(D1, (value & 0x02) >> 1);
	gpio_put(D0, value & 0x01);

	PulseEnable();
}

void CommandWriteEX(char value)
{
	gpio_put(EN, LOW);
	gpio_put(RS, LOW);
	gpio_put(RW, LOW);

	gpio_put(D7, (value & 0x80) >> 7);
	gpio_put(D6, (value & 0x40) >> 6);
	gpio_put(D5, (value & 0x20) >> 5);
	gpio_put(D4, (value & 0x10) >> 4);
	gpio_put(D3, (value & 0x08) >> 3);
	gpio_put(D2, (value & 0x04) >> 2);
	gpio_put(D1, (value & 0x02) >> 1);
	gpio_put(D0, value & 0x01);

	PulseEnable();
}

void ClearScreen() {
	CommandWriteEX(0x01);
}

void ReturnHome() {
	CommandWriteEX(0x02);
}

void CursorShiftLeftInc() {
	CommandWriteEX(0x04);
}

void CursorShiftRightInc() {
	CommandWriteEX(0x06);
}

void DisplayShiftLeft() {
	CommandWriteEX(0x07);
}

void DisplayShiftRight() {
	CommandWriteEX(0x05);
}

void DisplayOffCursorOff()
{
	CommandWriteEX(0x08);
}

void DisplayOffCursorOn() {
	CommandWriteEX(0x0A);
}

void DisplayOnCursorOff() {
	CommandWriteEX(0x0C);
}

void DisplayOnCursorBlink() {
	CommandWriteEX(0x0E);
	CommandWriteEX(0x0F);
}

void CursorPositionLeft() {
	CommandWriteEX(0x10);
}

void CursorPositionRight() {
	CommandWriteEX(0x14);
}

void DisplayEntireShiftLeft() {
	CommandWriteEX(0x18);
}

void DisplayEntireShiftRight() {
	CommandWriteEX(0x1C);
}

void CursorHomeTop() {
	CommandWriteEX(0x80);
}

void CursorHomeBottom() {
	CommandWriteEX(0xC0);
}

void StringWrite(std::string Message, int CursorPosition = 0, int Line = 0, bool ClearLine = true) {
	if (ClearLine) {
		switch (Line)
		{
		case 0:
			CommandWriteEX(0x80);
			break;

		case 1:
			CommandWriteEX(0xC0);
			break;
		default:
			break;
		}
		CommandWriteEX(0x80);
		for (int i = 0; i < 15; i++) {
			DataWriteEX(0x20);
			CommandWriteEX(0x06);
		}
	}

	switch (Line)
	{
	case 0:
		CommandWriteEX(0x80);
		break;

	case 1:
		CommandWriteEX(0xC0);
		break;
	default:
		break;
	}

	for (int i = 0; i < CursorPosition; i++) {
		CommandWriteEX(0x06);
	}

	bool Dropped = false;
	for (std::size_t i = 0; i < Message.size(); ++i)
	{
		if (i > 15) {
			if (!Dropped) {
				CursorHomeBottom();
				Dropped = true;
			}
		}
		char XK = Message[i];
		DataWriteEX(XK);
	}
	
}

void Initialize8Bit()
{
	gpio_put(EN, LOW);
	gpio_put(RS, LOW);
	gpio_put(RW, LOW);
	CommandWriteEX(0x30);
	PulseEnable();

	CommandWriteEX(0x30);
	PulseEnable();

	CommandWriteEX(0x30);
	PulseEnable();

	CommandWriteEX(0x38);
	PulseEnable();

	CommandWriteEX(0x08);
	PulseEnable();

	CommandWriteEX(0x01);
	PulseEnable();

	CommandWriteEX(0x06);
	PulseEnable();
}

int main() {

    InitPin(RS, GPIO_OUT);
    InitPin(RW, GPIO_OUT);
    InitPin(EN, GPIO_OUT);
    InitPin(D0, GPIO_OUT);
    InitPin(D1, GPIO_OUT);
    InitPin(D2, GPIO_OUT);
    InitPin(D3, GPIO_OUT);
    InitPin(D4, GPIO_OUT);
    InitPin(D5, GPIO_OUT);
    InitPin(D6, GPIO_OUT);
    InitPin(D7, GPIO_OUT);

    Initialize8Bit();
	// delay(500);

	CommandWriteEX(0x01);

	CommandWriteEX(0x0E);

	CommandWriteEX(0x80);

	CommandWriteEX(0x0F);

    StringWrite("Sapphire Labs", 0, 0, true);
    DisplayOnCursorOff();
}
