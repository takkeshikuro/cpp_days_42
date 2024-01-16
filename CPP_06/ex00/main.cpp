/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 05:31:22 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/16 05:31:41 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ScalarConverter.hpp"

int main(void) 
{
    ScalarConverter::convert("'a'");    // Test avec un littéral char
    ScalarConverter::convert("42");      // Test avec un littéral int
    ScalarConverter::convert("4.2f");    // Test avec un littéral float
    ScalarConverter::convert("4.2");     // Test avec un littéral double
    return 0;
}