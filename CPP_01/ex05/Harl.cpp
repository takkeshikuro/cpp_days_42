/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 06:32:00 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/02 09:04:25 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Harl.hpp"

Harl::Harl() {
/* 	mapping_level["debug"] = &Harl::debug;
	mapping_level["info"] = &Harl::info;
	mapping_level["warning"] = &Harl::warning;
	mapping_level["error"] = &Harl::error; */
}

Harl::~Harl() {}

void Harl::debug() {
	std::cout << "debug" <<  std::endl;
}

void Harl::info() {
	std::cout << "debug" <<  std::endl;
}

void Harl::warning() {
	std::cout << "debug" <<  std::endl;
}

void Harl::error() {
	std::cout << "debug" <<  std::endl;
}