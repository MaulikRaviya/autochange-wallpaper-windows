#include <windows.h>
#include <iostream>
#include <fstream>
#include <shlobj.h>
#include <time.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include <time.h>

// #define WINDOWS  /* uncomment this line to use it for windows.*/
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

using namespace std;

string GetCurrentWorkingDir(void)
{
	char buff[FILENAME_MAX];
	GetCurrentDir(buff, FILENAME_MAX);
	std::string current_working_dir(buff);
	return current_working_dir;
}

bool setBackground();

const string strLocalDirectory = GetCurrentWorkingDir();

string filePath;
ofstream myfile;

int main(int argc, char *argv[]) // so no warnings about unref params
{
	myfile.open("log.txt");
	try
	{
		time_t timer = time(NULL);
		cout << "Time=" << timer;

		struct tm *aTime = localtime(&timer);
		int hour = aTime->tm_hour;
		int minute = aTime->tm_min;

		cout << "hour = " << hour;

		string wallFile;

		if (hour >= 6 && hour < 21)
		{
			wallFile = string("img1.jpg");
		} else {
			wallFile = string("img2.jpg");
		}

		filePath = wallFile;


		if (setBackground())
		{
			cout << "Applied Background: " << filePath << "\n";
		}
		else
		{
			DWORD DWLastError = GetLastError();
			cout << "\nError: " << std::hex << DWLastError;
		}

		myfile << "success";
	}
	catch (exception &e)
	{
		cout << e.what();
		myfile << e.what();
		return EXIT_FAILURE;
	}

	myfile.close();
	return EXIT_SUCCESS;
}

bool setBackground()
{
	int dirSize = 5;  //Will be automated later.
	int bgChoice = 0; //Index of chosen wallpaper.

	srand((unsigned int)time(NULL));
	bgChoice = rand() % dirSize + 1;

	//Convert the index choice into a usable filename string.
	stringstream ssFilePath;
	ssFilePath << strLocalDirectory << "\\" << filePath;

	cout << "Path: " << ssFilePath.str().c_str();
	myfile << "Path: " << ssFilePath.str().c_str();

	//Returns true on success, false otherwise.
	if (SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, (PVOID)ssFilePath.str().c_str(),
							  SPIF_UPDATEINIFILE | SPIF_SENDCHANGE) != 0)
	{
		filePath = ssFilePath.str();
		return true;
	}

	return false;
}