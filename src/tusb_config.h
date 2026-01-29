#ifndef _TUSB_CONFIG_H_
#define _TUSB_CONFIG_H_

#define BOARD_TUD_RHPORT 0

// USB Port setup for CH32V305 (High Speed)
#define CFG_TUSB_RHPORT0_MODE     (OPT_MODE_DEVICE | OPT_MODE_HIGH_SPEED)

// Device Config
#define CFG_TUD_ENDPOINT_MAX      16
#define CFG_TUD_ENDPOINT0_SIZE    64

// Class Config
#define CFG_TUD_HID               1
#define CFG_TUD_HID_EP_BUFSIZE    64

// Enable Device stack
#define CFG_TUD_ENABLED       1

// Default is max speed that hardware controller could support with on-chip PHY
#define CFG_TUD_MAX_SPEED     BOARD_TUD_MAX_SPEED

#endif
