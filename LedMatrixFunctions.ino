void ledCoding(){
  ((millis()-lastmillis)<60000)?animateCoding(true):animateCoding(false);
}
void animateCoding(boolean animate){

   if(millis()%1000<500 || !animate){
   maxSingle(1,B00000000);
   maxSingle(2,B10000000);                       
   maxSingle(3,B01000000);                       
   maxSingle(4,B00100000);                   
   maxSingle(5,B01000000);                   
   maxSingle(6,B10000000);                   
   maxSingle(7,B00011111);                   
   maxSingle(8,B00000000);                   
 } else {
   maxSingle(1,B00000000);                   
   maxSingle(2,B10000000);                   
   maxSingle(3,B01000000);                   
   maxSingle(4,B00100000);                   
   maxSingle(5,B01000000);                   
   maxSingle(6,B10000000);                   
   maxSingle(7,B00000000);                   
   maxSingle(8,B00000000);                   
  
 }
}

void ledChar(char CharButton){
  switch(CharButton){
    case('C'):
      maxSingle(1,B00000000);                      
      maxSingle(2,B00111000);                      
      maxSingle(3,B01000000);                     
      maxSingle(4,B01000000);                     
      maxSingle(5,B01000000);                     
      maxSingle(6,B01000000);                     
      maxSingle(7,B01000000);                     
      maxSingle(8,B00111000); 
    break;
    case('D'):
      maxSingle(1,B00000000);                     
      maxSingle(2,B01110000);                     
      maxSingle(3,B01001000);                      
      maxSingle(4,B01001000);                       
      maxSingle(5,B01001000);                    
      maxSingle(6,B01001000);                    
      maxSingle(7,B01001000);                     
      maxSingle(8,B01110000); 
    break;
  }
}

void animateTxt(){
  ((millis()-lastmillis)<10000)?cursorBlink(true):cursorBlink(false);
}

void cursorBlink(boolean animate){  
      if(millis()%600<300 || !animate){
      maxSingle(1,B00000000);                     
      maxSingle(2,B11111000);                     
      maxSingle(3,B00100000);                      
      maxSingle(4,B00100000);                       
      maxSingle(5,B00100000);                    
      maxSingle(6,B00100000);                    
      maxSingle(7,B00101000);                     
      maxSingle(8,B00000000); 
      } else {
      maxSingle(1,B00000000);                     
      maxSingle(2,B11111010);                     
      maxSingle(3,B00100010);                      
      maxSingle(4,B00100010);                       
      maxSingle(5,B00100010);                    
      maxSingle(6,B00100010);                    
      maxSingle(7,B00101010);                     
      maxSingle(8,B00000000); 
      }

}

void musicLight(){
    ((millis()-lastmillis)<10000)?animateMusic(true):animateMusic(false);
}

void animateMusic(boolean animate){
  if(millis()%2000<500 && animate){
      maxSingle(1,B00000000);                     
      maxSingle(2,B00011110);                     
      maxSingle(3,B01111010);                      
      maxSingle(4,B01000010);                       
      maxSingle(5,B01000011);                    
      maxSingle(6,B01100011);                    
      maxSingle(7,B01100000);                     
      maxSingle(8,B00000000); 
      } else if (millis()%2000>=500 && millis()%2000<1000 && animate)  {
      maxSingle(1,B00000000);                     
      maxSingle(2,B01111110);                     
      maxSingle(3,B01000010);                      
      maxSingle(4,B01000010);                       
      maxSingle(5,B01100011);                    
      maxSingle(6,B01100011);                    
      maxSingle(7,B00000000);                     
      maxSingle(8,B00000000);
      } else if (millis()%2000>=1000 && millis()%2000<1500 && animate) {
      maxSingle(1,B00000000);                     
      maxSingle(2,B01111000);                     
      maxSingle(3,B01011110);                      
      maxSingle(4,B01000010);                       
      maxSingle(5,B01100010);                    
      maxSingle(6,B01100011);                    
      maxSingle(7,B00000011);                     
      maxSingle(8,B00000000);
      } else if (animate) {
      maxSingle(1,B00000000);                     
      maxSingle(2,B00000000);                     
      maxSingle(3,B01111110);                      
      maxSingle(4,B01000010);                       
      maxSingle(5,B01000010);                    
      maxSingle(6,B01100011);                    
      maxSingle(7,B01100011);                     
      maxSingle(8,B00000000);
      } else {
      maxSingle(1,B00000000);                     
      maxSingle(2,B00111100);                     
      maxSingle(3,B01000010);                      
      maxSingle(4,B01000010);                       
      maxSingle(5,B10000001);                    
      maxSingle(6,B11000011);                    
      maxSingle(7,B11000011);                     
      maxSingle(8,B01000010);
      }
}


void ledHouse(){
      maxSingle(1,B00011000);                     
      maxSingle(2,B00111100);                     
      maxSingle(3,B01100110);                      
      maxSingle(4,B11111111);                       
      maxSingle(5,B01111110);                    
      maxSingle(6,B01111110);                    
      maxSingle(7,B01101110);                     
      maxSingle(8,B01101110); 
}

void Smiley(){
      maxSingle(1,B00000000);                     
      maxSingle(2,B10010001);                     
      maxSingle(3,B10010001);                      
      maxSingle(4,B10010101);                       
      maxSingle(5,B11110001);                    
      maxSingle(6,B10010101);                     
      maxSingle(7,B10010100);                     
      maxSingle(8,B10010101);
}





