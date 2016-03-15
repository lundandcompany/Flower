
#include <SoftwareSerial.h>
#include "mpr121.h"
#include <Wire.h>

SoftwareSerial quadra(18, 2);


const int m1 = 8;// push
const int m2 = 9; // full in

const int sw3 = 10;//12
const int sw2 = 10;//11
const int sw1 = 10;
const int sw0 = 7;
const int soundin = 3;
const int rec = 6;




const int top = 13;
const int di = 11;

int x = 0;
int y = 0;
int z = 0;
int b = 0;
int d = 0;


int t0 = 0;
int t1 = 0;
int t2 = 0;

int timer = 0;

int val = 0;
int cent = 0;
int potPin = 0;

int zero = 0;
int sound = 0;
int music = 0;
int record = 0;
int die = 0;
int feed = 0;

long randNumber;

void setup() {
  
    pinMode(m1, OUTPUT);
    pinMode(m2, OUTPUT);
    pinMode(sw1, INPUT_PULLUP);
    pinMode(sw2, INPUT_PULLUP);
    pinMode(sw3, INPUT_PULLUP); 
    pinMode(sw0, INPUT); 
    pinMode(top, INPUT);
    pinMode(di, INPUT_PULLUP);
    pinMode(soundin, INPUT);
    pinMode(rec, INPUT);

    randomSeed(9);
    
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    
    Serial.begin(9600);
    quadra.begin(2400);
    quadra.write(byte(252));
    quadra.write(byte(62));
  Serial.begin(9600);
  Wire.begin();
   
   
  back(1500); 
  hungry();

}



void loop() {
zero = digitalRead(sw0);   //digi bird input
sound = digitalRead(soundin); //sound chip buzy input
music = digitalRead(top); //////DOES NOT WORK CONNECTED!!!!!!!!!! 
record = digitalRead(rec);
die = digitalRead(di);
feed = digitalRead(sw1);

    x++;



  pause(4);

  if (x== 1800){
    x = 0;
    play();
    
  }


//  if (x== 9000){
//    d = 0;
//    play();
//    
//  }


if (feed == LOW) {
        x = 0;
      d = 0;
  playSound(6);
talking1();
}


if (die == LOW){
        x = 0;
      d = 0;

wilt();
switch1();
revive();


  
}






  
  if ( (music == HIGH)&& (sound == HIGH) ){
      x = 0;
      d = 0;
      randNumber = random(1,10);
   //   Serial.println(randNumber);
      choseDance(randNumber);

  }









}


void choseDance(int c){



if (c == 1){
  dancea();
}

if (c == 2){
  danceb();
}
if (c == 3){
  dancec();
}
if (c == 4){
  danced();
}
if (c == 5){
  dancee();
}
if (c == 6) {
  dancef();
}
if (c == 7){
  danceg();
}
if (c == 8){
  danceh();
}
if (c == 9){
  dancei();
}
if (c == 10){
  dancej();
}




return;





  
}


void play(){
y++ ;
Serial.println("PLAY");


if (y == 1){
  letsDance();
   
}


if (y == 2){

singDance();
}


if (y == 3){
  

    letsPlay();
}


if (y == 4){
 

 letsDance();

}



if (y == 5){
  y =0;
  hungry();
}









return;

  
}

void dead(){
wilt();
switch1();
revive();

  
}

void hungry(){
b = 0;
playSound(5);
talking2();
pause(300);
talking1();








return;

}


//    while(digitalRead(sw1)){
//    b++;
//    Serial.println(b);
//    pause(3);
//    if (b == 900){
//      hungry();
//    }
//  }


void letsDance(){
  playSound(7);
talking2();
}


void singDance(){

    playSound(9);
talking1();
pause(200);
talking2();
  
}


void letsPlay(){
playSound(8);
talking2();
  
}




void wilt(){

playSound(0);
fwds(500);
 fwd(22000);
  return;
}

void revive(){
playSound(1);
back(26000);
return;

  
}


void talking1(){

dance(200);
pause(100);
dance(100);
return;
  
}

void talking2(){

dance(150);
dance(200);
pause(100);
dance(300);
dance(100);
dance(150);
  return;
}



void dance(int x){


    back(x);
    fwd(x - 15);
    

  return;
}

void switch13(){
 
    while(!digitalRead(top)){
   Serial.println("         *");
  }

  pause(10);
  Serial.println("Done");
  return;
}



void dancea(){
 // Serial.println("AAA");
  dance(100);
  return;
}

void danceb(){
 //   Serial.println("BBB");
  dance(300);
  pause(300);
    return;
}

void dancec(){
//    Serial.println("CCC");
  dance(220);
    dance(110);
      return;
}

void danced(){
 //   Serial.println("DDD");
  dance(80);
  pause(50);
    dance(80);
     pause(50);
      dance(80);
       pause(50);
        return;
}

void dancee(){
//    Serial.println("EEE");
  dance(400);
    return;
}

void dancef(){
 //   Serial.println("FFF");
  dance(300);
    return;
}

void danceg(){
 //   Serial.println("GGG");
  dance(260);
  pause(120);
    pause(160);
    return;
}

void danceh(){
//    Serial.println("HHH");
  dance(600);
    return;
}

void dancei(){
//    Serial.println("III");
  dance(170);
  dance(80);
    return;
}

void dancej(){
 //   Serial.println("JJJ");
  dance(300);
    dance(200);
      dance(100);
        return;
}







//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo   

void switch3(){
    while(digitalRead(sw3)){
    pause(10);
  }
  return;
}


void switch1(){
  
    while(digitalRead(sw1)){
    
      



  }

  pause(200);
  return;
}





void pause (int p){
 delay (p);
}


void pauseBack (){
  
  int i;
   for (i = 0; i = 20; i++){
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    delay (2);
    digitalWrite(m1, LOW);
   delay(16); 
   }
   return;
}


void back (int b){
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    delay (b);
    digitalWrite(m1, LOW); 
}

void backpause (int b){
  int i;
  for (i = 0; i < b; i++){
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    delay (3);
    digitalWrite(m1, LOW); 
    digitalWrite(m2, HIGH);
    delay (1);
  }
  
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
  return;
}


void backSlow (int b){
  int i;

    for (i = 0; i < b ; i++){
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    delay (4);
    digitalWrite(m1, LOW); 
    digitalWrite(m2, HIGH);
    delay (2);
  }

      digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
  return;
}


void fwdSlow (int a){
  int i;

    for (i = 0; i < a ; i++){
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    delay (4);
    digitalWrite(m1, HIGH); 
    digitalWrite(m2, LOW);
    delay (2);
  }
  
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
  return;
}

void fwd (int f){
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    delay (f);
    digitalWrite(m2, LOW); 
    return;
}

void fwds (int f){
    int i;
  for (i = 0; i < f; i++){
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    delay (5);
    digitalWrite(m2, LOW);
    delay (3 );    
  }
    digitalWrite(m2, LOW); 
    return;
}


void goback(){
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    return;
}

void gofwd(){
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    return;
}

void stoped (){
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    return;
}

void playSound(int sound){
  quadra.write(byte(sound));
  pause (300);
  return;
}



void volume(){
    quadra.write(byte(252));
    quadra.write(byte(37));
}

void soundStop(){
    quadra.write(byte(246));
  
}


void soundSequence(int f){
  int i;
    for (i = 0; i < f; i++){
      Serial.println(i);
  playSound(i);
  pause (3500);
    }
  
  
}
