#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtDogs.h"
#include "Controller.h"
#include <QWidgetList>
#include <QPushButton>
#include <QListWidget>

class QtDogs : public QWidget
{
	Q_OBJECT

public:
	QtDogs(Controller& ctrl, QWidget *parent = 0);
	~QtDogs();
private:
	//Ui::QtDogsClass ui;
	Controller& ctrl;
	std::vector<Dog> currentDogsInRepoList;
	std::vector<Dog> currentDogsInAdoptionList;
	std::vector<Dog> currentDogsByBreedAndAge;
	QListWidget* repoList;
	QLineEdit* nameEdit;
	QLineEdit* breedEdit;
	QLineEdit* ageEdit;
	QLineEdit* linkEdit;
	QLineEdit* newLinkEdit;
	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* deleteButtonAdoption;
	QPushButton* updateButton;
	QPushButton* moveOneDogButton;
	QPushButton* openPhoto;
	QPushButton* getDogsByBreed;
	QListWidget* Adoption;
	void initGUI();
	void populateRepoList();
	void populateAdoptionList();
	int getRepoListSelectedIndex();
	int getAdoptionIndex();
	int getAdoptionListSelectedIndex();
	void connectSignalsAndSlots();

private slots:
	void ListItemChanged();
	void ListItemChangedAdoption();
	void addNewDog();
	void deleteDog();
	void updateDog();
	void createAdoptionList();
	void deleteDogAdoption();
	void openPhotograph();
	void populateAdoptionByBreed();
};
