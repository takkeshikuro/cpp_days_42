/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:01:04 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/04 05:01:25 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRHUBBERYCREATIONFORM_HPP
#define SRHUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &cpy);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const &cpy);
		~ShrubberyCreationForm();
		
		void make_action();
		
	private : 
		std::string _target;
};

#endif