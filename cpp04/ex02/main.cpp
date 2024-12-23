#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	cout << endl;

	Dog* dog = new Dog();
	Cat* cat = new Cat();
	WrongAnimal* wronganimal = new WrongAnimal();
	WrongCat* wrongcat = new WrongCat();

	cout << endl;

	cout << dog->getType() << endl;
	dog->makeSound();
	dog->setBrainIdea(0, "deneme1");
	dog->setBrainIdea(5, "test dog");
	cout << dog->getBrainIdea(0) << endl;
	cout << dog->getBrainIdea(5) << endl;
	cout << dog->getBrainIdea(1) << endl;
	dog->setBrainIdea(5, "change test 5");
	cout << dog->getBrainIdea(5) << endl;

	cout << endl;

	cout << cat->getType() << endl;
	cat->makeSound();
	cat->setBrainIdea(0, "deneme2");
	cat->setBrainIdea(5, "test cat");
	cout << cat->getBrainIdea(0) << endl;
	cout << cat->getBrainIdea(5) << endl;
	cout << cat->getBrainIdea(1) << endl;
	cat->setBrainIdea(5, "change test 5");
	cout << cat->getBrainIdea(5) << endl;

	cout << endl;


	delete dog;
	delete cat;
	delete wronganimal;
	delete wrongcat;
	return 0;
}
