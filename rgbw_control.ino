const int p2_red = 3;
const int p2_green = 5;
const int p2_blue = 6;
const int p2_white = 9;

void setup() {
  Serial.begin(9600);
  pinMode(p2_red, OUTPUT);
  pinMode(p2_green, OUTPUT);
  pinMode(p2_blue, OUTPUT);
  pinMode(p2_white, OUTPUT);
}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {
    // look for the next valid integer in the incoming serial stream:
    int red = Serial.parseInt();
    int green = Serial.parseInt();
    int blue = Serial.parseInt();
    int white = Serial.parseInt();

    // look for the newline. That's the end of your sentence:
    if (Serial.read() == '\n') {
      // constrain the values to 0 - 255 and invert
      // if you're using a common-cathode LED, just use "constrain(color, 0, 255);"
      red = 255 - constrain(red, 0, 255);
      green = 255 - constrain(green, 0, 255);
      blue = 255 - constrain(blue, 0, 255);

      // fade the red, green, and blue legs of the LED:
      analogWrite(p2_red, red);
      analogWrite(p2_green, green);
      analogWrite(p2_blue, blue);
      analogWrite(p2_white, white);

      // print the three numbers in one string as hexadecimal:
      Serial.print(red, HEX);
      Serial.print(green, HEX);
      Serial.print(blue, HEX);
      Serial.println(white, HEX);
    }

  }
}