#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=== Test 1: Cannot instantiate Animal (commented out) ===" << std::endl;
    // Animal animal; // This will NOT compile - Animal is abstract!
    // const Animal* test = new Animal(); // This will NOT compile either!
    std::cout << "Animal class is abstract and cannot be instantiated." << std::endl;

    std::cout << "\n=== Test 2: Can instantiate Dog and Cat ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    j->makeSound();
    i->makeSound();
    
    delete j;
    delete i;

    std::cout << "\n=== Test 3: Array of Animals ===" << std::endl;
    const int arraySize = 6;
    Animal* animals[arraySize];
    
    std::cout << "\nCreating Dogs:" << std::endl;
    for (int idx = 0; idx < arraySize / 2; idx++)
    {
        animals[idx] = new Dog();
    }
    
    std::cout << "\nCreating Cats:" << std::endl;
    for (int idx = arraySize / 2; idx < arraySize; idx++)
    {
        animals[idx] = new Cat();
    }
    
    std::cout << "\nMaking sounds:" << std::endl;
    for (int idx = 0; idx < arraySize; idx++)
    {
        std::cout << animals[idx]->getType() << ": ";
        animals[idx]->makeSound();
    }
    
    std::cout << "\nDeleting all animals:" << std::endl;
    for (int idx = 0; idx < arraySize; idx++)
    {
        delete animals[idx];
    }

    std::cout << "\n=== Test 4: Deep copy still works ===" << std::endl;
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "I love bones!");
    
    Dog copiedDog(originalDog);
    
    std::cout << "\nOriginal dog's idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied dog's idea: " << copiedDog.getBrain()->getIdea(0) << std::endl;
    
    originalDog.getBrain()->setIdea(0, "Changed idea!");
    
    std::cout << "\nAfter modification:" << std::endl;
    std::cout << "Original dog's idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied dog's idea (unchanged): " << copiedDog.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n=== Test 5: Polymorphism still works ===" << std::endl;
    Animal* polymorphicDog = new Dog();
    Animal* polymorphicCat = new Cat();
    
    std::cout << "Dog says: ";
    polymorphicDog->makeSound();
    std::cout << "Cat says: ";
    polymorphicCat->makeSound();
    
    delete polymorphicDog;
    delete polymorphicCat;

    std::cout << "\n=== Test 6: Direct instantiation works ===" << std::endl;
    Dog dog;
    Cat cat;
    
    dog.makeSound();
    cat.makeSound();

    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
}