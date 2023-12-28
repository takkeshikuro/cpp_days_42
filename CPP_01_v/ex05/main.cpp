/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshikuro <keshikuro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 06:42:41 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/03 12:55:23 by keshikuro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Harl.hpp"

void Harl::complain(std::string level) 
{
	void (Harl::*p_function[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"debug", "info", "warning", "error"};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			return (this->*p_function[i])();
	}
	std::cout << "No msg" << std::endl;
	return ;
}

int main(void)
{
	Harl harl;
	harl.complain("error");
	harl.complain("debug");
	harl.complain("warning");
	harl.complain("info");
	harl.complain("ok");
	return 0;
}