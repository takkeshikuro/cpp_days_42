/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:16:39 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/02 02:57:43 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("default_ShrubberyCreationForm", 145, 137), _target("default_target") 
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target) 
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cpy) 
: AForm(cpy), _target(cpy._target) 
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &cpy) 
{
	if (this != &cpy)
		this->_target = cpy._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


void ShrubberyCreationForm::make_action() const
{
	std::ofstream ofs((_target + "_shrubbery").c_str());
	ofs << "               ,@@@@@@@," << std::endl;
	ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888#88/8o" << std::endl;
	ofs << "   ,%&@%&&%&&%,@@@#@@@/@@@88#88888/88'" << std::endl;
	ofs << "   %&&%&%&/%&&%@@#@@/ /@@@88888#88888'" << std::endl;
	ofs << "   %&&%/ %&%%&&@@@ V /@@' `88@8 `/88'" << std::endl;
	ofs << "   `&% |` /%&'    |.|         | '|8'" << std::endl;
	ofs << "       |o|        | |         | |" << std::endl;
	ofs << "       |.|        | |         | |" << std::endl;
	ofs << "    \\/ .|_//_/__/ ,|_//__\\_/. | _//__/_" << std::endl;
	ofs.close();
}
		