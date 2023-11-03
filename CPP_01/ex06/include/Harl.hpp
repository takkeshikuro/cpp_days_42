/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshikuro <keshikuro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:58:14 by keshikuro         #+#    #+#             */
/*   Updated: 2023/11/03 14:25:33 by keshikuro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
	public : 
		Harl();
		~Harl();
		void complain(std::string level);
	
    private :
		void debug(); //infos contextuelles
		void info(); // infos detailles
		void warning(); // msg avertissement
		void error(); // critique
};
#endif