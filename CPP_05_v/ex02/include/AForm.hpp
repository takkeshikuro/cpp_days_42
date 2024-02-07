/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:22:17 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/02 02:39:57 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#define TRUE 1
#define FALSE 0

class Bureaucrat;

class AForm {
	public :
		AForm();
		AForm(std::string name, int grade_sign, int grade_exec);
		AForm(AForm const &cpy);
		AForm &operator=(AForm const &cpy);
		virtual ~AForm();
		
		class GradeTooHighException : public std::exception {
			public :
				virtual const char * what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				virtual const char * what() const throw();	
		};
		class FormAlreadySignExeption : public std::exception {
			public :
				virtual const char * what() const throw();
		};
		class FormNotSignedExeption : public std::exception {
			public :
				virtual const char * what() const throw();
		};
	
		class GradetooLowToExec : public std::exception {
			public :
				virtual const char * what() const throw();
		};
		
		const std::string	getName() const;
		bool 				get_sign_bool() const ;
		int					getGradeSign() const ;
		int					getGradeExec() const ;
		void				beSigned(const Bureaucrat &bureaucrat);
		void				execute(Bureaucrat const &executor) const;	
	
	protected :
		virtual void make_action() const = 0;
	
	private :
		const std::string	_name;
		bool    			_is_signed;
		const int 			_grade_sign;
		const int			_grade_exec;	
};

std::ostream &operator<<(std::ostream &o, AForm const &ok);

#endif