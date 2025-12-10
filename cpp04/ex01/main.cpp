#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=== Test 1: Subject test ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j; // should not create a leak
    delete i;

    std::cout << "\n=== Test 2: Array of Animals ===" << std::endl;
    const int arraySize = 10;
    Animal* animals[arraySize];
    
    // Fill half with Dogs
    std::cout << "\nCreating Dogs:" << std::endl;
    for (int idx = 0; idx < arraySize / 2; idx++)
    {
        animals[idx] = new Dog();
    }
    
    // Fill half with Cats
    std::cout << "\nCreating Cats:" << std::endl;
    for (int idx = arraySize / 2; idx < arraySize; idx++)
    {
        animals[idx] = new Cat();
    }
    
    // Make sounds
    std::cout << "\nMaking sounds:" << std::endl;
    for (int idx = 0; idx < arraySize; idx++)
    {
        std::cout << animals[idx]->getType() << ": ";
        animals[idx]->makeSound();
    }
    
    // Delete all
    std::cout << "\nDeleting all animals:" << std::endl;
    for (int idx = 0; idx < arraySize; idx++)
    {
        delete animals[idx];
    }

    std::cout << "\n=== Test 3: Deep copy test - Dog ===" << std::endl;
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "I love bones!");
    originalDog.getBrain()->setIdea(1, "I want to play fetch!");
    
    std::cout << "\nCreating copy of dog:" << std::endl;
    Dog copiedDog(originalDog);
    
    std::cout << "\nOriginal dog's ideas:" << std::endl;
    std::cout << "Idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << originalDog.getBrain()->getIdea(1) << std::endl;
    
    std::cout << "\nCopied dog's ideas:" << std::endl;
    std::cout << "Idea 0: " << copiedDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << copiedDog.getBrain()->getIdea(1) << std::endl;
    
    std::cout << "\nModifying original dog's brain:" << std::endl;
    originalDog.getBrain()->setIdea(0, "I changed my mind!");
    
    std::cout << "\nOriginal dog's idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied dog's idea 0 (should be unchanged): " << copiedDog.getBrain()->getIdea(0) << std::endl;
    
    std::cout << "\nBrain addresses (should be different):" << std::endl;
    std::cout << "Original brain: " << originalDog.getBrain() << std::endl;
    std::cout << "Copied brain: " << copiedDog.getBrain() << std::endl;

    std::cout << "\n=== Test 4: Deep copy test - Cat ===" << std::endl;
    Cat originalCat;
    originalCat.getBrain()->setIdea(0, "I love fish!");
    originalCat.getBrain()->setIdea(1, "Sleeping is great!");
    
    std::cout << "\nCreating copy of cat:" << std::endl;
    Cat copiedCat(originalCat);
    
    std::cout << "\nOriginal cat's ideas:" << std::endl;
    std::cout << "Idea 0: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << originalCat.getBrain()->getIdea(1) << std::endl;
    
    std::cout << "\nCopied cat's ideas:" << std::endl;
    std::cout << "Idea 0: " << copiedCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << copiedCat.getBrain()->getIdea(1) << std::endl;
    
    std::cout << "\nModifying copied cat's brain:" << std::endl;
    copiedCat.getBrain()->setIdea(0, "I prefer milk now!");
    
    std::cout << "\nOriginal cat's idea 0 (should be unchanged): " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied cat's idea 0: " << copiedCat.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n=== Test 5: Assignment operator test ===" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "First dog's idea");
    
    Dog dog2;
    dog2.getBrain()->setIdea(0, "Second dog's idea");
    
    std::cout << "\nBefore assignment:" << std::endl;
    std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;
    
    std::cout << "\nAssigning dog1 to dog2:" << std::endl;
    dog2 = dog1;
    
    std::cout << "\nAfter assignment:" << std::endl;
    std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;
    
    std::cout << "\nModifying dog1's brain:" << std::endl;
    dog1.getBrain()->setIdea(0, "Modified idea");
    
    std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea (should be unchanged): " << dog2.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
}