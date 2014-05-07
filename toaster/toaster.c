void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  Serial.begin(9600);
}
int incomingByte = 0;   // for incoming serial data
unsigned long toastingTime = 0;
int relay = 13;
int tmp = 0; 
int waitTimeDown = 1100;
int waitTimeUp = 350;
//In order to spin the motor downwards, write 100 analogue to the 11th pin, and LOW to the 10th one.
//We use 100 because it's a nice slow spin.

void relayOn()
{
  digitalWrite(relay, HIGH);
}
void relayOff()
{
  digitalWrite(relay, LOW);

}
void motorUp()
{
  analogWrite(10, 100);
  digitalWrite(11, LOW);
  delay(waitTimeUp);
  digitalWrite(10, LOW);
	
}
	
void motorDown()
{
  analogWrite(11, 100);
  digitalWrite(10, LOW);
  delay(waitTimeDown);
  digitalWrite(11, LOW);
}

//Main body
void loop() 
{
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  while(!Serial.available());
  // read the incoming byte:
  toastingTime = Serial.read();
  delay(500);
  // say what you got:
  Serial.print("I received: ");
  Serial.println(toastingTime);
  motorDown();
  delay(100);
  relayOn();
  toastingTime = toastingTime * 1000;
  Serial.println(toastingTime);
  delay(toastingTime);
  relayOff();
  delay(100);
  motorUp();
  Serial.println("Motor went up successfully.");
}
