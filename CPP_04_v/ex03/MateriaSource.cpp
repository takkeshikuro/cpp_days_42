/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 05:06:05 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/28 03:01:04 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {
	for (int i = 0; i < 4; i++)
		learnedMaterias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &cpy) : IMateriaSource(cpy) {
	for (int i = 0; i < 4; i++) {
		if (cpy.learnedMaterias[i])
			learnedMaterias[i] = cpy.learnedMaterias[i];
		else
			learnedMaterias[i] = NULL;
	}	
}

MateriaSource &MateriaSource::operator=(MateriaSource const &cpy) {
	if (this != &cpy) 
	{
		for (int i = 0; i < 4; i++) 
		{
			if (cpy.learnedMaterias[i])
				learnedMaterias[i] = cpy.learnedMaterias[i];
			else
				learnedMaterias[i] = NULL;
		}		
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
	{
		if (learnedMaterias[i])
			delete learnedMaterias[i];
	}
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
