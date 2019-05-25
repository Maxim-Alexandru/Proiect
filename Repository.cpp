#include "Repository.h"
#include <string>
#include <vector>
#include "Exceptions.h"
#include <fstream>

using namespace std;

int Repository::getPosition(string& photograph)
{
	for (int i = 0; i < this->getVector().size(); i++)
		if (this->getVector()[i].getPhotograph() == photograph)
			return i;
	return -1;
}

int Repository::addDog( Dog& dog)
{
	string s = dog.getPhotograph();
	Exceptions::validateDog(dog);
	if (this->getPosition(s) == -1)
	{
		this->getVector().push_back(dog);
		this->writeToFile();
		return 1;
	}
	return 0;
}

int Repository::deleteDog(std::string& photograph)
{
	int i = this->getPosition(photograph);
	if (i != -1) 
	{
		this->getVector().erase(this->getVector().begin() + i);
		this->writeToFile();
		return 1;
	}
	return 0;
}

int Repository::updateDog(Dog& dog, std::string& link)
{
	int i = this->getPosition(link);
	string s = dog.getPhotograph();
	if (this->getPosition(s) == -1)
	{
		this->getVector()[i].setAge(dog.getAge());
		s = dog.getBreed();
		this->getVector()[i].setBreed(s);
		s = dog.getName();
		this->getVector()[i].setName(s);
		s = dog.getPhotograph();
		this->getVector()[i].setPhotograph(s);
		this->writeToFile();
		return 1;
	}
	return 0;
}

vector<Dog> Repository::getAllDogsByBreedAndAge(string& breed, double age)
{
	vector<Dog> list;
	if (breed == "")
		return this->getAllDogs();
	for (int i = 0; i < this->getVector().size(); i++)
		if (this->getVector()[i].getBreed() == breed && this->getVector()[i].getAge() < age)
			list.push_back(this->getVector()[i]);
	return list;

}

void Repository::readFromFile()
{
	ifstream f("DatabaseForReading.txt");
	if (!f.is_open())
		return;
	Dog d{};
	while (!f.eof())
	{
		f >> d;
		this->addDog(d);
	}
}

void Repository::writeToFile()
{
	this->emptyContent("DatabaseForWriting.txt");
	ofstream f("DatabaseForWriting.txt", ios::app);
	if (!f.is_open())
		return;
	for (int i = 0; i < this->getVector().size(); i++)
		f << this->getVector()[i];
}

void Repository::emptyContent(const string& file)
{
	std::ofstream ofs;
	ofs.open(file, std::ofstream::out | std::ofstream::trunc);
	ofs.close();
}






