/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:12:01 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/07 22:32:40 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

// # include"AForm.hpp"
class AForm;

class intern
{
public:
	intern();
	intern(const intern& obj);
	intern &operator=(const intern& obj);
	~intern();
	AForm* makeForm(std::string name, std::string target);

	class errincaseException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("هنالك خطأ");
			}
	};
};

#endif