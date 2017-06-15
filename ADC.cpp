//
// Created by steyn on 17-6-4.
//

#include <avr/io.h>
#include "ADC.h"

void ZebroXMega::ADC::enable(ADC_t *adc)
{

	adc->CTRLA |= ADC_ENABLE_bm;
}

void ZebroXMega::ADC::setReferenceVoltage(ADC_t *adc, ADC_REFSEL_t referenceVoltage)
{
	adc->REFCTRL = (adc->REFCTRL & ~ADC_REFSEL_gm) | referenceVoltage;
}

void ZebroXMega::ADC::startConversion(ADC_CH_t* channel)
{
	channel->CTRL |= ADC_CH_START_bm;
}

uint16_t ZebroXMega::ADC::getChannelResult(ADC_CH_t *channel)
{
	return channel->RES;
}

void ZebroXMega::ADC::setChannelInputMode(ADC_CH_t *channel, ADC_CH_INPUTMODE_t inputMode)
{
	channel->CTRL = (channel->CTRL & ~ADC_CH_INPUTMODE_gm) | inputMode;
}

void ZebroXMega::ADC::setChannelMultiplexerPosition(ADC_CH_t *channel, ADC_CH_MUXPOS_t position)
{
	channel->MUXCTRL = (channel->MUXCTRL & ~ADC_CH_MUXPOS_gm) | position;
}

void ZebroXMega::ADC::setChannelInterruptMode(ADC_CH_t *channel, ADC_CH_INTMODE_t mode)
{
	channel->INTCTRL = (channel->INTCTRL & ~ADC_CH_INTMODE_gm) | mode;
}

void ZebroXMega::ADC::setChannelInterruptLevel(ADC_CH_t *channel, ADC_CH_INTLVL_t level)
{
	channel->INTCTRL = (channel->INTCTRL & ~ADC_CH_INTLVL_gm) | level;
}

void ZebroXMega::ADC::setSignedMode(ADC_t *adc, bool value)
{
	if (value)
		adc->CTRLB |= ADC_CONMODE_bm;   // signed mode
	else
		adc->CTRLB &= ~ADC_CONMODE_bm;  // unsigned mode
}

