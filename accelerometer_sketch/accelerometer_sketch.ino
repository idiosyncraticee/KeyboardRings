/*
  accel sketch
  simple sketch to try out accelerometer
 */
 
 const int xPin = 0; // analog input pins
 const int yPin = 1;
 const int zPin = 2;

 const int numberValuesAverage = 10;

int xValArray[numberValuesAverage];
int yValArray[numberValuesAverage];
int zValArray[numberValuesAverage];
int Zsnooze;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // note the higher than usual serial speed
  //INITIALIZE ROLLING AVERAGE VALUE ARRAYS
  for (int i = 0; i < 5; i = i + 1) {
    xValArray[i] = 0;
    yValArray[i] = 0;
    zValArray[i] = 0;
  }

}

void loop() {
  // put your main code here, to run repeatedly: 
  int xValue;
  int yValue;
  int zValue;  
  xValue = analogRead(xPin);
  yValue = analogRead(yPin);
  zValue = analogRead(zPin);  

//  Serial.print("X value = ");
//  Serial.println(xValue);
//  
//  Serial.print("Y value = ");
//  Serial.println(yValue);
//  
//  Serial.print("Z value = ");
//  Serial.println(zValue);
  
  delay(100);
  
  //COMPUTE A ROLLING AVERAGE OF THE LAST 10 MEASUREMENTS

  //SET THE 1-9 VALUES TO THE PREVIOUS VALUE 
  for (int i=1; i < numberValuesAverage; i++) {   
    xValArray[i] = xValArray[i-1];
        yValArray[i] = yValArray[i-1];
            zValArray[i] = zValArray[i-1];
  }
  
  //SET THE ZERO ELEMENT TO THE CURRENT VALUE
  xValArray[0] = xValue;
  yValArray[0] = yValue;
  zValArray[0] = yValue; 
  int Xsum=0;
    int Ysum=0;
      int Zsum=0;
  //TAKE THE AVERAGE
  for (int i=0; i < numberValuesAverage; i++) {   
    Xsum = Xsum+xValArray[i];
    Ysum = Ysum+yValArray[i];
    Zsum = Zsum+zValArray[i];
  } 
  
  double XAverage = Xsum/numberValuesAverage;
    double YAverage = Ysum/numberValuesAverage;
      double ZAverage = Zsum/numberValuesAverage;
  //Serial.print("X average = ");
  //Serial.println(XAverage); 

  //SINCE I ONLY NEED THE ACCELERATION IN A SINGLE DIRECTION I WILL NOT USE THE ABSOLUTE VALUE TO DETECT AN EVENT 
  double XDiff = XAverage - xValue;
  double YDiff = YAverage - yValue;
  double ZDiff = ZAverage - zValue; 
    
//  if(XDiff > 10) {
//    Serial.print("X value = ");
//    Serial.print(xValue); 
//    Serial.print(" , X average = ");
//    Serial.print(XAverage);    
//    Serial.print(" , X diff = ");
//    Serial.println(XDiff); 
//
//  }
//    if(YDiff > 10) {
//    Serial.print("Y value = ");
//    Serial.print(yValue); 
//    Serial.print(" , Y average = ");
//    Serial.print(YAverage);    
//    Serial.print(" , Y diff = ");
//    Serial.println(YDiff); 
//  }
    if(ZDiff > 20 && Zsnooze<1) {
      Serial.print("Zvalue = ");
      Serial.print(zValue); 
      Serial.print(" , Z average = ");
      Serial.print(ZAverage);    
      Serial.print(" , Z diff = ");
      Serial.println(ZDiff); 
    
      Zsnooze=5;

    }

  if(Zsnooze > 0) {
    Zsnooze=Zsnooze-1; 
  }
}
