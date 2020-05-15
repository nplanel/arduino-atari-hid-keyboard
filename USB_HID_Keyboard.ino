#include "Keyboard.h"

class KeyboardUSBHID_
{
private:
  KeyReport _keyReport;
  void sendReport(KeyReport* keys);
public:
  KeyboardUSBHID_(void);
  void begin(void);
  void end(void);
  size_t write(uint8_t k);
  size_t write(const uint8_t *buffer, size_t size);
  size_t press(uint8_t k);
  size_t release(uint8_t k);
  void releaseAll(void);
};
extern KeyboardUSBHID_ KeyboardUSBHID;


#if defined(_USING_HID)

//================================================================================
//================================================================================
//  Keyboard

static const uint8_t _hidReportDescriptor[] PROGMEM = {

  //  Keyboard
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)  // 47
    0x09, 0x06,                    // USAGE (Keyboard)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x85, 0x02,                    //   REPORT_ID (2)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
   
  0x19, 0xe0,                    //   USAGE_MINIMUM (Keyboard LeftControl)
    0x29, 0xe7,                    //   USAGE_MAXIMUM (Keyboard Right GUI)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)
    0x75, 0x01,                    //   REPORT_SIZE (1)
    
  0x95, 0x08,                    //   REPORT_COUNT (8)
    0x81, 0x02,                    //   INPUT (Data,Var,Abs)
    0x95, 0x01,                    //   REPORT_COUNT (1)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x81, 0x03,                    //   INPUT (Cnst,Var,Abs)
    
  0x95, 0x06,                    //   REPORT_COUNT (6)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x73,                    //   LOGICAL_MAXIMUM (115)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
    
  0x19, 0x00,                    //   USAGE_MINIMUM (Reserved (no event indicated))
    0x29, 0x73,                    //   USAGE_MAXIMUM (Keyboard Application)
    0x81, 0x00,                    //   INPUT (Data,Ary,Abs)
    0xc0,                          // END_COLLECTION
};

KeyboardUSBHID_::KeyboardUSBHID_(void) 
{
// original Keyboard already instanciate this
//
//  static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
//  HID().AppendDescriptor(&node);
}

void KeyboardUSBHID_::begin(void)
{
}

void KeyboardUSBHID_::end(void)
{
}

void KeyboardUSBHID_::sendReport(KeyReport* keys)
{
  HID().SendReport(2,keys,sizeof(KeyReport));
}

extern
const uint8_t _asciimapFR[128] PROGMEM;

#define SHIFT 0x80
const uint8_t _asciimapFR[128] =
{
  0x00,             // NUL
  0x00,             // SOH
  0x00,             // STX
  0x00,             // ETX
  0x00,             // EOT
  0x00,             // ENQ
  0x00,             // ACK  
  0x00,             // BEL
  0x2a,     // BS Backspace
  0x2b,     // TAB  Tab
  0x28,     // LF Enter
  0x00,             // VT 
  0x00,             // FF 
  0x00,             // CR 
  0x00,             // SO 
  0x00,             // SI 
  0x00,             // DEL
  0x00,             // DC1
  0x00,             // DC2
  0x00,             // DC3
  0x00,             // DC4
  0x00,             // NAK
  0x00,             // SYN
  0x00,             // ETB
  0x00,             // CAN
  0x00,             // EM 
  0x00,             // SUB
  0x00,             // ESC
  0x00,             // FS 
  0x00,             // GS 
  0x00,             // RS 
  0x00,             // US 

  0x2c,      //  ' '
  0x1e|SHIFT,    // !
  0x34|SHIFT,    // "
  0x20|SHIFT,    // #
  0x21|SHIFT,    // $
  0x22|SHIFT,    // %
  0x24|SHIFT,    // &
  0x34,          // '
  0x26|SHIFT,    // (
  0x27|SHIFT,    // )
  0x25|SHIFT,    // *
  0x2e|SHIFT,    // +
  0x36,          // ,
  0x2d,          // -
  0x37,          // .
  0x38,          // /
  0x27,          // 0
  0x1e,          // 1
  0x1f,          // 2
  0x20,          // 3
  0x21,          // 4
  0x22,          // 5
  0x23,          // 6
  0x24,          // 7
  0x25,          // 8
  0x26,          // 9
  0x33|SHIFT,      // :
  0x33,          // ;
  0x36|SHIFT,      // <
  0x2e,          // =
  0x37|SHIFT,      // >
  0x38|SHIFT,      // ?
  0x1f|SHIFT,      // @
  0x04|SHIFT,      // A
  0x05|SHIFT,      // B
  0x06|SHIFT,      // C
  0x07|SHIFT,      // D
  0x08|SHIFT,      // E
  0x09|SHIFT,      // F
  0x0a|SHIFT,      // G
  0x0b|SHIFT,      // H
  0x0c|SHIFT,      // I
  0x0d|SHIFT,      // J
  0x0e|SHIFT,      // K
  0x0f|SHIFT,      // L
  0x10|SHIFT,      // M
  0x11|SHIFT,      // N
  0x12|SHIFT,      // O
  0x13|SHIFT,      // P
  0x14|SHIFT,      // Q
  0x15|SHIFT,      // R
  0x16|SHIFT,      // S
  0x17|SHIFT,      // T
  0x18|SHIFT,      // U
  0x19|SHIFT,      // V
  0x1a|SHIFT,      // W
  0x1b|SHIFT,      // X
  0x1c|SHIFT,      // Y
  0x1d|SHIFT,      // Z
  0x2f,          // [
  0x31,          // bslash
  0x30,          // ]
  0x23|SHIFT,    // ^
  0x2d|SHIFT,    // _
  0x35,          // `
  0x04,          // a
  0x05,          // b
  0x06,          // c
  0x07,          // d
  0x08,          // e
  0x09,          // f
  0x0a,          // g
  0x0b,          // h
  0x0c,          // i
  0x0d,          // j
  0x0e,          // k
  0x0f,          // l
  0x10,          // m
  0x11,          // n
  0x12,          // o
  0x13,          // p
  0x14,          // q
  0x15,          // r
  0x16,          // s
  0x17,          // t
  0x18,          // u
  0x19,          // v
  0x1a,          // w
  0x1b,          // x
  0x1c,          // y
  0x1d,          // z
  0x2f|SHIFT,    // {
  0x31|SHIFT,    // |
  0x30|SHIFT,    // }
  0x35|SHIFT,    // ~
  0       // DEL
};


