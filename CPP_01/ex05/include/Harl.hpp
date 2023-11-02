/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 06:30:22 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/02 10:05:52 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <map>

class Harl
{
	public : 
		Harl();
		~Harl();

		void complain(std::string level);
		
		void (*p_function)();
//		std::map<std::string, void(Harl::*)()> mapping_level;

	private :
		void debug(); //infos contextuelles
		void info(); // infos detailles
		void warning(); // msg avertissement
		void error(); // critique
};

#endif