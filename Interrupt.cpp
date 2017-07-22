/*
 * Created by Steyn Huurman on 05-06-2017
 *
 * You can ask me questions: zebro@steynhuurman.nl
 */

#include <avr/io.h>
#include "Interrupt.h"

void ZebroXMega::Interrupt::setEnableHighLevelInterrupt(bool enabled)
{
	if (enabled)
		PMIC.CTRL |= PMIC_HILVLEN_bm;   // Enable
	else
		PMIC.CTRL &= ~PMIC_HILVLEN_bm;  // Disable
}

void ZebroXMega::Interrupt::setEnableMediumLevelInterrupt(bool enabled)
{
	if (enabled)
		PMIC.CTRL |= PMIC_MEDLVLEN_bm;   // Enable
	else
		PMIC.CTRL &= ~PMIC_MEDLVLEN_bm;  // Disable
}

void ZebroXMega::Interrupt::setEnableLowLevelInterrupt(bool enabled)
{
	if (enabled)
		PMIC.CTRL |= PMIC_LOLVLEN_bm;   // Enable
	else
		PMIC.CTRL &= ~PMIC_LOLVLEN_bm;  // Disable
}
