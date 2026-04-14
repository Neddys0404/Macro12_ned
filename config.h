#pragma once

#define DEBOUNCE 5

/* Reset. (May not be needed) */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

// Encoder Pins and resolutions
#define ENCODERS_PAD_A { { GP3 }, { GP5 } }
#define ENCODERS_PAD_B { { GP4 }, { GP6 } }
#define ENCODER_RESOLUTION 4