uint8_t USBPutChar(uint8_t c);

//
// Byte 0: Keyboard modifier bits (SHIFT, ALT, CTRL etc)
// Byte 1: reserved
// Byte 2-7: Up to six keyboard usage indexes representing the keys that are 
//           currently "pressed". 
//           Order is not important, a key is either pressed (present in the 
//           buffer) or not pressed.
//
// modifier (bit 0 is L CTRL, bit 1 is L SHIFT, bit 2 is L ALT, bit 3 is L GUI,
//           bit 4 is R CTRL, bit 5 is R SHIFT, bit 6 is R ALT, and bit 7 is R GUI)
//
#define USBHID_LCRTL 0x01
#define USBHID_LSHIFT 0x02
#define USBHID_LALT 0x04
#define USBHID_LGUI 0x08
#define USBHID_RCRTL 0x10
#define USBHID_RSHIFT 0x20
#define USBHID_RALT 0x40
#define USBHID_RGUI 0x80

size_t KeyboardUSBHID_::press(uint8_t k)
{
  if ((k >= 0xe0) && (k <= 0xe7)) {
    _keyReport.modifiers |= (1<<(k&0x0f));
    k = 0;
  }
  // Add k to the key report only if it's not already present
  // and if there is an empty slot.
  if (_keyReport.keys[0] != k && _keyReport.keys[1] != k && 
    _keyReport.keys[2] != k && _keyReport.keys[3] != k &&
    _keyReport.keys[4] != k && _keyReport.keys[5] != k) {

    int i;
    for (i=0; i<6; i++) {
      if (_keyReport.keys[i] == 0x00) {
        _keyReport.keys[i] = k;
        break;
      }
    }
    if (i == 6) {
      return 0;
    } 
  }
  sendReport(&_keyReport);
  return 1;
}

size_t KeyboardUSBHID_::release(uint8_t k) 
{
  if ((k >= 0xe0) && (k <= 0xe7)) {
    _keyReport.modifiers &= ~(1<<(k&0x0f));
    k = 0;
  }
  // Test the key report to see if k is present.  Clear it if it exists.
  // Check all positions in case the key is present more than once (which it shouldn't be)
  for (int i=0; i<6; i++) {
    if (0 != k && _keyReport.keys[i] == k) {
      _keyReport.keys[i] = 0x00;
    }
  }
  sendReport(&_keyReport);
  return 1;
}

