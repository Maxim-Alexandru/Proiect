#include "Tests.h"
#include <assert.h>
#include <string>
#include <vector>

using namespace std;

void Test::test_dog()
{
	Dog d1{};
	string name = "Pet1";
	string breed = "Breed";
	double age = 10;
	string photograph = "link";
	Dog d{ "Pet1", "Breed", age, "link" };
	assert(d.getName() == name);
	assert(d.getBreed() == breed);
	assert(d.getAge() == age);
	assert(d.getPhotograph() == photograph);
	string name2 = "Pet2";
	d.setName(name2);
	assert(d.getName() == name2);
}

void Test::test_repository()
{
	Repository repo{};
	assert(repo.getAllDogs().size() == 0);
	Dog d1{ "Pet1", "Breed1", 10, "https://1" };
	assert(repo.addDog(d1) == 1);
	assert(repo.getAllDogs().size() == 1);
	//--------------------------------------------------------------------------------------------------
	string s = d1.getPhotograph();
	assert(repo.deleteDog(s) == 1);
	assert(repo.getAllDogs().size() == 0);
	assert(repo.deleteDog(s) == 0);
	//--------------------------------------------------------------------------------------------------
	assert(repo.addDog(d1) == 1);
	Dog d2{ "Pet2", "Breed2", 11, "https://2" };
	Dog d3{ "Pet3", "Breed3", 11, "https://1" };
	assert(repo.addDog(d3) == 0);
	//--------------------------------------------------------------------------------------------------
	string s1 = "Link1";
	assert(repo.updateDog(d2, s) == 1);
	string s2 = "www";
	assert(repo.updateDog(d2, s) == 0);
	assert(strcmp(repo.getAllDogs()[0].getName().c_str(), d2.getName().c_str()) == 0);
	assert(strcmp(repo.getAllDogs()[0].getBreed().c_str(), d2.getBreed().c_str()) == 0);
	assert(repo.getAllDogs()[0].getAge() == d2.getAge());
	assert(strcmp(repo.getAllDogs()[0].getPhotograph().c_str(), d2.getPhotograph().c_str()) == 0);
	//--------------------------------------------------------------------------------------------------
	string s3 = "Breed2";
}

