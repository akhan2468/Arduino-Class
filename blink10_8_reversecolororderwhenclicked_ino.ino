const int buttonPin = 2;    
const int RedPin = 3;    // R pin
const int GledPin = 4;   // G pin
const int BledPin = 5;   // B pin

int ledcolor = 0;        // Start at Red
int buttonState = 0;
bool ButtonPressed = false;
unsigned long previousMillis = 0;
const long interval = 1000;
bool ledColorOrder = true;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(RedPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
}

void loop() {

  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH && !ButtonPressed){
  ledColorOrder = !ledColorOrder;
  ButtonPressed = true;
  }
  if (buttonState == LOW && ButtonPressed){
    ButtonPressed = false;
  }
  unsigned long currentMillis = millis();

  // check if 1 second passed
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (ledColorOrder == true){
      ledcolor = ledcolor + 1;
      if(ledcolor > 3)
      ledcolor = 0;
    }
    else{
      ledcolor = ledcolor - 1;
      if (ledcolor < 0)
      ledcolor = 3;
    }

  // continuously display current color
if (ledcolor == 0){
      digitalWrite(RedPin, LOW);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, HIGH);
    }
else if (ledcolor == 1){
      digitalWrite(RedPin, HIGH);
      digitalWrite(GledPin, LOW);
      digitalWrite(BledPin, HIGH);
    }
else if (ledcolor == 2){
      digitalWrite(RedPin, HIGH);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, LOW);
    }
else if (ledcolor == 3){
      digitalWrite(RedPin, LOW);
      digitalWrite(GledPin, LOW);
      digitalWrite(BledPin, LOW);
    }
  }
}
