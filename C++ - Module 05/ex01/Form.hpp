/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:30:49 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/04 11:00:54 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include <string>
# include "Bureaucrat.hpp"

class Form
{
private:
	const std::string name;
	bool signedStatus;
	const int gradeToSign;
	const int gradeToExecute;

public:
	Form();
	Form(Form const &obj);
	Form(std::string name, bool signedStatus, int gradeToSing, int gradeToExecute);
	~Form();

	Form &operator=(const Form &obj);

	std::string getName() const;
	bool getSignedStatus() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat bureaucrat);
	void signForm(const Bureaucrat bureaucrat);
	
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

std::ostream &operator<<(std::ostream &output, Form const &obj);

#endif