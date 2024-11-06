//Declare variables
int motorL1 = 5;  // INPUT 1 - IZQUIERDA
int motorL2 = 6;  // INPUT 2 - IZQUIERDA
int motorR1 = 7; // INPUT 3 - DERECHA 
int motorR2 = 8;  // INPUT 4 - DERECHA

int vel = 50;
char dataFromApp = 'S';

void setup()
{
  Serial.begin(9600);

  //Variables de salida
  pinMode(motorL1, OUTPUT);  
  pinMode(motorL2, OUTPUT);
    
  pinMode(motorR1, OUTPUT);
  pinMode(motorR2, OUTPUT);
 
}

void loop()
{
    //Esperar nuevos datos
    if(Serial.available() > 0){
      dataFromApp = Serial.read();
    }

    switch (dataFromApp) {
    case 'U':
      up();        
      break;
    case 'D':
      down();
      break;
    case 'L':
      left();
      break;
    case 'R':
      right();
      break;
    case 'S':
      stop();
      break;
    }   
    delay(20);
}

void up(){
  digitalWrite(motorL1, 0);
  digitalWrite(motorL2, vel);
  digitalWrite(motorR1, 0);
  digitalWrite(motorR2, vel);
    
}

void down(){
  digitalWrite(motorL1, vel);
  digitalWrite(motorL2, 0); 
  digitalWrite(motorR1, vel);
  digitalWrite(motorR2, 0);

}

void right(){
  digitalWrite(motorL1, 0);
  digitalWrite(motorL2, vel);
  digitalWrite(motorR1, vel);
  digitalWrite(motorR2, 0);

}

void left(){
  digitalWrite(motorL1, vel);
  digitalWrite(motorL2, 0);
  digitalWrite(motorR1, 0);
  digitalWrite(motorR2, vel);

}

void stop(){
  digitalWrite(motorR1, 0);
  digitalWrite(motorR2, 0);
  digitalWrite(motorL1, 0);
  digitalWrite(motorL2, 0);
 
}
