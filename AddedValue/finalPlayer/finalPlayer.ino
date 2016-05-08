

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
int totSongs = 24;          //total number of songs +1


void setup() {
  Serial.begin(9600);
  Serial.println("Music Maker On");

  if (! musicPlayer.begin()) { // initialise the music player
     Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
     while (1);
  }
  Serial.println(F("Ready"));
  
  SD.begin(CARDCS);    // initialise the SD card
  
  // Set volume for left, right channels. lower numbers == louder volume!
  musicPlayer.setVolume(30,30);
musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT); 

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
      if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
              musicPlayer.stopPlaying(); }
       delay(150);
       }
    if(count == 0){
  Serial.println(F("Playing track: Thickfreakness"));
  musicPlayer.startPlayingFile("blkys001.mp3");
  
   while(! musicPlayer.stopped()) {

      if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
            if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
           else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
     if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
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
            // Serial.println(outputValue);
         musicPlayer.setVolume(outputValue,outputValue);

    delay (150);
              
       }
    } 
     if(count == 1){
         Serial.println(F("Playing track: Hard Row"));
         musicPlayer.startPlayingFile("blkys002.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
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
  musicPlayer.startPlayingFile("blkys003.mp3");
  
   while(! musicPlayer.stopped()) {

      if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
            if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
           else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
    if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
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
         musicPlayer.startPlayingFile("blkys004.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
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
  musicPlayer.startPlayingFile("blkys005.mp3");
  
   while(! musicPlayer.stopped()) {

      if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
            if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
           else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
        if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
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
         musicPlayer.startPlayingFile("blkys006.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
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
  musicPlayer.startPlayingFile("blkys007.mp3");
  
   while(! musicPlayer.stopped()) {

      if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
            if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
           else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
      if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
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
         musicPlayer.startPlayingFile("blkys008.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
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
         musicPlayer.startPlayingFile("blkys009.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
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
  musicPlayer.startPlayingFile("blkys010.mp3");
  
   while(! musicPlayer.stopped()) {

      if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
            if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
           else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
      if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
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
         musicPlayer.startPlayingFile("blkys011.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count = count++;
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
    if(count == 11){
        Serial.println(F("Playing track: The View from the Afternoon"));
         musicPlayer.startPlayingFile("amonk012.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count = count++;
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
      
    if(count == 12){
        Serial.println(F("Playing track: I Bet You Look Good on the Dancefloor"));
         musicPlayer.startPlayingFile("amonk013.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count = count++;
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
      
    if(count == 13){
        Serial.println(F("Playing track: Fake Tales of San Francisco"));
         musicPlayer.startPlayingFile("amonk014.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
          if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count = count++;
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
          if(count == 14){
        Serial.println(F("Playing track: Dancing Shoes"));
         musicPlayer.startPlayingFile("amonk015.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count = count++;
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
      
    if(count == 15){
        Serial.println(F("Playing track: You Probably Couldn't See for.."));
         musicPlayer.startPlayingFile("amonk016.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count =count++;
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
      
    if(count == 16){
        Serial.println(F("Playing track: Still Take You Home"));
         musicPlayer.startPlayingFile("amonk017.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count = count++;
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
      if(count == 17){
        Serial.println(F("Playing track: Riot Van"));
         musicPlayer.startPlayingFile("amonk018.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count = 18;
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
          if(count == 18){
        Serial.println(F("Playing track: Red Light Indicates Doors Are Secured"));
         musicPlayer.startPlayingFile("amonk019.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count = count++;
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
      
    if(count == 19){
        Serial.println(F("Playing track: Mardy Bum"));
         musicPlayer.startPlayingFile("amonk020.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count = count++;
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
      
    if(count == 20){
        Serial.println(F("Playing track: Perhaps Vampires Is a Bit Strong But.."));
         musicPlayer.startPlayingFile("amonk021.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count = count++;
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
                if(count == 21){
        Serial.println(F("Playing track: When the Sun Goes Down"));
         musicPlayer.startPlayingFile("amonk022.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count = count++;
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
      
    if(count == 22){
        Serial.println(F("Playing track: From the Ritz to the Rubble"));
         musicPlayer.startPlayingFile("amonk023.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
              musicPlayer.stopPlaying(); }
              
      if(musicPlayer.GPIO_digitalRead(5) ==1){ // if button is pressed Next Song
               Serial.println("Next Song");
               count = count++;
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
      
    if(count == 23){
        Serial.println(F("Playing track: A Certain Romance"));
         musicPlayer.startPlayingFile("amonk024.mp3");
  
        while(! musicPlayer.stopped()) {

           if(musicPlayer.GPIO_digitalRead(6) ==1){ // if button is pressed pause/unpause
              if (! musicPlayer.paused()) {
               Serial.println("Paused");
               musicPlayer.pausePlaying(true);}
             else { 
               Serial.println("Resumed");
              musicPlayer.pausePlaying(false); }
              }
           if(musicPlayer.GPIO_digitalRead(7) ==1){ // if button is pressed Random Song
               Serial.println("Random");
               count = random(0,totSongs);
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



