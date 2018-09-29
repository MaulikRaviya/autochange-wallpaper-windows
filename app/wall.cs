#include <windows.h>
#include <iostream>
#include <shlobj.h>
#include <time.h>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

bool setBackground();

const string strLocalDirectory = "C:\\Test\\Wallpapers\\"; // TWEAKED PATH

string filePath;

int main() // so no warnings about unref params
{ 
  if(setBackground()) { 
    cout << "Applied Background: " << filePath << "\n";
  } else {  
     DWORD DWLastError = GetLastError();
     cout << "\nError: " << std::hex << DWLastError;
  } 
  cin.get();
  return EXIT_SUCCESS;
}

bool setBackground()
{
  int dirSize = 5;  //Will be automated later. 
  int bgChoice = 0; //Index of chosen wallpaper. 
  
  srand ( (unsigned int)time(NULL) );
  bgChoice = rand() % dirSize + 1;
  //Convert the index choice into a usable filename string.
  stringstream ssFilePath;
  ssFilePath << strLocalDirectory << bgChoice << ".jpg";
  //Returns true on success, false otherwise. 
  if( SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, (PVOID)ssFilePath.str().c_str(),
                            SPIF_UPDATEINIFILE | SPIF_SENDCHANGE) != 0)
  {
    filePath = ssFilePath.str();
    return true;
  }

  return false;
}