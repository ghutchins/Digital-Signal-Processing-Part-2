/**  
*  @file    signal.cpp  
*  @author  Georgina Hutchins (hutcgb12)
*  @date    02/27/2014  
*  @version 1.0  
*
*  @brief CSC 112, Lab 5, Digital Signal Processing, Part 2
*
*  @section DESCRIPTION
*
*  Signal.cpp is the source file that contains the function
*  definitions that can be utilized in a digital signal
*  processing program to perform various tasks on user input
*  audio data.
*
*  @bug No known bugs
*
*/



#include "signal.h"



/**
*  @brief clearScreen clears an Xterm window
*
*  @return void
*/
void clearScreen()
{
	 cout << char(27) << "[;H" << char(27) << "[2J" << '\n';
}



/**
*  @brief myPause pauses the program
*
*  @return void
*/
void myPause()
{
   cout << "Press return to continue. ";
   getchar();
   getchar();  
}



/**
*  @brief displayMenu creates a main menu for the user to select
*  from
*
*  @param option is the option (0-5) that the user enters
*  @param loaded indicates if the input file has been loaded
*
*  @return void
*/
void displayMenu(int& option, bool& loaded)
{
	clearScreen();

	cout << "      Digital Signal Processing Program" << '\n';
	cout << "      ---------------------------------" << '\n';
	cout << "1) Read audio data from file    5) Play-audio" << '\n';
	cout << "2) Display signal		6) Multiplex" << '\n';
	cout << "3) Adjust volume		7) Compress" << '\n';
	cout << "4) Reverse-audio		8) Stretch" << '\n';
	cout <<	"		    0) Quit" << '\n' << endl;
	cout << "Enter option (0 - 8) - >";
	cin >> option;



	if (option == 1 || option == 0)
	{
		loaded = true;
	}
}



/**
*  @brief readFile reads audio data from a file
*
*  @param fileName is the name of the file
*  @param samples is the array of PCM samples
*  @param MaxSize is the physical size of the array
*  @param numSamples is the number of PCM samples in the array (logical size)
*
*  @return void
*/
void readFile(string fileName, short samples[], int MaxSize, int& numSamples)
{
	clearScreen();
	cout << "Read PCM Data from File" << '\n';
	cout << "Enter .au file name ->  ";
	cin >> fileName;

	readAuFile(fileName, samples, MaxSize, numSamples);

	cout << "Reading the .au file: " << fileName << '\n';
	cout << numSamples << " samples read signal duration " << (numSamples / 8000.0) << '\n';
	myPause();

}



/**
*  @brief displaySignal will display a segment of the signal
*
*  @param numSamples is the logical size of the array
*  @param samples is an array of PCM samples
*
*  @return void
*/
void displaySignal(int numSamples, short samples[])
{
	clearScreen();
	int startIndex;		///< First index of segment to be displayed
	int stopIndex;		///< Last index of segment to be displayed
	int numSymbol;		///< Number of symbols which represent sample value
	short temp;		///< Temporary variable to interchange start and stop indexes
	
	cout << "Signal Display" << '\n';
	cout << "Enter the start and stop index for the segment" << '\n';
	cout << "values range from 1 to " << numSamples << '\n' << '\n';
	cout << "Enter the start index -> ";
	cin >> startIndex;
	cout << "Enter the stop index -> ";
	cin >> stopIndex;
	cout << '\n';
	
	if (startIndex > stopIndex)
	{
		temp = startIndex;
		startIndex = stopIndex;
		stopIndex = temp;
	}

	if ((startIndex > 0 && stopIndex <= 0) || (startIndex < 0 && stopIndex >= 0) || (startIndex <= 0 && stopIndex <= 0))
	{
		clearScreen();
		cout << "Signal Display" << '\n';
		cout << "Enter the start and stop index for the segment" << '\n';
		cout << "values range from 1 to " << numSamples << '\n' << '\n';
		cout << "Enter the start index -> ";
		cin >> startIndex;
		cout << "Enter the stop index -> ";
		cin >> stopIndex;
		cout << '\n';
	}

	if (startIndex >= 0 && stopIndex >= 0)
	{
		for  (int i= startIndex; i < stopIndex; i++)
		{
			cout << i << '(' << samples[i] << ") : ";
			numSymbol = (samples[i] / 100);

			if (numSymbol > 0)
			{
				for (int j = 0; j < numSymbol; j++)
					cout << '>';
			}
			else if (numSymbol < 0)
			{
				numSymbol = (numSymbol * -1);
				for (int p = 0; p < numSymbol; p++)
					cout << '<';
			}
			else if (numSymbol == 0)
			{
				cout << ' ';
			}
			cout << '\n';
		}
	}

	myPause();
}



