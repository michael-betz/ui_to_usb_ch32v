#include "tusb_config.h"
#include <tusb.h>

// --- Device Descriptor ---
tusb_desc_device_t const desc_device =
{
    .bLength            = sizeof(tusb_desc_device_t),
    .bDescriptorType    = TUSB_DESC_DEVICE,
    .bcdUSB             = 0x0200,
    .bDeviceClass       = 0x00,
    .bDeviceSubClass    = 0x00,
    .bDeviceProtocol    = 0x00,
    .bMaxPacketSize0    = CFG_TUD_ENDPOINT0_SIZE,
    .idVendor           = 0xCAFE,
    .idProduct          = 0x0001,
    .bcdDevice          = 0x0100,
    .iManufacturer      = 0x01,
    .iProduct           = 0x02,
    .iSerialNumber      = 0x03,
    .bNumConfigurations = 0x01
};

uint8_t const * tud_descriptor_device_cb(void) { return (uint8_t const *) &desc_device; }

// --- HID Report Descriptor ---
// Defines a generic report: 64 bytes IN, 64 bytes OUT
uint8_t const desc_hid_report[] = {
    TUD_HID_REPORT_DESC_GENERIC_INOUT(64)
};

uint8_t const * tud_hid_descriptor_report_cb(uint8_t itf) {
    (void) itf;
    return desc_hid_report;
}

// --- Configuration Descriptor ---
#define EPNUM_HID   0x01 // Uses EP 1 for both IN (0x81) and OUT (0x01)

uint8_t const desc_configuration[] =
{
    // Config number, Interface count, String index, Total length, Attributes, Power
    TUD_CONFIG_DESCRIPTOR(1, 1, 0, TUD_CONFIG_DESC_LEN + TUD_HID_INOUT_DESC_LEN, 0x00, 100),

    // Interface 0: HID Generic, 2 Endpoints (IN/OUT), 64 byte buffer, 1ms poll (approx)
    TUD_HID_INOUT_DESCRIPTOR(0, 0, HID_ITF_PROTOCOL_NONE, sizeof(desc_hid_report),
                             0x80 | EPNUM_HID, EPNUM_HID, 64, 1)
};

uint8_t const * tud_descriptor_configuration_cb(uint8_t index) {
    (void) index;
    return desc_configuration;
}

// --- String Descriptors ---
uint16_t const* tud_descriptor_string_cb(uint8_t index, uint16_t langid) {
    (void) langid; (void) index;
    return NULL; // Skipping strings for simplicity
}
