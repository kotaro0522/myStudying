int rLed = 13;
int a;
char myCol[20];
void setup(){
  Serial.begin (9600);
  pinMode(rLed, OUTPUT);
  digitalWrite(rLed, LOW);
}
void loop(){
  /*  a = Serial.read();
  if(a==10){
    digitalWrite(rLed,HIGH);
  }
  */
  Serial.readBytes(myCol,1);
  if(strcmp(myCol,"r") == 0){
    digitalWrite(rLed, HIGH);
  }
  else{
    digitalWrite(rLed, LOW);
    }
  }


