#include "Validation.h"
#include <iostream>

bool Validation::validName(string& name)
{
	if (name == "")
		return false;
	return true;
}

bool Validation::validBreed( string& breed)
{
	if (breed == "")
		return false;
	return true;
}

bool Validation::validLink(string& link)
{
	if (link == "")
		return false;
	return true;
}

bool Validation::validAge(double age)
{
	if (age <= 0)
		return false;
	return true;
}

bool Validation::validOptionNumber(int lower, int upper, int option)
{
	if (option < lower || option > upper)
		return false;
	return true;
}