#include <Arduino.h>
#line 1 "c:\\CA-Software\\Open Source Projects\\OpenBionics Hand\\FingerLib\\examples\\MultipleFingers\\MultipleFingers.ino"
#line 1 "c:\\CA-Software\\Open Source Projects\\OpenBionics Hand\\FingerLib\\examples\\MultipleFingers\\MultipleFingers.ino"
/*  Open Bionics - FingerLib Example - MultipleFingers
* Author - Olly McBride
* Date - October 2015
*
* This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License.
* To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/.
* 
* Website - http://www.openbionics.com/
* GitHub - https://github.com/Open-Bionics
*/

#include <FingerLib.h>

/*
 * WHAT IT DOES
 * Uses the FingerLib.h library to open and close all fingers and thumb every 2 seconds
 * Attaches the finger pins in the file 'Pins.ino'
 * 
 */
 
// uncomment one of the following to select the board
//#define ALMOND_BOARD
//#define CHESTNUT_BOARD
#define ADAFRUIT_FEATHER_M0

// number of controllable fingers (number of motors)
#if defined(ALMOND_BOARD)
  #define NUM_FINGERS 5
  #define MYSERIAL Serial
#elif defined(CHESTNUT_BOARD) || defined(ADAFRUIT_FEATHER_M0)
  #define NUM_FINGERS 4
  #ifdef ADAFRUIT_FEATHER_M0
    #define MYSERIAL Serial
  #else
    #define MYSERIAL SerialUSB
  #endif
#else
  #error 'No board selected'
#endif

// uncomment one of the following to select which hand is used
int handFlag = LEFT;
//int handFlag = RIGHT;

// initialise Finger class to array
Finger finger[NUM_FINGERS];

#line 48 "c:\\CA-Software\\Open Source Projects\\OpenBionics Hand\\FingerLib\\examples\\MultipleFingers\\MultipleFingers.ino"
void setup();
#line 65 "c:\\CA-Software\\Open Source Projects\\OpenBionics Hand\\FingerLib\\examples\\MultipleFingers\\MultipleFingers.ino"
void loop();
#line 83 "c:\\CA-Software\\Open Source Projects\\OpenBionics Hand\\FingerLib\\examples\\MultipleFingers\\MultipleFingers.ino"
void openHand(void);
#line 93 "c:\\CA-Software\\Open Source Projects\\OpenBionics Hand\\FingerLib\\examples\\MultipleFingers\\MultipleFingers.ino"
void closeHand(void);
#line 3 "c:\\CA-Software\\Open Source Projects\\OpenBionics Hand\\FingerLib\\examples\\MultipleFingers\\Pins.ino"
void pinAssignment(void);
#line 48 "c:\\CA-Software\\Open Source Projects\\OpenBionics Hand\\FingerLib\\examples\\MultipleFingers\\MultipleFingers.ino"
void setup()
{
  // MYSERIAL.print is used to allow compatability between both the Mega (Serial.print) 
  // and the Zero Native Port (SerialUSB.print), and is defined in FingerLib.h
  MYSERIAL.begin(38400);
  MYSERIAL.println("Started");

#ifdef ADAFRUIT_FEATHER_M0
  AFMS.begin();
#endif

  // configure all of the finger pins 
  pinAssignment();
  MYSERIAL.println("Pins configured");

}

void loop()
{
  // set all of the fingers to OPEN
  openHand();
  MYSERIAL.println("Opening");
  
  // give them time to OPEN
  delay(2000);
  
  // set all of the fingers to CLOSE
  closeHand();
  MYSERIAL.println("Closing");
  
  // give them time to CLOSE
  delay(2000);
}

// count through all the fingers and set them to open
void openHand(void)
{
  int i;
  for(i=0;i<NUM_FINGERS;i++)
  {
    finger[i].open();
  }
}

// count through all the fingers and set them to close
void closeHand(void)
{
  int i;
  for(i=0;i<NUM_FINGERS;i++)
  {
    finger[i].close();
  }
}
#line 1 "c:\\CA-Software\\Open Source Projects\\OpenBionics Hand\\FingerLib\\examples\\MultipleFingers\\Pins.ino"
// attach the pins to the finger instances

void pinAssignment(void)
{

  if (handFlag == RIGHT)
  {
#if defined(ALMOND_BOARD) || defined(ADAFRUIT_FEATHER_M0)
    finger[0].attach(-1, -1, A0);     // Right motor connector
    finger[1].attach(-1, -1, A1);
    finger[2].attach(-1, -1, A2);
    finger[3].attach(-1, -1, A3);
    finger[4].attach(-1, -1, A4);
#elif defined(CHESTNUT_BOARD)
    finger[0].attach(4, 8, A2, A8, false);    // attach the thumb
    finger[1].attach(1, 2, A0, A6, true);   // attach the index (finger is inverted)
    finger[2].attach(7, 5, A1, A9, true);   // attach the middle (finger is inverted)
    finger[3].attach(0, 9, A3, A7, true);   // attach the ring & pinky (fingers are inverted)
#else
    #error 'No board selected'
#endif
  }
  else if (handFlag == LEFT)
  {
#if defined(ALMOND_BOARD) || defined(ADAFRUIT_FEATHER_M0)
    finger[0].attach(-1, -1, A0);     // Left motor connector
    finger[1].attach(-1, -1, A1);
    finger[2].attach(-1, -1, A2);
    finger[3].attach(-1, -1, A3);
    finger[4].attach(-1, -1, A4);
#elif defined(CHESTNUT_BOARD)
    finger[0].attach(7, 5, A1, A9, false);    // attach the thumb
    finger[1].attach(0, 9, A3, A7, true);   // attach the index (finger is inverted)
    finger[2].attach(4, 8, A2, A8, true);   // attach the middle (finger is inverted)
    finger[3].attach(1, 2, A0, A6, true);   // attach the ring & pinky (fingers are inverted)
 #else
    #error 'No board selected'
#endif
  }
}

