/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:30:36 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/11/02 09:45:18 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Sed.hpp"

// a voir pour safe les dossier

void Sed::swap_occ(std::string& line)
{
	int index = 0;
	while ((const unsigned long)(index = line.find(_S1, index)) != std::string::npos)
	{
		line.erase(index, _S1.length());
		line.insert(index, _S2);
		index += _S2.length();
	}
}

void	Sed::reading()
{
	std::ifstream ifs(_file_name.c_str());

	if (ifs.is_open())
	{
		std::ofstream ofs((_file_name + ".replace").c_str());
		std::string line_buf;
		int i = 0;
		while (std::getline(ifs, line_buf)) 
		{
			if (i != 0)
				ofs << std::endl;
			if (ifs.fail())
			{
				std::cerr << "error during reading from " << _file_name << std::endl;
				return ;
			}
			swap_occ(line_buf);
			ofs << line_buf;
			i += 1;
		}
		ifs.close();
		ofs.close();
	}
	else
		std::cerr << "can't open " << _file_name << std::endl;
	return ;
}

int main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string file = av[1];
		std::string s1 = av[2];
		std::string s2 = av[3];
		if (file.empty())
		{
			std::cerr << "need a file" << std::endl;
			return 1;
		}
		else if (s1.empty() || s2.empty())
		{
			std::cerr << "need valid args" << std::endl;
			return 1;			
		}
		Sed seding = Sed(file, s1, s2);
		seding.reading();
	}
	else
	{
		std::cout << "use ./fakeSed <file target> <element string you want to remove ";
		std::cout << "and replace> <element string which will be replaced ans added>" << std::endl;
	}
	return 0;
}