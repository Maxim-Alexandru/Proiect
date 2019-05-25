#include "Exceptions.h"
#include <string>

using namespace std;

void Exceptions::validateDog(Dog& dog)
{
	string exception = "";
	if (dog.getName().size() < 2)
		exception += "The length of the name of the dog is too short. \n";
	if (!isupper(dog.getName()[0]))
		exception += "The name of the dog must start with a capital letter. \n";
	if (dog.getBreed().size() < 2)
		exception += "The length of breed of the dog is too short. \n";
	if (dog.getAge() <= 0 || dog.getAge() >= 20)
		exception += "The age of the dog is invalid. \n";
	if (dog.getPhotograph().size() < 2)
		exception += "The length of the link of the dog is too short. \n";
	if (strstr(dog.getPhotograph().c_str(), "https://") == 0)
		exception += "The link must start with the following syntax: <https://> . \n";
	if (exception.size() > 0)
		throw exception;
}
