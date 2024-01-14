//Name - Shazia
//Date - March 28 2022
//Assignment 6
//Purpose - to encrypt or decrypt a message

#include <iostream>

using namespace std;

//TO ENCRYPT MESSAGE
void encrypt(string word, int shift) {
  string new_message = word;

  for (int i = 0; i < word.length(); i++) {
    //if word has spaces in it ignore
    if (word[i] != 32) {
      //for uppercase letters
      if ((word[i] + shift) > 90 && (word[i] + shift) <= 96)      {
        new_message[i] = int((word[i] + shift) - 90) + 64;
        //for lowercase letters
      } else if ((word[i] + shift) > 122) {
        new_message[i] = int((word[i] + shift) - 122) + 96;
        //if word + shift is in between letters a-z
      } else {
        new_message[i] += shift;
      }
    }
  }
  cout << "Encrypted message: " << new_message << endl;
}

//TO DECRYPT MESSAGE
void decrypt(string word, int shift) {
  string new_message = word;

  for (int i = 0; i < word.length(); i++) {
    //if word has spaces in it ignore
    if (word[i] != 32) {
      //for lowercase letters
      if ((word[i] - shift) < 97 && (word[i] - shift) > 90) 
      {
        new_message[i] = int(word[i] - shift) + 26;
      }
      //for uppercase letters
      else if ((word[i] - shift) < 65) {
        new_message[i] = int(word[i] - shift) + 26;
      }
      //if (word - shift) is between letters a-z
      else {
        new_message[i] -= shift;
      }
    }
  }
  cout << "Decrypted message: " << new_message << endl;
}

//MAIN FUNCTION
int main() {

  string message;
  int choice;
  int shift;

  cout << "What is your message? " << endl;
  getline(cin, message);
  cout << "\033[2J\033[1;1H";

  cout << "Do you want to..." << endl;
  cout << "1. Encrypt\n2. Decrypt" << endl;
  cout << "Choice: ";
  cin >> choice;
  cout << "\033[2J\033[1;1H";

  cout << "What is the shift? " << endl;
  cout << "Shift: ";
  cin >> shift;
  cout << "\033[2J\033[1;1H";

  while (true) {
    switch (choice) {
      //if user wants to encrypt
    case 1:
      encrypt(message, shift);
      return 0;
      //if user wants to decrypt
    case 2:
      decrypt(message, shift);
      return 0;
      //if user does not enter valid option
    default:
      cout << "INVALID INPUT" << endl;
      return 0;
    }
  }
}