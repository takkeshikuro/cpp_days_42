/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 02:25:47 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/27 06:05:19 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "Character.hpp"

class Cure : public AMateria
{
	public :
		Cure();
		Cure(Cure const &cpy);
		Cure& operator=(Cure const &cpy);
		~Cure();

        AMateria* clone() const;
        void use(ICharacter &target);
};

#endif