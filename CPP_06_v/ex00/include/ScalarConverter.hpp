/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 05:15:32 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/06 08:15:44 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <limits>
#include <cctype>
#include <climits>
#include "is_something.hpp"

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define SPECIAL 5
#define INVALID 6

class ScalarConverter {
	public :
		static void convert(const std::string& s);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &cpy);
		ScalarConverter& operator=(ScalarConverter const &cpy);
		~ScalarConverter();
		class invalid_input_exeption : public std::exception {
			public :
				virtual const char * what() const throw();
		};
};

#endif
