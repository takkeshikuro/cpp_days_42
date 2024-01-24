/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:33:51 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/24 02:37:04 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Base.hpp"
#include "include/A.hpp"
#include "include/B.hpp"
#include "include/C.hpp"

Base * generate(void) 
{	
	Base* instance;
		
	int choice = rand() % 3;
	switch (choice)
	{
		case 0 :
//			std::cout << "spawn:A\n";
			instance = new A();
			break;
		case 1 :
//			std::cout << "spawn:B\n";
			instance = new B();
			break;
		case 2 :
//			std::cout << "spawn:C\n";
			instance = new C();
			break; 
	}
	return instance;
}

void    identify(Base* p) 
{
	if (dynamic_cast<A*>(p))
		std::cout << "(*) type = A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "(*) type = B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "(*) type = C\n";
}

void	identify(Base& p) {
	try 
	{
		A& ok_a = dynamic_cast<A&>(p);
		(void)ok_a;
		std::cout << "(&) type = A" << std::endl;
	}
	catch (const std::exception& e) 
	{
		try 
		{
			B& ok_b = dynamic_cast<B&>(p);
			(void)ok_b;
			std::cout << "(&) type = B" << std::endl;
		}
		catch (const std::exception& e) 
		{
			try 
			{
				C& ok_c = dynamic_cast<C&>(p);
				(void)ok_c;
				std::cout << "(&) type = C" << std::endl;
			}
			catch (const std::exception& e) 
			{
				std::cout << "ERROR" << std::endl;
			}
		}
	}
}


int main()
{
	srand(time(NULL));
	Base *base = generate();
	identify(base);
	identify(*base);
}