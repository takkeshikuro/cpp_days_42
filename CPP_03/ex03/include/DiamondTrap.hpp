/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:55:40 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/24 07:22:20 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    public :
        DiamondTrap();
        DiamondTrap(std::string str);
        DiamondTrap(DiamondTrap const &cpy);
        DiamondTrap& operator=(DiamondTrap const &cpy);
        ~DiamondTrap();
        void whoAmI() const;
        void attack(const std::string &target);
        void printAttributes() const;
    private :
        std::string name;

};

#endif