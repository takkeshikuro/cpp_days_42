/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 06:48:48 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/20 04:44:37 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/BitcoinExchange.hpp"

void	starting_point(std::ifstream &ifs_input)
{
	Data data;
	
	std::ifstream ifs_history("data.csv");
	data.read_data_file(ifs_history);
	ifs_history.close();
	
	std::string line_buf;
	int i = 0;
	while (std::getline(ifs_input, line_buf))
	{
		if (i != 0)
		{
			if (ifs_input.fail())
				throw Data::GetDataLineError();
			std::istringstream iss(line_buf);
			std::string date;
			float exchange_rate = 0;
			std::getline(iss >> std::ws, date, '|') && (iss >> exchange_rate);
			if (data.parse_value(date))
				std::cout << "Error: bad input => " << date << std::endl;
			else 
			{
				if (exchange_rate > 1000)
					std::cout << "Error: too large a number." << std::endl;
				else if (exchange_rate < 0)
					std::cout << "Error: not a positive number." << std::endl;
				else
					data.print_line(date, exchange_rate);
			}
		}
		i++;
	}
}

int main(int ac, char **av)
{
	try {
		if (ac == 2)
		{
			std::ifstream ifs_input(av[1]);
			if (ifs_input.is_open())
				starting_point(ifs_input);
			ifs_input.close();
		}
		else
			throw Data::BadInput();
	}
	catch (const std::exception &e) {
		std::cerr << "Error :" << e.what() << std::endl;
	}
}
