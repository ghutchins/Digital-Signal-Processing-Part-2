/**  
*  @file    signal.h
*  @author  Georgina Hutchins (hutcgb12)
*  @date    02/27/2014  
*  @version 1.0  
*
*  @brief CSC 112, Lab 5, Digital Signal Processing, Part 2
*
*  @section DESCRIPTION
*
*  The signal.h header file contains the function declarations
*  or prototypes that can be utilized in a digital signal 
*  processing program.
*
*  @bug No known bugs
*
*/



#ifndef SIGNAL_H
#define SIGNAL_H
#define MAX_SIZE 240000
#include <iostream>
#include "sound.h"
#include <cstdio>
using namespace std;



void clearScreen();


void myPause();


void displayMenu(int& option, bool& loaded);


void readFile(string fileName, short samples[], int MaxSize, int& numSamples);


void playSample(short samples[], int numSamples);


void displaySignal(int numSamples, short samples[]);


void adjustVolume(int numSamples, short samples[]);


void reverseAudio(int numSamples, short samples[]);


void compress(int& numSamples, short samples[]);


void stretch(int& numSamples, short samples[], int MaxSize);


void multiplex(string fileName2, short samples2[], int MaxSize, int& numSamples2, short samples[], int& numSamples);


#endif



