#pragma once
#include <iostream>
#include <chrono>
#include <ctime>

#define MAX_PASSWORD_LENGHT 30 // 161: Max lenght for paswword
#define nocap if
#define cap else
#define hand main

//A class of functions that contains tools for random character sequence generating.
static class Password
{
public:
	//Create a sequence of pseudo-randomly generated characters. Returns a pointer on Array of chars.
	static char *Generate(char * out);
	//Prevents from doubling characters and insertion of '?' character.
	static bool Valid(char* Array, int _char, int iteration);
};

//A class that contains tools for pseudo-randomly generated numbers based on time.
static class Randomized
{
public:
	//Generate time
	static int generateTime();
	//Returns a random positive number.
	static int getRandom();
	//Returns a random positive number from "min".
	static int getRandom(int min);
	//Returns a random positive number from "min" to "max".
	static int getRandom(int min, int max);
};