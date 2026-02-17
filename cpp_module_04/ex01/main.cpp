/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 07:48:29 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/18 11:21:46 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

int main() {
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        const Animal* meta = new Animal();
        
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();
        
        delete meta;
        delete j;
        delete i;
    }
    
    {
        Dog *original = new Dog();
        original->getBrain()->setIdea(0, "I want to chase squirrels");
        
        Dog *copy = new Dog(*original);
        std::cout << "Original dog's idea: " << original->getBrain()->getIdea(0) << std::endl;
        std::cout << "Copied dog's idea: " << copy->getBrain()->getIdea(0) << std::endl;
        
        original->getBrain()->setIdea(0, "I want to sleep");
        std::cout << "After change - Original dog's idea: " << original->getBrain()->getIdea(0) << std::endl;
        std::cout << "After change - Copied dog's idea: " << copy->getBrain()->getIdea(0) << std::endl;
        
        delete original;
        delete copy;
    }
    
    {
        const int count = 6;
        Animal *animals[count];
        
        for (int i = 0; i < count; i++) {
            if (i < count / 2)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }
        for (int i = 0; i < count; i++) {
            delete animals[i];
        }
    }
    
    return 0;
}