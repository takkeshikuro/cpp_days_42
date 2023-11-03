/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshikuro <keshikuro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:07:23 by keshikuro         #+#    #+#             */
/*   Updated: 2023/11/03 13:07:25 by keshikuro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Harl.hpp"

Harl::Harl() {}	

Harl::~Harl() {}

void Harl::debug() {
	std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger. I really do !";
	std::cout << std::endl << std::endl;
}

void Harl::info() {
	std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more ! ";
	std::cout << "If you did, I wouldn’t be asking for more !" <<  std::endl;
	std::cout << std::endl;
}

void Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started working here since ";
	std::cout << "last month." <<  std::endl << std::endl;
}

void Harl::error() {
	std::cout << "[ ERROR ]" << std::endl << "This is unacceptable ! ";
	std::cout << "I want to speak to the manager now." <<  std::endl << std::endl;
	
}