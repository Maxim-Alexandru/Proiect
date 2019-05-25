#pragma once
#include <iostream>
#include "Controller.h"
#include "Validation.h"

class UI
{
	private:
		Controller ctrl;
		Validation valid;
	public:
		UI(const Controller c) : ctrl( c ) {}
		Controller& getController() { return this->ctrl; }
		Validation& getValidation() { return this->valid; }
		void run();
	private:
		/*
		This function reads the name of a pet.
		Input: A string containing a message that will be printed on the screen.
		Output: A string containing the name of the pet.
		*/
		string readName(string& message);
		/*
		This function reads the breed of a pet.
		Input: A string containing a message that will be printed on the screen.
		Output: A string containing the breed of the pet.
		*/
		string readBreed(string& message);
		/*
		This function reads the link of a pet.
		Input: A string containing a message that will be printed on the screen.
		Output: A string containing the link of the pet.
		*/
		string readLink(string& message);
		/*
		This function reads the age of a pet.
		Input: A string containing a message that will be printed on the screen.
		Output: A double containing the age of the pet.
		*/
		double readAge(string& message);
		/*
		This function reads an option in order to access some functionalities.
		Input: The interval for which the read option is valid.
		Output: An integer containing the option.
		*/
		int readOptionNumber(int lower, int upper);
		/*
		This function prints the main menu, from which the user of the application can choose 2 different interfaces.
		Input: - 
		Output: -
		*/
		static void printMenuAdministrator();
		/*
		This function prints the options that the user can use.
		Input: -
		Output: -
		*/
		static void printMenuUser();
		/*
		This function prints the menu for the administrator.
		Input: -
		Output: -
		*/
		static void printMenu();
		static void printMessages(string& message) { std::cout << message.c_str(); }
};
