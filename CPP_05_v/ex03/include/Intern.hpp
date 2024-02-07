/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 06:29:22 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/11 02:13:13 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



class Intern {
	public :
		Intern();
		Intern( Intern const &src );
		Intern	&	operator=( Intern const &cpy);
		~Intern();
		
		AForm *makeForm(std::string form_name, std::string target);
		
		class BadFormNameException : public std::exception {
			public :
				virtual const char * what() const throw();
		};
};

#endif