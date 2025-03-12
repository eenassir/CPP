/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 07:48:29 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/12 00:12:09 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete(meta);
    delete(j);
    delete(i);

    Cat j1;
    Dog i1;
    Animal meta2(j1), meta3(i1);

    meta2.makeSound();
    j1.getType();
    i1.getType();
    meta3.makeSound();

    const WrongAnimal* meta1 = new WrongAnimal();
    const WrongAnimal *Cat = new WrongCat();

    std::cout << meta1->getType() << " " << std::endl;
    std::cout << Cat->getType() << " " << std::endl;
    
    meta1->makeSound();
    Cat->makeSound();

    delete(meta1);
    delete(Cat);
    
    return 0;
}