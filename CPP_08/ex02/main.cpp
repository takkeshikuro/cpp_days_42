/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 04:21:29 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/13 17:06:59 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/MutantStack.hpp"

void main_test()
{
	std::cout << "\n-TEST MUTANTSTACK-\n";

	MutantStack<int> mstack;
	mstack.push(10);
	mstack.push(20);
	mstack.push(30);
	std::cout << "top of stack is : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "top of stack (after pop) is : " << mstack.top() << std::endl;
	std::cout << "size of stack is : " << mstack.size() << std::endl;
	mstack.push(40);
	mstack.push(50);
	mstack.push(60);
	mstack.push(70);
	
	MutantStack<int>::iterator it_begin = mstack.begin();
	MutantStack<int>::iterator it_end = mstack.end();
	
	std::cout << "begin is : " << *(it_begin) << std::endl;
	std::cout << "end is : " << *(it_end - 1) << std::endl;
	
	while (it_begin != it_end) 
	{
		std::cout << "display -> [" << *it_begin << "]" << std::endl;
		++it_begin;
	}
	std::stack<int> s(mstack);
	std::cout << "top of stack is : " << s.top() << std::endl;
	std::cout << std::endl;
}

void list_test() 
{
	std::cout << "-TEST LIST-\n";
	std::list<int> mlist;
	mlist.push_back(10);
	mlist.push_back(20);
	mlist.push_back(30);
	std::cout << "top of vector is : " << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << "top of vector (after pop) is : " << mlist.back() << std::endl;
	std::cout << "size of vector is : " << mlist.size() << std::endl;
	mlist.push_back(40);
	mlist.push_back(50);
	mlist.push_back(60);
	mlist.push_back(70);


	std::list<int>::iterator it = mlist.begin();
	std::list<int>::iterator it_end = mlist.end();
	
	std::cout << "begin is : " << *(it) << std::endl;
	std::cout << "end is : " << *(--it_end) << std::endl;
	
	while (it != mlist.end())
	{
		std::cout << "display -> [" << *(it) << "]" << std::endl;
		++it;
	}
}

int main() {
	main_test();
	list_test();
	return 0;
}

/* int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
} */