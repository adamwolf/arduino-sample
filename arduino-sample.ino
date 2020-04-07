int pushButton = 2;

int doubler(int in)
{
  return 2*in;
}

void setup() {
  Serial.begin(9600);
  Serial.println("Hello world.");
  pinMode(pushButton, INPUT);
}

void loop() {
  bool buttonState = digitalRead(pushButton);
  if (buttonState)
  {
    Serial.print("2 * 5 ==");
    Serial.println(doubler(5));
  } else {
    Serial.println("Not pushed.");
  }

  delay(1);
}
