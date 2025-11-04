// Pin setup
const int buttonPin = 2;
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

int buttonState = 0;
int lastButtonState = 0;
int colorIndex = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Use internal pull-up resistor
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // Detect button press
  if (buttonState == LOW && lastButtonState == HIGH) {
    colorIndex = (colorIndex + 1) % 4; // Cycle through 4 states
    setColor(colorIndex);
    delay(200); // Debounce delay
  }

  lastButtonState = buttonState;
}

void setColor(int index) {
  switch (index) {
    case 0: // Orange
      analogWrite(redPin, 255);
      analogWrite(greenPin, 100);
      analogWrite(bluePin, 0);
      break;
    case 1: // Purple
      analogWrite(redPin, 180);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 180);
      break;
    case 2: // Green
      analogWrite(redPin, 0);
      analogWrite(greenPin, 255);
      analogWrite(bluePin, 0);
      break;
    case 3: // Off
      analogWrite(redPin, 0);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 0);
      break;
  }
}