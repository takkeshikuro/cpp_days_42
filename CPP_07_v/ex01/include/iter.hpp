/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 06:50:20 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/08 03:33:10 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void    function_test(T const &tab_content)
{
    std::cout << "tab content = " << tab_content << std::endl;
    return ;
}

template <typename T>
void    iter(T *arr, int tab_size, void (*f)(T const &)) 
{
    for (int i = 0; i < tab_size; i++)
        f(arr[i]);
    return;
}

// template <typename T, typename F>
// void    iter(T *arr, int tab_size, F fun) 
// {
//     for (int i = 0; i < tab_size; i++)
//         fun(arr[i], i);
//     return;
// }


#endif