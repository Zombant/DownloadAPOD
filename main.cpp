#include <stdio.h>
#include <string>
#include <iostream>
#include <ostream>
#include <cstring>
#include <algorithm>
#include <curl/curl.h>

//https://curl.se/libcurl/c/url2file.html
static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}

using namespace std;

bool string_in_array(char** _array, string _string, int numOfStrings) {
  for(int i = 0; i < numOfStrings; i++){
    if (_array[i] == _string) {
      return true;
    }
  }
  return false;
}

void downloadHTML(string date, const char* htmlFileName) {
  
  CURL *curl_handle;
  FILE *pagefile;

  curl_global_init(CURL_GLOBAL_ALL);

  curl_handle = curl_easy_init();

  string url = "https://apod.nasa.gov/apod/ap" + date + ".html";
  curl_easy_setopt(curl_handle, CURLOPT_URL, url.c_str());

  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);  
  pagefile = fopen(htmlFileName, "wb");
  if(pagefile) {
 
    /* write the page body to this file handle */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, pagefile);
 
    /* get it! */
    curl_easy_perform(curl_handle);
 
    /* close the header file */
    fclose(pagefile);
  }
 
  /* cleanup curl stuff */
  curl_easy_cleanup(curl_handle);
 
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
      dateArg = argv[argument];
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

  const char* htmlFileName = "apod.txt";
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

  downloadHTML(dateArg, htmlFileName);

  return 0;
  
}
