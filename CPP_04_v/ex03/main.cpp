/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 01:20:51 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/28 02:56:59 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/AMateria.hpp"
#include "include/MateriaSource.hpp"
#include "include/Ice.hpp"
#include "include/Cure.hpp"
#include "include/Character.hpp"

# define GREEN "\033[32m"
# define RESET "\033[0m"

void test1() {
	std::cout << std::endl;
	std::cout << GREEN  "[Test 1 (from subject.pdf)]" RESET << std::endl;
	std::cout << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	AMateria* tmp;
	
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	std::cout << std::endl;
}

void test2() {
	std::cout << std::endl;
	std::cout << GREEN  "[Test 2]" RESET << std::endl;
	std::cout << std::endl;

	IMateriaSource* src = new MateriaSource();
	ICharacter* me = new Character("me");
	Cure *cures[4 + 1];
	AMateria* tmp[4 + 1];

	for (int i = 0; i < 4 + 1; i++)
		cures[i] = new Cure();

	tmp[0] = src->createMateria("fire"); // try to create without learn
	tmp[0] = src->createMateria("cure");
	std::endl(std::cout);

	for (int i = 0; i < 4 + 1; i++)
		src->learnMateria(cures[i]); // learn all cure
	std::endl(std::cout);

	for (int i = 0; i < 4 + 1; i++)
		tmp[i] = src->createMateria("cure"); // create all cure
	std::endl(std::cout);

	for (int i = 0; i < 4 + 1; i++)
		me->equip(tmp[i]); 
	std::endl(std::cout);

	me->unequip(1);
	me->use(1, *me);
	std::endl(std::cout);

	me->unequip(4 + 1);
	me->use(3, *me);

	delete src;
	delete me;
	delete tmp[1];
	delete tmp[4];
	delete cures[4];
}

int main() {
	test1();
	test2();
	return 0;
}

/* int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}*/

//$> clang++ -W -Wall -Werror *.cpp
//$> ./a.out | cat -e
//* shoots an ice bolt at bob *$
//* heals bob's wounds *$ 