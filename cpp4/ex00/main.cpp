#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	const WrongAnimal *k = new WrongCat();

	cout << j->getType() << " " << endl;
	cout << i->getType() << " " << endl;
	cout << k->getType() << " " << endl;

	meta->makeSound();
	i->makeSound();
	j->makeSound();
	k->makeSound();

	delete i;
	delete j;
	delete k;
	delete meta;
	return 0;
}
