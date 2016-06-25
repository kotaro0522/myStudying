

int Distance = 0;
int d=1;
int flg=1;
char myCol[20];

void setup() {
  Serial.begin(9600);
  
  pinMode(8, OUTPUT);     
  pinMode(9, OUTPUT);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  while(flg){
    Serial.readBytes(myCol, 1);
    if(strcmp(myCol, "h") == 0){
      flg = 0;
    }
  }
}

void loop() {
  if (Serial.available()){
  Serial.readBytes(myCol, 1);
  Serial.println(Distance);
  }
  
  
if(0 <= Distance && Distance <= 5000){

  if(d==1){
  digitalWrite(9, HIGH);
  if(Distance <= 1000){
    delayMicroseconds(150); }
   else if(Distance <= 2500){
    delayMicroseconds(150); }
  else{delayMicroseconds(300); }
//  delayMicroseconds(360 - int(40*log((3000-Distance)*3)));  
  digitalWrite(9, LOW); 
  if(Distance <= 1000){
    delayMicroseconds(150); }
   else if(Distance <= 2500){
    delayMicroseconds(150); }
  else{ delayMicroseconds(300); }
//  delayMicroseconds(360 - int(0*log((3000-Distance)*3)));
  }

//if(d==1){
//  digitalWrite(9, HIGH);
//  delayMicroseconds(6 + atan(Distance-2000));
//  digitalWrite(9, LOW);
//  delayMicroseconds(6 + atan(Distance-2000));
//}
  
  
  if(d==-1){
  digitalWrite(9, HIGH);
  if(Distance <= 1000){
    delayMicroseconds(300); }
   else if(Distance <= 2500){
    delayMicroseconds(150); }
  else{delayMicroseconds(150); }
//  delayMicroseconds(360 - int(40*log((3000-Distance)*3)));  
  digitalWrite(9, LOW); 
  if(Distance <= 1000){
    delayMicroseconds(300); }
   else if(Distance <= 2500){
    delayMicroseconds(150); }
  else{ delayMicroseconds(150); }
//  delayMicroseconds(360 - int(0*log((3000-Distance)*3)));
  }
  
 Distance = Distance + d;
 
  }
  
  if(strcmp(myCol, "g") == 0){
    digitalWrite(8, HIGH);
    d = -1;
     if(Distance > 5000){
      Distance = 5000;
    }
  }
  else if(strcmp(myCol, "h") == 0){
    digitalWrite(8, LOW);
    d = 1;
     if(Distance < 0){
      Distance = 0;
    }
  }
}
  
  


