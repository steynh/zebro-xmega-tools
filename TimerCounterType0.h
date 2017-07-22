/*
 * Created by Steyn Huurman on 07-06-2017
 *
 * You can ask me questions: zebro@steynhuurman.nl
 */

#ifndef ZEBRO_XMEGA_TIMER_COUNTER_TYPE_0_H
#define ZEBRO_XMEGA_TIMER_COUNTER_TYPE_0_H


#include <avr/io.h>

class TimerCounterType0 {
public:
	static void setPeriod(TC0_t *timerCounter, uint16_t period);
	static void selectClock(TC0_t *timerCounter, TC_CLKSEL_t clksel);
	static void setEnableCompareOrCaptureD(TC0_t *timerCounter, bool enabled);
	static void setWaveformGenerationMode(TC0_t *timerCounter, TC_WGMODE_t waveformGenerationMode);
	static void setCompareOrCaptureAInterruptLevel(TC0_t *timerCounter, TC_CCAINTLVL_t interruptLevel);
	static void setCompareOrCaptureDInterruptLevel(TC0_t *timerCounter, TC_CCDINTLVL_enum interruptLevel);
	static void setCompareOrCaptureD(TC0_t *timerCounter, uint16_t value);
};


#endif //ZEBRO_XMEGA_TIMER_COUNTER_TYPE_0_H
