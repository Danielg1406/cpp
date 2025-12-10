#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Test 1: Subject tests ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== Test 2: Wrong classes (no polymorphism) ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // will output WrongAnimal sound (not polymorphic!)
    wrongMeta->makeSound();
    
    delete wrongMeta;
    delete wrongCat;

    std::cout << "\n=== Test 3: Direct instantiation ===" << std::endl;
    Dog dog;
    Cat cat;
    
    std::cout << "Dog type: " << dog.getType() << std::endl;
    dog.makeSound();
    std::cout << "Cat type: " << cat.getType() << std::endl;
    cat.makeSound();

    std::cout << "\n=== Test 4: Copy constructor ===" << std::endl;
    Dog originalDog;
    Dog copiedDog(originalDog);
    copiedDog.makeSound();

    std::cout << "\n=== Test 5: Array of Animals ===" << std::endl;
    const Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();
    
    for (int idx = 0; idx < 4; idx++)
    {
        std::cout << "Animal " << idx << " is a " << animals[idx]->getType() << ": ";
        animals[idx]->makeSound();
    }
    
    for (int idx = 0; idx < 4; idx++)
    {
        delete animals[idx];
    }

    std::cout << "\n=== Test 6: Demonstrating polymorphism difference ===" << std::endl;
    std::cout << "\nCorrect polymorphism (Animal*):" << std::endl;
    Animal* polymorphicCat = new Cat();
    polymorphicCat->makeSound(); // Cat sound
    delete polymorphicCat;
    
    std::cout << "\nWrong polymorphism (WrongAnimal*):" << std::endl;
    WrongAnimal* nonPolymorphicCat = new WrongCat();
    nonPolymorphicCat->makeSound(); // WrongAnimal sound (not WrongCat!)
    delete nonPolymorphicCat;

    return 0;
}