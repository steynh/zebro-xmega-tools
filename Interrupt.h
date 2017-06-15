//
// Created by steyn on 17-6-5.
//

#ifndef ZEBRO_XMEGA_INTERRUPT_H
#define ZEBRO_XMEGA_INTERRUPT_H


namespace ZebroXMega {
	class Interrupt {
	public:
		static void setEnableHighLevelInterrupt(bool enabled);
		static void setEnableMediumLevelInterrupt(bool enabled);
		static void setEnableLowLevelInterrupt(bool enabled);
	};
}


#endif //ZEBRO_XMEGA_INTERRUPT_H
