#include "Dog.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Dog::Dog() :  name(""), breed(""), age(0), photograph("") {}
Dog::Dog(const string& name,const string& breed,const double& age,const string& photograph)
{
	this->breed = breed;
	this->name = name;
	this->age = age;
	this->photograph = photograph;
}

vector<string> tokenize(string str) {
	stringstream ss(str);
	string token;
	vector<string> result;
	while (getline(ss, token, ','))
		result.push_back(token);
	return result;
}

istream & operator>>(istream & is, Dog & d)
{
	string line;
	getline(is, line);
	vector<string> v = tokenize(line);
	if (v.size() != 4)
		return is;
	d.name = v[0];
	d.breed = v[1];
	d.age = stod(v[2]);
	d.photograph = v[3];
	return is;
}

ostream & operator<<(ostream & os, Dog & d)
{
	os << d.getName() << " - " << d.getBreed() << " - " << d.getAge() << + " - " + d.getPhotograph()<< "\n";
	return os;
}