void Test::test_controller()
{
	Adoption list;
	Dog dog1{ "name1", "breed1", 1, "https://1" };
	Dog dog2{ "name2", "breed2", 2, "https://2" };
	assert(list.getAdoptionList().size() == 0);
	assert(list.addToAdoptionList(dog1) == 1);
	assert(list.addToAdoptionList(dog2) == 1);
	assert(list.addToAdoptionList(dog1) == 0);
	assert(list.getAdoptionList().size() == 2);
	Repository repo;
	Dog d1{ "Max", "Bulldog", 2, "https://www.google.com/imgres?imgurl=https%3A%2F%2Fcdn2-www.dogtime.com%2Fassets%2Fuploads%2Fgallery%2Fbulldog-dog-breed-pictures%2F1-threequartersitting.jpg&imgrefurl=https%3A%2F%2Fdogtime.com%2Fdog-breeds%2Fbulldog&docid=q2_vqQdd802x1M&tbnid=YmiGQZQbsBTBJM%3A&vet=10ahUKEwim6OGIiMjhAhUD_aQKHdDLC9QQMwhpKAIwAg..i&w=680&h=453&safe=active&bih=610&biw=1280&q=bulldog&ved=0ahUKEwim6OGIiMjhAhUD_aQKHdDLC9QQMwhpKAIwAg&iact=mrc&uact=8" };
	Dog d2{ "Cooper", "German Shepherd", 2, "https://www.google.com/imgres?imgurl=https%3A%2F%2Fs3.amazonaws.com%2Fcdn-origin-etr.akc.org%2Fwp-content%2Fuploads%2F2017%2F11%2F12213218%2FGerman-Shepherd-on-White-00.jpg&imgrefurl=https%3A%2F%2Fwww.akc.org%2Fdog-breeds%2Fgerman-shepherd-dog%2F&docid=zr2r0feuK-u4KM&tbnid=zKyuUIVlbbqLIM%3A&vet=10ahUKEwiZkMb1icjhAhVkw8QBHUV2DcoQMwhpKAEwAQ..i&w=729&h=486&safe=active&bih=610&biw=1280&q=german%20shepherd&ved=0ahUKEwiZkMb1icjhAhVkw8QBHUV2DcoQMwhpKAEwAQ&iact=mrc&uact=8" };
	Dog d3{ "Buddy", "Beagle", 1, "https://www.google.com/url?sa=i&source=images&cd=&cad=rja&uact=8&ved=2ahUKEwiBsuCDisjhAhWK_qQKHb-QBycQjRx6BAgBEAU&url=https%3A%2F%2Fdogtime.com%2Fdog-breeds%2Fbeagle&psig=AOvVaw0Ezl5Yx4AvHts9mM0_TTid&ust=1555073410394164" };
	Dog d4{ "Oliver", "Pug", 0.5, "https://www.google.com/imgres?imgurl=https%3A%2F%2Fs3.amazonaws.com%2Fcdn-origin-etr.akc.org%2Fwp-content%2Fuploads%2F2017%2F11%2F12225358%2FPug-On-White-01.jpg&imgrefurl=https%3A%2F%2Fwww.akc.org%2Fdog-breeds%2Fpug%2F&docid=jWPpicemWyT5aM&tbnid=aU91cwGlZb15JM%3A&vet=10ahUKEwjs0_OMisjhAhVP-qQKHSH0A9MQMwhtKAQwBA..i&w=729&h=486&safe=active&bih=610&biw=1280&q=pug&ved=0ahUKEwjs0_OMisjhAhVP-qQKHSH0A9MQMwhtKAQwBA&iact=mrc&uact=8" };
	Dog d5{ "Tucker", "Puddle", 2, "https://www.google.com/imgres?imgurl=https%3A%2F%2Fbowwowinsurance.com.au%2Fwp-content%2Fuploads%2F2018%2F10%2Fstandard-poodle-brown-700x700.jpg&imgrefurl=https%3A%2F%2Fbowwowinsurance.com.au%2Fdogs%2Fdog-breeds%2Fpoodle%2F&docid=_p-3LxZz3EeChM&tbnid=fkl_XRHPXkBPmM%3A&vet=10ahUKEwir_9ubisjhAhVCz6YKHRc_Bc4QMwiRASgYMBg..i&w=700&h=700&safe=active&bih=610&biw=1280&q=puddle%20dgo&ved=0ahUKEwir_9ubisjhAhVCz6YKHRc_Bc4QMwiRASgYMBg&iact=mrc&uact=8" };
	Dog d6{ "Bella", "Labrador", 3, "https://www.google.com/imgres?imgurl=https%3A%2F%2Fs3.amazonaws.com%2Fcdn-origin-etr.akc.org%2Fwp-content%2Fuploads%2F2017%2F11%2F12231354%2FLabrador-Retriever-On-White-05.jpg&imgrefurl=https%3A%2F%2Fwww.akc.org%2Fdog-breeds%2Flabrador-retriever%2F&docid=LE1TM6YbCTzRWM&tbnid=VRx8lQ7Cto6QxM%3A&vet=10ahUKEwjg3JOnisjhAhXJyKQKHd-9Dh0QMwhoKAEwAQ..i&w=729&h=486&safe=active&bih=610&biw=1280&q=labrador&ved=0ahUKEwjg3JOnisjhAhXJyKQKHd-9Dh0QMwhoKAEwAQ&iact=mrc&uact=8" };
	Dog d7{ "Luna", "Siberian Husky", 4, "https://www.google.com/imgres?imgurl=https%3A%2F%2Fs3.amazonaws.com%2Fcdn-origin-etr.akc.org%2Fwp-content%2Fuploads%2F2017%2F11%2F12224224%2FSiberian-Husky-On-White-03.jpg&imgrefurl=https%3A%2F%2Fwww.akc.org%2Fdog-breeds%2Fsiberian-husky%2F&docid=EFEWcvuitN1IXM&tbnid=ZzDt_8T0-5K0qM%3A&vet=10ahUKEwju8tuwisjhAhXGMewKHZPeDj0QMwhnKAIwAg..i&w=729&h=485&safe=active&bih=610&biw=1280&q=siberian%20husky&ved=0ahUKEwju8tuwisjhAhXGMewKHZPeDj0QMwhnKAIwAg&iact=mrc&uact=8" };
	Dog d8{ "Sophie", "Boxer", 2, "https://www.google.com/imgres?imgurl=https%3A%2F%2Fbowwowinsurance.com.au%2Fwp-content%2Fuploads%2F2018%2F10%2Fboxer-700x700.jpg&imgrefurl=https%3A%2F%2Fbowwowinsurance.com.au%2Fdogs%2Fdog-breeds%2Fboxer%2F&docid=XIEn_ZQakQV_YM&tbnid=BYoYN7_LvFEfJM%3A&vet=10ahUKEwiNm6G6isjhAhVNwqYKHawYC7QQMwhxKAgwCA..i&w=700&h=700&safe=active&bih=610&biw=1280&q=boxer&ved=0ahUKEwiNm6G6isjhAhVNwqYKHawYC7QQMwhxKAgwCA&iact=mrc&uact=8" };
	Dog d9{ "Sadie", "Rottweiler", 4, "https://www.google.com/imgres?imgurl=https%3A%2F%2Fs3.amazonaws.com%2Fcdn-origin-etr.akc.org%2Fwp-content%2Fuploads%2F2017%2F11%2F12224942%2FRottweiler-On-White-10.jpg&imgrefurl=https%3A%2F%2Fwww.akc.org%2Fdog-breeds%2Frottweiler%2F&docid=I3l5m22PGBQueM&tbnid=P804ltx8q3VxUM%3A&vet=10ahUKEwi1_JfEisjhAhUP-aQKHTILCiwQMwhnKAAwAA..i&w=729&h=486&safe=active&bih=610&biw=1280&q=rottweiler&ved=0ahUKEwi1_JfEisjhAhUP-aQKHTILCiwQMwhnKAAwAA&iact=mrc&uact=8" };
	Dog d10{ "Lucy", "Chow Chow", 0.6, "https://www.google.com/imgres?imgurl=https%3A%2F%2Fs3.amazonaws.com%2Fcdn-origin-etr.akc.org%2Fwp-content%2Fuploads%2F2017%2F11%2F12234550%2FChow-Chow-Care-500x749.jpg&imgrefurl=https%3A%2F%2Fwww.akc.org%2Fdog-breeds%2Fchow-chow%2F&docid=PdVpa_J4Y-zEKM&tbnid=8CJCAyTcRwLQ_M%3A&vet=10ahUKEwizp43LisjhAhWNyqQKHf-vB3oQMwhrKAIwAg..i&w=500&h=749&safe=active&bih=610&biw=1280&q=chow%20chow&ved=0ahUKEwizp43LisjhAhWNyqQKHf-vB3oQMwhrKAIwAg&iact=mrc&uact=8" };
	Dog d11{ "Name", "Breed", 10, "https://3" };
	assert(repo.getAllDogs().size() == 0);
	assert(repo.addDog(d1) == 1);
	assert(repo.addDog(d2) == 1);
	assert(repo.addDog(d3) == 1);
	assert(repo.addDog(d4) == 1);
	assert(repo.addDog(d5) == 1);
	assert(repo.addDog(d6) == 1);
	assert(repo.addDog(d7) == 1);
	assert(repo.addDog(d8) == 1);
	assert(repo.addDog(d9) == 1);
	assert(repo.addDog(d10) == 1);
	assert(repo.addDog(d11) == 1);
	assert(repo.getAllDogs().size() == 11);
	Controller ctrl{ repo };
	string name = d1.getName();
	string breed = d1.getBreed();
	string link = d1.getPhotograph();
	assert(ctrl.addDogController(name, breed, d1.getAge(), link) == 0);
	ctrl.getAllDogsController();
	assert(ctrl.deleteDogController(link) == 1);
	assert(ctrl.getAllDogsController().size() == 10);
	assert(ctrl.getAllDogsController().size() == 10);
	ctrl.getAllDogsFromAdoptionList();
	string name0 = "Name0";
	string breed0 = "Breed0";
	string link1 = "https://1";
	string link2 = "https://3";
	assert(ctrl.updateDogController(name, breed, 1, link1, link2) == 1);
	assert(ctrl.getAllDogsController().size() == 10);
	string name2 = d1.getName();
	string breed2 = d1.getBreed();
	string link0000 = d1.getPhotograph();
	assert(ctrl.addToAdoptionListController(name, breed, d1.getAge(), link) == 1);
	assert(ctrl.getAllDogsFromAdoptionList().size() == 1);
	ctrl.getAllDogsByBreedAndAgeController(breed, d1.getAge());
	UI ui{ctrl};
	ui.getController();
}
