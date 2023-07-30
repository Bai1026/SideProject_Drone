#define joyX A0
#define joyY A1

int xValue, yValue;
// int SW = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  xValue = analogRead(joyX);
  yValue = analogRead(joyY);

  Serial.print("X axis: ");
  Serial.print(xValue);
  Serial.print("\t");
  Serial.print("Y Axis: ");
  Serial.print(yValue);
  Serial.print("\n");
  delay(200);
}

