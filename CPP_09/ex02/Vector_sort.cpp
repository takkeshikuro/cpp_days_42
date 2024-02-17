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

//cette fonction fusionne les deux vecteurs triés first et second en insérant les éléments 
//de second dans first tout en conservant l'ordre croissant. La séquence de Jacobsthal est 
//utilisée pour déterminer les positions d'insertion afin de minimiser le nombre de 
//comparaisons nécessaires.
void	PmergeMe::merge_all_vct(std::vector<int> &first, std::vector<int> &second)
{
	int jacob[11] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365};
	int i = 1;
	int size = first.size();

	_ite_s_vct = second.begin();
	std::vector<int>::iterator temps = _ite_s_vct;

	first.insert(first.begin(), *_ite_s_vct);
	
	while (i < 11)
	{
		if (size >= jacob[i])
		{
			_ite_f_vct = first.begin();
			temps = _ite_s_vct;
			for (int x = 1; x != jacob[i]; x++)
				temps++;
			while (*_ite_f_vct < *temps)
				_ite_f_vct++;
			first.insert(_ite_f_vct, *temps);
			for (int x = 1; x != (jacob[i] - jacob[i - 1]); x++)
			{
				temps--;
				_ite_f_vct = first.begin();
				while (*_ite_f_vct < *temps)
					_ite_f_vct++;
				first.insert(_ite_f_vct, *temps);
			}
		}
		else
			break ;
		i++;
	}
	
	temps = _ite_s_vct;
	for (int x = 0; x != jacob[i - 1]; x++)
		temps++;
	
	while (temps != second.end())
	{
		_ite_f_vct = first.begin();
		while (*_ite_f_vct < *temps && _ite_f_vct != first.end())
			_ite_f_vct++;
		if (_ite_f_vct != first.end())
			first.insert(_ite_f_vct, *temps);
		else
			first.push_back(*temps);
		temps++;
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

	//Si l'élément actuel est inférieur à l'élément précédent, elle échange les éléments de 
	//first et de second correspondants à l'aide d'une variable temporaire.
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
	//sinon, il est ajouté à first. Cela divise efficacement le vecteur 
	//_vector en deux sous-vecteurs alternés.
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
