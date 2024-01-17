/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshikuro <keshikuro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 05:15:32 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/17 17:23:39 by keshikuro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <limits>
#include <cctype>
#include <climits>
#include "is_something.hpp"

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define SPECIAL 5
#define INVALID 6

class ScalarConverter {
	public :
	
		static void convert(const std::string& s);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &cpy);
		ScalarConverter& operator=(ScalarConverter const &cpy);
		virtual ~ScalarConverter() = 0;
		
		class invalid_input_exeption : public std::exception {
			public :
				virtual const char * what() const throw();
		};
};

#endif


/*                 POURQUOI "STATIC VOID"                */

/*Dans le contexte de cet exercice, la fonction convert est déclarée 
comme statique dans la classe ScalarConverter pour indiquer qu'elle appartient 
à la classe elle-même plutôt qu'à une instance particulière de la classe. 
Il y a quelques raisons pour lesquelles cela peut être approprié dans ce 
cas spécifique :

Pas de données d'instance : La classe ScalarConverter est conçue de manière 
à ne pas avoir de données membres (variables d'instance). La fonction convert 
ne nécessite aucune information spécifique à une instance particulière de la 
classe pour effectuer la conversion. 
Déclarer la fonction comme statique indique que la conversion peut être effectuée 
indépendamment de toute instance de la classe.

Faciliter l'utilisation : Les méthodes statiques peuvent être appelées directement 
à partir de la classe sans nécessiter la création d'une instance. 
ela peut rendre l'utilisation de la classe plus simple et plus intuitive, 
en particulier lorsque la classe est conçue pour fournir des services ou des 
fonctionnalités sans avoir besoin d'être instanciée.

Conventions de conception : Dans certains cas, les méthodes statiques sont 
utilisées pour des fonctions utilitaires qui n'ont pas besoin d'accéder à des 
données d'instance. Cela peut être une convention de conception pour indiquer 
que la fonction ne dépend pas de l'état interne de l'objet.
*/