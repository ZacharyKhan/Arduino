
#define motorfwd 3
#define motorbwd 4
#define enable 5

int motorspeed = 0;

void setup() {
pinMode(motorfwd, OUTPUT);
pinMode(motorbwd, OUTPUT);
pinMode(enable, OUTPUT);

digitalWrite(enable, LOW);
Serial.begin(9600);
}

void loop() {

  int joy_x = analogRead(A0);

  Serial.print("X-axis: ");
  Serial.print(joy_x);
  Serial.print("\n\n");

  if (joy_x < 450) {
    digitalWrite(motorfwd, HIGH);
    digitalWrite(motorbwd, LOW);
    motorspeed = map(joy_x, 450, 0, 0, 255);
  }
  else if (joy_x > 550) {
    digitalWrite(motorfwd, LOW);
    digitalWrite(motorbwd, HIGH);
    motorspeed = map(joy_x, 550, 1023, 0, 255);
  }
  else {
    motorspeed = 0;
  }

  if (motorspeed < 70){
    motorspeed = 0;
  }

  analogWrite(enable, motorspeed);
  delay(200);
} 
