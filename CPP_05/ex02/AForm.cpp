/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:33:38 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/04 03:32:16 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/AForm.hpp"

AForm::AForm() : _name("default"), _is_signed(FALSE), _grade_sign(100), 
_grade_exec(150) {
	std::cout << "[AForm default constructor called]" << std::endl;
	std::cout << std::endl;
	return ;
}

AForm::AForm(std::string name, int grade_sign, int grade_exec) :_name(name), 
_is_signed(FALSE), _grade_sign(grade_sign), _grade_exec(grade_exec) {
	std::cout << "[AForm normal constructor called]" << std::endl;
	std::cout << std::endl;

	if (grade_sign > 150 || grade_exec > 150)
		throw GradeTooLowException();
	else if (grade_sign < 1 || grade_exec < 1)
		throw GradeTooHighException();
}

AForm::AForm(AForm const &cpy) : _name(cpy._name), 
_is_signed(FALSE), _grade_sign(cpy._grade_sign), _grade_exec(cpy._grade_exec) {
	std::cout << "[AForm copy constructor called]" << std::endl;
	std::cout << std::endl;
	return ;
}

AForm &AForm::operator=(AForm const &cpy) {
	std::cout << "[AForm copy assignment operator called]" << std::endl;
	std::cout << std::endl;
	if (this != &cpy)
		this->_is_signed = cpy._is_signed; // a voir
	return *this;
}

AForm::~AForm() {
	std::cout << "[AForm destructor called]" << std::endl;
}


const char *AForm::GradeTooHighException::what() const throw() {
		return "grade out of the range : too high.";
}

const char *AForm::GradeTooLowException::what() const throw() {
		return "grade out of the range : too low.";
}


const std::string AForm::getName() const { return _name; }

bool AForm::get_sign_bool() const { return _is_signed; }

int AForm::getGradeSign() const { return _grade_sign; }

int AForm::getGradeExec() const { return _grade_exec; }


void   AForm::beSigned(Bureaucrat &boy) {
	if (_is_signed == FALSE) {
		if (boy.getGrade() <= _grade_sign) {
			_is_signed = TRUE;
			boy.signForm(0, this->getName());
			return ;
		}
		else {
			boy.signForm(1, this->getName());
			return ;
		}
	}
	boy.signForm(2, this->getName());
}

std::ostream	&operator<<( std::ostream & o, AForm const &ok)
{	
	o << "|AForm " << ok.getName();
	if (ok.get_sign_bool() == FALSE)
		o << " is not signed yet." << std::endl;
	else
		o << " is already signed." << std::endl;
	o << "|[required grade " << ok.getGradeSign() << " to sign]" << std::endl;
	o << "|[and grade " << ok.getGradeExec() << " to execute]" << std::endl;
	return o;
}