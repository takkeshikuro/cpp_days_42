/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 02:00:05 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/31 04:02:17 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/RPN.hpp"

const char *ErrorDuringIss::what() const throw() {
	return "error when using iss.";
}

const char *ErrorBadInputInvalidChar::what() const throw() {
	return "invalid character into input.";
}

const char *ErrorBadInputMoreThanOne::what() const throw() {
	return "more than one value after full operation.";
}

const char *ErrorInputOverTen::what() const throw() {
	return "Value into input is over 10";
}

const char *ErrorDivByZero::what() const throw() {
	return "You tryed to div something by zero!";
}

double ope_rpn(std::string &input)
{
	std::stack<double> ope_stack;
	
	std::istringstream iss(input);
	std::string token;

	while (iss >> token) 
	{
		double value;
		if (iss.fail())
			throw ErrorDuringIss();
		if (isdigit(token[0]))
		{
			std::istringstream(token) >> value;
			if (value < 0 || value >= 10)
				throw ErrorInputOverTen();
			ope_stack.push(value);
		}
		else 
		{
			if (ope_stack.size() <= 1)
				throw ErrorBadInputInvalidChar();
			double operand2 = ope_stack.top();
			ope_stack.pop();
			double operand1 = ope_stack.top();
			ope_stack.pop();
			if (token == "+")
				ope_stack.push(operand1 + operand2);
			else if (token == "-")
				ope_stack.push(operand1 - operand2);
			else if (token == "*")
				ope_stack.push(operand1 * operand2);
			else if (token == "/") {
				if (operand2 == 0)
					throw ErrorDivByZero();
				ope_stack.push(operand1 / operand2);
			}
		}
	}
	if (ope_stack.size() != 1)
		throw ErrorBadInputMoreThanOne();
	return ope_stack.top();
}