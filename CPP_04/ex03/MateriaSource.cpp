/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 05:06:05 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/20 07:52:17 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {
//	std::cout << "[MateriaSource default constructor called]" << std::endl;
//	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		learnedMaterias[i] = NULL;
}

//copy et operator= ???

MateriaSource::~MateriaSource() {
	//	std::cout << "[MateriaSource destructor called]" << std::endl;
	//	std::cout << std::endl;
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
