/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_something.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 06:50:22 by tmorikaw          #+#    #+#             */
/*   Updated: 2024/01/16 06:52:39 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_SOMETHING_HPP
# define IS_SOMETHING_HPP
# include <string>

int	is_special(const std::string &value);

int	is_float(const std::string &value);

int	is_double(const std::string &value);

int	is_int(const std::string &value);

#endif