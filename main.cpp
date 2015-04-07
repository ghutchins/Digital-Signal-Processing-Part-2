/**  
*  @file    main.cpp  
*  @author  Georgina Hutchins (hutcgb12)
*  @date    02/27/2014  
*  @version 1.0  
*
*  @brief CSC 112, Lab 5, Digital Signal Processing, Part 2
*
*  @section DESCRIPTION
*
*  This program performs various tasks on audio data, upon user's
*  request. After the program has loaded the audio data from the
*  user's file, the main menu will allow the user to choose 
*  from different options to perform tasks on the audio file.
*
*  @bug No known bugs
*
*/

#include <iostream>
#include <cstdio>
#include "signal.h"
#include "sound.h"
#define MAX_SIZE 240000
using namespace std;



int main()
{
	int option;		///< Main menu options for user to select		
	bool loaded = false;	///< Boolean indicating if the file has been loaded
	string fileName;	///< Name of user input file	
	int numSamples;		///< Number of PCM samples (logical size of array)
	short samples[MAX_SIZE];///< Array of PCM samples
	int MaxSize = MAX_SIZE; ///< Maximum number of elements in samples (physical size)
	short samples2[MAX_SIZE];///< Another array of PCM samples
	int numSamples2;	///< Number of PCM samples in samples2 (logical size of array)
	string fileName2;	///< Name of another user input file
	
	displayMenu(option, loaded);

	while (option != 0)
	{
		if (option == 1)
		{
			readFile(fileName, samples, MaxSize, numSamples);
			displayMenu(option, loaded);
		}
		if (option == 2 && loaded)
		{
			displaySignal(numSamples, samples);
			displayMenu(option,loaded);
		}
		if (option == 3 && loaded)
		{
			adjustVolume(numSamples, samples);
			displayMenu(option, loaded);
		}
		if (option == 4 && loaded)
		{
			reverseAudio(numSamples, samples);
			displayMenu(option, loaded);
		}
		if (option == 5 && loaded)
		{
			playSample(samples, numSamples);
			displayMenu(option, loaded);
		}
		if (option == 6 && loaded)
		{
			multiplex(fileName2, samples2, MaxSize, numSamples2, samples, numSamples);
			displayMenu(option, loaded);
		}
		if (option == 7 && loaded)
		{	compress(numSamples, samples);
			displayMenu(option, loaded);
		}
		if (option == 8 && loaded)
		{
			stretch(numSamples, samples, MaxSize);
			displayMenu(option, loaded);
		}
		else if (loaded == false)
		{
			displayMenu(option, loaded);
		}

	}
	
	return 0;
}