void KeyboardUSBHID_::releaseAll(void)
{
  _keyReport.keys[0] = 0;
  _keyReport.keys[1] = 0; 
  _keyReport.keys[2] = 0;
  _keyReport.keys[3] = 0; 
  _keyReport.keys[4] = 0;
  _keyReport.keys[5] = 0; 
  _keyReport.modifiers = 0;
  sendReport(&_keyReport);
}

size_t KeyboardUSBHID_::write(uint8_t c)
{
  uint8_t p = press(c);  // Keydown
  release(c);            // Keyup
  return p;              // just return the result of press() since release() almost always returns 1
}

size_t KeyboardUSBHID_::write(const uint8_t *buffer, size_t size) {
  // unimplemented
  return size;
}

KeyboardUSBHID_ KeyboardUSBHID;

#endif



// ST keyboard reset pin
const int ST_KB_RESET = 4;

// Atari modifier key codes
const uint8_t ST_LEFT_CTRL = 0x1D;
const uint8_t ST_LEFT_SHIFT = 0x2A;
const uint8_t ST_LEFT_ALT = 0x38;
const uint8_t ST_RIGHT_SHIFT = 0x36;
const uint8_t ST_CAPS_LOCK = 0x3A;

// Keyboard auto-repeat
static uint8_t last_make;    // Last make char
static unsigned long last_make_time;  // Last make time (milliseconds)
int auto_repeat_delay = 500; // Keyboard auto-repeat delay (milliseconds)
int auto_repeat_rate = 25;   // Keyboard auto-repeat rate (milliseconds)

// Key scancodes
// Use ST scancode as index to find the corresponding USB scancode.
// https://www.usb.org/sites/default/files/documents/hut1_12v2.pdf
// Page 53 Chapter 10 Keypad pages
// Make-codes are single byte, with some exceptions.
// These are escaped with a 0xe0 byte, when this appear in this table a
// simple switch is used to look up the correct scancode.
// All break codes are the same as the scancodes, but are prefixed with 0xf0.
// The escaped keys are first escaped, then 0xf0, then scancode.
uint8_t scanCodes[] =
{
  0x00, // (Nothing)
  0x29, // Esc
  0x1e, // 1
  0x1f, // 2
  0x20, // 3
  0x21, // 4
  0x22, // 5
  0x23, // 6
  0x24, // 7
  0x25, // 8
  0x26, // 9
  0x27, // 0
  0x2d, // °
  0x2e, // -
  0x2a, // Backspace
  0x2b, // Tab
  0x14, // a
  0x1a, // z
  0x08, // e
  0x15, // r
  0x17, // t
  0x1c, // y
  0x18, // u
  0x0c, // i
  0x12, // o
  0x13, // p
  0x5B, // [
  0x5D, // ]
  0x28, // Enter
  0xe0, // Control (Left)
  0x04, // q
  0x16, // s
  0x07, // d
  0x09, // f
  0x0a, // g
  0x0b, // h
  0x0d, // j
  0x0e, // k
  0x0f, // l
  0x33, // m
  0x34, // %
  0x28, // `£ (Mapped Return)
  0xe1, // Lshift
  0x32, // #~
  0x1d, // w
  0x1b, // x
  0x06, // c
  0x19, // v
  0x05, // b
  0x11, // n
  0x10, // ,
  0x36, // ;
  0x37, // :
  0x38, // !
  0xe5, // Rshift
  0x00, // (Not used)
  0xe2, // Alternate
  0x2c, // Space
  0x39, // CapsLock
  0x3a, // F1
  0x3b, // F2
  0x3c, // F3
  0x3d, // F4
  0x3e, // F5
  0x3f, // F6
  0x40, // F7
  0x41, // F8
  0x42, // F9
  0x43, // F10
  0x00, // (Not used)
  0x00, // (Not used)
  0x4a, // Clr/Home
  0x52, // Up Arrow
  0x00, // (Not used)
  0x56, // N-
  0x50, // Left Arrow
  0x00, // (Not used)
  0x4f, // Right Arrow
  0x57, // N+
  0x00, // (Not used)
  0x51, // Down Arrow
  0x00, // (Not used)
  0x49, // Insert
  0x4c, // Delete
  0x00, // (Not used)
  0x00, // (Not used)
  0x00, // (Not used)
  0x00, // (Not used)
  0x00, // (Not used)
  0x00, // (Not used)
  0x00, // (Not used)
  0x00, // (Not used)
  0x00, // (Not used)
  0x00, // (Not used)
  0x00, // (Not used)
  0x00, // (Not used)
  0x31, // <> Keys
  0x45, // Undo (Mapped to F12)
  0x44, // Help (Mapped to F11)
  0x22, // N( Mapped to 5
  0x2d, // N) Mapped to °
  0x54, // N/
  0x55, // N*
  0x5f, // N7
  0x60, // N8
  0x61, // N9
  0x5c, // N4
  0x5d, // N5
  0x5e, // N6
  0x59, // N1
  0x5a, // N2
  0x5b, // N3
  0x62, // N0
  0x63, // N.
  0x28  // NEnter
};

