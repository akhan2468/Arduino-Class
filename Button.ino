// Pin definitions
const int buttonPin = 9;  // the number of the pushbutton pin
const int ledPin = 3;     // the number of the LED pin

// State variables
int ledState = 0;              // 0=steady, 1=slow blink, 2=medium blink, 3=fast blink
int lastButtonState = LOW;
int currentButtonState = LOW;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

// Blinking variables
unsigned long previousMillis = 0;
bool ledOn = true;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
  // Start with LED off
  digitalWrite(ledPin, LOW);
}

void loop() {
  // Read button with debouncing
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != currentButtonState) {
      currentButtonState = reading;

      // Button pressed (HIGH)
      if (currentButtonState == HIGH) {
        ledState++;
        if (ledState > 3) {
          ledState = 0;  // Return to steady state
        }

        // Reset blink timer and turn LED on when changing state
        previousMillis = millis();
        ledOn = true;
        digitalWrite(ledPin, HIGH);
      }
    }
  }

  lastButtonState = reading;

  // Handle LED states
  switch (ledState) {
    case 0:  // Steady lighting
      digitalWrite(ledPin, HIGH);
      break;

    case 1:  // Slow blink (1 second interval)
      blinkLED(1000);
      break;

    case 2:  // Medium blink (500ms interval)
      blinkLED(500);
      break;

    case 3:  // Fast blink (200ms interval)
      blinkLED(200);
      break;
  }
}

// Blink LED with given interval
void blinkLED(int interval) {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Toggle LED state
    ledOn = !ledOn;
    digitalWrite(ledPin, ledOn ? HIGH : LOW);
  }
}