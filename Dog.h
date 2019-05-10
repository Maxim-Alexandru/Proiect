#pragma once
#include <iostream>
using namespace std;
/*
An instance of a Dog is defined by 4 attributes.
A string containing its breed.
A string containing its name.
A double containing its age.
A string which contains a link to the photograph of the pet.
*/
class Dog
{
private:
	string breed;
	string name;
	double age;
	string photograph;
	/*
	This function enables us to print an instance of a dog.
	Input: A Dog variable.
	Output: - 
	*/
public:
	Dog();
	Dog( const string& name, const string& breed, const double age, const string& photograph);
	string getBreed() const { return this->breed; }
	string getName() const { return this->name; }
	double getAge() const { return this->age; }
	string getPhotograph() const { return this->photograph; }
	void setBreed(const string& breed) { this->breed = breed; }
	void setName(const string& name) { this->name = name; }
	void setAge(const double age) { this->age = age; }
	void setPhotograph(const string& photograph) { this->photograph = photograph; }
};