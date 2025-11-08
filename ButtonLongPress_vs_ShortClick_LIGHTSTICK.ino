const int RledPin = 9;
const int GledPin = 10;
const int BledPin = 11;
const int buttonPin = 2;

bool buttonPressed = false;
unsigned long pressStart = 0;
const int longPressInterval = 2000;
const int debounceDelay = 50;

int currentMode = 0;

// Modes: 0 = Constant, 1 = Blink, 2 = Breathing
unsigned long blinkTimer = 0;
const int blinkInterval = 500;
bool blinkOn = true;

unsigned long breathTimer = 0;
int breathBrightness = 0;
int breathDirection = 1;

int RLightColor = 255;
int GLightColor = 255;
int BLightColor = 255;

int RCurrentColor = 0;
int GCurrentColor = 0;
int BCurrentColor = 0;

void setup() {
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);   // IMPORTANT
}

void loop() {
  checkButtonLogic();
  updateLEDBehavior();
  analogWrite(RledPin, RCurrentColor);
  analogWrite(GledPin, GCurrentColor);
  analogWrite(BledPin, BCurrentColor);
}

void checkButtonLogic() {
  static unsigned long lastDebounce = 0;
  static int lastState = HIGH;

  int reading = digitalRead(buttonPin);

  if (reading != lastState) {
    lastDebounce = millis();
  }

  if ((millis() - lastDebounce) > debounceDelay) {

    if (reading == LOW && !buttonPressed) {
      buttonPressed = true;
      pressStart = millis();
    }

    if (reading == HIGH && buttonPressed) {
      unsigned long pressDuration = millis() - pressStart;

      if (pressDuration >= longPressInterval) {
        changeMode();
      } else {
        changeLEDColor();
      }

      buttonPressed = false;
    }
  }

  lastState = reading;
}

void changeMode() {
  currentMode = (currentMode + 1) % 3;

  if (currentMode == 1) {
    blinkTimer = 0;
    blinkOn = true;
  }

  if (currentMode == 2) {
    breathTimer = 0;
    breathBrightness = 0;
    breathDirection = 1;
  }
}

void changeLEDColor() {
  if (RLightColor == 255 && GLightColor == 0 && BLightColor == 0) {
    RLightColor = 0; GLightColor = 255; BLightColor = 0;   // Green
  } else if (RLightColor == 0 && GLightColor == 255 && BLightColor == 0) {
    RLightColor = 0; GLightColor = 0; BLightColor = 255;   // Blue
  } else {
    RLightColor = 255; GLightColor = 0; BLightColor = 0;   // Red
  }
}

void updateLEDBehavior() {
  if (currentMode == 0) {   // CONSTANT
    RCurrentColor = RLightColor;
    GCurrentColor = GLightColor;
    BCurrentColor = BLightColor;
  }

  else if (currentMode == 1) { // BLINK
    if (millis() - blinkTimer > blinkInterval) {
      blinkOn = !blinkOn;
      blinkTimer = millis();
    }

    if (blinkOn) {
      RCurrentColor = RLightColor;
      GCurrentColor = GLightColor;
      BCurrentColor = BLightColor;
    } else {
      RCurrentColor = 0;
      GCurrentColor = 0;
      BCurrentColor = 0;
    }
  }

  else if (currentMode == 2) { // BREATHING
    if (millis() - breathTimer > 15) {
      breathBrightness += breathDirection;
      if (breathBrightness <= 0 || breathBrightness >= 255) {
        breathDirection = -breathDirection;
      }
      breathTimer = millis();
    }

    RCurrentColor = (RLightColor * breathBrightness) / 255;
    GCurrentColor = (GLightColor * breathBrightness) / 255;
    BCurrentColor = (BLightColor * breathBrightness) / 255;
  }
}
