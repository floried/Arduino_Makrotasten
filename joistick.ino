#define KEY_NUMPAD_DIVIDE   0xDC
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

const int switchPin = 9;      // switch to turn on and off mouse control
const int mouseButton = 9;    // input pin for the mouse pushButton
const int xAxis = A2;         // joystick X axis
const int yAxis = A3;         // joystick Y axis

int range = 150;               // output range of X or Y movement
int responseDelay = 3;        // response delay of the mouse, in ms
float threshold = range / 128;    // resting threshold
int center = range / 2;       // resting position value

boolean mouseIsActive = true;    // whether or not to control the mouse
int lastSwitchState = LOW;        // previous switch state

void joystickMouse(){
  /*
    // read the switch:
  int switchState = digitalRead(switchPin);
  // if it's changed and it's high, toggle the mouse state:
  if (switchState != lastSwitchState) {
    if (switchState == HIGH) {
      mouseIsActive = !mouseIsActive;
    }

  }
  // save switch state for next comparison:
  lastSwitchState = switchState;
  */

  // read and scale the two axes:
  int xReading = readAxis(A2);
  int yReading = readAxis(A3)/2;
  
  // if the mouse control state is active, move the mouse:
  if (mouseIsActive) {
    Mouse.move(xReading, -yReading, 0);
  } 

  // read the mouse button and click or not click:
  // if the mouse button is pressed:
  if (digitalRead(mouseButton) == LOW) {
    // if the mouse is not pressed, press it:
    if (!Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.press(MOUSE_LEFT);
      
    }
  }

  // else the mouse button is not pressed:
  else {
    // if the mouse is pressed, release it:
    if (Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.release(MOUSE_LEFT);
    }
  }

  delay(responseDelay);
} //end joystickMouse
int readAxis(int thisAxis) {
  // read the analog input:
  int reading = analogRead(thisAxis);

  // map the reading from the analog input range to the output range:
  float distance = map(reading, 0, 1023, -range, range);

  // if the output reading is outside from the
  // rest position threshold,  use it:
  //float distance = reading - center;
  distance /= 50;
  distance = pow(distance,2)*(distance/abs(distance));
/*
  if (abs(distance) < 0.125) {
    distance = 0;
  }
*/
  // return the distance for this axis:
  return distance;
}

unsigned long xDelayTime, yDelayTime;


void joystickNavigation(){
  int xValue = map(analogRead(A2),3,1020,-2,2);
  int yValue = map(analogRead(A3),0,1020,-3,3); if(yValue<0)yValue++; if(yValue>0)yValue--;
  
if(xDelayTime < millis()){
  switch(xValue){
    case -2:
      Keyboard.begin();
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ARROW);
      Keyboard.releaseAll();
      Keyboard.end();
      xDelayTime = millis() + 100;
    break;
    case -1:
      Keyboard.begin();
      Keyboard.press(KEY_LEFT_ARROW);
      Keyboard.releaseAll();
      Keyboard.end();
      xDelayTime = millis() + 200;
    break;
    case 0:
      xDelayTime = millis();
    break;
    case 1:
      Keyboard.begin();
      Keyboard.press(KEY_RIGHT_ARROW);
      Keyboard.releaseAll();
      Keyboard.end();
      xDelayTime = millis() + 200;
    break;
    case 2:
      Keyboard.begin();
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_RIGHT_ARROW);
      Keyboard.releaseAll();
      Keyboard.end();
      xDelayTime = millis() + 100;
    break;
    
  } //end switch
} // end if xDelayTime

if(yDelayTime < millis()){
  switch(yValue){
    case -2:
      Mouse.begin();
      Mouse.move(0,0,-1);
      yDelayTime = millis() + 100;
    break;
    case -1:
      Keyboard.begin();
      Keyboard.press(KEY_DOWN_ARROW);
      Keyboard.releaseAll();
      Keyboard.end();
      yDelayTime = millis() + 200;
    break;
    case 0:
      yDelayTime = millis();
    break;
    case 1:
      Keyboard.begin();
      Keyboard.press(KEY_UP_ARROW);
      Keyboard.releaseAll();
      Keyboard.end();
      yDelayTime = millis() + 200;
    break;
    case 2:
      Mouse.move(0,0,1);
      yDelayTime = millis() + 100;
    break;
    
  } //end switch
} // end if yDelayTime

} //end joystickNavagion

