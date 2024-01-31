/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 06:56:06 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/31 07:39:16 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class ErrorBadInput : public std::exception {
    public :
        virtual const char *what() const throw();
};
