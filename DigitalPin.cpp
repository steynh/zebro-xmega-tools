//
// Created by steyn on 17-6-2.
//

#include "DigitalPin.h"

ZebroXMega::DigitalPin::DigitalPin(PORT_t *port, uint8_t pin_bm) :
		port(port),
		pin_bm(pin_bm)
{
}

void ZebroXMega::DigitalPin::setMode(ZebroAvr::PinMode mode)
{
	setMode(port, pin_bm, mode);
}

ZebroAvr::PinValue ZebroXMega::DigitalPin::read()
{
	return (port->IN & pin_bm) ? ZebroAvr::HIGH : ZebroAvr::LOW;
}

void ZebroXMega::DigitalPin::write(ZebroAvr::PinValue pinValue)
{
	write(port, pin_bm, pinValue);
}

void ZebroXMega::DigitalPin::toggle()
{
	port->OUTTGL = pin_bm;
}

void ZebroXMega::DigitalPin::write(PORT_t *port, uint8_t pin_bm, ZebroAvr::PinValue pinValue)
{
	if (pinValue == ZebroAvr::HIGH) {
		port->OUTSET = pin_bm;
	} else if (pinValue == ZebroAvr::LOW) {
		port->OUTCLR = pin_bm;
	}
}

void ZebroXMega::DigitalPin::setMode(PORT_t *port, uint8_t pin_bm, ZebroAvr::PinMode mode)
{
	if (mode == ZebroAvr::OUTPUT) {
		port->DIRSET = pin_bm;
	} else if (mode == ZebroAvr::INPUT) {
		port->DIRCLR = pin_bm;
	}
}
