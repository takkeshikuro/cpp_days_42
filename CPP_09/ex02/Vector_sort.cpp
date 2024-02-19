/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector_sort.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 06:05:19 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/02/15 10:45:10 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PmergeMe.hpp"

/*	std::cerr << "first : |";
	for (std::vector<int>::iterator ok = first.begin(); ok != first.end(); ++ok)
		std::cerr << *ok << " ,";
	std::cerr<<"|\nsecond : |";
	for (std::vector<int>::iterator ok2 = second.begin(); ok2 != second.end(); ++ok2)
		std::cerr << *ok2 << " ,";
	std::cerr << "|check end" << std::endl;
	std::cout<<"i = "<<i<<" jacob[i] = "<<jacob[i]<<"\n";
	std::cout<<"if ("<<size<<" >= "<<jacob[i]<<")\n";*/

void	PmergeMe::merge_all_vct(std::vector<int> &first, std::vector<int> &second)
{
	int jacob[11] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365};
	int i = 1;
	int size = first.size();

	_ite_s_vct = second.begin();
	std::vector<int>::iterator tmp_second = _ite_s_vct;
	first.insert(first.begin(), *_ite_s_vct);

	while (i < 11)
	{
		if (size >= jacob[i])
		{
			_ite_f_vct = first.begin();
			tmp_second = second.begin();

			// looking for [second vector]'s element to insert into first
			for (int x = 1; x != jacob[i]; x++)
				tmp_second++;

			//looking for the good place to insert
			while (*_ite_f_vct < *tmp_second)
				_ite_f_vct++;

			// then insert
			first.insert(_ite_f_vct, *tmp_second);
			
			// same job for second's element--;
			for (int x = 1; x != (jacob[i] - jacob[i - 1]); x++) {
				tmp_second--;
				_ite_f_vct = first.begin();
				while (*_ite_f_vct < *tmp_second)
					_ite_f_vct++;
				first.insert(_ite_f_vct, *tmp_second);
			}
		}
		else
			break ;
		i++;
	}
	
	std::vector<int>::iterator tmp_surplus = second.begin();
	for (int x = 0; x != jacob[i - 1]; x++)
		tmp_surplus++;
	// si il reste des elements restant dans second a insert dans first
	while (tmp_surplus != second.end())
	{
		_ite_f_vct = first.begin();
		while (*_ite_f_vct < *tmp_surplus && _ite_f_vct != first.end())
			_ite_f_vct++;
		if (_ite_f_vct != first.end())
			first.insert(_ite_f_vct, *tmp_surplus);
		else
			first.push_back(*tmp_surplus);
		tmp_surplus++;
	}
}

//cette fonction assure que les éléments de first sont triés par rapport à leurs homologues dans 
//second en échangeant les éléments si nécessaire.
void	PmergeMe::sort_first_vct(std::vector<int> &first, std::vector<int> &second)
{
	std::vector<int>::iterator itfn = _ite_f_vct;
	++itfn;

	std::vector<int>::iterator itsn = _ite_s_vct;
	++itsn;

	while (itfn != first.end())
	{
		if (*_ite_f_vct > *itfn)
		{
			int tempf = *_ite_f_vct;
			*_ite_f_vct = *itfn;
			*itfn = tempf;

			int temps = *_ite_s_vct;
			*_ite_s_vct = *itsn;
			*itsn = temps;

			_ite_f_vct = first.begin();
			itfn = _ite_f_vct;
			++itfn;

			_ite_s_vct = second.begin();
			itsn = _ite_s_vct;
			++itsn;
		}
		else
		{
			_ite_f_vct++;
			itfn++;
			_ite_s_vct++;
			itsn++;
		}
	}
}

void    PmergeMe::sort_vct() 
{
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int>::iterator ite = _vector.begin();
	
	//Si l'élément actuel est plus petit que le suivant, il est ajouté à second, 
	//sinon, il est ajouté à first.
	while (ite != _vector.end())
	{
		std::vector<int>::iterator itn = ite;
		itn++;
		if (itn == _vector.end()) {
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
	
	_ite_f_vct = first.begin();
	_ite_s_vct = second.begin();

	_vector.clear();
	sort_first_vct(first, second);
	
	merge_all_vct(first, second);
	_vector.swap(first);
}
