/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 06:34:01 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/10 06:41:19 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &cpy) : Intern(cpy) {}

Intern & Intern::operator=(Intern const &cpy) {
    return *this;
}

Intern::~Intern() {}

///////////////////////////////////////////////////////////////

AForm * Intern::makeForm(std::string form_name, std::string target)
{
    
}