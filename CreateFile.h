#pragma once
#include "Repository.h"
#include "AdoptionList.h"

class CreateFiles
{
protected:
	vector<Dog> l;
public:
	CreateFiles() {};
	virtual ~CreateFiles() {};
	virtual void createFile() = 0;
};

class Webpage: public CreateFiles
{
private:
	vector<Dog> l;
public:
	Webpage() {};
	Webpage(vector<Dog>& l) : l(l) {}
	~Webpage() override {}
	void createFile() override;
};

class CSVFile : public CreateFiles
{
private:
	vector<Dog> l;
public:
	CSVFile() {};
	CSVFile(vector<Dog>& l) : l(l) {}
	~CSVFile() override {}
	void createFile() override;
};
