/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:29:21 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/13 11:08:09 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat("adolf hitler", 53);
		Form form("ziyani", 52, 10);
		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
		form.beSigned(bureaucrat);
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}