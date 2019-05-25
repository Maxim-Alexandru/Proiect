#include "UI.h"
#include "Dog.h"
#include "Tests.h"
#include <Windows.h>
#include <crtdbg.h>
#include "CreateFile.h"

using namespace std;

int main()
{
	{
		Test::test_dog();
		Test::test_repository();
		Test::test_controller();
		Repository repo{};
		repo.readFromFile();
		repo.writeToFile();
		Controller ctrl{ repo };
		UI ui{ ctrl };
		ui.run();
		repo.emptyContent("AdoptionList.txt");
		repo.emptyContent("WebPage.htm");
	}
	system("pause");
	_CrtDumpMemoryLeaks();
	return 0;
}