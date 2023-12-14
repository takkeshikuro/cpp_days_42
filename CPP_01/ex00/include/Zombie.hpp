/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:05:40 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/14 02:56:35 by tmorikaw         ###   ########.fr       */
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

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif
