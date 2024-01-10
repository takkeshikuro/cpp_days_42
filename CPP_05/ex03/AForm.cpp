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
_grade_exec(150) 
{}

AForm::AForm(std::string name, int grade_sign, int grade_exec) :_name(name), 
_is_signed(FALSE), _grade_sign(grade_sign), _grade_exec(grade_exec) 
{
	if (grade_sign > 150 || grade_exec > 150)
		throw GradeTooLowException();
	else if (grade_sign < 1 || grade_exec < 1)
		throw GradeTooHighException();
}

AForm::AForm(AForm const &cpy) : _name(cpy._name), 
_is_signed(FALSE), _grade_sign(cpy._grade_sign), _grade_exec(cpy._grade_exec) 
{}

AForm &AForm::operator=(AForm const &cpy) 
{
	if (this != &cpy)
		this->_is_signed = cpy._is_signed; // a voir
	return *this;
}

AForm::~AForm() {}

///////////////////////////////////////////////////////////////////////////////////////////

const char *AForm::GradeTooHighException::what() const throw() {
		return "grade out of the range : too high. (exeption)";
}

const char *AForm::GradeTooLowException::what() const throw() {
		return "grade out of the range : too low. (exeption)";
}

const std::string AForm::getName() const { return _name; }

bool AForm::get_sign_bool() const { return _is_signed; }

int AForm::getGradeSign() const { return _grade_sign; }

int AForm::getGradeExec() const { return _grade_exec; }


int   AForm::beSigned(Bureaucrat &boy) 
{
	if (_is_signed == TRUE)						// can't sign bc form statue
		return 1;	
	else if (boy.getGrade() > _grade_sign)		// can't sign bc grade
		return 2;
	else 
	{										// can sign
		_is_signed = TRUE;
		return 3;
	}										
}

int AForm::execute(Bureaucrat const & executor) const 
{	
	if (_is_signed == FALSE)						// can't exec bc not signed
		return 1;
	else if (executor.getGrade() > getGradeExec())  // can't exec bc grade
		return 2;
	else 											// can exec good
	{
		this->make_action();
		return 3;
	}
}

std::ostream	&operator<<( std::ostream & o, AForm const &ok)
{	
	o << "AForm " << ok.getName();
	if (ok.get_sign_bool() == FALSE)
		o << " (not signed yet)" << std::endl;
	else
		o << " (already signed)" << std::endl;
	o << "|(info)[required grade " << ok.getGradeSign() << " to sign / ";
	o << ok.getGradeExec() << " to execute]" << std::endl;
	return o;
}