/**
*  @brief adjustVolume is a function that prompts the user for 
*  a value to adjust the audio volume
*  @param numSamples is the logical size of the array
*  @param samples is an array of PCM samples
*
*  @return void
*/
void adjustVolume(int numSamples, short samples[])
{
	clearScreen();
	float input;		///< Value entered by the user to adjust volume

	cout << "Adjust Volume" << '\n';
	cout << "Anything less than 1.0 decreases the volume, anything greater increases the volume" << '\n';
	cout << "Enter any value between 0 and 10 to adjust the volume: ";
	cin >> input;

	if (input > 10.0 || input < 0.0)
	{
		cout << "Error" << '\n';
		cout << "Enter a valid value between 0 and 10 to adjust the volume: ";
		cin >> input;
	}

		if (input < 1.0 && input > 0.0)
		{
			for(int i = 0; i < numSamples; i++)
			{
				samples[i] = (samples[i] * input);
			}
		cout << "The volume has been decreased" << '\n';
		}

		else if (input >= 1.0 && input <= 10.0)
		{
			for(int j = 0; j <= numSamples; j++)
			{
				samples[j] = (samples[j] * input);
			}
		cout << "The volume has been increased" << '\n';
		}

	myPause();
}



/**
*  @brief reverseAudio reverses the PCM samples in the array
*
*  @param numSamples is the logical size of the array
*  @param samples is an array of PCM samples
*
*  @return void
*/
void reverseAudio(int numSamples, short samples[])
{
	clearScreen();

	short temp;			 ///< Temporary variable to reverse values
	int lastIndex = (numSamples - 1);///< Last index of the array

	for(int i = 0; i < (lastIndex/ 2); i++)
	{
		temp = samples[i];
		samples[i] = samples[lastIndex - i];
		samples[lastIndex - i] = temp;
	}

	cout << "Total number of samples in the signal: " << numSamples << '\n';
	cout << "Signal duration: " << (numSamples / 8000.0) << '\n';

	myPause();
}



/**
*  @brief playSample plays the PCM audio data in the array
*
*  @param samples is an array of PCM samples
*  @param numSamples is the logical size of the array
*
*  @return void
*/
void playSample(short samples[], int numSamples)
{
	clearScreen();

	cout << "Total number of samples in the signal: " << numSamples << '\n';
	cout << "Signal duration: " << (numSamples/ 8000.0) << '\n';

	playPCMsamples(samples, numSamples);

	myPause();
}



/**
*  @brief multiplex adds two audio arrays together element-
*  by-element
*
*  @param fileName2 is the name of the second file input by user
*  @param samples2 is the second array of PCM samples
*  @param MaxSize is the physical size of the arrays
*  @param numSamples2 is the logical size of array samples2
*  @param samples is the first array of PCM samples
*  @param numSamples is the logical size of array samples
*
*  @return void
*/
void multiplex(string fileName2, short samples2[], int MaxSize, int& numSamples2, short samples[], int& numSamples) 
{
	clearScreen();

	cout << "Multiplex Audio \n";
	cout << "Enter name of second .au file -> ";
	cin >> fileName2;

	readAuFile(fileName2, samples2, MaxSize, numSamples2);
	
	cout << "Reading the .au file: " << fileName2 << '\n';
	cout << fileName2 << " has " << numSamples2 << " samples \n";
	
	
	if (numSamples > numSamples2)
	{
		for (int i= 0; i < numSamples2; i++)
		{
			samples[i] += samples2[i];
		}
	}
	else
	{
		for (int i= 0; i < numSamples; i++)
		{
			samples2[i] += samples[i];
		}
		for (int i= 0; i < numSamples2; i++)
		{
			samples[i] = samples2[i];
		}

		numSamples = numSamples2;
	}

	cout << "After multiplexing, \n";
	cout << "  new audio has " << (numSamples) << " samples and duration of " << ((numSamples) / 8000.0) << " seconds" << '\n' << endl;

	myPause();
}



/**
*  @brief compress compresses the contents of the array by
*  removing every other audio sample stored in the array
*
*  @param numSamples is the logical size of the array
*  @param samples is the array of PCM samples
*
*  @return void
*/
void compress(int& numSamples, short samples[])
{
	clearScreen();

	short temp[MAX_SIZE];	///< Temporary array to compress samples array
	int j= 0;		///< Counter varaible for number of elements in array

	for (int i= 0; i < numSamples; i = i + 2)
	{
		temp[j] = samples[i];
		j++;
	}

	numSamples = j;

	for (int i = 0; i < numSamples; i++)
	{
		samples[i] = temp[i];
	}

	cout << "Compress Audio \n";
	cout << "After compressing, \n";
	cout << "  audio has " << numSamples << " samples and duration of " << (numSamples / 8000.0) << " seconds" << '\n'<< endl;

	myPause();

}



/**
*  @brief stretch stretches the contents of an array by
*  duplicating every audio sample stored in that array
*
*  @param numSamples is the logical size of the array
*  @param samples is the array of PCM samples
*  @param MaxSize is the physical size of the array
*/
void stretch(int& numSamples, short samples[], int MaxSize)
{
	clearScreen();

	short temp[MAX_SIZE];	///< Temporary array to duplicate samples array
	int j= 0;		///< Counter varaible for number of elements in array

	for (int i= 0; i < numSamples; i++)
	{
		temp[j] = samples[i];
		j++;
		if (j < MaxSize)
		{
			temp[j] = samples[i];
			j++;
		}
	}

	numSamples = j;	

	for (int i= 0; i < numSamples; i++)
	{
		samples[i] = temp[i];
	}

	cout << "Stretch audio \n";
	cout << "After stretching, \n";
	cout << "  audio has " << numSamples << " samples and duration of " << (numSamples / 8000.0) << " seconds" << '\n'<< endl;
	
	myPause();
}




















