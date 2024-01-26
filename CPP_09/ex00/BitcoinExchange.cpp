/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 07:22:13 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/26 09:19:25 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/BitcoinExchange.hpp"

Data::Data() {}


Data::Data(Data const &cpy) {
	(void)cpy;
}

Data &Data::operator=(Data const &cpy) {
	if (this != &cpy)
		this->data_history = cpy.data_history;
	return *this;
}

Data::~Data() {}

const char *Data::BadInput::what() const throw() {
	return "bad input / can't read file";
}

const char *Data::GetDataLineError::what() const throw() {
	return "getline from data.csv failed during process.";
}

void	Data::read_data_file(std::ifstream &ifs) 
{	
	std::string line_buf;
	int i = 0;
	while (std::getline(ifs, line_buf))
	{
		if (i != 0) // pour skip la premiere ligne
		{
			
			if (ifs.fail())
				throw GetDataLineError();
			std::istringstream iss(line_buf);
			std::string date;
			float	price = 0;
			if (std::getline(iss, date, ',') && (iss >> price))
				data_history[date] = price;
			else
				throw GetDataLineError();
		}
		i++;
	}
	return ;
}

float	Data::get_price(std::string date) const {
	
	std::map<std::string, float>::const_iterator it = data_history.find(date);
	if (it != data_history.end())
		return it->second;
	else {
		std::map<std::string, float>::const_iterator close_before = data_history.lower_bound(date);
		if (close_before == data_history.begin())
			return -1;
		else {
			--close_before;
			return close_before->second;
		}
	}
}

void	Data::print_line(std::string date, float exchange_rate) {
	float price = get_price(date);
	if (price == -1)
		std::cout << "Error: bad input => " << date << std::endl;
	else if (exchange_rate < 0)
		std::cout << "Error: not a positive number." << std::endl;
	else if (exchange_rate > 1000)
		std::cout << "Error: too large a number." << std::endl;
	else
		std::cout << date << " => " << exchange_rate << " = " << (price * exchange_rate) << std::endl;
}

/*std::getline(iss, date, ',') : Cette fonction utilise iss 
pour extraire une sous-chaîne jusqu'à la première virgule (,) 
rencontrée dans la ligne du fichier et stocke le résultat dans 
la variable date.
(iss >> price) : Cette expression utilise iss pour extraire un 
nombre (le prix) à partir du flux, et stocke le résultat dans 
la variable price.
L'utilisation de std::istringstream permet de traiter chaque 
ligne du fichier comme une chaîne de caractères, et nous pouvons
extraire les parties de cette chaîne que nous souhaitons utiliser 
(date et prix, dans ce cas).*/