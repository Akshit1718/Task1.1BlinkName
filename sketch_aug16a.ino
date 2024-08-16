const int ledPin = LED_BUILTIN; // Built-in LED pin
const int buttonPin = 2; // Button connected to D2
bool buttonPressed = false;

// Morse code timing
const int dotDuration = 250; // Duration of a dot
const int dashDuration = 750; // Duration of a dash
const int letterGap = 1000; // Gap between letters
const int partGap = 250; // Gap between parts of the same letter

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Using internal pull-up resistor
}

void loop() {
  if (digitalRead(buttonPin) == LOW) { // Button pressed
    buttonPressed = !buttonPressed; // Toggle state
    delay(500); // Debounce delay
  }
  
  if (buttonPressed) {
    blinkMorseCode();
  }
}

void blinkMorseCode() {
  // Blink "A"
  dot(); dash();
  delay(letterGap);

  // Blink "K"
  dash(); dot(); dash();
  delay(letterGap);

  // Blink "S"
  dot(); dot(); dot();
  delay(letterGap);

  // Blink "H"
  dot(); dot(); dot(); dot();
  delay(letterGap);

  // Blink "I"
  dot(); dot();
  delay(letterGap);

  // Blink "T"
  dash();
  delay(letterGap);
}

void dot() {
  digitalWrite(ledPin, HIGH);
  delay(dotDuration);
  digitalWrite(ledPin, LOW);
  delay(partGap);
}

void dash() {
  digitalWrite(ledPin, HIGH);
  delay(dashDuration);
  digitalWrite(ledPin, LOW);
  delay(partGap);
}
