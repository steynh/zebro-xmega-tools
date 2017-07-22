/*
 * Created by Steyn Huurman on 02-06-2017
 *
 * You can ask me questions: zebro@steynhuurman.nl
 */

#ifndef ZEBRO_XMEGA_DIGITALPIN_H
#define ZEBRO_XMEGA_DIGITALPIN_H

#include <stdint.h>
#include <avr/io.h>
#include "../zebro-avr-tools/DigitalPin.h"
#include "../zebro-avr-tools/DigitalPinInterruptListener.h"

namespace ZebroXMega {

	class DigitalPin : public ZebroAvr::DigitalPin {
	public:
		DigitalPin(PORT_t* port, uint8_t pin_bm);

		void setMode(ZebroAvr::PinMode mode) override;

		ZebroAvr::PinValue read() override;
		void write(ZebroAvr::PinValue pinValue) override;
		void toggle();

		static void write(PORT_t *port, uint8_t pin_bm, ZebroAvr::PinValue pinValue);
		static void setMode(PORT_t *port, uint8_t pin_bm, ZebroAvr::PinMode mode);

	private:
		PORT_t* port;
		uint8_t pin_bm;
	};
}


#endif //ZEBRO_XMEGA_DIGITALPIN_H
