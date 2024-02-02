/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:21:47 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/02 02:53:54 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default_name"), _grade(150) 
{}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) 
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &cpy)
{
	*this = cpy;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &cpy) 
{
	if (this != &cpy)
		_grade = cpy.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() 
{}

//////////////getter&exception/////////////////////////////////////////////////////////////

const char *Bureaucrat::GradeTooHighException::what() const throw() {
		return "grade out of the range : too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
		return "grade out of the range : too low.";
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const { 
	return _grade; 
}

//////////////grade_increment/decrement////////////////////////////////////////////////////////

void	Bureaucrat::grade_increment() 
{
	if ((_grade - 1) < 1)
		throw GradeTooHighException();
	this->_grade -= 1;
	std::cout << "-(" << getName() << " grade + 1)-" << std::endl;
}

void	Bureaucrat::grade_decrement() 
{
	if ((_grade + 1) > 150)
		throw GradeTooLowException();
	this->_grade += 1;
	std::cout << "-(" << getName() << " grade - 1)-" << std::endl;
}

//////////////sign&execute/////////////////////////////////////////////////////////////

void	Bureaucrat::signForm(AForm &form)
{
	if (_grade > form.getGradeSign())
	{
		std::cout << _name << " couldn't sign " << form.getName();
		std::cout << " because the bureaucrat don't have the required grade to sign." << std::endl;
	}
	else if (form.get_sign_bool() == TRUE)
	{
		std::cout << _name << " couldn't sign " << form.getName();
		std::cout << " because the form is already signed." << std::endl;
	}
	else
	{
		std::cout << _name << " signed " << form.getName() << std::endl;
		form.beSigned(*this);
	}
}

void	Bureaucrat::executeForm(AForm const &AForm)
{
	if (AForm.get_sign_bool() == FALSE)
	{
		std::cout << _name << " couldn't execute " << AForm.getName();
		std::cout << " because the form is not signed." << std::endl;
	}
	else if (_grade > AForm.getGradeExec()) 
	{
		std::cout << _name << " couldn't execute " << AForm.getName();
		std::cout << " because the bureaucrat don't have the required grade to sign.\n";
	}	

	else
	{
		std::cout << "+ " << _name << " executed ";
		std::cout << AForm.getName() << " +" << std::endl;
		AForm.execute(*this);
	}
}

std::ostream	&operator<<( std::ostream & o, Bureaucrat const &ok)
{	
	o << ok.getName() << ", bureaucrat grade ";
	if (ok.getGrade() >= 1 && ok.getGrade() <= 150)
		std::cout << ok.getGrade() << std::endl;
	else
		std::cout << "(no valid data)" << std::endl;
	return o;
}