#include<iostream>

#include "myecho/echo.h"
#include "myprint/print.h"


int main(void)
{
	std::cout << "Hello CMake !" << std::endl;

	print();
	echo();
	return 0;
}