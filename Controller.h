#pragma once
#include "Repository.h"
#include "AdoptionList.h"
#include <vector>

/*
This class creates the structure of a controller, from which all the functions in the repository are called.
It has a reference to a Repository data type, which contains the list of all pets.
*/
class Controller
{
	private:
		Repository repo;
		Adoption list;
	public:
		//constructor
		Controller(const Repository& r, Adoption& list): repo(r), list(list) {}
		Repository& getRepository() { return this->repo; }
		Adoption& getAdoption() { return this->list; }
		/*
		This function adds a pet in the repository.
		Input: strings containig the name of the new pet, its breed and a link to its photograph and its age.
		Output: 1 if the pet was successfully added to the list, 0 otherwise.
		*/
		int addDogController(std::string& name, std::string& breed, double age, std::string& photograph);
		/*
		This function deletes a certain pet from the repository.
		Input: the link to the photograph of the specific dog.
		Output: 1 if the pet was successfully deleted to the list, 0 otherwise.
		*/
		int deleteDogController(std::string& photograph);
		/*
		This function updates an existing pet from the repository with a new one.
		Input: strings containig the name of the new pet, its breed and a link to its photograph and its age..
		Output: 1 if the pet was successfully updated to the list, 0 otherwise.
		*/
		int updateDogController(std::string& name, std::string& breed, double age, std::string& photograph, std::string& link);
		/*
		This function returns the list containing all the pets from the repository.
		Input: -
		Output: A DynamicVector variable containing all the instances of the pets.
		*/
		vector<Dog> getAllDogsController();
		/*
		This function adds some dogs to the adoption list.
		Input: the attributes of a Dog object type.
		Output: 1 if the dog was successfully added, 0 otherwise.
		*/
		int addToAdoptionListController(std::string& name, std::string& breed, double age, std::string& photograph);
		/*
		This function retuns a list containing all the dogs from a given breed, having an age smaller than a given one.
		Input: a string containing the breed and a double containing the age.
		Output: A DynamicVector data type containing the filtered list.
		*/
		vector<Dog> getAllDogsByBreedAndAgeController(string& breed, double age);
		/*
		This function returns the adoption list.
		Input: -
		Output: A DynamicVector data type containing the adoption list.
		*/
		vector<Dog> getAllDogsFromAdoptionList() { return this->list.getAdoptionList(); }
};
