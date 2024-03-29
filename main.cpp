/*
Name: Noah Mitchell, CodingScape Challenge
Description: Finds the sum of all of the calibration values
Input: Calibration encryption
Output: Sum of all calibration values
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


int main() {

  //Initializes variables
  ifstream infile;
  string fileName = "";
  string input = "";
  string value = "";
  vector <string> digits;
  int calibration = 0;
  int sum = 0;
  

  //Asks user to input a file
  cout << "Enter a file name" << endl << "**";
  cin >> fileName;

  //Attempts to open the requested file
  infile.open(fileName);

  //Checks for invalid file name and prompts user to retry
  while (!infile.is_open()) {
    cout << endl << "Error: Invalid file name." << endl;
    cout << "Enter a file name" << endl << "**";
    cin >> fileName;
    infile.open(fileName);
  }

  cout << endl;

  //Loops through the file and finds sum of all calibration values
  while (!infile.eof()) {

    //Retrieves individual line
    getline(infile, input);

    for (int i = 0; i < input.length(); i++) {
      
      if (isdigit(input[i])) {
        value = input[i];
        digits.push_back(value);
      }
    
    }

    //Converts strings to a single integer
    calibration = stoi(digits[0] + digits[digits.size() - 1]);
    sum = sum + calibration;
    digits.clear();
  }

  //Displays sum of all of the calibration values
  cout << "Sum = " << sum;

  //Closes file
  infile.close();

  return 0;
}