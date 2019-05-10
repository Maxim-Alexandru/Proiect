#pragma once
#include "Dog.h"
#include <vector>
class Repository
{
	private:
		vector<Dog> repo;
	public:
		Repository() {}
		/*
		This function returns the database of pets.
		Input: -
		Output: A vector containing the database.
		*/
		vector<Dog>& getVector() { return this->repo; }
		/*
		This function adds a pet in the repository.
		Input: A Dog data type containig the pet.
		Output: 1 if the adding was successful, 0 otherwise.
		*/
		int addDog(const Dog& dog);
		int deleteDog(const std::string& photograph);
		int updateDog(const Dog& dog, const std::string& link); 
		vector<Dog> getAllDogs() const { return repo; };
		vector<Dog> getAllDogsByBreedAndAge(const string& breed, const double age);
		int getPosition(const string& photograph);
};

