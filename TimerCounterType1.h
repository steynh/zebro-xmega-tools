/*
 * Created by Steyn Huurman on 01-08-2017
 *
 * You can ask me questions: zebro@steynhuurman.nl
 */

#ifndef DECI_ZEBRO_LEG_MODULE_TIMERCOUNTERTYPE1_H
#define DECI_ZEBRO_LEG_MODULE_TIMERCOUNTERTYPE1_H


#include <avr/io.h>

class TimerCounterType1 {
public:
	static void setPeriod(TC1_t *timerCounter, uint16_t period);
	static void selectClock(TC1_t *timerCounter, TC_CLKSEL_t clksel);
	static void setEnableCompareOrCaptureB(TC1_t *timerCounter, bool enabled);
	static void setWaveformGenerationMode(TC1_t *timerCounter, TC_WGMODE_t waveformGenerationMode);
	static void setCompareOrCaptureAInterruptLevel(TC1_t *timerCounter, TC_CCAINTLVL_t interruptLevel);
	static void setCompareOrCaptureDInterruptLevel(TC1_t *timerCounter, TC_CCDINTLVL_enum interruptLevel);
	static void setCompareOrCaptureB(TC1_t *timerCounter, uint16_t value);
};



#endif //DECI_ZEBRO_LEG_MODULE_TIMERCOUNTERTYPE1_H
