AUX_SOURCE_DIRECTORY(. SOURCE_FILES)

add_avr_library(
        zebro-xmega-tools
        ${SOURCE_FILES}
)

target_link_libraries(
        zebro-xmega-tools-${AVR_MCU}
        zebro-avr-tools-${AVR_MCU}
)
