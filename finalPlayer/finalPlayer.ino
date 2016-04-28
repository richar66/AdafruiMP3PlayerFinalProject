

// include SPI, MP3 and SD libraries
#include <SPI.h>
#include <Adafruit_VS1053.h>
#include <SD.h>


// These are the pins used for the music maker shield
#define SHIELD_RESET  -1      // VS1053 reset pin (unused!)
#define SHIELD_CS     7      // VS1053 chip select pin (output)
#define SHIELD_DCS    6      // VS1053 Data/command select pin (output)

// These are common pins between breakout and shield
#define CARDCS 4     // Card chip select pin
// DREQ should be an Int pin, see http://arduino.cc/en/Reference/attachInterrupt
#define DREQ 3       // VS1053 Data request, ideally an Interrupt pin

Adafruit_VS1053_FilePlayer musicPlayer = 
  Adafruit_VS1053_FilePlayer(SHIELD_RESET, SHIELD_CS, SHIELD_DCS, DREQ, CARDCS);

const int VolumePin = A1;
int sensorValue = 0;        // value read from the pot
int outputValue = 0; 
int count = 0; 


void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit VS1053 Simple Test");

  if (! musicPlayer.begin()) { // initialise the music player
     Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
     while (1);
  }
  Serial.println(F("VS1053 found"));
  
  SD.begin(CARDCS);    // initialise the SD card
  
  // Set volume for left, right channels. lower numbers == louder volume!
  musicPlayer.setVolume(30,30);

 musicPlayer.GPIO_pinMode(7, INPUT);
  // If DREQ is on an interrupt pin (on uno, #2 or #3) we can do background
  // audio playing
    musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT);  // DREQ int
    musicPlayer.GPIO_pinMode(7, INPUT);
    musicPlayer.GPIO_pinMode(6, INPUT);
    musicPlayer.GPIO_pinMode(5, INPUT);
    musicPlayer.GPIO_pinMode(4, INPUT);

}

