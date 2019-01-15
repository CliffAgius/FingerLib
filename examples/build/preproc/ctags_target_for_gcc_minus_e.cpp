# 1 "c:\\CA-Software\\Open Source Projects\\OpenBionics Hand\\FingerLib\\examples\\MultipleFingers\\MultipleFingers.ino"
# 1 "c:\\CA-Software\\Open Source Projects\\OpenBionics Hand\\FingerLib\\examples\\MultipleFingers\\MultipleFingers.ino"
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

# 13 "c:\\CA-Software\\Open Source Projects\\OpenBionics Hand\\FingerLib\\examples\\MultipleFingers\\MultipleFingers.ino" 2

/*
 * WHAT IT DOES
 * Uses the FingerLib.h library to open and close all fingers and thumb every 2 seconds
 * Attaches the finger pins in the file 'Pins.ino'
 * 
 */

// uncomment one of the following to select the board
//#define ALMOND_BOARD
//#define CHESTNUT_BOARD


// number of controllable fingers (number of motors)
# 41 "c:\\CA-Software\\Open Source Projects\\OpenBionics Hand\\FingerLib\\examples\\MultipleFingers\\MultipleFingers.ino"
// uncomment one of the following to select which hand is used
int handFlag = 2 /* hand type*/;
//int handFlag = RIGHT;

// initialise Finger class to array
Finger finger[4];

void setup()
{
  // MYSERIAL.print is used to allow compatability between both the Mega (Serial.print) 
  // and the Zero Native Port (SerialUSB.print), and is defined in FingerLib.h
  Serial.begin(38400);
  Serial.println("Started");


  AFMS.begin();


  // configure all of the finger pins 
  pinAssignment();
  Serial.println("Pins configured");

}

void loop()
{
  // set all of the fingers to OPEN
  openHand();
  Serial.println("Opening");

  // give them time to OPEN
  delay(2000);

  // set all of the fingers to CLOSE
  closeHand();
  Serial.println("Closing");

  // give them time to CLOSE
  delay(2000);
}

// count through all the fingers and set them to open
void openHand(void)
{
  int i;
  for(i=0;i<4;i++)
  {
    finger[i].open();
  }
}

// count through all the fingers and set them to close
void closeHand(void)
{
  int i;
  for(i=0;i<4;i++)
  {
    finger[i].close();
  }
}
# 1 "c:\\CA-Software\\Open Source Projects\\OpenBionics Hand\\FingerLib\\examples\\MultipleFingers\\Pins.ino"
// attach the pins to the finger instances

void pinAssignment(void)
{

  if (handFlag == 1 /* hand type*/)
  {

    finger[0].attach(-1, -1, A0); // Right motor connector
    finger[1].attach(-1, -1, A1);
    finger[2].attach(-1, -1, A2);
    finger[3].attach(-1, -1, A3);
    finger[4].attach(-1, -1, A4);
# 22 "c:\\CA-Software\\Open Source Projects\\OpenBionics Hand\\FingerLib\\examples\\MultipleFingers\\Pins.ino"
  }
  else if (handFlag == 2 /* hand type*/)
  {

    finger[0].attach(-1, -1, A0); // Left motor connector
    finger[1].attach(-1, -1, A1);
    finger[2].attach(-1, -1, A2);
    finger[3].attach(-1, -1, A3);
    finger[4].attach(-1, -1, A4);
# 39 "c:\\CA-Software\\Open Source Projects\\OpenBionics Hand\\FingerLib\\examples\\MultipleFingers\\Pins.ino"
  }
}
