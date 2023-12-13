/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:29:21 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/12 21:59:33 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
	try
	{
		Bureaucrat bureaucrat("adolf hitler", 6);
		
		ShrubberyCreationForm shrubberycreation("sadam");
		RobotomyRequestForm robotomyrequest("sadam");
		PresidentialPardonForm presedentialpardon("sadam");
		
		shrubberycreation.beSigned(bureaucrat);
		robotomyrequest.beSigned(bureaucrat);
		presedentialpardon.beSigned(bureaucrat);
		
		bureaucrat.signForm(shrubberycreation);
		bureaucrat.signForm(robotomyrequest);
		bureaucrat.signForm(presedentialpardon);

		shrubberycreation.execute(bureaucrat);
		robotomyrequest.execute(bureaucrat);
		presedentialpardon.execute(bureaucrat);

		bureaucrat.executeForm(presedentialpardon);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}