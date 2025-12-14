#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    std::cout << "=== Creating array of Animals ===" << std::endl;
    const Animal* meta[4];
    for (int i = 0; i < 2; i++)
        meta[i] = new Dog();
    for (int i = 2; i < 4; i++)
        meta[i] = new Cat();

    std::cout << "\n=== Testing types and sounds ===" << std::endl;
    for (int i = 0; i < 4; i++)
        std::cout << meta[i]->getType() << " " << std::endl;
    for (int i = 0; i < 4; i++)
        meta[i]->makeSound();
    
    std::cout << "\n=== Testing deep copy ===" << std::endl;
    Dog original;
    original.getBrain()->setIdea(0, "Original idea");
    
    Dog copy = original;
    std::cout << "\nModifying copy's brain..." << std::endl;
    copy.getBrain()->setIdea(0, "Modified idea");
    
    std::cout << "Original brain idea[0]: " << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy brain idea[0]: " << copy.getBrain()->getIdea(0) << std::endl;
    std::cout << "Original brain address: " << original.getBrain() << std::endl;
    std::cout << "Copy brain address: " << copy.getBrain() << std::endl;
    
    std::cout << "\n=== Deleting animals ===" << std::endl;
    for (int i = 0; i < 4; i++)
        delete meta[i];
    
    return 0;
}