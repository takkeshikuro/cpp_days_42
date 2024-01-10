/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:21:47 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/10 06:11:38 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default_name"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) 
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &cpy) : _name(cpy._name), _grade(cpy._grade) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &cpy) 
{ // voir le _name
	if (this != &cpy) {
		_grade = cpy.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

//////////////////////////////////////////////////////////////////////////////////////////////

const char *Bureaucrat::GradeTooHighException::what() const throw() {
		return "grade out of the range : too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
		return "grade out of the range : too low.";
}

const char *Bureaucrat::FormAlreadySignExeption::what() const throw() {
		return "Form is already signed. (exeption)";
}

const char *Bureaucrat::FormNotSignedExeption::what() const throw() {
		return "Form is not signed yet. (exeption)";
}

std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

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


void	Bureaucrat::signForm(AForm &form) 
{
	int ok = form.beSigned(*this);
	
	if (ok == 1) // can't sign bc statue 
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << "'s official form";
		std::cout << " because the form is already signed." << std::endl;
		throw FormAlreadySignExeption();
	}
	else if (ok == 2)  // can't sign bc grade
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << "'s official form";
		std::cout << " because the bureaucrat don't have the required grade to sign." << std::endl;
		throw GradeTooLowException();
	}
	if (ok == 3)	// can sign
	{
		std::cout << "+ " << this->getName() << " signed ";
		std::cout << form.getName() << "'s official form +" << std::endl;

	} 
}

void	Bureaucrat::executeForm(AForm const & form) 
{	
	int ok = form.execute(*this);

	if (ok == 1)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName();
		std::cout << " because the form is not signed." << std::endl;
		throw FormNotSignedExeption();
	}
	else if (ok == 2)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName();
		std::cout << " because the bureaucrat don't have the requiered grade to execute." << std::endl;
		throw GradeTooLowException();
	}
	else if (ok == 3) 
	{
		std::cout << "+ " << this->getName() << " executed ";
		std::cout << form.getName() << " +" << std::endl;
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