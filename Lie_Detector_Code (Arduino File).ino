void setup()
{
  // Calling for tbe use of serial input/output and Setting the desired communication speed = 9600 baud.
  // Baud is a measure of the number of bits transmitted per second.
  // 9600 baud rate ~ 1000 characters per second.
  Serial.begin(9600);

  // Setting the digital pins for the output(LEDs)
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  // Setting each LED once as turned on
  digitalWrite(2, HIGH);
  delay(500);               // wait for 500 ms
  digitalWrite(3, HIGH);
  delay(500);               // wait for 500 ms
  digitalWrite(4, HIGH);
  delay(500);               // wait for 500 ms
}

void loop()
{
  // lie detected (higher conductivity observed)
  if(analogRead(A0) > 3)     
  {
    digitalWrite(4, HIGH);

    digitalWrite(2, LOW);

    digitalWrite(3, LOW);
  }

  // neutral case (slightly higher than the normal conductivity but not that high to conclude that the subject is lying)
  else if(analogRead(A0) > 2)
  {
    digitalWrite(3, HIGH);

    digitalWrite(2, LOW);

    digitalWrite(4, LOW);
  }

  // truth proven (normal conductivity observed)
  else
  {
    digitalWrite(2, HIGH);

    digitalWrite(3, LOW);

    digitalWrite(4, LOW);
  }

  // printing the analogRead data to the serial port as human readable ASCII text.
  Serial.println(analogRead(A0));
  // wait for 20 ms
  delay(20);      
}
