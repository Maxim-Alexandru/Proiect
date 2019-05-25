#pragma once
#include <string>

using namespace std;

class Validation
{
	public:
		static bool validName(string& name);
		static bool validBreed(string& breed);
		static bool validLink(string& link);
		static bool validAge(double age);
		static bool validOptionNumber(int lower, int upper, int option);
};
