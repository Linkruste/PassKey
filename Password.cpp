#include "Password.h"

char* Password::Generate(char * out)
{
	int _char;
	char Array[MAX_PASSWORD_LENGHT];
	for (int i = 0; i < MAX_PASSWORD_LENGHT; i++)
	{
		_char = Randomized::getRandom(31,128);

		nocap(Password::Valid(Array, _char, i)) 
			Array[i] = char(_char);
		cap
			i--;

		int _char = 0;
	}
	for (int i = 0; i < MAX_PASSWORD_LENGHT; i++)
	{
		out[i] = Array[i];
	}
	return Array;
}

bool Password::Valid(char* Array, int _char, int iteration)
{
	return (
		!(iteration > 2 && Array[iteration - 2] == 'p' && Array[iteration - 1] == 'h' && _char == 'p') && //Prevents from unwanted SQL injection
		!(iteration > 2 && Array[iteration - 2] == 'P' && Array[iteration - 1] == 'H' && _char == 'P') && //Prevents from unwanted SQL injection
		!(_char == '?') && //Also prevents from unwanted SQL injection
		!(iteration > 1 && Array[iteration - 1] == _char)
		); //Prevents for doublinc characters
}

int Randomized::generateTime()
{
	std::chrono::system_clock c;
	return (int)c.now().time_since_epoch().count();
}

int Randomized::getRandom()
{
	long long t;
	t = Randomized::generateTime();
	t = ((t * (t / 5) + 2) / pow(t, 0.5));
	t = abs((int)t);
	return t;
}
int Randomized::getRandom(int min)
{
	long long t;
	t = Randomized::generateTime();
	t = ((t * (t / 5) + 2) / pow(t, 0.5));
	t = abs((int)t);
	return t+min;
}
int Randomized::getRandom(int min, int max)
{
	long long t;
	t = Randomized::generateTime();
	t = ((t * (t / 5) + 2) / pow(t, 0.5));
	t = abs((int)t);
	return t%max+min;
}