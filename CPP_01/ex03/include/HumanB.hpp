/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 06:09:54 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/01 08:21:59 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>

class Weapon;
//pas tjr de weapon

class HumanB
{
  public :
	HumanB(void);
	HumanB(std::string name);
	HumanB(std::string name, Weapon *weapon);
	~HumanB(void);
  
  void  attack() const;
  void setWeapon(Weapon &weapon);
  
  private : 
  Weapon *_weapon;
  std::string _name;
};

#endif