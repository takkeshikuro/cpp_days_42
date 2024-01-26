/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 04:21:29 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/26 05:35:16 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/MutantStack.hpp"

void main_test()
{
	std::cout << "-TEST MUTANTSTACK-\n";

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
	std::cout << "top of s is : " << s.top() << std::endl;
	std::cout << std::endl;
}

void vector_test() {
	std::cout << "-TEST VECTOR-\n";
	std::vector<int> mvector;
	mvector.push_back(10);
	mvector.push_back(20);
	mvector.push_back(30);
	std::cout << "top of vector is : " << mvector.back() << std::endl;
	mvector.pop_back();
	std::cout << "top of vector (after pop) is : " << mvector.back() << std::endl;
	std::cout << "size of vector is : " << mvector.size() << std::endl;
	mvector.push_back(40);
	mvector.push_back(50);
	mvector.push_back(60);
	mvector.push_back(70);
	
	std::vector<int>::iterator it_begin = mvector.begin();
	std::vector<int>::iterator it_end = mvector.end();
	
	std::cout << "begin is : " << *(it_begin) << std::endl;
	std::cout << "end is : " << *(it_end - 1) << std::endl;
	
	while (it_begin != it_end)
	{
		std::cout << "display -> [" << *(it_begin) << "]" << std::endl;
		++it_begin;
	}
}

int main() {
	main_test();
	vector_test();
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