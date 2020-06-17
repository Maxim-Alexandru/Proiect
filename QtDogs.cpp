#include "QtDogs.h"
#include <vector>
#include <Dog.h>
#include <QHBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QObject>
#include <QlineEdit>
#include <QWidgetList>
#include <QGridLayout>
#include <QAbstractItemView>
#include <QWidget>
#include <QList>
#include <QListWidgetItem>
#include <QMessageBox>
#include "Exceptions.h"
#include <sstream>
#include <Windows.h>
#include "AdoptionList.h"


QtDogs::QtDogs(Controller& ctrl, QWidget *parent): QWidget(parent), ctrl(ctrl)
{
	this->initGUI();
	this->currentDogsInRepoList = this->ctrl.getAllDogsController();
	this->populateRepoList();
}

QtDogs::~QtDogs()
{
}

void QtDogs::initGUI()
{
	QHBoxLayout* layout = new QHBoxLayout{ this };
	QWidget* leftWidget = new QWidget{};
	QVBoxLayout* leftSide = new QVBoxLayout{ leftWidget };
	this->repoList = new QListWidget{};
	this->repoList->setSelectionMode(QAbstractItemView::SingleSelection);
	QWidget* DogDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ DogDataWidget };
	this->nameEdit = new QLineEdit{};
	this->breedEdit = new QLineEdit{};
	this->ageEdit = new QLineEdit{};
	this->linkEdit = new QLineEdit{};
	this->newLinkEdit = new QLineEdit{};
	formLayout->addRow("&Name:", nameEdit);
	formLayout->addRow("&Breed:", breedEdit);
	formLayout->addRow("&Age:", ageEdit);
	formLayout->addRow("&Link:", linkEdit);
	formLayout->addRow("&NewLink:", newLinkEdit);
	QWidget* buttonsWidget = new QWidget{};
	QGridLayout* gridLayout = new QGridLayout{ buttonsWidget };
	this->addButton = new QPushButton{ "Add" };
	this->deleteButton = new QPushButton{ "Delete" };
	this->updateButton = new QPushButton{ "Update" };
	this->deleteButtonAdoption = new QPushButton{ "Delete from adoption" };
	this->openPhoto = new QPushButton{ "Open the link" };
	this->getDogsByBreed = new QPushButton{ "Get all the dogs by breed and age" };
	gridLayout->addWidget(addButton, 0, 0);
	gridLayout->addWidget(deleteButton, 0, 1);
	gridLayout->addWidget(updateButton, 0, 2);
	gridLayout->addWidget(deleteButtonAdoption, 1, 1);
	leftSide->addWidget(new QLabel{ "All songs" });
	leftSide->addWidget(repoList);
	leftSide->addWidget(DogDataWidget);
	leftSide->addWidget(buttonsWidget);
	QWidget* middleWidget = new QWidget{};
	QVBoxLayout* vLayoutMiddle = new QVBoxLayout{ middleWidget };
	this->moveOneDogButton = new QPushButton{ ">> Move one dog" };
	QWidget* upperPart = new QWidget{};
	QVBoxLayout* vLayoutUpperPart = new QVBoxLayout{ upperPart };
	vLayoutUpperPart->addWidget(this->moveOneDogButton);
	vLayoutMiddle->addWidget(upperPart);
	QWidget* rightWidget = new QWidget{};
	QVBoxLayout* rightSide = new QVBoxLayout{ rightWidget };
	this->Adoption = new QListWidget{};
	rightSide->addWidget(new QLabel{ "Adoption" });
	rightSide->addWidget(this->Adoption);
	rightSide->addWidget(openPhoto);
	rightSide->addWidget(getDogsByBreed);
	layout->addWidget(leftWidget);
	layout->addWidget(middleWidget);
	layout->addWidget(rightWidget);
	this->connectSignalsAndSlots();
}

void QtDogs::populateRepoList()
{
	if (this->repoList->count() > 0)
		this->repoList->clear();
	for (auto dog : this->currentDogsInRepoList)
	{
		QString itemList = QString::fromStdString(dog.getName() + "-" + dog.getBreed() + "-" + to_string(dog.getAge()));
		QListWidgetItem *item = new QListWidgetItem(itemList);
		this->repoList->addItem(item);
	}
}

void QtDogs::populateAdoptionList()
{
	if (this->Adoption->count() > 0)
		this->Adoption->clear();
	for (auto dog : this->currentDogsInAdoptionList)
	{
		QString itemList = QString::fromStdString(dog.getName() + "-" + dog.getBreed() + "-" + to_string(dog.getAge()));
		QListWidgetItem *item = new QListWidgetItem(itemList);
		this->Adoption->addItem(item);
	}
}

int QtDogs::getRepoListSelectedIndex()
{

	if (this->repoList->count() == 0)
		return -1;

	QModelIndexList index = this->repoList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->nameEdit->clear();
		this->breedEdit->clear();
		this->ageEdit->clear();
		this->linkEdit->clear();
		return -1;
	}
	int idx = index.at(0).row();
	return idx;
}

int QtDogs::getAdoptionIndex()
{
	if (this->Adoption->count() == 0)
		return -1;

	QModelIndexList index = this->Adoption->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->nameEdit->clear();
		this->breedEdit->clear();
		this->ageEdit->clear();
		this->linkEdit->clear();
		return -1;
	}
	int idx = index.at(0).row();
	return idx;
}

int QtDogs::getAdoptionListSelectedIndex()
{
	if (this->Adoption->count() == 0)
		return -1;

	QModelIndexList index = this->Adoption->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->nameEdit->clear();
		this->breedEdit->clear();
		this->ageEdit->clear();
		this->linkEdit->clear();
		return -1;
	}
	int idx = index.at(0).row();
	return idx;
}

