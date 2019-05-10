#include "Repository.h"
#include <string>
#include <vector>

using namespace std;

int Repository::getPosition(const string& photograph)
{
	for (int i = 0; i < this->getVector().size(); i++)
		if (this->getVector()[i].getPhotograph() == photograph)
			return i;
	return -1;
}

int Repository::addDog(const Dog& dog)
{
	if (this->getPosition(dog.getPhotograph()) == -1)
	{
		this->getVector().push_back(dog);
		return 1;
	}
	return 0;
}

int Repository::deleteDog(const std::string& photograph)
{
	int i = this->getPosition(photograph);
	if (i != -1) 
	{
		this->getVector().erase(this->getVector().begin() + i);
		return 1;
	}
	return 0;
}

int Repository::updateDog(const Dog& dog, const std::string& link)
{
	int i = this->getPosition(link);
	if (this->getPosition(dog.getPhotograph()) == -1)
	{
		this->getVector()[i].setAge(dog.getAge());
		this->getVector()[i].setBreed(dog.getBreed());
		this->getVector()[i].setName(dog.getName());
		this->getVector()[i].setPhotograph(dog.getPhotograph());
		return 1;
	}
	return 0;
}

vector<Dog> Repository::getAllDogsByBreedAndAge(const string& breed, const double age)
{
	vector<Dog> list;
	if (breed == "")
		return this->getAllDogs();
	for (int i = 0; i < this->getVector().size(); i++)
		if (this->getVector()[i].getBreed() == breed && this->getVector()[i].getAge() < age)
			list.push_back(this->getVector()[i]);
	return list;

}





