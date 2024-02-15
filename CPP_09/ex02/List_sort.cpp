/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List_sort.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 06:11:09 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/15 10:47:10 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PmergeMe.hpp"

void	PmergeMe::merge_all_lst(std::list<int> &first, std::list<int> &second)
{
	int jacob[11] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365};
	int i = 1;
	int size = first.size();

	_ite_s_lst = second.begin();
	std::list<int>::iterator temps = _ite_s_lst;

	first.insert(first.begin(), *_ite_s_lst);
	
	while (i < 11)
	{
		if (size >= jacob[i])
		{
			_ite_f_lst = first.begin();
			temps = _ite_s_lst;
			for (int x = 1; x != jacob[i]; x++)
				temps++;
			while (*_ite_f_lst < *temps)
				_ite_f_lst++;
			first.insert(_ite_f_lst, *temps);
			for (int x = 1; x != (jacob[i] - jacob[i - 1]); x++)
			{
				temps--;
				_ite_f_lst = first.begin();
				while (*_ite_f_lst < *temps)
					_ite_f_lst++;
				first.insert(_ite_f_lst, *temps);
			}
		}
		else
			break ;
		i++;
	}
	
	temps = _ite_s_lst;
	for (int x = 0; x != jacob[i - 1]; x++)
		temps++;
	
	while (temps != second.end())
	{
		_ite_f_lst = first.begin();
		while (*_ite_f_lst < *temps && _ite_f_lst != first.end())
			_ite_f_lst++;
		if (_ite_f_lst != first.end())
			first.insert(_ite_f_lst, *temps);
		else
			first.push_back(*temps);
		temps++;
	}
}

void	PmergeMe::sort_first_lst(std::list<int> &first, std::list<int> &second)
{
	std::list<int>::iterator itfn = _ite_f_lst;
	++itfn;

	std::list<int>::iterator itsn = _ite_s_lst;
	++itsn;

	while (itfn != first.end())
	{
		if (*_ite_f_lst > *itfn)
		{
			int tempf = *_ite_f_lst;
			*_ite_f_lst = *itfn;
			*itfn = tempf;

			int temps = *_ite_s_lst;
			*_ite_s_lst = *itsn;
			*itsn = temps;

			_ite_f_lst = first.begin();
			itfn = _ite_f_lst;
			++itfn;

			_ite_s_lst = second.begin();
			itsn = _ite_s_lst;
			++itsn;
		}
		else
		{
			_ite_f_lst++;
			itfn++;
			_ite_s_lst++;
			itsn++;
		}
	}
}

void    PmergeMe::sort_lst() 
{
	std::list<int> first;
	std::list<int> second;
	std::list<int>::iterator ite = _list.begin();

	while (ite != _list.end())
	{
		std::list<int>::iterator itn = ite;
		itn++;
		if (itn == _list.end()) {
			second.push_back(*ite);
			break ;
		}
		if (*ite < *itn) {
			second.push_back(*ite);
			first.push_back(*itn);
		}
		else {
			first.push_back(*ite);
			second.push_back(*itn);
		}
		std::advance(ite, 2);
	}

	_ite_f_lst = first.begin();
	_ite_s_lst = second.begin();

	_list.clear();
	sort_first_lst(first, second);
	merge_all_lst(first, second);
	_list.swap(first);
}