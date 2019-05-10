#include "UI.h"
#include <iostream>
#include <sstream>
#include <typeinfo>
#include <Windows.h>
#include <shellapi.h>
#include <vector>

using namespace std;

string UI::readName(const string& message)
{
	string name;
	cout << message;
	getline(cin, name);
	while (this->getValidation().validName(name) == false)
	{
		UI::printMessages("The name that you typed is not valid. Please enter another one: ");
		getline(cin, name);
	}
	return name;
}

string UI::readBreed(const string& message)
{
	string breed;
	cout << message;
	getline(cin, breed);
	while (this->getValidation().validBreed(breed) == false)
	{
		UI::printMessages("The breed that you typed is not valid Please enter another one: ");
		getline(cin, breed);
	}
	return breed;
}

string UI::readLink(const string& message)
{
	string link;
	cout << message;
	getline(cin, link);
	while (this->getValidation().validLink(link) == false)
	{
		UI::printMessages("The link that you typed is not valid. Please enter another one: ");
		getline(cin, link);
	}
	return link;
}

double UI::readAge(const string& message)
{
	double age;
	cout << message;
	cin >> age;
	while (this->getValidation().validAge(age) == false)
	{
		UI::printMessages("Please introduce a valid age for the pet: ");
		cin >> age;
	}
	return age;
}

int UI::readOptionNumber(const int lower, const int upper)
{
	int option;
	UI::printMessages("------------------------------------------------------ \nPlease choose a mode: ");
	cin >> option;
	while (this->getValidation().validOptionNumber(lower, upper, option) == false)
	{
		UI::printMessages("Please introduce a valid option: ");
		cin >> option;
	}
	UI::printMessages("------------------------------------------------------ \n \n");
	return option;
}

void UI::printMenuUser()
{
	cout << "Please select one of the following options: \n";
	cout << "\t 1) See the dogs in the database. \n";
	cout << "\t 2) See all dogs of the given breed, having the age less than a given value. \n";
	cout << "\t 3) Visualize your adoption list. \n";
	cout << "\t 0) Exit. \n \n";
}

void UI::printMenu()
{
	cout << "Please select an interactive mode: \n";
	cout << "\t 1) Administrator mode. \n";
	cout << "\t 2) User mode. \n \n";
}


void UI::printMenuAdministrator()
{
	cout << "These are the following options: \n";
	cout << "\t 1) Add a pet in the list. \n";
	cout << "\t 2) Delete a pet from the repository. \n";
	cout << "\t 3) Update a certain pet from the list. \n";
	cout << "\t 4) Get the list of all pets. \n";
	cout << "\t 0) Exit the menu. \n \n";
}

