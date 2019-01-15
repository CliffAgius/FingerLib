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
