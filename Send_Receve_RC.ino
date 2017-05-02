void recieve(){
  
    if (mySwitch.available()) {
      Serial.print("4.. ");
    int value = mySwitch.getReceivedValue();
      Serial.println("6.. ");
    if (value == 0) {
      Serial.print("Unknown encoding");
    } else {
      Serial.print("Received ");
      Serial.print( mySwitch.getReceivedValue() );
      Serial.print(" / ");
      Serial.print( mySwitch.getReceivedBitlength() );
      Serial.print("bit ");
      Serial.print("Protocol: ");
      Serial.println( mySwitch.getReceivedProtocol() );
    }
    switch(value) 
      {
      case 4527377:                                   //D, On
        Keyboard.begin();
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_NUMPAD_8);
        Keyboard.releaseAll();
        lastpress = (millis() + 100);
        Serial.println("D, On, received");
        Keyboard.end();
      break; 
      case 4527380:                                   //D, Off
        Keyboard.begin();
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_NUMPAD_9);
        Keyboard.releaseAll();
        lastpress = (millis() + 100);
        Serial.println("D, Off, received");
        Keyboard.end();
      break;
   }
    mySwitch.resetAvailable();
  }
}


void transmit(int data){
//  mySwitch.disableReceive();
//  mySwitch.enableTransmit(9);
    switch(data){
      case(1):
        mySwitch.switchOn("01001", "10000");
        mySwitch.switchOn("01001", "01000");
        state1 = state2 = state3 = state4 = 1;
      break;
      case(2):
        !state1? mySwitch.switchOn("01001", "10000"):mySwitch.switchOff("01001", "10000");
        state1 = !state1;
        nextpress = millis()+100;
      break;
      case(3):
        !state2? mySwitch.switchOn("01001", "01000"):mySwitch.switchOff("01001", "01000");
        state2 = !state2;
        nextpress = millis()+100;
      break;
      case(4):
        mySwitch.switchOff("01001", "10000");
        mySwitch.switchOff("01001", "01000");
        mySwitch.switchOff("01001", "00100");
        mySwitch.switchOff("01001", "00010");
        mySwitch.switchOff("01001", "00001");
        state1 = state2 = state3 = state4 = 0;
      break;
    }
//  mySwitch.disableTransmit();
//  mySwitch.enableReceive(4);
}

