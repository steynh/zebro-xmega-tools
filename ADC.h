//
// Created by steyn on 17-6-4.
//

#ifndef ZEBRO_XMEGA_ADC_H
#define ZEBRO_XMEGA_ADC_H


namespace ZebroXMega {
	class ADC {
	public:
		static void enable(ADC_t *adc);
		static void startConversion(ADC_CH_t* channel);
		static uint16_t getChannelResult(ADC_CH_t* channel);
		static void setChannelInputMode(ADC_CH_t *channel, ADC_CH_INPUTMODE_t inputMode);
		static void setChannelMultiplexerPosition(ADC_CH_t *channel, ADC_CH_MUXPOS_t position);
		static void setChannelInterruptMode(ADC_CH_t *channel, ADC_CH_INTMODE_t mode);
		static void setChannelInterruptLevel(ADC_CH_t *channel, ADC_CH_INTLVL_t level);
		static void setReferenceVoltage(ADC_t *adc, ADC_REFSEL_t referenceVoltage);
		static void setSignedMode(ADC_t *adc, bool value);

	private:
		ADC(){}
	};
}


#endif //ZEBRO_XMEGA_ADC_H
