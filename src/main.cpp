int IN1 = 2;
int IN2 = 4;
int IN3 = 9;
int IN4 = 10;
int ENA = 3;
int ENB = 5;

int Lsensor = A1;   // Left sensor
int Rsensor = A0;   // Right sensor
int Lsensor2 = A2;  // Middle sensor

int RIGHT, LEFT, MIDDLE;
int x = 137;  // سرعة الموتور A
int y = 145;  // سرعة الموتور B

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(Rsensor, INPUT);
  pinMode(Lsensor, INPUT);
  pinMode(Lsensor2, INPUT);  
}

void loop() {
  
  RIGHT = digitalRead(Rsensor);
  LEFT = digitalRead(Lsensor);
  MIDDLE = digitalRead(Lsensor2);

  Serial.print("L: "); Serial.print(LEFT);
  Serial.print(" M: "); Serial.print(MIDDLE);
  Serial.print(" R: "); Serial.println(RIGHT);

  // السينسور على خط = 1، مفيش خط = 0

  if (MIDDLE == 1 && LEFT == 0 && RIGHT == 0) {
    // الخط تحت النص بس → امشي لقدام
    digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
    analogWrite(ENA, x); analogWrite(ENB, y);
    Serial.println("FORWARD - MIDDLE ONLY");
  
  } else if (MIDDLE == 1 && LEFT == 1 && RIGHT == 0) {
    // الخط تحت النص و الشمال → ضايع يمين → لف شمال خفيف
    digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
    analogWrite(ENA, x); analogWrite(ENB, y);
    Serial.println("TURN LEFT");

  } else if (MIDDLE == 1 && LEFT == 0 && RIGHT == 1) {
    // الخط تحت النص و اليمين → ضايع شمال → لف يمين خفيف
    digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
    analogWrite(ENA, x); analogWrite(ENB, y);
    Serial.println("TURN RIGHT");

  } else if (MIDDLE == 1 && LEFT == 1 && RIGHT == 1) {
    // الخط تحت التلاتة → امشي لقدام
    digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
    analogWrite(ENA, x); analogWrite(ENB, y);
    Serial.println("FORWARD - ALL SENSORS ON LINE");

  } else if (RIGHT == 1 && MIDDLE == 0 && LEFT == 0) {
    // فقط اليمين شايف الخط → لف يمين جامد
    digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
    analogWrite(ENA, x); analogWrite(ENB, y);
    Serial.println("HARD RIGHT - RIGHT SENSOR ONLY");

  } else if (LEFT == 1 && MIDDLE == 0 && RIGHT == 0) {
    // فقط الشمال شايف الخط → لف شمال جامد
    digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
    analogWrite(ENA, x); analogWrite(ENB, y);
    Serial.println("HARD LEFT - LEFT SENSOR ONLY");

  } else if (LEFT == 1 && MIDDLE == 1 && RIGHT == 0) {
    // نص و شمال → لف شمال متوسط
    digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
    analogWrite(ENA, x); analogWrite(ENB, y);
    Serial.println("MEDIUM LEFT");

  } else if (LEFT == 0 && MIDDLE == 1 && RIGHT == 1) {
    // نص و يمين → لف يمين متوسط
    digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
    analogWrite(ENA, x); analogWrite(ENB, y);
    Serial.println("MEDIUM RIGHT");

  } else {
    // مش شايف الخط → وقف
    digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
    analogWrite(ENA, 0); analogWrite(ENB, 0);
    Serial.println("STOP - LINE LOST");
  }

  delay(100);
}
