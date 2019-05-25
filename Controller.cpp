#include "Controller.h"
#include <iostream>
#include <fstream>


int Controller::addDogController(std::string& name, std::string& breed, double age, std::string& photograph)
{
	Dog dog{ name, breed, age, photograph };
	return this->getRepository().addDog(dog);
}

int Controller::updateDogController(std::string& name, std::string& breed, double age, std::string& photograph, std::string& link)
{
	Dog dog{ name, breed, age, photograph };
	int i = this->getRepository().updateDog(dog, link);
	return i;
}

int Controller::deleteDogController(std::string& photograph)
{
	int i = this->getRepository().deleteDog(photograph);
	return i;
}

vector<Dog> Controller::getAllDogsController()
{
	return this->getRepository().getAllDogs();
	this->getRepository().writeToFile();
}

int Controller::addToAdoptionListController(std::string & name, std::string & breed, double age, std::string & photograph)
{
	Dog dog{ name, breed, age, photograph };
	return this->getAdoption().addToAdoptionList(dog);
}

vector<Dog> Controller::getAllDogsByBreedAndAgeController(string& breed, double age)
{
	return this->getRepository().getAllDogsByBreedAndAge(breed, age);
}



