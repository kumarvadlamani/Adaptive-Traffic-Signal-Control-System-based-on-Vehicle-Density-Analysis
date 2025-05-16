#define NORTH_LED 2
#define EAST_LED 3
#define WEST_LED 4
#define SOUTH_LED 5

void setup() {
  pinMode(NORTH_LED, OUTPUT);
  pinMode(EAST_LED, OUTPUT);
  pinMode(WEST_LED, OUTPUT);
  pinMode(SOUTH_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char dir = Serial.read();

    // Turn off all LEDs first
    digitalWrite(NORTH_LED, LOW);
    digitalWrite(EAST_LED, LOW);
    digitalWrite(WEST_LED, LOW);
    digitalWrite(SOUTH_LED, LOW);

    // Turn on the relevant LED
    switch (dir) {
      case 'N':
        digitalWrite(NORTH_LED, HIGH);
        break;
      case 'E':
        digitalWrite(EAST_LED, HIGH);
        break;
      case 'W':
        digitalWrite(WEST_LED, HIGH);
        break;
      case 'S':
        digitalWrite(SOUTH_LED, HIGH);
        break;
    }
  }
}
