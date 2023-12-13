/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:11:53 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/13 13:12:06 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

intern::intern()
{
}

intern::intern(const intern& obj)
{
	*this = obj;
}

intern::~intern()
{
}

intern &intern::operator=(const intern& __unused obj)
{
	return *this;
}

AForm* intern::makeForm(std::string name, std::string target)
{
	std::string tab[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	size_t i = 0;
	while (i < 3)
	{
		if (tab[i] == name)
		{
			switch (i) 
			{
				case 0:
					std::cout << "Intern creates " << name << std::endl;
					return new ShrubberyCreationForm(target);
				case 1:
					std::cout << "Intern creates " << name << std::endl;
					return new RobotomyRequestForm(target);
				case 2:
					std::cout << "Intern creates " << name << std::endl;
					return new PresidentialPardonForm(target);
			}
		}
		i++;
	}
	throw intern::errincaseException();
	return(NULL);
}
