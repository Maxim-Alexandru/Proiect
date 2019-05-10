#include "Validation.h"
#include <iostream>

bool Validation::validName(const string& name)
{
	if (name == "")
		return false;
	return true;
}

bool Validation::validBreed(const string& breed)
{
	if (breed == "")
		return false;
	return true;
}

bool Validation::validLink(const string& link)
{
	if (link == "")
		return false;
	return true;
}

bool Validation::validAge(const double age)
{
	if (age <= 0)
		return false;
	return true;
}

bool Validation::validOptionNumber(const int lower, const int upper, const int option)
{
	if (option < lower || option > upper)
		return false;
	return true;
}