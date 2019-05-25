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
		int addDog(Dog& dog);
		/*
		This function deletes a pet from the database.
		Input: The link of the specified dog.
		Output: 1 if the removing was successful, 0 otherwise.
		*/
		int deleteDog(std::string& photograph);
		/*
		This function updates a pet from the database.
		Input: An object of type Dog, wchich will represent the new pet and the link of the old pet.
		Output: 1 if the updating was successful, 0 otherwise.
		*/
		int updateDog(Dog& dog, std::string& link); 
		/*
		This function returns the database containing all the pets.
		Input: -
		Output: A vector of pets.
		*/
		vector<Dog> getAllDogs() const { return repo; };
		/*
		This function returns the database containing all the pets with the specific attributes.
		Input: -
		Output: A vector of pets.
		*/
		vector<Dog> getAllDogsByBreedAndAge(string& breed, double age);
		/*
		This function returns the index of a pet in the database.
		Input: The link of the searched pet.
		Output: The index of the pet, if it is found and -1 otherwise.
		*/
		int getPosition(string& photograph);
		/*
		This function reads from a text file the entities of type Dog.
		Input: -
		Output: -
		*/
		void readFromFile();
		/*
		This function writes to a text file the entities of type Dog.
		Input: -
		Output: -
		*/
		void writeToFile();
		/*
		This function empties the content of the text file.
		Input: - 
		Output: -
		*/
		void emptyContent(const string& file);
};

