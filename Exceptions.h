#pragma once
#include <string>
#include "Dog.h"

using namespace std;

class Exceptions
{
public:
	/*
	This function verifies if the attributes of an object of type Dog are valid.
	Input: An object of type Dog.
	Output: -
	Exception: Any exception regarding the attributes of the dog
	*/
	static void validateDog(Dog& dog);
};

