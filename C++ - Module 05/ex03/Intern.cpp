/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:11:53 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/07 22:37:03 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm* intern::makeForm(std::string name, std::string target)
{
	std::string tab[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	size_t i = 0;
	// for (i = 0; i < 3; i++)
	// {
	// 	if(tab[i] == name)
	// 		break;	
	// }
	while (i < 3)
	{
		if (tab[i] == name)
		{
			switch (i) 
			{
				case 0:
					return new ShrubberyCreationForm(target);
				case 1:
					return new RobotomyRequestForm(target);
				case 2:
					return new PresidentialPardonForm(target);
				default:
					throw intern::errincaseException();
		}
		i++;
	}
	}
	return(NULL);
}
