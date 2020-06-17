#pragma once
#include <vector>
#include <string>

/*
This class defines a database containing all the adopted pets.
It contains only a single private attribute, which represents the adoption list.
*/

class Adoption
{
	private:
		vector<Dog> list;
	public:
		Adoption() {}
		/*
		This function returns the adoption list.
		Input: - 
		Output: A vector containing the adoption list.
		*/
		vector<Dog>& getAdoptionList() { return this->list; }
		/*
		This function returns the index of a certain pet in the adoption list.
		Input: A Dog data type.
		Output: An integer data type containing the index.
		*/
		int getPositionAdoption(string& link)
		{
			for (int i = 0; i < this->list.size(); i++)
				if (this->list[i].getPhotograph() == link)
					return i;
			return -1;
		}
		/*
		This function adds a new pet to the adoption list.
		Input: A variable of type Dog.
		Output: 1 if the adding was successful, 0 otherwise.
		*/
		int addToAdoptionList(Dog& dog)
		{
			if (this->getPositionAdoption(dog.getPhotograph()) == -1)
			{
				this->list.push_back(dog);
				return 1;
			}
			return 0;
		}
};
