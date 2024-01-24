/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshikuro <keshikuro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 06:50:20 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/24 15:14:02 by keshikuro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void    function_test(T const &tab_content, int i)
{
    std::cout << "tab[" << i << "] = " << tab_content << std::endl;
    return ;
}

template <typename T>
void    iter(T *arr, int tab_size, void (*f)(T const &, int)) 
{
    for (int i = 0; i < tab_size; i++)
        f(arr[i], i);
    return;
}


#endif