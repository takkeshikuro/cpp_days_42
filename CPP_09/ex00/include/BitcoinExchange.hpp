/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 07:02:14 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/26 09:13:24 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <fstream>
#include <sstream>
#include <ios>



class Data {
	public :
		Data();
		Data(Data const &cpy);
		Data &operator=(Data const &cpy);
		~Data();


		class BadInput : public std::exception {
			virtual const char *what() const throw();
		};

		class GetDataLineError : public std::exception {
			virtual const char *what() const throw();
		};

		
		void    read_data_file(std::ifstream &ifs);
		float	get_price(std::string date) const;
		void	print_line(std::string date, float exchange_rate);
		
	private :
		
		std::map<std::string, float> data_history;
};

#endif