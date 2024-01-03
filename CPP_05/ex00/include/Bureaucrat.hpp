/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:14:59 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/03 02:20:41 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

class Bureaucrat
{
	public :
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat const &cpy);
		Bureaucrat& operator=(Bureaucrat const &cpy);
		~Bureaucrat();
		std::string	getName() const;
		int					getGrade() const;
		
		class GradeTooHighException {
			public :
				virtual const char * what() const throw();
		};
		
		class    GradeTooLowException {
			public :
				virtual const char * what() const throw();	
		};

		void	grade_increment();
		void	grade_decrement();

	private :
		const std::string _name;
		int _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &ok);

#endif