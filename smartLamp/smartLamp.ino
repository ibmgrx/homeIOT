
#include <ESP8266WiFi.h>                                /* Enable the use of wifi module. Make sure you downloaded and installed the ESP8266 library*/
#include <BlynkSimpleEsp8266.h>                         /* Code for talking with Blynk*/
char auth[] = "387u6fCtFAU_86cNMQPXmApsj7Z1NeBm";       // Put in the Auth Token for the project from Blynk. You should receive it in your email.
char ssid[] = "IBRAHIM";                    // Key in your wifi name. You can check with your smart phone for your wifi name
char pass[] = "manggarai";                               // Key in your wifi password.
int LED = 2, relay = 4;

WidgetLED led1(V1);

BLYNK_WRITE(V3) {
  int pinValue = param.asInt(); // Assigning incoming value from pin V3 to a variable
  if (pinValue == 1) {
    Serial.println("1");
    led1.off();
    digitalWrite(LED, HIGH); // Turn LED on.
    digitalWrite(relay, HIGH); // Turn LED on.
  }
  else {
    Serial.println("2");
    led1.on();
    digitalWrite(LED, LOW); // Turn LED off.
    digitalWrite(relay, LOW); // Turn LED off.
  }
}

void setup()
{
  
  /* 0 - General */
  
  Serial.begin(115200);                                           /* Initiate the Serial Monitor function */
  pinMode(LED,OUTPUT);                                            /* Declare the Output Pin D4 (GPIO 2) as an output pin for LED Light*/
  pinMode(relay,OUTPUT);   

  /* 1- Blynk Server and Wifi Connection */
  
  Blynk.begin(auth,ssid,pass, "blynk-cloud.com", 8080);                                  /* Initiate the Blynk server login for the specific project*/
  while (Blynk.connect() == false ) {}                          /* If the Blynk Server not yet connected to nodeMCU, keep waiting here */

}


void loop()
{
  
  /* 1- Blynk Server and Wifi Connection */
  
  Blynk.run();                                                                    /* allow the communication between Blynk server and Node MCU*/ 
 

}
