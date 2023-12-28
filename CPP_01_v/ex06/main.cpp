/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshikuro <keshikuro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:04:28 by keshikuro         #+#    #+#             */
/*   Updated: 2023/11/03 13:25:35 by keshikuro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Harl.hpp"

void Harl::complain(std::string level) 
{
	void (Harl::*p_function[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			int ok = i;
			while (ok < 4)
			{
				switch (ok) 
				{
					case 0:
						(this->*p_function[ok])();
						break;
					case 1:
						(this->*p_function[ok])();
						break;
					case 2:
						(this->*p_function[ok])();
						break;
					case 3:
						(this->*p_function[ok])();
						break;
				}
				ok++;
			}
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return ;
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string level = av[1];
		if (!level.empty())
		{
			Harl harl;
			harl.complain(level);
			return 0;
		}
	}
	std::cout << "use ./HarlFilter with DEBUG/INFO/WARNING/ERROR " << std::endl;	
	return 0;
}