void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command = this->readOptionNumber(0, 2);
		cin.ignore();
		if (command == 0)
		{
			cout << "\n \n";
			break;
		}
		if (command == 1)
		{
			while (true)
			{
				UI::printMenuAdministrator();
				int command = this->readOptionNumber(0, 4);
				cin.ignore();
				if (command == 0)
					break;
				switch (command)
				{
				case 1:
				{
					string name = this->readName("Please enter the name of the pet you want to add: ");
					string breed = this->readBreed("Please enter the breed of the pet: ");
					string photograph = this->readLink("Please enter the link that will open the photograph of the pet: ");
					double age = this->readAge("Please enter the age of the pet: ");
					if (this->getController().addDogController(name, breed, age, photograph) == 1)
						UI::printMessages("------------------------------------------------------\nThe pet was successfully added to the list. \n ------------------------------------------------------ \n");
					else
						UI::printMessages("------------------------------------------------------ \nError! The pet already exists in the list. \n ------------------------------------------------------ \n \n");
					break;
				}
				case 2:
				{
					string photograph = this->readLink("Please enter the link of the pet you want to remove: ");
					if (this->getController().deleteDogController(photograph) == 1)
						cout << "------------------------------------------------------ \nThe pet was successfully deleted to the repository. \n ------------------------------------------------------ \n";
					else
						cout << "------------------------------------------------------ \nError! The pet does not exist in the repository. \n ------------------------------------------------------ \n \n";
					break;
				}
				case 3:
				{
					string name = this->readName("Please enter the name of the new pet: ");
					string breed = this->readBreed("Please enter the breed of the new pet: ");
					string photograph = this->readLink("Please enter the link that will open the photograph of the pet: ");
					string link = this->readLink("Please enter the link of the pet you want to update: ");
					double age = this->readAge("Please enter the age of the new pet: ");
					if (this->getController().updateDogController(name, breed, age, photograph, link) == 1)
						cout << "------------------------------------------------------ \nThe pet was successfully updated to the repository. \n ------------------------------------------------------ \n";
					else
						cout << "------------------------------------------------------ \n \nError!The pet already exists in the repository. \n ------------------------------------------------------ \n \n";
					break;
				}
				case 4:
				{
					vector<Dog> list = this->getController().getAllDogsController();
					cout << "------------------------------------------------------ \nThis is the list of all pets: \n \n";
					for (int i = 0; i < list.size(); i++)
					{
						Dog d = list[i];
						if (d.getAge() < 1)
							cout << "\tThe pet number " << i + 1 << " is " << d.getName() << ". It is from the race " << d.getBreed() << " and it is " << d.getAge() * 10 <<" months old."<< endl;
						else
							cout << "\tThe pet number " << i + 1 << " is " << d.getName() << ". It is from the race " << d.getBreed() << " and it is " << d.getAge() << " years old." << endl;
					}
					cout << "------------------------------------------------------ \n \n";
					break;
				}
				default:
					break;
				}
			}
		}
		if (command == 2)
		{
			while (true)
			{
				UI::printMenuUser();
				int command = this->readOptionNumber(0, 3);
				cin.ignore();
				if (command == 0)
				{
					cout << "\n \n";
					break;
				}
				switch (command)
				{
				case 1:
				{
					bool valid = true;
					int i = 0;
					vector<Dog> list = this->getController().getAllDogsFromAdoptionList();
					while (valid == true && i < this->getController().getAllDogsController().size())
					{
						if (this->getController().getAllDogsController()[i].getAge() > 1)
						{
							cout << "\n";
							cout << "------------------------------------------------------ \nThis is the pet " << this->ctrl.getAllDogsController()[i].getName()
								<< ", which is a " << this->getController().getAllDogsController()[i].getBreed()
								<< " and it is " << this->getController().getAllDogsController()[i].getAge()
								<< " years old.\n------------------------------------------------------\n \n";
						}
						else
						{
							cout << "\n";
							cout << "------------------------------------------------------ \nThis is the pet " << this->ctrl.getAllDogsController()[i].getName()
								<< ", which is a " << this->getController().getAllDogsController()[i].getBreed()
								<< " and it is " << this->getController().getAllDogsController()[i].getAge() * 10
								<< " months old.\n------------------------------------------------------\n \n";
						}
						string option = "";
						cout << "Would you like to open the link? \n";
						cout << "Answer: ";
						cin >> option;
						if (option == "Yes" || option == "yes" || option == "Y" || option == "y")
							ShellExecuteA(NULL, NULL, "chrome.exe", this->getController().getAllDogsController()[i].getPhotograph().c_str(), NULL, SW_SHOWMAXIMIZED);
						string adopt = "";
						cout << " \nWould you like to adopt this pet? \n";
						cout << "Answer: ";
						cin >> adopt;
						cout << "\n";
						if (adopt == "Yes" || adopt == "yes" || adopt == "Y" || adopt == "y")
							if (this->getController().addToAdoptionListController(
								this->getController().getAllDogsController()[i].getName(),
								this->getController().getAllDogsController()[i].getBreed(),
								this->getController().getAllDogsController()[i].getAge(),
								this->getController().getAllDogsController()[i].getPhotograph())
								== 1)
								cout << "------------------------------------------------------\n The pet was successfully added to your adoption list. \n------------------------------------------------------ \n \n";
							else
								cout << "------------------------------------------------------ \n Error! The pet may already exist in your adoption list. \n------------------------------------------------------ \n \n";
						else
						{
							cout << "Would you like to continue visualizing the list of pets? \n";
							cout << "Answer: ";
							cin >> adopt;
							if (adopt == "Yes" || adopt == "yes" || adopt == "Y" || adopt == "y")
								int x = 0;
							else
								valid = false;
						}
						i++;
						if (i == this->getController().getAllDogsController().size())
						{
							string command = "";
							cout << "There are no more pets in the database. Would you like to go over again? \n";
							cout << "Answer: ";
							cin >> command;
							if (command == "Yes" || command == "yes" || command == "Y" || command == "y")
								i = 0;
							else
								valid = false;
						}
					}
					break;
				}
				case 2:
				{
					string breed;
					vector<Dog> list;
					cout << "Please enter breed in order to filter the database: ";
					getline(cin, breed);
					double age = this->readAge("Please set an age limit for the pets: ");
					if (breed == "")
						list = this->getController().getAllDogsController();
					else
						list = this->getController().getAllDogsByBreedAndAgeController(breed, age);
					if (list.size() == 0)
						cout << "------------------------------------------------------ \nThere are no pets that fulfill the requirements : \n";
					else
					{
						cout << "------------------------------------------------------ \nThis is the list after the filtering: \n \n";
						for (int i = 0; i < list.size(); i++)
						{
							Dog d = list[i];
							if (d.getAge() < 1)
								cout << "\tThe pet number " << i + 1 << " is " << d.getName() << ". It is from the race " << d.getBreed() << " and it is " << d.getAge() * 10 << " months old." << endl;
							else
								cout << "\tThe pet number " << i + 1 << " is " << d.getName() << ". It is from the race " << d.getBreed() << " and it is " << d.getAge() << " years old." << endl;
						}
					}
					cout << "------------------------------------------------------";
					cout << "\n \n";
					bool valid = true;
					int i = 0;
					while (valid == true && i < list.size())
					{
						cout << "\n";
						cout << "------------------------------------------------------ \nThis is the pet " << list[i].getName()
							<< ", which is a " << list[i].getBreed()
							<< " and it is " << list[i].getAge()
							<< " years old.\n------------------------------------------------------\n \n"; //You may see it at the following address: \n" << "\t" <<this->ctrl.getAllDogsController().getAllElements()[i].getPhotograph();
						string option = "";
						cout << "Would you like to open the link? \n";
						cout << "Answer: ";
						cin >> option;
						if (option == "Yes" || option == "yes" || option == "Y" || option == "y")
							ShellExecuteA(NULL, NULL, "chrome.exe", list[i].getPhotograph().c_str(), NULL, SW_SHOWMAXIMIZED);
						string adopt = "";
						cout << " \nWould you like to adopt this pet? \n";
						cout << "Answer: ";
						cin >> adopt;
						cout << "\n";
						if (adopt == "Yes" || adopt == "yes" || adopt == "Y" || adopt == "y")
							if (this->getController().addToAdoptionListController(
								list[i].getName(),
								list[i].getBreed(),
								list[i].getAge(),
								list[i].getPhotograph())
								== 1)
								cout << "------------------------------------------------------\nThe pet was successfully added to your adoption list. \n------------------------------------------------------ \n \n";
							else
								cout << "------------------------------------------------------ \nError! The pet may already exist in your adoption list. \n------------------------------------------------------ \n \n";
						else
						{
							cout << "Would you like to continue visualizing the list of pets? \n";
							cout << "Answer: ";
							cin >> adopt;
							if (adopt == "Yes" || adopt == "yes" || adopt == "Y" || adopt == "y")
								int x = 0;
							else
								valid = false;
						}
						i++;
						if (i == list.size())
						{
							string command = "";
							cout << "There are no more pets in the database. Would you like to go over again? \n";
							cout << "Answer: ";
							cin >> command;
							if (command == "Yes" || command == "yes" || command == "Y" || command == "y")
								i = 0;
							else
								valid = false;
						}
					}
					break;
				}
				case 3:
				{
					vector<Dog> list = this->getController().getAllDogsFromAdoptionList();
					if (list.size() == 0)
						cout << "At this moment, yor adoption list is empty. \n";
					else
					{
						cout << "Currently, this is your adoption list: \n \n";
						for (int i = 0; i < list.size(); i++)
						{
							Dog d = list[i];
							cout << "\tPet " << i + 1 << ") " <<"Race: "<< d.getBreed() << ", Name: " << d.getName() << ", Age: " << d.getAge() << ".\n"; 
						}
						cout << "\n";

					}
					break;
				}
				default:
					break;
				}
			}
		}
	}
}