void joystickMusic(){

  int xValue = map(analogRead(A2),3,1020,-1,1);
  int yValue = map(analogRead(A3),0,1020,-2,2); if(yValue<0)yValue++; if(yValue>0)yValue--;

if(xDelayTime < millis()){  
switch(xValue){
  case(-1):
    Serial.println("x -1");
    Keyboard.begin();
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_NUMPAD_DIVIDE);
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.releaseAll();
    xDelayTime = millis() + 300;
    Keyboard.end();
  break;
  case(0):
    xDelayTime = millis()+500;
    if(digitalRead(9)==LOW){
      Keyboard.begin();
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press(KEY_NUMPAD_8);
      Keyboard.release(KEY_LEFT_GUI);
      Keyboard.releaseAll();
      xDelayTime = millis() + 2000;
      Keyboard.end();
    }
  break;
  case(1):
    Serial.println("x  1");
    Keyboard.begin();
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_NUMPAD_9);
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.releaseAll();
    xDelayTime = millis() + 2000;
    Keyboard.end();
  break;
}
}
if(yDelayTime < millis()){
switch(yValue){
  case(-1):
    Serial.println("y -1");
    Keyboard.begin();
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_PAGE_DOWN);
    Keyboard.release(KEY_LEFT_ALT);
    Keyboard.releaseAll();
    yDelayTime = millis() + 50;
    Keyboard.end();
  break;
  case(0):
    yDelayTime = millis();
  break;
  case(1):
    Serial.println("y  1");
    Keyboard.begin();
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_PAGE_UP);
    Keyboard.release(KEY_LEFT_ALT);
    Keyboard.releaseAll();
    yDelayTime = millis() + 50;
    Keyboard.end();
  break;
}
  
}// end joystickMusic()
}

void joystickMoveWindow(){
  long buttondelay;
  boolean stickstate;
  boolean laststickstate = false;
  int xValue = map(analogRead(A2),3,1020,-1,1);
  int yValue = map(analogRead(A3),0,1020,-2,2); if(yValue<0)yValue++; if(yValue>0)yValue--;


if(xDelayTime < millis()){  
  switch(xValue){
  case(-1):
    Serial.println("x -1");
    Keyboard.begin();
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_LEFT_ARROW);
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.releaseAll();
    Keyboard.press(KEY_ESC);
    Keyboard.release(KEY_ESC);
    xDelayTime = millis() + 100;
    Keyboard.end();
  break;
  case(0):
    if(digitalRead(9)==LOW){
      buttondelay = millis()+3000;
      Keyboard.begin();
      Keyboard.press(KEY_LEFT_ALT);
        while(buttondelay > millis()){
          stickstate = digitalRead(9);
            if(!stickstate && laststickstate){
              Keyboard.press(KEY_TAB);
              Keyboard.release(KEY_TAB);
              buttondelay = millis()+2000;
            }
          laststickstate = stickstate;
        }
      Keyboard.release(KEY_LEFT_ALT);
      Keyboard.releaseAll();
      xDelayTime = millis() + 500;
      Keyboard.end();
    }
  break;
  case(1):
    Serial.println("x  1");
    Keyboard.begin();
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_RIGHT_ARROW);
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.releaseAll();
    Keyboard.press(KEY_ESC);
    Keyboard.release(KEY_ESC);
    xDelayTime = millis() + 100;
    Keyboard.end();
  break;
}
}

if(yDelayTime < millis()){
switch(yValue){
  case(-1):
    Serial.println("y -1");
    Keyboard.begin();
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_DOWN_ARROW);
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.releaseAll();
    Keyboard.press(KEY_ESC);
    Keyboard.release(KEY_ESC);
    yDelayTime = millis() + 50;
    Keyboard.end();
  break;
  case(0):
    yDelayTime = millis();
  break;
  case(1):
    Serial.println("y  1");
    Keyboard.begin();
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_UP_ARROW);
    Keyboard.release(KEY_LEFT_GUI);
    Keyboard.releaseAll();
    Keyboard.press(KEY_ESC);
    Keyboard.release(KEY_ESC);
    yDelayTime = millis() + 50;
    Keyboard.end();
  break;
}
}
} //end joystickMoveWindow


