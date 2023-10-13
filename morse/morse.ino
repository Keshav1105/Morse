// Define the led pins
int ledPin = 13;
int led = ledPin;

#include <Arduino.h>
// Define the led pins


const char morseCode[][5] = {
  { '.', '-' },            // A
  { '-', '.', '.', '.' },  // B
  { '-', '.', '-', '.' },  // C
  { '-', '.', '.' },       // D
  { '.' },                 // E
  { '.', '.', '-', '.' },  // F
  { '-', '-', '.' },       // G
  { '.', '.', '.', '.' },  // H
  { '.', '.' },            // I
  { '.', '-', '-', '-' },  // J
  { '-', '.', '-' },       // K
  { '.', '-', '.', '.' },  // L
  { '-', '-' },            // M
  { '-', '.' },            // N
  { '-', '-', '-' },       // O
  { '.', '-', '-', '.' },  // P
  { '-', '-', '.', '-' },  // Q
  { '.', '-', '.' },       // R
  { '.', '.', '.' },       // S
  { '-' },                 // T
  { '.', '.', '-' },       // U
  { '.', '.', '.', '-' },  // V
  { '.', '-', '-' },       // W
  { '-', '.', '.', '-' },  // X
  { '-', '.', '-', '-' },  // Y
  { '-', '-', '.', '.' },  // Z
  { ' ' }                  // Space
};

char decodeMorse(String morseCode) {
  if (morseCode == ".-") {
    return 'a';
  } else if (morseCode == "-...") {
    return 'b';
  } else if (morseCode == "-.-.") {
    return 'c';
  } else if (morseCode == "-..") {
    return 'd';
  } else if (morseCode == ".") {
    return 'e';
  } else if (morseCode == "..-.") {
    return 'f';
  } else if (morseCode == "--.") {
    return 'g';
  } else if (morseCode == "....") {
    return 'h';
  } else if (morseCode == "..") {
    return 'i';
  } else if (morseCode == ".---") {
    return 'j';
  } else if (morseCode == "-.-") {
    return 'k';
  } else if (morseCode == ".-..") {
    return 'l';
  } else if (morseCode == "--") {
    return 'm';
  } else if (morseCode == "-.") {
    return 'n';
  } else if (morseCode == "---") {
    return 'o';
  } else if (morseCode == ".--.") {
    return 'p';
  } else if (morseCode == "--.-") {
    return 'q';
  } else if (morseCode == ".-.") {
    return 'r';
  } else if (morseCode == "...") {
    return 's';
  } else if (morseCode == "-") {
    return 't';
  } else if (morseCode == "..-") {
    return 'u';
  } else if (morseCode == "...-") {
    return 'v';
  } else if (morseCode == ".--") {
    return 'w';
  } else if (morseCode == "-..-") {
    return 'x';
  } else if (morseCode == "-.--") {
    return 'y';
  } else if (morseCode == "--..") {
    return 'z';
  } else if (morseCode == ".----") {
    return '1';
  } else if (morseCode == "..---") {
    return '2';
  } else if (morseCode == "...--") {
    return '3';
  } else if (morseCode == "....-") {
    return '4';
  } else if (morseCode == ".....") {
    return '5';
  } else if (morseCode == "-....") {
    return '6';
  } else if (morseCode == "--...") {
    return '7';
  } else if (morseCode == "---..") {
    return '8';
  } else if (morseCode == "----.") {
    return '9';
  } else if (morseCode == "-----") {
    return '0';
  } else {
    return ' ';
  }
}

int stringLength(String str) {
  int length = 0;
  while (str[length] != '\0') {
    length++;
  }
  return length;
}

// Start the Serial Monitor
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
  int index = -1;
  if (input >= 'a' && input <= 'z') {
    index = input - 'a';
  } else if (input >= 'A' && input <= 'Z') {
    index = input - 'A';
  } else if (input >= '0' && input <= '9') {
    index = input - '0' + 26;
  } else if (input == ' ') {
    index = 36;
  }

  if (index != -1) {
    for (int i = 0; morseCode[index][i] != '\0'; i++) {
      if (morseCode[index][i] == '.') {
        dot();
      } else if (morseCode[index][i] == '-') {
        dash();
      } else {
        space();
      }
    }
    space();
  }
}

void loop() {
  char n;
  int len = 0;
  int len1 = 0;
  String binval;
  Serial.println("Please enter 1 or 0 if you want to either convert a string into morse code or vice versa respectively:");
  while (Serial.available() == 0) {
  }
  int x = Serial.read();
  if (x == 49) {
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
  if (x == 48) {
    String morseCode;
    Serial.println("Enter morse code");
    while (Serial.available() == 0) {
    }
    String input = Serial.readString();
    len = stringLength(input);
    for (int i = 0; i < len; i++) {
      if (input.charAt(i) != ' ') {
        morseCode += input.charAt(i);
      } else {
        char decodedChar = decodeMorse(morseCode);
        Serial.print(decodedChar);
        morseCode = "";
      }
    }
    if (morseCode != "") {  //Last Character
      char decodedChar = decodeMorse(morseCode);
      Serial.println(decodedChar);
    }
    digitalWrite(ledPin, HIGH);
    delay(900);
    digitalWrite(ledPin, LOW);
    delay(300);
  }
}

