const int buttonPin = 2; // the number of the pushbutton pin
const int RedPin = 3; // the number of the R pin
const int GledPin = 4; // the number of the G pin
const int BledPin = 5; // the number of the B pin

// variables will change:
int buttonState = 1; // variable for reading the pushbutton status
int ledcolor = 0;

void setup() {
// initialize the LED pin as an output:
pinMode (RedPin, OUTPUT);
pinMode (GledPin, OUTPUT); 
pinMode (BledPin, OUTPUT);
// initialize the pushbutton pin as an input:
pinMode (buttonPin, INPUT);
}

void loop() {
  //read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW) {
    ledcolor = ledcolor + 1;
    delay(100);
  }
 
  if (ledcolor == 0){

  digitalWrite(RedPin, HIGH);
  digitalWrite(GledPin, HIGH);
  digitalWrite(BledPin, HIGH);
  }

  else if (ledcolor == 1) {
  //RED
  digitalWrite(RedPin, LOW);
  digitalWrite(GledPin, HIGH);
  digitalWrite(BledPin, HIGH);
  }

  else if(ledcolor == 2) {
  //Green
  digitalWrite(RedPin, HIGH);
  digitalWrite(GledPin, LOW);
  digitalWrite(BledPin, HIGH);
  }

  else if(ledcolor == 3) {
  //BLUE
  digitalWrite(RedPin, HIGH);
  digitalWrite(GledPin, HIGH);
  digitalWrite(BledPin, LOW);
  }

  else if(ledcolor == 4) {

  digitalWrite(RedPin, LOW);
  digitalWrite(GledPin, LOW);
  digitalWrite(BledPin, HIGH);
  }

  else if(ledcolor == 5) {
  //PURPLE
  digitalWrite(RedPin, LOW);
  digitalWrite(GledPin, HIGH);
  digitalWrite(BledPin, LOW);
  }

  else if(ledcolor == 6) {
  //CYAN
  digitalWrite(RedPin, HIGH);
  digitalWrite(GledPin, LOW);
  digitalWrite(BledPin, LOW);
  }

  else if(ledcolor == 7) {
  //WHITE
  digitalWrite(RedPin, LOW);
  digitalWrite(GledPin, LOW);
  digitalWrite(BledPin, LOW);
  }

  else if(ledcolor == 8) {
  ledcolor = 0;

  }
}