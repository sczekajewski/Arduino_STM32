/*
  BlinkNcount for Maple Mini by m. ray burnette, update by The Lightning Stalker to use #define
    Sketch uses 13,808 bytes (12%) of program storage space. Maximum is 108,000 bytes.
    Global variables use 2,592 bytes of dynamic memory.
  Turns on an LED on for one second, then off for one second, repeatedly.
  Counts and displays the count on the attached serial monitor
  This example code is in the public domain.
*/

#define LED_PIN PC13  // Maple Mini LED is on PB1, other boards may vary

int n = 0;


void setup() {
  // initialize the digital pin as an output.
  pinMode(LED_PIN, OUTPUT);
  // Initialize virtual COM over USB on Maple Mini
  Serial.begin(9600);  // BAUD has no effect on USB serial: placeholder for physical UART
  // wait for serial monitor to be connected.
  while (!Serial)
  {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN)); // Turn the LED from off to on, or on to off
    delay(100);         // fast blink
  }
  Serial.println("Blink LED & count Demo");
}

void loop() {
  digitalWrite(LED_PIN, HIGH);   // set the LED on
  delay(500);              // wait for a second
  digitalWrite(LED_PIN, LOW);    // set the LED off
  Serial.print("Loop #: ");
  n++;
  Serial.println(n);

  delay(500);              // wait
}
