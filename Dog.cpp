#include "Dog.h"
using namespace std;

Dog::Dog() :  name(""), breed(""), age(0), photograph("") {}
Dog::Dog(const string& name, const string& breed, const double age, const string& photograph)
{
	this->breed = breed;
	this->name = name;
	this->age = age;
	this->photograph = photograph;
}
