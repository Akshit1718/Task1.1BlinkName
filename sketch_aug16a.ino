const int ledPin = LED_BUILTIN; // Pin for the built-in LED
const int buttonPin = 2; // Pin for the button connected to D2
bool buttonPressed = false; // To track button press state

// Morse code timing constants
const int dotDuration = 250; // Duration of a dot in milliseconds
const int dashDuration = 750; // Duration of a dash in milliseconds
const int letterGap = 1000; // Gap between letters in milliseconds
const int partGap = 250; // Gap between parts of the same letter

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as output
  pinMode(buttonPin, INPUT_PULLUP); // Set the button pin as input with internal pull-up resistor
}

void loop() {
  // Check if the button is pressed (LOW because of pull-up resistor)
  if (digitalRead(buttonPin) == LOW) {
    buttonPressed = !buttonPressed; // Toggle the buttonPressed state
    delay(500); // Debounce delay to prevent multiple triggers
  }

  // If the button is pressed, start blinking the Morse code
  if (buttonPressed) {
    blinkMorseCode();
  }
}

void blinkMorseCode() {
  // Blink "A" in Morse code (dot-dash)
  dot();
  dash();
  delay(letterGap); // Gap between letters

  // Blink "K" in Morse code (dash-dot-dash)
  dash();
  dot();
  dash();
  delay(letterGap);

  // Blink "S" in Morse code (dot-dot-dot)
  dot();
  dot();
  dot();
  delay(letterGap);

  // Blink "H" in Morse code (dot-dot-dot-dot)
  dot();
  dot();
  dot();
  dot();
  delay(letterGap);

  // Blink "I" in Morse code (dot-dot)
  dot();
  dot();
  delay(letterGap);

  // Blink "T" in Morse code (dash)
  dash();
  delay(letterGap);
}

// Function to blink a dot (short blink)
void dot() {
  digitalWrite(ledPin, HIGH); // Turn on LED
  delay(dotDuration); // Wait for the duration of a dot
  digitalWrite(ledPin, LOW); // Turn off LED
  delay(partGap); // Wait between parts of the same letter
}

// Function to blink a dash (long blink)
void dash() {
  digitalWrite(ledPin, HIGH); // Turn on LED
  delay(dashDuration); // Wait for the duration of a dash
  digitalWrite(ledPin, LOW); // Turn off LED
  delay(partGap); // Wait between parts of the same letter
}
