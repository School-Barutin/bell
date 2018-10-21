// Pin confirguration
int bl = 7;

// Default values
double beginning = 8.00; // o'clock AM
int lessonDuration = 45 * 60000; // milliseconds
int firstBell = -5 * 60000; // 5 mins before the lesson
int secondBell = 0; // exactly when the lesson starts

void setup() {
  pinMode(bl, OUTPUT);
  first();
}

void first() {
  digitalWrite(bl, HIGH);
  delay(500);
  digitalWrite(bl, LOW);
  delay(500);
  
  digitalWrite(bl, HIGH);
  delay(500);
  digitalWrite(bl, LOW);
  delay(500);
  
  digitalWrite(bl, HIGH);
  delay(500);
  digitalWrite(bl, LOW);
  delay(500);
  
  digitalWrite(bl, HIGH);
  delay(500);
  digitalWrite(bl, LOW);
  delay(1200);
}

void second() {
  digitalWrite(bl, HIGH);
  delay(1000);
  digitalWrite(bl, LOW);
  delay(1000);
  
  digitalWrite(bl, HIGH);
  delay(1000);
  digitalWrite(bl, LOW);
  delay(1000);
  
  digitalWrite(bl, HIGH);
  delay(1000);
  digitalWrite(bl, LOW);
  delay(2200);
}

void third() {
  digitalWrite(bl, HIGH);
  delay(2500);
  digitalWrite(bl, LOW);
  delay(2000);
  
  digitalWrite(bl, HIGH);
  delay(2500);
  digitalWrite(bl, LOW);
  delay(2000);
}

void loop() {}
