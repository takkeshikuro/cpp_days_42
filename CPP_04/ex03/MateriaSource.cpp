/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 05:06:05 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/06 03:09:52 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {
//	std::cout << "M-Source default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		learnedMaterias[i] = NULL;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
	{
		if (learnedMaterias[i])
			delete learnedMaterias[i];
	}
//	std::cout << "M-Source destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m) {
	int i = 0;
	while (i < 4)
	{
		if (learnedMaterias[i])
			i++;
		else {   
			learnedMaterias[i] = m;
			std::cout << "materias learned." << std::endl;
			return ;
		}
	}
	std::cout << "no more space to learn" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++)
	{
		if (learnedMaterias[i] && learnedMaterias[i]->getType() == type)
		{
	 		std::cout << "Created " << type << " materia!" << std::endl;
			return learnedMaterias[i]->clone();
		}
	}
	std::cout << "Cannot create " << type << " materia, not found!" << std::endl;
	return NULL;
}