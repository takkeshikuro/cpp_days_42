/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 05:59:37 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/12/20 07:34:13 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Brain.hpp"

const std::string Brain::no_idea = "";

Brain::Brain() {
	std::cout << "[Brain default constructor called]" << std::endl;
	std::cout << std::endl;
}

Brain::Brain(const Brain &cpy) {
	std::cout << "[Brain copy constructor called]" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = cpy.ideas[i];
}

Brain& Brain::operator=(Brain const &cpy) {
	std::cout << "[Brain copy operator called]" << std::endl;
	std::cout << std::endl;
	if (this != &cpy) {
		for (int i = 0; i < 100; i++)
			ideas[i] = cpy.ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "[Brain destructor called.]" << std::endl;
}

const std::string &Brain::GetIdea(int i) const {
	if (i < 0 || i >= 100) {
		std::cerr << "invalid index" << std::endl;
		return no_idea;
	}
	return ideas[i];
}

void	Brain::SetIdea(std::string idea, int i) {
	if (i >= 0 && i < 100)
		ideas[i] = idea;
}