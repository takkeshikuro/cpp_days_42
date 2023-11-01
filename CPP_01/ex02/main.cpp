/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 04:25:00 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/01 05:48:32 by tmorikaw         ###   ########.fr       */
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

/*
1- Vous déclarez une chaîne de caractères str contenant la valeur "HI THIS IS BRAIN".

2- Vous créez un pointeur stringPTR de type std::string* qui pointe vers 
l'adresse mémoire de la chaîne str en utilisant l'opérateur &. 
Cela signifie que stringPTR stocke l'adresse mémoire où str est stockée.

3- Vous créez une référence stringREF de type std::string& qui référence la variable str. 
Cela signifie que stringREF est un alias de str ; les deux variables se réfèrent 
à la même zone mémoire.

4- Vous utilisez std::cout pour afficher les adresses et les valeurs des variables :
#Vous affichez l'adresse de str avec &str.
#Vous affichez l'adresse stockée dans stringPTR qui est l'adresse de str.
#Vous affichez l'adresse stockée dans stringREF qui est également l'adresse de str.
#Vous affichez la valeur de str, qui est la chaîne de caractères "HI THIS IS BRAIN".
#Vous affichez la valeur pointée par stringPTR avec *stringPTR, ce qui donne également 
la chaîne de caractères "HI THIS IS BRAIN".
#Vous affichez la valeur référencée par stringREF, qui est également la chaîne 
de caractères "HI THIS IS BRAIN".

Toutes les sorties devraient être identiques car str, stringPTR, et stringREF font 
référence à la même chaîne de caractères et partagent la même adresse mémoire.*/