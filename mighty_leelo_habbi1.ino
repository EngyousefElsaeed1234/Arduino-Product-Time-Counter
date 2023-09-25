byte button = 8;
byte counter = 0;
uint64_t t1 = 0;
double t2;
double time;
bool currentButtonState,lastButtonState;
void setup() {
  Serial.begin(9600);
pinMode(button, INPUT_PULLUP);
}

void loop() {
lastButtonState = currentButtonState;
currentButtonState = digitalRead(button);
if(currentButtonState == LOW && lastButtonState == HIGH && counter == 0)
{
  t1 = millis();
  counter = 1;
}
if(digitalRead(button) && counter == 1)
{
  t2 = millis()- t1;
  Serial.print("Time = ");
  Serial.print(t2/1000);
  Serial.println(" S");
  counter = 0;
}
}
