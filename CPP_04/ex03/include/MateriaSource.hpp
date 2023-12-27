/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 04:25:38 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/27 06:05:28 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <string>
#include <cstdlib> //exit
#include <sstream>
#include "AMateria.hpp"

class AMateria;

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria* m) = 0;
		virtual AMateria* createMateria(std::string const &type) = 0;
};

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		~MateriaSource();

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const &type);

	private:
		AMateria* learnedMaterias[4]; // Maximum 4 Materias
};

#endif