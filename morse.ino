int ledPin = 9;
int led = ledPin;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void space() {
  delay(1200);
}

void dot() {
  digitalWrite(led, HIGH);
  delay(300);
  digitalWrite(led, LOW);
  delay(300);
}

void dash() {
  digitalWrite(led, HIGH);
  delay(900);
  digitalWrite(led, LOW);
  delay(300);
}

void gap() {
  delay(600);
}

void morse(char input) {
  Serial.println(input);
  if (input == 'a' || input == 'A') {
    dot();
    dash();
  } else if (input == 'b' || input == 'B') {
    dash();
    dot();
    dot();
    dot();

  } else if (input == 'c' || input == 'C') {
    dash();
    dot();
    dash();
    dot();


  } else if (input == 'd' || input == 'D') {
    dash();
    dot();
    dot();
  } else if (input == 'e' || input == 'E') {
    dot();

  } else if (input == 'f' || input == 'F') {
    dot();
    dot();
    dash();
    dot();
  } else if (input == 'g' || input == 'G') {
    dash();
    dash();
    dot();
  } else if (input == 'h' || input == 'H') {
    dot();
    dot();
    dot();
    dot();
  } else if (input == 'i' || input == 'I') {
    dot();
    dot();
  } else if (input == 'j' || input == 'J') {
    dot();
    dash();
    dash();
    dash();
  } else if (input == 'k' || input == 'K') {
    dash();
    dot();
    dash();
  } else if (input == 'l' || input == 'L') {
    dot();
    dash();
    dot();
    dot();
  } else if (input == 'm' || input == 'M') {
    dash();
    dash();
  } else if (input == 'n' || input == 'N') {
    dash();
    dot();
  } else if (input == 'o' || input == 'O') {
    dash();
    dash();
    dash();
  } else if (input == 'p' || input == 'P') {
    dot();
    dash();
    dash();
    dot();
  } else if (input == 'q' || input == 'Q') {
    dash();
    dash();
    dot();
    dash();
  } else if (input == 'r' || input == 'R') {
    dot();
    dash();
    dot();
  } else if (input == 's' || input == 'S') {
    dot();
    dot();
    dot();
  } else if (input == 't' || input == 'T') {
    dash();
  } else if (input == 'u' || input == 'U') {
    dot();
    dot();
    dash();
  } else if (input == 'v' || input == 'V') {
    dot();
    dot();
    dot();
    dash();
  } else if (input == 'w' || input == 'W') {
    dot();
    dash();
    dash();
  } else if (input == 'x' || input == 'X') {
    dash();
    dot();
    dot();
    dash();
  } else if (input == 'y' || input == 'Y') {
    dash();
    dot();
    dash();
    dash();
  } else if (input == 'z' || input == 'Z') {
    dash();
    dash();
    dot();
    dot();
  } else if (input == ' ') {
    space();
  } else if (input == '1') {
    dot();
    dash();
    dash();
    dash();
    dash();
  } else if (input == '2') {
    dot();
    dot();
    dash();
    dash();
    dash();
  } else if (input == '3') {
    dot();
    dot();
    dot();
    dash();
    dash();
  } else if (input == '4') {
    dot();
    dot();
    dot();
    dot();
    dash();
  } else if (input == '5') {
    dot();
    dot();
    dot();
    dot();
    dot();
  } else if (input == '6') {
    dash();
    dot();
    dot();
    dot();
    dot();
  } else if (input == '7') {
    dash();
    dash();
    dot();
    dot();
    dot();
  } else if (input == '8') {
    dash();
    dash();
    dash();
    dot();
    dot();
  } else if (input == '9') {
    dash();
    dash();
    dash();
    dash();
    dot();
  } else if (input == '0') {
    dash();
    dash();
    dash();
    dash();
    dash();
  }

  gap();
}


void loop() {
  char n;
  int len = 0;
  int len1 = 0;
  String binval;
  Serial.println("Please enter your string: ");

  while (Serial.available() == 0) {
  }

  String input = Serial.readString();
  input.trim();
  Serial.read();



  len = input.length();
    Serial.println(input);
    for (int i = 0; i < len; i++) {
      n = input.charAt(i);
      morse(n);
    }
  }
}
