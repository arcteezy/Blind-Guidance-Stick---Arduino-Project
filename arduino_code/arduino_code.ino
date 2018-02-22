// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;

// defines variables
long duration;
int distance;

void setup() 
{
  pinMode(trigPin, OUTPUT);   // Sets the trigPin as an Output
  pinMode(6, OUTPUT);   //VIBRATOR
  pinMode(3,OUTPUT);  //BUZZER
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input
}
void loop() 
{
  digitalWrite(trigPin, LOW); // Clears the trigPin
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);  // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance= duration*0.034/2;

  if(distance<25)
  {
    analogWrite(6,140); 
    tone(3,1000,1000);
  }
  else if(distance<50)
  {
     analogWrite(6,110); 
    tone(3,1000,1000);
  }
  else if(distance<75)
  {
      analogWrite(6,90);
    analogWrite(3,255);
  }
  else if(distance<100)
  {
    analogWrite(6,70); 
    analogWrite(3,255);
  }
  else
  {
    analogWrite(6,0);
    analogWrite(3,0);
    noTone(3); 
  }
}

