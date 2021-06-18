#include <stdio.h>
#include <string>
#include <iostream>
#include <ostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool string_in_array(char** _array, string _string, int numOfStrings) {
  for(int i = 0; i < numOfStrings; i++){
    if (_array[i] == _string) {
      return true;
    }
  }
  return false;
}


int main(int argc, char *argv[]) {
  string dateArg = "";
  bool shouldChooseRandom = false;

  // Start at the argument at index 1 (0 index is the command that was run)
  for(int argument = 1; argument < argc; argument++) {
    int dateInt = -1;

    try {
      dateInt = stoi(argv[argument]); // Returns -1 if invalid
    } catch(invalid_argument) { }

    if(dateInt != -1) {
      dateArg == argv[argument];
      continue;
    }

    //Check for invalid arguments
    if (strcmp(argv[argument], "-d") && strcmp(argv[argument], "--default") && strcmp(argv[argument], "-r") && strcmp(argv[argument], "--random") && strcmp(argv[argument], "-h") && strcmp(argv[argument], "--help") && strcmp(argv[argument], "-nw") && strcmp(argv[argument], "--no-wallpaper")) {
       cout << "Invalid arguments. Use -h or --help to see available arguments" << endl;
       return 0;
    }
    
  }

  // If -h or --help is used as an argument
  if(string_in_array(argv, "-h", argc) || string_in_array(argv, "--help", argc)) {
    cout << "Usage:   -h   or  --help             Help Menu" << endl;
    cout << "         -nw  or  --no-wallpaper     Do not set as wallpaper" << endl;
    cout << "         -r   or  --random           Random image" << endl;
    cout << "         -d   or  --default          Save in this directory and do not create config file" << endl;
    cout << "         YYMMDD                      Specify a date in YYMMDD format" << endl;
    return 0;
  }

  if(string_in_array(argv, "-r", argc) || string_in_array(argv, "--help", argc)) {
    cout << "Choosing random image..." << endl;
    shouldChooseRandom = true;
  }

  string htmlFileLocation = "apod.txt";
  string configFileLocation = "config.txt";
  string imageFileName = "apod.jpg";

  string imageFileLocation = "";

  // If -d or --default is used as an argument
  if(string_in_array(argv, "-h", argc) || string_in_array(argv, "--help", argc)) {
    //TODO: imageFileLocation is here
  } else {
    //TODO: Create a config.txt if it does not exist

    //TODO: Read from the config file
  }
  
}
