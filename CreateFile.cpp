#include "CreateFile.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void Webpage::createFile()
{
	Repository repo{};
	repo.emptyContent("WebPage.htm");
	ofstream f("Webpage.htm");
	if (!f.is_open())
		return;
	f << "<!DOCTYPE html> \n";
	f << "<html> \n";
	f << "<head>";
	f << "Adoption list";
	f << "</head> \n <body> \n <table border=";
	f << """1""";
	f << ">\n";
	f << "<tr> \n <td>Name</td> \n <td>Breed</td> \n <td>Age</td> \n <td>Photograph</td> \n";
	f << "</tr> \n";
	vector<Dog> v = this->l;
	for (int i = 0; i < v.size(); i++)
	{
		f << "<tr> \n";
		f << "<td>" << v[i].getName() << "</td> \n";
		f << "<td>" << v[i].getBreed() << "</td> \n";
		f << "<td>" << to_string((int)(v[i].getAge())) << "</td> \n";
		f << "<td><a href = " << v[i].getPhotograph() << ">Link</a></td> \n";
		f << "</tr> \n";
	}
	f << "</table> \n";
	f << "</body> \n";
	f << "</html> \n";
}

void CSVFile::createFile()
{
	Repository repo{};
	repo.emptyContent("AdoptionList.csv");
	ofstream f("AdoptionList.csv");
	if (!f.is_open())
		return;
	vector<Dog> v = this->l;
	for (int i = 0; i < v.size(); i++)
		f << v[i].getName() << "," << v[i].getBreed() << "," << v[i].getAge() << "," << v[i].getPhotograph() << "\n";
}
