int pot=A2;
void setup()
{
  // Setting pins as OUTPUTS and INPUTS, INPUTS are the pins connected to the switch.
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, INPUT_PULLUP);
  pinMode(10,INPUT_PULLUP);
  pinMode(11,INPUT_PULLUP);
  pinMode(12,INPUT_PULLUP);
}
// Function to move forward
void forward(int a,int b,int c,int d){
  analogWrite(a,b);
  analogWrite(c,d);
}
// Function to move right
void right(int a,int b,int c){
  analogWrite(a,b);
  digitalWrite(c,LOW);
}
// Function to move left
void left(int a,int b,int c){
  analogWrite(a,b);
  digitalWrite(c,LOW);
}
// Function to move backwards
void backwards(int a,int b,int c,int d){
  analogWrite(a,b);
  analogWrite(c,d);
}
// Function to not move
void noMove(int a,int b){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
}

void loop(){
int motorF1=4;
int motorB1=5;
int motorB2=6;
int motorF2=7;
int potVal=analogRead(pot)/4;
  
if (digitalRead(12)==LOW){
  forward(motorF1,potVal,motorF2,potVal);
  noMove(motorB1,motorB2);
}else if (digitalRead(11)==LOW){
  right(motorF1,potVal,motorF2);
  noMove(motorB1,motorB2);
}else if (digitalRead(10)==LOW){
  left(motorF2,potVal,motorF1);
  noMove(motorB1,motorB2);
}else if (digitalRead(9)==LOW){
  backwards(motorB1,potVal,motorB2,potVal);
  noMove(motorF1,motorF2);
}else{
  noMove(motorF1,motorF2);
  noMove(motorB1,motorB2);
	}
}