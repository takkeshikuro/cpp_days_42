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

AForm::AForm() : _name("default"), _is_signed(FALSE), _grade_sign(150), 
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
{
	if (cpy._grade_sign > 150 || cpy._grade_exec > 150)
		throw GradeTooLowException();
	else if (cpy._grade_sign < 1 || cpy._grade_exec < 1)
		throw GradeTooHighException();
}

AForm &AForm::operator=(AForm const &cpy) 
{
	if (this != &cpy)
		this->_is_signed = cpy._is_signed;
	return *this;
}

AForm::~AForm() {}

//////////////getter&exception/////////////////////////////////////////////////////////////

const char *AForm::GradeTooHighException::what() const throw() {
		return "grade out of the range : too high. (exeption)";
}

const char *AForm::GradeTooLowException::what() const throw() {
		return "grade out of the range : too low. (exeption)";
}

const char *AForm::FormAlreadySignExeption::what() const throw() {
		return "Form is already signed. (exeption)";
}

const char *AForm::FormNotSignedExeption::what() const throw() {
		return "Form is not signed yet. (exeption)";
}

const char *AForm::GradetooLowToExec::what() const throw() {
	return "Actual bureaucrat's grade is too low to exec.";
}

const std::string AForm::getName() const {
	return _name;
}

bool AForm::get_sign_bool() const {
	return _is_signed;
}

int AForm::getGradeSign() const {
	return _grade_sign;
}

int AForm::getGradeExec() const {
	return _grade_exec;
}

//////////////be_signed&execute/////////////////////////////////////////////////////////////

void	AForm::beSigned(const Bureaucrat &bureaucrat) 
{
	if (bureaucrat.getGrade() > _grade_sign)
		throw GradeTooLowException();
	else
		_is_signed = TRUE;
}

void	AForm::execute(Bureaucrat const &executor) const 
{	
	if (_is_signed == FALSE)						// can't exec bc not signed
		throw FormNotSignedExeption();
	else if (executor.getGrade() > _grade_exec)  // can't exec bc grade
		throw GradetooLowToExec();
	else 											// can exec good
	{
		this->make_action();
		return;
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
