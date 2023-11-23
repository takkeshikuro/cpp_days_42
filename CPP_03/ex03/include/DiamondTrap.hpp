/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:55:40 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/23 08:10:09 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONTRAP_HPP
#define DIAMONTRAP_HPP

#include "ClapTrap.hpp"

class DiamonTrap 
{
    public :
        DiamondTrap();
        DiamondTrap(std::string str);
        DiamondTrap(DiamondTrap const &cpy);
        DiamondTrap& operator=(DiamondTrap const &cpy);
        ~DiamondTrap();
        void whoAmI();
    private :
        std::string name;

};

#endif