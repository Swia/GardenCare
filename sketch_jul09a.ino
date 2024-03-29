#define BLYNK_PRINT Serial // Comment this out to disable prints and save space 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <TimeLib.h>

TimeLib tt;
char auth[] = "34c8a75373404b31aed2be71cab0727"; //insert here your token generated by Blynk
SimpleTimer mytimer; // allocate a name (mytimer) to the timer

int relay1 = 5;//D1
int relay2 = 4;//D2
int relay3 = 14;//D5
int relay4 = 12;//D6

int relayVButton1 = 0;
int relayVButton2 = 0;
int relayVButton3 = 0;
int relayVButton4 = 0;
int scenario1 = 0;

boolean relayState1 = 1;
boolean relayState2 = 1;
boolean relayState3 = 1;
boolean relayState4 = 1;

WidgetLED led1(24); //virtual led1
WidgetLED led2(25); //virtual led2
WidgetLED led3(26); //virtual led3
WidgetLED led4(27); //virtual led4

void setup() {
  Serial.begin(115200); // See the connection status in Serial Monitor
  Blynk.begin(auth, "iPhone", "11223344");
  mytimer.setInterval(2000L, somefunction);


  /*while (Blynk.connect() == false) {
    buttonState1 = digitalRead (button1);
    if (buttonState1 > 0){
    relayState1 = !relayState1;
    }
    digitalWrite(relay1, relayState1);
    delay(500);
    buttonState2 = digitalRead (button2);
    if (buttonState2 > 0){
    relayState2 = !relayState2;
    }
    digitalWrite(relay2, relayState2);
    delay(500);
    }
  */

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);

}
void somefunction()
{
  Serial.print ( tt.tmTime() );

  if ( relayVButton1 > 0) {
    relayState1 = !relayState1;
  }
  digitalWrite(relay1, relayState1);

  if ( relayVButton2 > 0) {
    relayState2 = !relayState2;
  }
  digitalWrite(relay2, relayState2);

  if ( relayVButton3 > 0) {
    relayState3 = !relayState3;
  }
  digitalWrite(relay3, relayState3);

  if ( relayVButton4 > 0) {
    relayState4 = !relayState4;
  }
  digitalWrite(relay4, relayState4);
  //delay(500);
  if ( scenario1 > 0) {
    digitalWrite(relay2, 0);
    digitalWrite(relay2, 1);
    delay(500);
    
  }


  //----------------button virtual led1-------------—
  byte inp = digitalRead(relay1);

  if (inp == HIGH) {
    led1.on();
  }
  else 
    led1.off();
  
  //----------------button virtual led2-------------—
  byte inp2 = digitalRead(relay2);

  if (inp2 == HIGH) {
    led2.on();
  }
  else 
    led2.off();
  

  //----------------button virtual led3-------------—
  byte inp3 = digitalRead(relay3);

  if (inp == HIGH) {
    led3.on();
  }
  else 
    led3.off();
  
  //----------------button virtual led4-------------—
  byte inp4 = digitalRead(relay4);

  if (inp == HIGH) {
    led4.on();
  }
  else
    led4.off();
}
  BLYNK_WRITE(V28)
  {
    // Get the state of the VButton
    relayVButton1 = param.asInt();
  }

  BLYNK_WRITE(V29)
  {
    // Get the state of the VButton
    relayVButton2 = param.asInt();
  }

  BLYNK_WRITE(V30)
  {
    // Get the state of the VButton
    relayVButton3 = param.asInt();
  }

  BLYNK_WRITE(V31)
  {
    // Get the state of the VButton
    relayVButton4 = param.asInt();
  }
  BLYNK_WRITE(V23)
  {
    scenario1 = param.asInt(); 
  }

  void loop() {
    Blynk.run();
    mytimer.run(); // call the simple timer routine
  }
