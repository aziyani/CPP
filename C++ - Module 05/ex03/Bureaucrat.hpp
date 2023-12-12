/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:24:08 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/12 19:37:48 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;
class Bureaucrat
{
private:
	const std::string name;
	int         grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &obj);
	~Bureaucrat();
	
	Bureaucrat &operator=(const Bureaucrat &obj);
	
	std::string getName() const;
	int     getGrade() const;
	void    incrementGrade();
	void    decrementGrade();

	void	signForm(AForm &form);
	void	executeForm(AForm const & form);
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &output, Bureaucrat const &obj);

#endif