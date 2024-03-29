/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 03:48:19 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/14 02:55:27 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public :
	Zombie(void);
	~Zombie(void);
	
	void announce( void );
	std::string get_name() const;
	void	set_name(std::string str);

	private :
	std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif