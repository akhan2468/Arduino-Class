const int buttonPin = 2; // pushbutton pin
const int RedPin = 3;    // R pin
const int GledPin = 4;   // G pin
const int BledPin = 5;   // B pin

int buttonState = 0;     // current button state
int lastButtonState = 0; // previous button state
int ledcolor = 0;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50; // debounce time in milliseconds

void setup() {
  pinMode(RedPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  int reading = digitalRead(buttonPin);

  // Check if button state changed
  if (reading != lastButtonState) {
    lastDebounceTime = millis(); // reset the debounce timer
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // if the button state has been stable for > debounceDelay
    if (reading == HIGH && buttonState == LOW) {
      ledcolor++;
      if (ledcolor > 7) ledcolor = 0;
    }
    buttonState = reading;
  }

  lastButtonState = reading;

  // LED color control
  if (ledcolor == 0) { // OFF (white off)
    digitalWrite(RedPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 1) { // RED
    digitalWrite(RedPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 2) { // GREEN
    digitalWrite(RedPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 3) { // BLUE
    digitalWrite(RedPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
  }
  else if (ledcolor == 4) { // YELLOW
    digitalWrite(RedPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
  }
  else if (ledcolor == 5) { // PURPLE
    digitalWrite(RedPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
  }
  else if (ledcolor == 6) { // CYAN
    digitalWrite(RedPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
  }
  else if (ledcolor == 7) { // WHITE
    digitalWrite(RedPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
  }
}
