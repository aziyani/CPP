/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:29:21 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/13 13:16:43 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat("adolf hitler", 26);

		intern someRandomIntern;
		AForm* rrf;
		ShrubberyCreationForm ayoub("target ayoub");
		ShrubberyCreationForm mehdi(ayoub);
		std::cout << mehdi.getTarget()<< std::endl;
		rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
		rrf->beSigned(bureaucrat);
		rrf->execute(bureaucrat);
		delete rrf;
		
		rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
		rrf->beSigned(bureaucrat);
		rrf->execute(bureaucrat);
		delete rrf;
		
		rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
		rrf->beSigned(bureaucrat);
		rrf->execute(bureaucrat);
		
		delete rrf;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}