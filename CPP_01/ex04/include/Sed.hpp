/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 01:42:32 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/02 05:20:58 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>

class Sed
{
	public :
		Sed(std::string file, std::string& s1, std::string& s2);
		~Sed();
		void	reading();
		void	swap_occ(std::string& line);
		
	private :
		std::string _file_name;
		const std::string _S1;
		const std::string _S2;
};

#endif