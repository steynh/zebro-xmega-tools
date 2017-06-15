//
// Created by steyn on 17-6-7.
//

#include "TimerCounterType0.h"

void TimerCounterType0::setPeriod(TC0_t *timerCounter, uint16_t period)
{
	timerCounter->PER = period;
}

void TimerCounterType0::selectClock(TC0_t *timerCounter, TC_CLKSEL_t clksel)
{
	timerCounter->CTRLA = clksel;  // first 4 bits are reserved/unused so can be written to zero
}

void TimerCounterType0::setEnableCompareOrCaptureD(TC0_t *timerCounter, bool enabled)
{
	if (enabled)
		timerCounter->CTRLB |= TC0_CCDEN_bm;
	else
		timerCounter->CTRLB &= ~TC0_CCDEN_bm;
}

void TimerCounterType0::setWaveformGenerationMode(TC0_t *timerCounter, TC_WGMODE_t waveformGenerationMode)
{
	timerCounter->CTRLB = (timerCounter->CTRLB & ~TC0_WGMODE_gm) | waveformGenerationMode;
}

void TimerCounterType0::setCompareOrCaptureAInterruptLevel(TC0_t *timerCounter, TC_CCAINTLVL_t interruptLevel)
{
	timerCounter->INTCTRLB = (timerCounter->INTCTRLB & ~TC0_CCAINTLVL_gm) | interruptLevel << TC0_CCAINTLVL_gp;
}

void TimerCounterType0::setCompareOrCaptureDInterruptLevel(TC0_t *timerCounter, TC_CCDINTLVL_enum interruptLevel)
{
	timerCounter->INTCTRLB |= TC_CCDINTLVL_HI_gc; //(TCC0.INTCTRLB & ~TC0_CCDINTLVL_gm) | interruptLevel;
}

void TimerCounterType0::setCompareOrCaptureD(TC0_t *timerCounter, uint16_t value)
{
	timerCounter->CCD = value;
}
