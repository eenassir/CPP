/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 01:29:24 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/18 00:43:20 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        this->templates[i] = NULL;
    }
}

MateriaSource::MateriaSource(MateriaSource const & src) {
    for (int i = 0; i < 4; i++) {
        this->templates[i] = NULL;
    }
    
    for (int i = 0; i < 4; i++) {
        if (src.templates[i] != NULL) {
            this->templates[i] = src.templates[i]->clone();
        }
    }
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 4; i++) {
            if (this->templates[i] != NULL) {
                delete this->templates[i];
                this->templates[i] = NULL;
            }
        }
        
        for (int i = 0; i < 4; i++) {
            if (rhs.templates[i] != NULL) {
                this->templates[i] = rhs.templates[i]->clone();
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] != NULL)   
            delete templates[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (m == NULL)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (this->templates[i] == NULL)
        {
            this->templates[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->templates[i] != NULL && this->templates[i]->getType() == type)
            return this->templates[i]->clone();
    }
    return NULL;
}