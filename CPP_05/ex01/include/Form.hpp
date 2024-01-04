/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:22:17 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/04 01:30:08 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#define TRUE 1
#define FALSE 0

class Form {
	public :
		Form();
		Form(std::string name, int grade_sign, int grade_exec);
		Form(Form const &cpy);
		Form &operator=(Form const &cpy);
		~Form();
		
		class GradeTooHighException {
			public :
				virtual const char * what() const throw();
		};
		
		class    GradeTooLowException {
			public :
				virtual const char * what() const throw();	
		};


		const std::string getName() const;
		bool get_sign_bool() const ;
		int getGradeSign() const ;
		int getGradeExec() const ;
		void    beSigned(Bureaucrat &boy);
		
	private :
		const std::string _name;
		bool    _is_signed;
		const int _grade_sign;
		const int _grade_exec;
		
};

std::ostream &operator<<(std::ostream &o, Form const &ok);

#endif