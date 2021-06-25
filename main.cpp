#include <stdio.h>
#include <string>
#include <iostream>
#include <ostream>
#include <cstring>
#include <algorithm>
#include <curl/curl.h> // URL downloading
#include <unistd.h>
#include <fstream> // File reading and writing
#include <ctime> // Time and date

using namespace std;

//https://curl.se/libcurl/c/url2file.html
static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  //cout << "Writing data..." << endl;
  return written;
}


bool string_in_array(char** _array, string _string, int numOfStrings) {
  for(int i = 0; i < numOfStrings; i++){
    if (_array[i] == _string) {
      return true;
    }
  }
  return false;
}

void downloadHTML(string url, const char* htmlFileName) {
  
  CURL *curl_handle;
  FILE *pagefile;

  curl_global_init(CURL_GLOBAL_ALL);

  curl_handle = curl_easy_init();

  
  curl_easy_setopt(curl_handle, CURLOPT_URL, url.c_str());
  
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);  
  pagefile = fopen(htmlFileName, "w");
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
void downloadImage(string url, const char* imageFileName) {
  
  CURL *curl_handle;
  FILE *pagefile;

  curl_global_init(CURL_GLOBAL_ALL);

  curl_handle = curl_easy_init();

  curl_easy_setopt(curl_handle, CURLOPT_URL, url.c_str());
  
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);  
  pagefile = fopen(imageFileName, "w");
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

  string htmlFileLocation = "apod.txt";
  
  string configFileName = "config.txt";
 
  string imageFileLocation = "";

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


  // If -d or --default is used as an argument
  if(string_in_array(argv, "-d", argc) || string_in_array(argv, "--default", argc)) {

    imageFileLocation = (string)get_current_dir_name();

    // Else use a config file
  } else {
    // Create a config.txt if it does not exist
    ifstream file_in(configFileName);
    if(!file_in.is_open()){
      cout << "Enter the save location for the image or leave blank to store in program directory." << endl;

      getline(cin, imageFileLocation);

      file_in.close();
      ofstream file_out(configFileName);
      file_out << imageFileLocation;
      file_out.close();

    }


    // Read from the config file
    ifstream file_in2(configFileName);
    file_in2 >> imageFileLocation;
    file_in2.close();

    //If the file is empty
    if(!strcmp(imageFileLocation.c_str(), "")) {

      imageFileLocation = (string)get_current_dir_name();

      // Write default location to file
      ofstream file_out2(configFileName);
      file_out2 << imageFileLocation;
      file_out2.close();
    }
    
  }


  // Set up datestring
  string dateString = "";
  
  tm* date;
  time_t t = time(NULL);
  date = localtime(&t);
  
  if(!strcmp(dateArg.c_str(), "")){

    if(shouldChooseRandom) {
      //date = random
    } else {
      //Year
      dateString += to_string(date->tm_year).substr(1, 2);

      //Month
      switch(date->tm_mon) {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
	dateString = dateString + "0" + to_string(date->tm_mon + 1);
	break;
      case 9:
      case 10:
      case 11:
	dateString = dateString + to_string(date->tm_mon + 1);
	break;
      }

      if (date->tm_mday >= 1 && date->tm_mday <= 9) {
	dateString = dateString + "0" + to_string(date->tm_mday);
      } else {
	dateString = dateString + to_string(date->tm_mday);
      }
      
    }

  } else {
    dateString += dateArg;
  }

  
  
  string url = "https://apod.nasa.gov/apod/ap" + dateString + ".html";
  
  downloadHTML(url, htmlFileLocation.c_str());
  cout << "Downloading HTML from:  " + url << endl; 

  //Check if it is a valid date and
  //Find part of the html that has the image URL
  string line = "";
  string targetText = "<a href=\"image";
  string error404 = "<title>404 Not Found</title>";
  ifstream htmlFile(htmlFileLocation);
  
  while(getline(htmlFile, line)) {
    if(line.find(error404) != string::npos) {
      cout << "Failed to download image. Make sure you choose a valid date." << endl;
      remove(htmlFileLocation.c_str());
      return 0;
    }
    if(line.find(targetText) != string::npos) {
      break;
    }
  }

  htmlFile.close();

  if(!strcmp(line.c_str(), "")){
    cout << endl << endl << "No image found on https://apod.nasa.gov/apod/ap" + dateString + ".html" << endl;
    cout << "Try again tomorrow!" << endl;
    remove(htmlFileLocation.c_str());
    return 0;
  }

  //Remove unwanted parts from URL
  int beginningIndex = line.find('i', 0);
  int endIndex = line.find('\"', beginningIndex);
  string imageUrlEnd = line.substr(beginningIndex, endIndex-beginningIndex);

  string imageUrl = "https://apod.nasa.gov/apod/" + imageUrlEnd;

  //TODO: Support for gifs
  imageFileLocation = imageFileLocation + "/apod_" + dateString + ".jpg";

  cout << "Downloading image:      " + imageUrlEnd << endl;
  cout << "Image URL:              " + imageUrl << endl;
  downloadImage(imageUrl, imageFileLocation.c_str());
  cout << "Image saved to " + imageFileLocation << endl;


  //Delete HTML file
  remove(htmlFileLocation.c_str());

  //TODO: Set as wallpaper

  
  return 0;
  
}
