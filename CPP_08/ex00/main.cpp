/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 05:02:03 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/26 01:08:45 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/easyfind.hpp"

const char * OccurenceNotFound::what() const throw() {
	return "no occurence found";
}

int main() {


	try {
		std::vector<int> vector_test;
		vector_test.push_back(10);
		vector_test.push_back(20);
		vector_test.push_back(30);
	
		::easyfind(vector_test, 10);
		::easyfind(vector_test, 40);
	}
	catch (const std::exception &e) {
		std::cerr << "error : " << e.what() << std::endl;
	}
	try {
		std::list<int> list_test;
		list_test.push_back(1);
		list_test.push_back(2);
		list_test.push_back(3);

		::easyfind(list_test, 2);
		::easyfind(list_test, 4);
	}
	catch (const std::exception &e){
		std::cerr << "error " << e.what() << std::endl; 
	}
}