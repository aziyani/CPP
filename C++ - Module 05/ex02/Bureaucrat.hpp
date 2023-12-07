/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:24:08 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/07 21:58:39 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <exception>

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

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Grade is too high!");
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Grade is too low!");
			}
	};
};

std::ostream &operator<<(std::ostream &output, Bureaucrat const &obj);

#endif