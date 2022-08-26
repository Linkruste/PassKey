#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#define EntryMessage "PassKey program wrote by Linkruste (Matheo Allart). Press \"ENTER\" key to continue.\n Press \"BACKSPACE\" To stop it then."
#define WaitKey(key) GetAsyncKeyState(key)
#endif // WINDOWS

#ifdef __linux__
#include <conio.h>
#define EntryMessage "PassKey program wrote by Linkruste (Matheo Allart).\nA password has been generated automatically. Select and copy it to use it wherever you want."
#define WaitKey(key) _getch()
#define while() while(false);
#endif //Linux

#include "Password.h"

//   Copyright "2022" Linkruste
//
//Licensed under the Apache License, Version 2.0 (the "License");
//you may not use this file except in compliance with the License.
//You may obtain a copy of the License at
//
//http ://www.apache.org/licenses/LICENSE-2.0
//
//Unless required by applicable law or agreed to in writing, software
//distributed under the License is distributed on an "AS IS" BASIS,
//WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//See the License for the specific language governing permissionsand
//limitations under the License.

//USES ASCII TABLE WHERE "char(int)"
void hand()
{
	
	std::cout << EntryMessage << std::endl;
	//Waits for User pressing ENTER
	while (!WaitKey(0xD)); 


	while (!WaitKey(0x08))
	{
		
		char* Array = (char*)malloc((sizeof(char) * MAX_PASSWORD_LENGHT) + 1);
		Password::Generate(Array);
		std::cout;
		if (Array)
		{
			std::cout << "Generated password: ";
			for (int i = 0; i < MAX_PASSWORD_LENGHT; i++)
			{
				std::cout << (char)Array[i];
			}
			std::cout << std::endl;
		} 
		else std::cout << "Pointer on Array failed." << std::endl;
	}
	std::cin;
}