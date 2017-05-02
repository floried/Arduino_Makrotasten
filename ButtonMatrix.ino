//tab for all stuff with the Button-Matrix

int extenderwrite = 0x38;
int extenderread = 0x38;
unsigned long nextpress;


void getbutton(){
int pressCounter;
  
  for(int i=0;i<=3;i++){
  Wire.beginTransmission(extenderwrite); //Öffnen der Verbindung
  Wire.write(1<<i);
  Wire.endTransmission();
  Wire.requestFrom(extenderread,1,true);
  if(!Wire.read() && nextpress < millis()){
    for(int j=4;j<=7;j++){
      Wire.beginTransmission(extenderwrite); //Öffnen der Verbindung
      Wire.write(1<<j);
      Wire.endTransmission();
      Wire.requestFrom(extenderread, 1,1);
      if(!Wire.read()){
        pressedButton = Buttons[(i*4)+(j-4)];
        nextpress = millis() + 300;
        pressCounter++;
      } //end if col
    } //end for col (j)
  }//end if row
}   //end for row (i)
 (pressCounter)? pressed=true : pressed=false;
pressCounter = 0;

} //end getbutton()

void setMode(){
      if(pressedButton == 'A') Mode='A';
      if(pressedButton == 'B') Mode='B';
      if(pressedButton == 'C') Mode='C';
      if(pressedButton == 'D') Mode='D';
      if(pressed) lastmillis = millis();
} //end setMode


void buttonMacros(){
  switch(Mode){
    case 'A':
      ledCoding();
      joystickMoveWindow();
      caseA();
    break;
    case 'B':
      animateTxt();
      joystickNavigation();
    break;
    case 'C':
      musicLight();
      joystickMusic();
      caseC();
    break;
    case 'D':
      textloop(" LED ");
    break;
    case 'E':
      Smiley();
      joystickMouse();
    break;

    
  }  //end switch
} //end buttonMacros()

void caseA(){
  if(pressed){
  switch(pressedButton){
    case('A'):
      Serial.println("x  1");
      Keyboard.begin();
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press(KEY_NUMPAD_MULTIPLY);
      Keyboard.release(KEY_LEFT_GUI);
      Keyboard.releaseAll();
      Keyboard.end();
    break;
    case('1'):
      Keyboard.begin();
      Keyboard.press(KEY_LEFT_CTRL);
      delay(20);
      Keyboard.press('s');
      delay(20);
      Keyboard.releaseAll();
      Keyboard.end();
    break;
    case('2'):
      Keyboard.begin();
      Keyboard.press(KEY_LEFT_CTRL);
      delay(20);
      Keyboard.press('r');
      delay(20);
      Keyboard.releaseAll();
      Keyboard.end();
    break;
    case('3'):
      Keyboard.begin();
      Keyboard.press(KEY_LEFT_CTRL);
      delay(20);
      Keyboard.press('u');
      delay(20);
      Keyboard.releaseAll();
      Keyboard.end();
    break;
    case('4'):
      Keyboard.begin();
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.release(KEY_LEFT_ALT);
      delay(10);
      for(int i=0;i<3;i++){
        Keyboard.press(KEY_RIGHT_ARROW);
        Keyboard.release(KEY_RIGHT_ARROW);
      }
      for(int i=0;i<9;i++){
        Keyboard.press(KEY_DOWN_ARROW);
        Keyboard.release(KEY_DOWN_ARROW);
      }
      Keyboard.press(KEY_RIGHT_ARROW);
      delay(20);
      Keyboard.releaseAll();
      Keyboard.end();
    break;
    case('5'):
      Keyboard.begin();
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      delay(20);
      Keyboard.press('m');
      delay(20);
      Keyboard.releaseAll();
      Keyboard.end();
    break;
    case('6'):
      Keyboard.begin();
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.release(KEY_LEFT_ALT);
      delay(10);
      for(int i=0;i<3;i++){
        Keyboard.press(KEY_RIGHT_ARROW);
        Keyboard.release(KEY_RIGHT_ARROW);
      }
      for(int i=0;i<7;i++){
        Keyboard.press(KEY_DOWN_ARROW);
        Keyboard.release(KEY_DOWN_ARROW);
      }
      Keyboard.press(KEY_RIGHT_ARROW);
      delay(20);
      Keyboard.releaseAll();
      Keyboard.end();
    break;
    case('7'):
      Keyboard.begin();
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.release(KEY_LEFT_GUI);
      delay(10);
      Keyboard.print("Opera");
      delay(10);
      Keyboard.press(KEY_RETURN);
      Keyboard.release(KEY_RETURN);
      delay(1000);
      Keyboard.print("Arduino ");
      Keyboard.releaseAll();
      Keyboard.end();
    break;
    
} //end switch pressedButton
} //end if pressed
} //end caseB


void caseC(){
    if(pressed){
  switch(pressedButton){
    case('1'):
      transmit(1);
    break;
    case('2'):
      transmit(2);
    break;
    case('3'):
      transmit(3);
    break;
    case('4'):
      transmit(4);
    break;
} //end switch pressedButton
} //end if pressed
} //end caseC


