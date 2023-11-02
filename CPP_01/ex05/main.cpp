/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 06:42:41 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/02 10:04:14 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Harl.hpp"

void Harl::complain(std::string level) 
{
	
}

int main(void)
{
	Harl harl;
	harl.complain("error");

	harl.complain("debug");
	harl.complain("warning");
	harl.complain("info");
	return 0;
}