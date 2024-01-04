/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:21:47 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/04 01:41:08 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default_name"), _grade(150) {
	std::cout << "[Bureaucrat must have a name and a grade (default)]" << std::endl;
	std::cout << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	std::cout << "[Bureaucrat normal constructor called]" << std::endl;
	std::cout << std::endl;
	try {
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		this->_grade = grade;
	}
	catch (const Bureaucrat::GradeTooHighException & e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException & e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &cpy) : _name(cpy._name), _grade(cpy._grade) {
	std::cout << "[Bureaucrat copy constructor called]" << std::endl;
	std::cout << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &cpy) { // voir le _name
	std::cout << "[Bureaucrat copy assignment operator called]" << std::endl;
	std::cout << std::endl;

	if (this != &cpy) {
		_grade = cpy.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "[Bureaucrat destructor called.]" << std::endl;
}

std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

const char *Bureaucrat::GradeTooHighException::what() const throw() {
		return "grade out of the range : too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
		return "grade out of the range : too low.";
}

void	Bureaucrat::grade_increment() {
	try {
		if ((_grade - 1) < 1)
			throw Bureaucrat::GradeTooHighException();
		else if ((_grade - 1) > 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade -= 1;
		std::cout << "-(" << getName() << " grade + 1)-" << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << "Error : " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << "Error : " << e.what() << std::endl;
	}	
}

void	Bureaucrat::grade_decrement() {
	try {
		if ((_grade + 1) < 1)
			throw Bureaucrat::GradeTooHighException();
		else if ((_grade + 1) > 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade += 1;
		std::cout << "-(" << getName() << " grade - 1)-" << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << "Error : " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << "Error : " << e.what() << std::endl;
	}	
}


void	Bureaucrat::signForm(int ok, std::string name_form) {
	if (ok == 0)
		std::cout << this->getName() << " signed " << name_form << "'s official form" << std::endl;
	else if (ok == 1) {
		std::cout << this->getName() << " couldn't sign " << name_form << "'s official form";
		std::cout << " because the bureaucrat don't have the required grade to sign." << std::endl;
	}
	else if (ok == 2) {
		std::cout << this->getName() << " couldn't sign " << name_form << "'s official form";
		std::cout << " because the form is already signed." << std::endl;
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