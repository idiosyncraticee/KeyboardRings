/*
  accel sketch
  simple sketch to try out accelerometer
 */
 
 const int xPin = 0; // analog input pins
 const int yPin = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // note the higher than usual serial speed
}

void loop() {
  // put your main code here, to run repeatedly: 
  int xValue;
  int yValue;
  
  xValue = analogRead(xPin);
  yValue = analogRead(yPin);
  
  Serial.print("X value = ");
  Serial.println(xValue);
  
  Serial.print("Y value = ");
  Serial.println(yValue);
  delay(100);
}
