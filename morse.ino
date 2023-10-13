#include <Arduino.h>
#include <unordered_map>

int ledPin = 9;

std::unordered_map<char, String> morseCode = {
    {'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."}, {'f', "..-."}, {'g', "--."}, {'h', "...."},
    {'i', ".."}, {'j', ".---"}, {'k', "-.-"}, {'l', ".-.."}, {'m', "--"}, {'n', "-."}, {'o', "---"}, {'p', ".--."},
    {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"}, {'u', "..-"}, {'v', "...-"}, {'w', ".--"}, {'x', "-..-"},
    {'y', "-.--"}, {'z', "--.."}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."},
    {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."}, {'0', "-----"}, {' ', " "}
};

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void dot() {
  digitalWrite(ledPin, HIGH);
  delay(300);
  digitalWrite(ledPin, LOW);
  delay(300);
}

void dash() {
  digitalWrite(ledPin, HIGH);
  delay(900);
  digitalWrite(ledPin, LOW);
  delay(300);
}

void space() {
  delay(1200);
}

void morse(char input) {
  String code = morseCode[tolower(input)];
  for (int i = 0; i < code.length(); i++) {
    if (code[i] == '.') {
      dot();
    } else if (code[i] == '-') {
      dash();
    } else {
      space();
    }
  }
  space();
}

void loop() {
  Serial.println("Please enter your string: ");
  while (Serial.available() == 0) {
  }
  String input = Serial.readString();
  input.trim();
  Serial.read();
  for (int i = 0; i < input.length(); i++) {
    morse(input.charAt(i));
  }
}
