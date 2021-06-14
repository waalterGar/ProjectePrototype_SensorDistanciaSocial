
const int trigPin = 9; 
const int echoPin = 10; 
const int ledPin = 13; 
const int buzzPin = 2; 
long duration; 
int distance;

void setup(){
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT); 
  pinMode(buzzPin, OUTPUT);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2; 
  Serial.println("Distance: "); 
  Serial.println(distance); 

  if (distance <= 150 && distance >= 0) { 
    digitalWrite(ledPin, HIGH); 
    digitalWrite(buzzPin, HIGH); 
    tone(2, 500, 120); 
  } else {
    digitalWrite(ledPin, LOW); 
    digitalWrite(buzzPin, LOW); 
    }
} 
