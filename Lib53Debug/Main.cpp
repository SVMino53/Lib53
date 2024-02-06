// Lib53 
// Created by Isak "Mino53" Forsberg, 2024-01-16
// V 0.1, 2024-02-06

// Main source file used to test and debug Lib53.


#include <iostream>

#include "Lib53.h"
#include "Test.h"


int main()
{
	if (!Test::RunTest())
	{
		std::cout << "Uh oh! O_o";
	}

	return 0;
}