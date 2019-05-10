#include "Controller.h"

int Controller::addDogController(const std::string& name, const std::string& breed, const double age, const std::string& photograph)
{
	Dog dog{ name, breed, age, photograph };
	return this->getRepository().addDog(dog);
}

int Controller::updateDogController(const std::string& name, const std::string& breed, const double age, const std::string& photograph, const std::string& link)
{
	Dog dog{ name, breed, age, photograph };
	int i = this->getRepository().updateDog(dog, link);
	return i;
}

int Controller::deleteDogController(const std::string& photograph)
{
	int i = this->getRepository().deleteDog(photograph);
	return i;
}

vector<Dog> Controller::getAllDogsController()
{
	return this->getRepository().getAllDogs();
}

int Controller::addToAdoptionListController(const std::string & name, const std::string & breed, const double age, const std::string & photograph)
{
	Dog dog{ name, breed, age, photograph };
	return this->getAdoption().addToAdoptionList(dog);
}

vector<Dog> Controller::getAllDogsByBreedAndAgeController(const string& breed, const double age)
{
	return this->getRepository().getAllDogsByBreedAndAge(breed, age);
}

