/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:22:08 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/04 04:14:08 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

class Form;

class Bureaucrat
{
	public :
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat const &cpy);
		Bureaucrat& operator=(Bureaucrat const &cpy);
		~Bureaucrat();
		std::string	getName() const;
		int			getGrade() const;
		
		class GradeTooHighException : public std::exception {
			public :
				virtual const char * what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				virtual const char * what() const throw();	
		};

		void	grade_increment();
		void	grade_decrement();
        void    signForm(int ok, std::string name_form);
		//void execute_form();
	
	private :
		const std::string _name;
		int _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &ok);

#endif