const int buttonPin = 2; // the number of the pushbutton pin
const int RedPin = 3; // the number of the R pin
const int GledPin = 4; // the number of the G pin
const int BledPin = 5; // the number of the B pin
String currentcolor = "led";

int buttonState = 0;     // variable for reading the pushbutton status
int ledcolor = 0;

bool buttonPressed = false;

void setup() {
  // initialize the LED pin as an output:
  pinMode (RedPin, OUTPUT);
  pinMode (GledPin, OUTPUT); 
  pinMode (BledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode (buttonPin, INPUT);
  Serial.begin(9600); //Bound rate setting
}

void loop() {
  //read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  Serial.print ("Current Color:") ;
  Serial.println (currentcolor);
  
  if (buttonState == HIGH && !buttonPressed) {   
    ledcolor = ledcolor + 1;
    buttonPressed = true;
    //delay(100);
  }

  if (buttonState == LOW && buttonPressed) {     
    ledcolor = ledcolor + 1;
    buttonPressed = false;
  } 
 
  if (ledcolor == 0){
    currentcolor = "LED off";
    digitalWrite(RedPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  }

  else if (ledcolor == 1) {
    currentcolor = "RED";
    digitalWrite(RedPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  }

  else if(ledcolor == 2) {
    currentcolor = "GREEN";
    digitalWrite(RedPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
  }

  else if(ledcolor == 3) {
    currentcolor = "BLUE";
    digitalWrite(RedPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
  }

  else if(ledcolor == 4) {
    currentcolor = "YELLOW";
    digitalWrite(RedPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
  }

  else if(ledcolor == 5) {
    currentcolor = "PURPLE";
    digitalWrite(RedPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
  }

  else if(ledcolor == 6) {
    currentcolor = "CYAN";
    digitalWrite(RedPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
  }

  else if(ledcolor == 7) {
    currentcolor = "WHITE";
    digitalWrite(RedPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
  }

  else if(ledcolor == 8) {
    ledcolor = 0;
  }
}
