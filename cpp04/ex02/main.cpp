#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	cout << "----- Polymorphism Test -----" << endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	cout << "Type of j: " << j->getType() << endl;
	cout << "Type of i: " << i->getType() << endl;

	j->makeSound();
	i->makeSound();

	delete j;
	delete i;

	cout << "\n----- Brain Class Test -----" << endl;

	Dog* dog = new Dog();
	Cat* cat = new Cat();

	dog->setBrainIdea(0, "I want to play!");
	dog->setBrainIdea(1, "I am hungry.");
	cat->setBrainIdea(0, "I want to sleep.");
	cat->setBrainIdea(1, "Where's the mouse?");

	cout << "Dog's Brain Idea 0: " << dog->getBrainIdea(0) << endl;
	cout << "Dog's Brain Idea 1: " << dog->getBrainIdea(1) << endl;
	cout << "Cat's Brain Idea 0: " << cat->getBrainIdea(0) << endl;
	cout << "Cat's Brain Idea 1: " << cat->getBrainIdea(1) << endl;

	cout << "\n----- Deep Copy Test -----" << endl;

	Dog* copyDog = new Dog(*dog);

	cout << "Original Dog Brain Idea 0: " << dog->getBrainIdea(0) << endl;
	cout << "Copied Dog Brain Idea 0: " << copyDog->getBrainIdea(0) << endl;

	dog->setBrainIdea(0, "I want to run!");
	cout << "Original Dog Brain Idea 0 (changed): " << dog->getBrainIdea(0) << endl;
	cout << "Copied Dog Brain Idea 0 (should be unchanged): " << copyDog->getBrainIdea(0) << endl;

	delete dog;
	delete cat;
	delete copyDog;

	cout << "\n----- WrongAnimal Test -----" << endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	cout << "WrongAnimal Type: " << wrongAnimal->getType() << endl;
	cout << "WrongCat Type: " << wrongCat->getType() << endl;

	wrongAnimal->makeSound();
	wrongCat->makeSound();

	delete wrongAnimal;
	delete wrongCat;

	return 0;
}
