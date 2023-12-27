/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 05:22:48 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/27 04:32:25 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	public :
		Brain();
		Brain(const Brain &cpy);
		Brain& operator=(const Brain &cpy);
		~Brain();
		
		const std::string &GetIdea(int i) const;
		void SetIdea(std::string idea, int i);
	
	private :
		std::string ideas[100];
		static const std::string no_idea;
};

#endif