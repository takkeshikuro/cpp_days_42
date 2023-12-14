/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 04:25:00 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/14 04:09:24 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;
	
	std::cout << "addr de str : " << &str << std::endl;
	std::cout << "addr stocke dans PTR : " << stringPTR << std::endl;
	std::cout << "addr stocke dans REF : " << &stringREF << std::endl;

	std::cout << "valeur de str : " << str << std::endl;
	std::cout << "valeur pointe par PTR : " << *stringPTR << std::endl;
	std::cout << "valeur pointe par REF : " << stringREF << std::endl;
	return 0;
}

/*Éviter la copie inutile : Lorsqu'une fonction est appelée avec un objet 
en tant que paramètre, la copie de cet objet peut être évitée en utilisant 
une référence. Cela peut améliorer les performances, surtout pour des objets volumineux.

Modification d'objets : Les références permettent de modifier l'objet référencé. 
Si une référence est passée à une fonction, 
toute modification de l'objet à l'intérieur de la fonction affectera l'objet d'origine.

Les références ne peuvent pas être nulles. 
Une référence doit être initialisée lors de sa déclaration, ce qui élimine le risque 
de pointer vers une zone mémoire non valide.

*/