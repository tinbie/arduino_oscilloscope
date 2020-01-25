/*
 *  POOR MANS OSCILLOSCOPE - EXTENDED
 *  FOR ARDUINO UNO R3
 *  BY TINBIE
 *
 *  SPEED ON SERIAL MONITOR
 *  1 SEC FOR 650 VALUES BAUD230400
 *
 *  SPEED ON SERIAL PLOT
 *  1 SEC FOR 4.000 UINT16_T VALUES BAUD115200
 *  1 SEC FOR 5.200 UINT16_T VALUES BAUD230400
 *  1 SEC FOR 5.400 UINT8_T VALUES BAUD230400
 *
 *  Choose "#define SERIALPLOT 1" for
 *  plotting Diagram on Serial Plotter.
 *
 *  Choose #define SERIALPLOT 0" for
 *  print Values on Serial Monitor.
 *
 */


#define SERIALPLOT 1
#define BAUDRATE 230400
#define ANALOGPIN1 A0
#define ANALOGPIN2 A5


unsigned long mTimePrev = 0;


void setup(void) {
    /* set up pins and UART */
    pinMode(ANALOGPIN1, INPUT);
    pinMode(ANALOGPIN2, INPUT);
    Serial.begin(BAUDRATE);

#if! SERIALPLOT
    /* print table header */
    Serial.println("INITIALIZE...");
    Serial.println("++++++++++++++++++++++++++++++++");
    Serial.println("TIME [ms] | DELTA |  VAL1 | VAL2");
    Serial.println("--------------------------------");

#endif /* SERIALPLOT */
}


void loop(void) {
    /* read ADC */
    uint16_t value0 = analogRead(ANALOGPIN1);
    uint16_t value1 = analogRead(ANALOGPIN2);

#if SERIALPLOT
    /* print results */
    Serial.print(value0);
    Serial.print(" ");
    Serial.println(value1);

#else /* SERIALPLOT */
    /* set up time measurement */
    unsigned long timeNow = millis();
    unsigned long timeDelta = timeNow - mTimePrev;
    mTimePrev = timeNow;

    /* print time and results */
    Serial.print(timeNow);
    Serial.print(" ms     ");
    Serial.print(timeDelta);
    Serial.print(" ms     ");
    Serial.print(value0);
    Serial.print("     ");
    Serial.println(value1);

#endif /* SERIALPLOT */
}
