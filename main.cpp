#include "QtDogs.h"
#include <QtWidgets/QApplication>
#include "Controller.h"
#include "Tests.h"


int main(int argc, char *argv[])
{
	Test::test_dog();
	Test::test_repository();
	QApplication a(argc, argv);
	Repository repo{};
	Adoption list{};
	repo.readFromFile();
	Controller ctrl{ repo, list };
	QtDogs w{ctrl};
	w.show();
	return a.exec();
}
