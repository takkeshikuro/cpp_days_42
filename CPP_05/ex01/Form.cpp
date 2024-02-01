/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:33:38 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/04 03:34:35 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Form.hpp"

Form::Form() : _name("default"), _is_signed(FALSE), _grade_sign(100), 
_grade_exec(150) {
	std::cout << "[Form default constructor called]" << std::endl;
	std::cout << std::endl;
	return ;
}

Form::Form(std::string name, int grade_sign, int grade_exec) :_name(name), 
_is_signed(FALSE), _grade_sign(grade_sign), _grade_exec(grade_exec) {
	std::cout << "[Form normal constructor called]" << std::endl;
	std::cout << std::endl;
	if (grade_sign > 150 || grade_exec > 150)
		throw GradeTooLowException();
	else if (grade_sign < 1 || grade_exec < 1)
		throw GradeTooHighException();
	return ;
}

Form::Form(Form const &cpy) : _name(cpy._name), 
_is_signed(FALSE), _grade_sign(cpy._grade_sign), _grade_exec(cpy._grade_exec) {
	std::cout << "[Form copy constructor called]" << std::endl;
	std::cout << std::endl;
	return ;
}

Form &Form::operator=(Form const &cpy) {
	std::cout << "[Form copy assignment operator called]" << std::endl;
	std::cout << std::endl;
	if (this != &cpy)
		this->_is_signed = cpy._is_signed; // a voir
	return *this;
}

Form::~Form() {
	std::cout << "[Form destructor called]" << std::endl;
}

const char *Form::GradeTooHighException::what() const throw() {
		return "grade out of the range : too high.";
}

const char *Form::GradeTooLowException::what() const throw() {
		return "grade out of the range : too low.";
}

const std::string Form::getName() const { return _name; }

bool Form::get_sign_bool() const { return _is_signed; }

int Form::getGradeSign() const { return _grade_sign; }

int Form::getGradeExec() const { return _grade_exec; }

/*
void	Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _grade_sign)
		throw GradeTooLowException();
	else
		_is_signed = TRUE;
}*/

void   Form::beSigned(Bureaucrat &boy) {
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


std::ostream	&operator<<( std::ostream & o, Form const &ok)
{	
	o << "|Form " << ok.getName();
	if (ok.get_sign_bool() == FALSE)
		o << " is not signed yet." << std::endl;
	else
		o << " is already signed." << std::endl;
	o << "|[required grade " << ok.getGradeSign() << " to sign]" << std::endl;
	o << "|[and grade " << ok.getGradeExec() << " to execute]" << std::endl;
	return o;
}