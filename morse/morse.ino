#include <Arduino.h>
// Define the led pins
int ledPin = 13;

const char morseCode[][5] = {
    {'.', '-'}, // A
    {'-', '.', '.', '.'}, // B
    {'-', '.', '-', '.'}, // C
    {'-', '.', '.'}, // D
    {'.'}, // E
    {'.', '.', '-', '.'}, // F
    {'-', '-', '.'}, // G
    {'.', '.', '.', '.'}, // H
    {'.', '.'}, // I
    {'.', '-', '-', '-'}, // J
    {'-', '.', '-'}, // K
    {'.', '-', '.', '.'}, // L
    {'-', '-'}, // M
    {'-', '.'}, // N
    {'-', '-', '-'}, // O
    {'.', '-', '-', '.'}, // P
    {'-', '-', '.', '-'}, // Q
    {'.', '-', '.'}, // R
    {'.', '.', '.'}, // S
    {'-'}, // T
    {'.', '.', '-'}, // U
    {'.', '.', '.', '-'}, // V
    {'.', '-', '-'}, // W
    {'-', '.', '.', '-'}, // X
    {'-', '.', '-', '-'}, // Y
    {'-', '-', '.', '.'}, // Z
    {'-','-','-','-','-'},//0
    {'.','-','-','-','-'},//1
    {'.','.','-','-','-'},//2
    {'.','.','.','-','-'},//3
    {'.','.','.','.','-'},//4
    {'.','.','.','.','.'},//5
    {'-','.','.','.','.'},//6
    {'-','-','.','.','.'},//7
    {'-','-','-','.','.'},//8
    {'-','-','-','-','.'},//9
    {' '} // Space
};
// Start the Serial Monitor
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
// It takes each character and map it to the morse code output
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
  Serial.println("Please enter your string: ");
  // Loop which waits for user to enter string in Serial Monitor
  while (Serial.available() == 0) {
  }
  String input = Serial.readString();
  input.trim();
  Serial.read();
  for (int i = 0; i < input.length(); i++) {
    morse(input.charAt(i));
  }
}
