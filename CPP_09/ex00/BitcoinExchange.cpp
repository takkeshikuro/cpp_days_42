/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 07:22:13 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/13 18:05:54 by tmorikaw         ###   ########.fr       */
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

// (1) read data.csv and stock all data
void	Data::read_data_file(std::ifstream &ifs) 
{	
	std::string line_buf;
	int i = 0;
	while (std::getline(ifs, line_buf))
	{
		if (i != 0)
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

void	Data::print_line(std::string date, float exchange_rate) 
{
	float price;
	std::map<std::string, float>::const_iterator it = data_history.find(date);
	
	if (it != data_history.end())
		price = it->second;
	else 
	{
		std::map<std::string, float>::const_iterator close_before = data_history.lower_bound(date);
		--close_before;
		price = close_before->second;
	}	
	std::cout << date << " => " << exchange_rate << " = " << (price * exchange_rate) << std::endl;
}


bool   Data::parse_value(std::string date)
{
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day  = date.substr(8, 2);

    if (std::atoi(year.c_str()) < 2009 || std::atoi(year.c_str()) > 2024)
		return 1;
    if (std::atoi(month.c_str()) < 1 || std::atoi(month.c_str()) > 12)
		return 1;
    if (std::atoi(day.c_str()) < 1 || std::atoi(day.c_str()) > 31)
		return 1;
    if (std::atoi(month.c_str()) == 4 || std::atoi(month.c_str()) == 5 
        || std::atoi(month.c_str()) == 9 || std::atoi(month.c_str()) == 11)
    {
        if (std::atoi(day.c_str()) > 30)
			return 1;
    }
    if (std::atoi(month.c_str()) == 2)
    {
        if (std::atoi(day.c_str()) > 29)
			return 1;
	}
	if (std::atoi(year.c_str()) == 2009 && std::atoi(month.c_str()) == 1  \
			&& std::atoi(day.c_str()) == 1)
		return 1;
	return 0;
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