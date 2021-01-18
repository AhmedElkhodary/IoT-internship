#include <ESP8266WiFi.h>
#include <WiFi.h>                                               
#include <FirebaseArduino.h>                                        

#define WIFI_SSID              "***********"                                          // SSID name                                  
#define WIFI_PASSWORD  "***********"                                          // password  
#define FIREBASE_HOST   "***********"                                          // the project name address from firebase id
#define FIREBASE_AUTH   "***********"     		                    // the secret key generated from firebase

/*************************************************/
const int sw0 = 36;
const int sw1 = 39;
const int sw2 = 34;
const int sw3 = 35;
const int sw4 = 32;
const int sw5 = 33;
const int sw6 = 25;
const int sw7 = 26;
const int sw8 = 27;
const int sw9 = 13;


const int led0 = 23;
const int led1 = 22;
const int led2 = 21;
const int led3 = 19;
const int led4 = 18;
const int led5 = 05;
const int led6 = 17;
const int led7 = 16;
const int led8 = 04;
const int led9 = 14;

//const int indLed1 = 15;
//const int indLed2 = 12;
//const int indLed3 = 02;
/*************************************************/


void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  Serial.print("Connecting");
  while(WiFi.status() != WL_CONNECTED){
      Serial.print(".");
      delay(500);
    }
  Serial.println();
  Serial.println("\nConnected to the WiFi network");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  pinMode(sw0, INPUT);
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  pinMode(sw4, INPUT);
  pinMode(sw5, INPUT);
  pinMode(sw6, INPUT);
  pinMode(sw7, INPUT);
  pinMode(sw8, INPUT);
  pinMode(sw9, INPUT);
  
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT); 
     
  //pinMode(indLed0, OUTPUT);
  //pinMode(indLed1, OUTPUT);
  //pinMode(indLed2, OUTPUT);
}

/****************************************************************/

int sw0_status_old = digitalRead(sw0);
int sw1_status_old = digitalRead(sw1);
int sw2_status_old = digitalRead(sw2);
int sw3_status_old = digitalRead(sw3);
int sw4_status_old = digitalRead(sw4);
int sw5_status_old = digitalRead(sw5);
int sw6_status_old = digitalRead(sw6);
int sw7_status_old = digitalRead(sw7);
int sw8_status_old = digitalRead(sw8);
int sw9_status_old = digitalRead(sw9);




void loop() {
  
  int led0_status = Firebase.getInt("led0");
  int led1_status = Firebase.getInt("led1");
  int led2_status = Firebase.getInt("led2");
  int led3_status = Firebase.getInt("led3");
  int led4_status = Firebase.getInt("led4");
  int led5_status = Firebase.getInt("led5");
  int led6_status = Firebase.getInt("led6");
  int led7_status = Firebase.getInt("led7");
  int led8_status = Firebase.getInt("led8");
  int led9_status = Firebase.getInt("led9");
  
  int sw0_status = digitalRead(sw0);
  int sw1_status = digitalRead(sw1);
  int sw2_status = digitalRead(sw2);
  int sw3_status = digitalRead(sw3);
  int sw4_status = digitalRead(sw4);
  int sw5_status = digitalRead(sw5);
  int sw6_status = digitalRead(sw6);
  int sw7_status = digitalRead(sw7);
  int sw8_status = digitalRead(sw8);
  int sw9_status = digitalRead(sw9);
  
  if (sw0_status != sw0_status_old){
      Firebase.setInt("led0", !led0_status);
      sw0_status_old = sw0_status;
    }

  if (sw1_status != sw1_status_old){
      Firebase.setInt("led1", !led1_status);
      sw1_status_old = sw1_status;
    }

   
  if (sw2_status != sw2_status_old){
      Firebase.setInt("led2", !led2_status);
      sw2_status_old = sw2_status;
    }

  if (sw3_status != sw3_status_old){
      Firebase.setInt("led3", !led3_status);
      sw3_status_old = sw3_status;
    }
    
  if (sw4_status != sw4_status_old){
      Firebase.setInt("led4", !led4_status);
      sw4_status_old = sw4_status;
    }

  if (sw5_status != sw5_status_old){
      Firebase.setInt("led5", !led5_status);
      sw5_status_old = sw5_status;
    }
    
  if (sw6_status != sw6_status_old){
      Firebase.setInt("led6", !led6_status);
      sw6_status_old = sw6_status;
    }

  if (sw7_status != sw7_status_old){
      Firebase.setInt("led7", !led7_status);
      sw7_status_old = sw7_status;
    } 
  if (sw8_status != sw8_status_old){
      Firebase.setInt("led8", !led8_status);
      sw8_status_old = sw8_status;
    }
   if (sw9_status != sw9_status_old){
      Firebase.setInt("led9", !led9_status);
      sw9_status_old = sw9_status;
    }   



  
  if (led0_status == 1){
      digitalWrite(led0, HIGH);
    }
  else{
      digitalWrite(led0, LOW);
    }
     
  if (led1_status == 1){
      digitalWrite(led1, HIGH);
    }
  else{
      digitalWrite(led1, LOW);
    }
    
  if (led2_status == 1){
      digitalWrite(led2, HIGH);
    }
  else{
      digitalWrite(led2, LOW);
    }
     
  if (led3_status == 1){
      digitalWrite(led3, HIGH);
    }
  else{
      digitalWrite(led3, LOW);
    }
  
  if (led4_status == 1){
      digitalWrite(led4, HIGH);
    }
  else{
      digitalWrite(led4, LOW);
    }
     
  if (led5_status == 1){
      digitalWrite(led5, HIGH);
    }
  else{
      digitalWrite(led5, LOW);
    }
    
  if (led6_status == 1){
      digitalWrite(led6, HIGH);
    }
  else{
      digitalWrite(led6, LOW);
    }
     
  if (led7_status == 1){
      digitalWrite(led7, HIGH);
    }
  else{
      digitalWrite(led7, LOW);
    }
    
   if (led8_status == 1){
      digitalWrite(led8, HIGH);
    }
  else{
      digitalWrite(led8, LOW);
    }
     
  if (led9_status == 1){
      digitalWrite(led9, HIGH);
    }
  else{
      digitalWrite(led9, LOW);
    }
    
  Serial.println(led0_status);
  Serial.println(led1_status);
 
  Serial.println();
  
    
}
