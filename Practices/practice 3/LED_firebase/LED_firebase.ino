#include <ESP8266WiFi.h>                                               
#include <FirebaseArduino.h>                                        
 
#define FIREBASE_HOST "led1-8be56.firebaseio.com"              // the project name address from firebase id
#define FIREBASE_AUTH "Rk5p5IspTROCfFgkh66itwiKVhG0jqn5pgvEdDoa"   // the secret key generated from firebase
#define WIFI_SSID "berlin"                                          
#define WIFI_PASSWORD "imfj107&"                                  
 
String fireStatus = "";                                                     // led status received from firebase
int led1 = 12;
int led2 = 14;
int led3 = 4;
int led4 = 16;                                                              
void setup() 
{
  Serial.begin(9600);
  delay(1000);    
  pinMode(led1, OUTPUT);                 
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                               
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                  // connect to firebase
  Firebase.setString("LED_STATUS", "OFF");                       //send initial string of led status
}
 
void loop() 
{
  fireStatus = Firebase.getString("LED_STATUS");                                      // get ld status input from firebase
  if (fireStatus == "ON") 
  {                                                          // compare the input of led status received from firebase
    Serial.println("Led Turned ON");                                                        
    digitalWrite(led1, HIGH);                                                         // make external led ON
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  } 
  else if (fireStatus == "OFF") 
  {                                                  // compare the input of led status received from firebase
    Serial.println("Led Turned OFF");
    digitalWrite(led1, LOW);                                                         // make external led OFF
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else 
  {
    Serial.println("Command Error! Please send ON/OFF");
  }
}
