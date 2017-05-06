#define KEY_NUMPAD_MULTIPLY 0xDD
#define KEY_NUMPAD_MINUS    0xDE
#define KEY_NUMPAD_PLUS     0xDF
#define KEY_NUMPAD_ENTER    0xE0
#define KEY_NUMPAD_1        0xE1
#define KEY_NUMPAD_2        0xE2
#define KEY_NUMPAD_3        0xE3
#define KEY_NUMPAD_4        0xE4
#define KEY_NUMPAD_5        0xE5
#define KEY_NUMPAD_6        0xE6
#define KEY_NUMPAD_7        0xE7
#define KEY_NUMPAD_8        0xE8
#define KEY_NUMPAD_9        0xE9
#define KEY_NUMPAD_0        0xEA
#define KEY_NUMPAD_DEL      0xEB

#include <Wire.h>
#include <Keyboard.h>
#include <Mouse.h>

#include <RCSwitch.h>
RCSwitch mySendSwitch = RCSwitch();
RCSwitch mySwitch = RCSwitch();

char Buttons[] = {'1', '2', '3', 'A', '4', '5', '6', 'B', '7', '8', '9', 'C', '*', '0', '#', 'D'};
char pressedButton;               //contains the Caracter of the last pressed button
boolean pressed;                  //went true if a button is pressed
unsigned long lastmillis = 0;              //counter ageinst bouncing and rapid repeating
unsigned long millisDelay = 0;             //not used variable(?)
unsigned long lastpress = 0;

int dataIn = 4;                   //pins used for the LED Matrix
int load = 5;
int clock = 6;

char Mode = 'E';                  //LED begin Modus

boolean state1 = 0;               //the states of the lamps
boolean state2 = 0;
boolean state3 = 0;
boolean state4 = 0;

byte max7219_reg_noop        = 0x00;
byte max7219_reg_digit0      = 0x01;
byte max7219_reg_digit1      = 0x02;
byte max7219_reg_digit2      = 0x03;
byte max7219_reg_digit3      = 0x04;
byte max7219_reg_digit4      = 0x05;
byte max7219_reg_digit5      = 0x06;
byte max7219_reg_digit6      = 0x07;
byte max7219_reg_digit7      = 0x08;
byte max7219_reg_decodeMode  = 0x09;
byte max7219_reg_intensity   = 0x0a;
byte max7219_reg_scanLimit   = 0x0b;
byte max7219_reg_shutdown    = 0x0c;
byte max7219_reg_displayTest = 0x0f;

int maxInUse = 1;

void putByte(byte data) {
  byte i = 8;
  byte mask;
  while(i > 0) {
    mask = 0x01 << (i - 1);      // get bitmask
    digitalWrite( clock, LOW);   // tick
    if (data & mask){            // choose bit
      digitalWrite(dataIn, HIGH);// send 1
    }else{
      digitalWrite(dataIn, LOW); // send 0
    }
    digitalWrite(clock, HIGH);   // tock
    --i;                         // move to lesser bit
  }
}

void maxAll (byte reg, byte col) {    // initialize  all  MAX7219's in the system
  int c = 0;
  digitalWrite(load, LOW);  // begin    
  for ( c =1; c<= maxInUse; c++) {
  putByte(reg);  // specify register
  putByte(col);//((data & 0x01) * 256) + data >> 1); // put data
    }
  digitalWrite(load, LOW);
  digitalWrite(load,HIGH);
}

void maxSingle( byte reg, byte col) {    
//maxSingle is the "easy"  function to use for a single max7219
 
  digitalWrite(load, LOW);       // begin    
  putByte(reg);                  // specify register
  putByte(col);//((data & 0x01) * 256) + data >> 1); // put data  
  digitalWrite(load, LOW);       // and load da stuff
  digitalWrite(load,HIGH);
}

void setup() {
  pinMode(dataIn, OUTPUT);        //the LED Matrix pinMode-setup
  pinMode(clock,  OUTPUT);        //
  pinMode(load,   OUTPUT);        //


  
  Serial.begin(9600);
  Wire.begin();                   //for the expander that controlls the buttons
  pinMode(9, INPUT_PULLUP);       // the switch pin joystick
  Mouse.begin();                  //Mouse functions
  pinMode(7, INPUT);
  mySwitch.enableReceive(4);      // Receiver on interrupt 4 => that is pin #7
  mySendSwitch.enableTransmit(9);

  maxAll(max7219_reg_scanLimit, 0x07);   //Matrix setup
  maxAll(max7219_reg_decodeMode, 0x00);  // using an led matrix (not digits)
  maxAll(max7219_reg_shutdown, 0x01);    // not in shutdown mode
  maxAll(max7219_reg_displayTest, 0x00); // no display test
   for (int e=1; e<=8; e++) {    // empty registers, turn all LEDs off
    maxAll(e,0);
  }
  maxAll(max7219_reg_intensity, 0x0f & 0x0f);    
}

void loop() {
  recieve();                      //execute what to do if something is receaved
  getbutton();                    //test if something is pressed
  setMode();                      //sets the Mode ('A', 'B', 'C', 'D')
  buttonMacros();                 //execute what to do when a button is pressed
  }
 
