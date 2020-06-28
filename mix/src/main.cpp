#include<iostream>

#include "print.h"

int main(void)
{
	std::cout << "Hello CMake !" << std::endl;

	#ifdef USE_PRINT
		print();
	#endif

	return 0;
}