/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:23:31 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/20 02:38:50 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap 
{
	public :
		FragTrap();
		FragTrap(std::string str);
		FragTrap(FragTrap const &cpy);
		FragTrap& operator=(FragTrap const &cpy);
		~FragTrap();

		void highFivesGuys(void);
};

#endif