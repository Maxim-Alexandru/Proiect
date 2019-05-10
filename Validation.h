#pragma once
#include <string>

using namespace std;

class Validation
{
	public:
		static bool validName(const string& name);
		static bool validBreed(const string& breed);
		static bool validLink(const string& link);
		static bool validAge(const double age);
		static bool validOptionNumber(const int lower, const int upper, const int option);
};
