int cflPin = PB4;
int buzzerPin = PB1;
int flamePin = PB0;
int smokePin = PB3;
int wifiPin = PB6;
int error =0;
int i;
int messageSent = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(cflPin,OUTPUT);
pinMode(buzzerPin,OUTPUT);
pinMode(flamePin,INPUT);
pinMode(smokePin,INPUT);
pinMode(wifiPin,OUTPUT);
}

void loop() {
while(digitalRead(smokePin)==0)
{
 
 if(messageSent==0)
 {
   digitalWrite(wifiPin,HIGH);
  messageSent = 1;
 }
  
  digitalWrite(cflPin,LOW);
  digitalWrite(buzzerPin,HIGH);
  delay(100);
  digitalWrite(buzzerPin,LOW);
  delay(100);
  digitalWrite(buzzerPin,HIGH);
  delay(100);
  digitalWrite(buzzerPin,LOW);
 if(digitalRead(flamePin)==0)
 {
  break;
 }
  delay(2000);
}
while(digitalRead(flamePin)==0)
{
  if(messageSent ==0)
  {
    digitalWrite(wifiPin,HIGH);
    messageSent =1;
  }
  digitalWrite(buzzerPin,HIGH);
  digitalWrite(cflPin,LOW);
  delay(2000);
  
}
while(digitalRead(smokePin)==0 && digitalRead(flamePin)==0)
{
    if(messageSent ==0)
  {
    digitalWrite(wifiPin,HIGH);
    messageSent =1;
  }
  digitalWrite(buzzerPin,HIGH);
  digitalWrite(cflPin,LOW);
  delay(2000);
}
/*
 while(digitalRead(smokePin)==0&&digitalRead(flamePin)==0)
 {
    digitalWrite(wifiPin,HIGH);
  digitalWrite(cflPin,LOW);
   for(i=700;i<800;i++){
    tone(buzzerPin,i);
    delay(15);
   }
  for(i=800;i>700;i--){
   tone(buzzerPin,i);
   delay(15);
   }
   delay(5000);
 }

*/
 digitalWrite(cflPin,HIGH);
 digitalWrite(buzzerPin,LOW);


 
}
