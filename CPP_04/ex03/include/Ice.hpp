/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 02:07:38 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/05 06:29:51 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "Character.hpp"

class Ice : public AMateria
{
	public :
		Ice();
		Ice(Ice const &cpy);
		Ice& operator=(Ice const &cpy);
		~Ice();
	    AMateria* clone() const ;
    	void use(ICharacter &target);
	private :
	
};

#endif