void loop(){

     if(count < 0){ 
      Serial.println(F("Error! Play Next Song"));
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count++;
              musicPlayer.stopPlaying(); }
       delay(200);
       }
    if(count == 0){
  Serial.println(F("Playing track: Thickfreakness"));
  musicPlayer.startPlayingFile("track001.mp3");
  
   while(! musicPlayer.stopped()) {

      if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
            if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
           else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
      if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Stop
               Serial.println("Random");
               count = random(0,11);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count++;
              musicPlayer.stopPlaying(); }
              
     if(musicPlayer.GPIO_digitalRead(4) ==1){ // if button is pressed Previous Song
               Serial.println("Previous Song");
               count--;
              musicPlayer.stopPlaying(); }

          sensorValue = analogRead(VolumePin);
             // map it to the range of the analog out:
           outputValue = map(sensorValue, 0, 1023, 0, 100);
             // change the analog out value:
         musicPlayer.setVolume(outputValue,outputValue);

    delay (150);
              
       }
    } 
     if(count == 1){
         Serial.println(F("Playing track: Hard Row"));
         musicPlayer.startPlayingFile("track002.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Stop
               Serial.println("Random");
               count = random(0,11);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count++;
              musicPlayer.stopPlaying(); }
              
     if(musicPlayer.GPIO_digitalRead(4) ==1){ // if button is pressed Previous Song
               Serial.println("Previous Song");
               count--;
              musicPlayer.stopPlaying(); }

            sensorValue = analogRead(VolumePin);
             // map it to the range of the analog out:
             outputValue = map(sensorValue, 0, 1023, 0, 100);
             // change the analog out value:
            musicPlayer.setVolume(outputValue,outputValue);

      delay (150);}
              
      }
  
    if(count == 2){
  Serial.println(F("Playing track: Set You Free"));
  musicPlayer.startPlayingFile("track003.mp3");
  
   while(! musicPlayer.stopped()) {

      if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
            if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
           else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
      if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Stop
              Serial.println("Random");
               count = random(0,11);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count++;
              musicPlayer.stopPlaying(); }
              
     if(musicPlayer.GPIO_digitalRead(4) ==1){ // if button is pressed Previous Song
               Serial.println("Previous Song");
               count--;
              musicPlayer.stopPlaying(); }

          sensorValue = analogRead(VolumePin);
             // map it to the range of the analog out:
           outputValue = map(sensorValue, 0, 1023, 0, 100);
             // change the analog out value:
         musicPlayer.setVolume(outputValue,outputValue);

    delay (150);
              
       }
    } 
     if(count == 3){
        Serial.println(F("Playing track: Midnight In Her Eyes"));
         musicPlayer.startPlayingFile("track004.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Stop
               Serial.println("Random");
               count = random(0,11);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count++;
              musicPlayer.stopPlaying(); }
              
     if(musicPlayer.GPIO_digitalRead(4) ==1){ // if button is pressed Previous Song
               Serial.println("Previous Song");
               count--;
              musicPlayer.stopPlaying(); }

            sensorValue = analogRead(VolumePin);
             // map it to the range of the analog out:
             outputValue = map(sensorValue, 0, 1023, 0, 100);
             // change the analog out value:
            musicPlayer.setVolume(outputValue,outputValue);

      delay (150);}
              
      }
          if(count == 4){
  Serial.println(F("Playing track: Have Love Will Travel"));
  musicPlayer.startPlayingFile("track005.mp3");
  
   while(! musicPlayer.stopped()) {

      if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
            if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
           else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
      if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Stop
               Serial.println("Random");
               count = random(0,11);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count++;
              musicPlayer.stopPlaying(); }
              
     if(musicPlayer.GPIO_digitalRead(4) ==1){ // if button is pressed Previous Song
               Serial.println("Previous Song");
               count--;
              musicPlayer.stopPlaying(); }

          sensorValue = analogRead(VolumePin);
             // map it to the range of the analog out:
           outputValue = map(sensorValue, 0, 1023, 0, 100);
             // change the analog out value:
         musicPlayer.setVolume(outputValue,outputValue);

    delay (150);
              
       }
    } 
     if(count == 5){
        Serial.println(F("Playing track: Hurt Like Mine"));
         musicPlayer.startPlayingFile("track006.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Stop
               Serial.println("Random");
               count = random(0,11);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count++;
              musicPlayer.stopPlaying(); }
              
     if(musicPlayer.GPIO_digitalRead(4) ==1){ // if button is pressed Previous Song
               Serial.println("Previous Song");
               count--;
              musicPlayer.stopPlaying(); }

            sensorValue = analogRead(VolumePin);
             // map it to the range of the analog out:
             outputValue = map(sensorValue, 0, 1023, 0, 100);
             // change the analog out value:
            musicPlayer.setVolume(outputValue,outputValue);

      delay (150);}
              
      }
  
    if(count == 6){
  Serial.println(F("Playing track: Everywhere I Go"));
  musicPlayer.startPlayingFile("track007.mp3");
  
   while(! musicPlayer.stopped()) {

      if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
            if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
           else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
      if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Stop
               Serial.println("Random");
               count = random(0,11);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count++;
              musicPlayer.stopPlaying(); }
              
     if(musicPlayer.GPIO_digitalRead(4) ==1){ // if button is pressed Previous Song
               Serial.println("Previous Song");
               count--;
              musicPlayer.stopPlaying(); }

          sensorValue = analogRead(VolumePin);
             // map it to the range of the analog out:
           outputValue = map(sensorValue, 0, 1023, 0, 100);
             // change the analog out value:
         musicPlayer.setVolume(outputValue,outputValue);

    delay (150);
              
       }
    } 
     if(count == 7){
        Serial.println(F("Playing track: No Trust"));
         musicPlayer.startPlayingFile("track008.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Stop
               Serial.println("Random");
               count = random(0,11);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count++;
              musicPlayer.stopPlaying(); }
              
     if(musicPlayer.GPIO_digitalRead(4) ==1){ // if button is pressed Previous Song
               Serial.println("Previous Song");
               count--;
              musicPlayer.stopPlaying(); }

            sensorValue = analogRead(VolumePin);
             // map it to the range of the analog out:
             outputValue = map(sensorValue, 0, 1023, 0, 100);
             // change the analog out value:
            musicPlayer.setVolume(outputValue,outputValue);

      delay (150);}
              
      }

      
     if(count == 8){
        Serial.println(F("Playing track: If You See Me"));
         musicPlayer.startPlayingFile("track009.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Stop
               Serial.println("Random");
               count = random(0,11);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count++;
              musicPlayer.stopPlaying(); }
              
     if(musicPlayer.GPIO_digitalRead(4) ==1){ // if button is pressed Previous Song
               Serial.println("Previous Song");
               count--;
              musicPlayer.stopPlaying(); }

            sensorValue = analogRead(VolumePin);
             // map it to the range of the analog out:
             outputValue = map(sensorValue, 0, 1023, 0, 100);
             // change the analog out value:
            musicPlayer.setVolume(outputValue,outputValue);

      delay (150);}
              
      }
  
    if(count == 9){
  Serial.println(F("Playing track: Hold Me In Your Arms"));
  musicPlayer.startPlayingFile("BlckKeys010.mp3");
  
   while(! musicPlayer.stopped()) {

      if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
            if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
           else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
      if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Stop
               Serial.println("Random");
               count = random(0,11);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count++;
              musicPlayer.stopPlaying(); }
              
     if(musicPlayer.GPIO_digitalRead(4) ==1){ // if button is pressed Previous Song
               Serial.println("Previous Song");
               count--;
              musicPlayer.stopPlaying(); }

          sensorValue = analogRead(VolumePin);
             // map it to the range of the analog out:
           outputValue = map(sensorValue, 0, 1023, 0, 100);
             // change the analog out value:
         musicPlayer.setVolume(outputValue,outputValue);

    delay (150);
              
       }
    } 
     if(count == 10){
        Serial.println(F("Playing track: I Cry Alone"));
         musicPlayer.startPlayingFile("track011.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Stop
               Serial.println("Random");
               count = random(0,11);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count = 0;
              musicPlayer.stopPlaying(); }
              
     if(musicPlayer.GPIO_digitalRead(4) ==1){ // if button is pressed Previous Song
               Serial.println("Previous Song");
               count--;
              musicPlayer.stopPlaying(); }

            sensorValue = analogRead(VolumePin);
             // map it to the range of the analog out:
             outputValue = map(sensorValue, 0, 1023, 0, 100);
             // change the analog out value:
            musicPlayer.setVolume(outputValue,outputValue);

      delay (150);}
              
      }
  }