void QtDogs::ListItemChanged()
{
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1)
		return;
	std::vector<Dog> dogs = this->currentDogsInRepoList;
	if (idx >= dogs.size())
		return;
	Dog d = dogs[idx];
	this->nameEdit->setText(QString::fromStdString(d.getName()));
	this->breedEdit->setText(QString::fromStdString(d.getBreed()));
	this->ageEdit->setText(QString::fromStdString(to_string(d.getAge())));
	this->linkEdit->setText(QString::fromStdString(d.getPhotograph()));
}


void QtDogs::connectSignalsAndSlots()
{
	QObject::connect(this->repoList, SIGNAL(itemSelectionChanged()), this, SLOT(ListItemChanged()));
	QObject::connect(this->Adoption, SIGNAL(itemSelectionChanged()), this, SLOT(ListItemChangedAdoption()));
	QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addNewDog()));
	QObject::connect(this->deleteButton, SIGNAL(clicked()), this, SLOT(deleteDog()));
	QObject::connect(this->updateButton, SIGNAL(clicked()), this, SLOT(updateDog()));
	QObject::connect(this->moveOneDogButton, SIGNAL(clicked()), this, SLOT(createAdoptionList()));
	QObject::connect(this->deleteButtonAdoption, SIGNAL(clicked()), this, SLOT(deleteDogAdoption()));
	QObject::connect(this->openPhoto, SIGNAL(clicked()), this, SLOT(openPhotograph()));
	QObject::connect(this->getDogsByBreed, SIGNAL(clicked()), this, SLOT(populateAdoptionByBreed()));
}

void QtDogs::ListItemChangedAdoption()
{
	int idx = this->getAdoptionIndex();
	if (idx == -1)
		return;
	std::vector<Dog> dogs = this->currentDogsInAdoptionList;
	if (idx >= dogs.size())
		return;
	Dog d = dogs[idx];
	this->nameEdit->setText(QString::fromStdString(d.getName()));
	this->breedEdit->setText(QString::fromStdString(d.getBreed()));
	this->ageEdit->setText(QString::fromStdString(to_string(d.getAge())));
	this->linkEdit->setText(QString::fromStdString(d.getPhotograph()));
}

void QtDogs::addNewDog()
{
	std::string name = this->nameEdit->text().toStdString();
	std::string breed = this->breedEdit->text().toStdString();
	std::string link = this->linkEdit->text().toStdString();
	double age = this->ageEdit->text().toDouble();
	this->ctrl.addDogController(name, breed, age, link);
	this->currentDogsInRepoList = this->ctrl.getAllDogsController();
	this->populateRepoList();
}


void QtDogs::deleteDog()
{
	std::string link = this->linkEdit->text().toStdString();
	this->ctrl.deleteDogController(link);
	this->currentDogsInRepoList = this->ctrl.getAllDogsController();
	this->populateRepoList();
}

void QtDogs::updateDog()
{
	std::string name = this->nameEdit->text().toStdString();
	std::string breed = this->breedEdit->text().toStdString();
	std::string link = this->linkEdit->text().toStdString();
	std::string newLink = this->newLinkEdit->text().toStdString();
	double age = this->ageEdit->text().toDouble();
	this->ctrl.updateDogController(name, breed, age, newLink, link);
	this->currentDogsInRepoList = this->ctrl.getAllDogsController();
	this->populateRepoList();
}

void QtDogs::createAdoptionList()
{
	std::string name = this->nameEdit->text().toStdString();
	std::string breed = this->breedEdit->text().toStdString();
	std::string link = this->linkEdit->text().toStdString();
	double age = this->ageEdit->text().toDouble();
	this->ctrl.addToAdoptionListController(name, breed, age, link);
	this->currentDogsInAdoptionList = this->ctrl.getAllDogsFromAdoptionList();
	this->populateAdoptionList();
}

void QtDogs::deleteDogAdoption()
{
	std::string link = this->linkEdit->text().toStdString();
	int index = this->ctrl.getAdoption().getPositionAdoption(link);
	if (index!=-1)
		currentDogsInAdoptionList.erase(currentDogsInAdoptionList.begin() + index);
	this->ctrl.getAdoption().getAdoptionList() = currentDogsInAdoptionList;
	this->populateAdoptionList();
}

void QtDogs::openPhotograph()
{
	std::string link = this->linkEdit->text().toStdString();
	ShellExecuteA(NULL, NULL, "chrome.exe", link.c_str(), NULL, SW_SHOWMAXIMIZED);
}

void QtDogs::populateAdoptionByBreed()
{
	std::string breed = this->breedEdit->text().toStdString();
	double age = this->ageEdit->text().toDouble();
	if (this->Adoption->count() > 0)
		this->Adoption->clear();
	this->currentDogsByBreedAndAge = this->ctrl.getAllDogsByBreedAndAgeController(breed, age);
	for (int i = 0; i < currentDogsByBreedAndAge.size(); i++)
		this->ctrl.addToAdoptionListController(currentDogsByBreedAndAge[i].getName(),
			currentDogsByBreedAndAge[i].getBreed(),
			currentDogsByBreedAndAge[i].getAge(),
			currentDogsByBreedAndAge[i].getPhotograph());
	this->currentDogsInAdoptionList = this->currentDogsByBreedAndAge;
	for (auto dog : this->currentDogsByBreedAndAge)
	{
		QString itemList = QString::fromStdString(dog.getName() + "-" + dog.getBreed() + "-" + to_string(dog.getAge()));
		QListWidgetItem *item = new QListWidgetItem(itemList);
		this->Adoption->addItem(item);
	}
}


