/*
 * Created by Steyn Huurman on 01-08-2017
 *
 * You can ask me questions: zebro@steynhuurman.nl
 */

#include "TimerCounterType1.h"

void TimerCounterType1::setPeriod(TC1_t *timerCounter, uint16_t period)
{
	timerCounter->PER = period;
}

void TimerCounterType1::selectClock(TC1_t *timerCounter, TC_CLKSEL_t clksel)
{
	timerCounter->CTRLA = clksel;  // first 4 bits are reserved/unused so can be written to zero
}

void TimerCounterType1::setEnableCompareOrCaptureB(TC1_t *timerCounter, bool enabled)
{
	if (enabled)
		timerCounter->CTRLB |= TC0_CCBEN_bm;
	else
		timerCounter->CTRLB &= ~TC0_CCBEN_bm;
}

void TimerCounterType1::setWaveformGenerationMode(TC1_t *timerCounter, TC_WGMODE_t waveformGenerationMode)
{
	timerCounter->CTRLB = (timerCounter->CTRLB & ~TC0_WGMODE_gm) | waveformGenerationMode;
}

void TimerCounterType1::setCompareOrCaptureAInterruptLevel(TC1_t *timerCounter, TC_CCAINTLVL_t interruptLevel)
{
	timerCounter->INTCTRLB = (timerCounter->INTCTRLB & ~TC0_CCAINTLVL_gm) | interruptLevel << TC0_CCAINTLVL_gp;
}

void TimerCounterType1::setCompareOrCaptureDInterruptLevel(TC1_t *timerCounter, TC_CCDINTLVL_enum interruptLevel)
{
	timerCounter->INTCTRLB |= TC_CCDINTLVL_HI_gc; //(TCC0.INTCTRLB & ~TC0_CCDINTLVL_gm) | interruptLevel;
}

void TimerCounterType1::setCompareOrCaptureB(TC1_t *timerCounter, uint16_t value)
{
	timerCounter->CCB = value;
}