void setup(void)
{
  // Initialize keyboard:
  KeyboardUSBHID.begin();
  // Open serial port from Atari keyboard
  Serial1.begin(7812);
#ifdef DEBUG
  // Open serial port to PC
  Serial.begin(9600);
#endif
  
  // Reset ST keyboard
  delay(200);
  reset_st_keyboard();
  delay(200);

  // Empty serial buffer before starting
  while(Serial1.available() > 0) Serial1.read();
}

void loop()
{
  // Process incoming Atari keypresses
  if (Serial1.available() > 0) process_keypress(Serial1.read());

  // Handle keyboard auto-repeat
  auto_repeat();
}

// Reset ST Keyboard
void reset_st_keyboard(void)
{
  Serial1.print(0x80);
  Serial1.print(1);
  pinMode(ST_KB_RESET, OUTPUT);
  digitalWrite(ST_KB_RESET, HIGH);
  delay(20);
  digitalWrite(ST_KB_RESET, LOW);
  delay(20);
  digitalWrite(ST_KB_RESET, HIGH);
}

// Process each keypress
void process_keypress(uint8_t key)
{
  // Keypress
  if (((key & 0x7f) > 0) && ((key & 0x7f) < 0x73))
  {
    // Break codes (other than modifiers) do not need to be sent 
    // to the PC as the Leonardo keyboard interface handles that
    if (key & 0x80) // Break
    {
      last_make = 0;
      last_make_time = 0;
      process_modifier(key);
    }
    else // Make
    {
      last_make = key;
      last_make_time = millis();
      convert_scancode(key);
    }
  }
}

// Convert from ST scancode to PC scancode
void convert_scancode(uint8_t key)
{
  uint8_t break_code = key & 0x80;
  uint8_t pc_code = scanCodes[key & 0x7f];
  
#ifdef DEBUG
    Serial.print("Atari scancode: ");
    Serial.println(key, DEC);
    Serial.print("PC scancode: ");
    Serial.println(pc_code, DEC);
    Serial.print("Break code: ");
    Serial.println(break_code, DEC);
#endif
  
  // Handle modifier key presses
  if (process_modifier(key)) return;

  KeyboardUSBHID.write(pc_code);
}

// Send code for escaped Atari keypresses
void send_escaped_key(uint8_t key)
{
  KeyboardUSBHID.press(key);
  delay(20);
  KeyboardUSBHID.release(key); 
}

// Process modifier keypresses
boolean process_modifier(uint8_t key)
{
  // Modifier key press  
  switch (key)
    {
      case ST_LEFT_CTRL:
      case ST_LEFT_SHIFT:
      case ST_LEFT_ALT:
      case ST_RIGHT_SHIFT:
      case ST_CAPS_LOCK:
        KeyboardUSBHID.press(key);
        return true;
    }

  // Modifier key release
  switch (key & 0x7f)
    {
      case ST_LEFT_CTRL:
      case ST_LEFT_SHIFT:
      case ST_LEFT_ALT:
      case ST_RIGHT_SHIFT:
      case ST_CAPS_LOCK:
        KeyboardUSBHID.release(key);
        return true;
    }
  
  return false;
}

// Keyboard auto repeat
void auto_repeat(void)
{
  static unsigned long last_repeat;
  static byte key_repeating;  // True if key being repeated
  
  // Don't want to repeat modifiers  
  switch (last_make)
  {
    case ST_LEFT_CTRL:
    case ST_LEFT_SHIFT:
    case ST_RIGHT_SHIFT:
    case ST_LEFT_ALT:
    case ST_CAPS_LOCK:
    case 0x00: // No key held down
      key_repeating = false;
      return;
  }

  // Delay to first repeat  
  if (!key_repeating && (millis() - last_make_time > auto_repeat_delay))
  {
    key_repeating = true;
    last_repeat = millis();
    return;
  }

  // Start repeating
  if (key_repeating && (millis() - last_repeat > auto_repeat_rate))
  {
    last_repeat = millis();
    convert_scancode(last_make);
  }
}
