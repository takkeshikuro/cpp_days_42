/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshikuro <keshikuro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:05:40 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/03 14:19:10 by keshikuro        ###   ########.fr       */
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
