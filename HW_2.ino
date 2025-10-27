const int RledPin = 9;
const int GledPin = 11;
const int BledPin = 10;
const int buttonPin = 2;  // ✅ Declare the button pin

int mood = 0;
const int neutralMood = 10;
int buttonState = 0;
bool ButtonPressed = false;

unsigned long reducedTimer = 0;
unsigned long touchedTimer = 0;

const long unTouchInterval = 5000;  // Time before mood starts decreasing
const long reducedInterval = 1000;  // Time between each mood decrease

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);

  mood = neutralMood;
}

void loop() {
  showLEDState(mood);

  buttonState = digitalRead(buttonPin);

  // ✅ Use comparison (==) not assignment (=)
  if (buttonState == HIGH && !ButtonPressed) {
    mood = mood + 1;
    if (mood > 20) mood = 20;
    touchedTimer = millis();
    ButtonPressed = true;
  }

  if (buttonState == LOW && ButtonPressed) {
    ButtonPressed = false;
  }

  unsigned long currentTimer = millis();
  if (currentTimer - touchedTimer > unTouchInterval) {
    if (currentTimer - reducedTimer > reducedInterval) {
      mood = mood - 1;
      if (mood < 0) mood = 0;
      reducedTimer = currentTimer;
    }
  }
}

void showLEDState(int state) {
  float brightnessInterval = 255 / 10.0;
if(mood >= neutralMood){
analogWrite(RledPin, 255);
analogWrite(GledPin, brightnessInterval * (mood - neutralMood));
analogWrite(BledPin, 255 - brightnessInterval * (mood - neutralMood));
}
else{
analogWrite(RledPin, 255 - brightnessInterval * (neutralMood - mood));
analogWrite(GledPin, brightnessInterval * (neutralMood - mood));
analogWrite(BledPin, 255);
}
}