/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:10:34 by keshikuro         #+#    #+#             */
/*   Updated: 2024/01/31 04:00:14 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

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

class ErrorDuringIss : public std::exception {
	public :
		virtual const char *what() const throw();
};

class ErrorBadInputInvalidChar : public std::exception {
	public :
		virtual const char *what() const throw();
};

class ErrorBadInputMoreThanOne : public std::exception {
	public :
		virtual const char *what() const throw();
};

class ErrorInputOverTen : public std::exception {
	public :
		virtual const char *what() const throw();
};

class ErrorDivByZero : public std::exception {
	public :
		virtual const char *what() const throw();
};

double ope_rpn(std::string &input);

#endif