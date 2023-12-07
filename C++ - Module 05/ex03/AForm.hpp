/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:30:49 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/07 21:54:38 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

# include <string>
# include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string name;
	bool signedStatus;
	const int gradeToSign;
	const int gradeToExecute;

public:
	AForm();
	AForm(AForm const &obj);
	AForm(std::string name, bool signedStatus, int gradeToSing, int gradeToExecute);
	~AForm();

	AForm &operator=(const AForm &obj);

	std::string getName() const;
	bool getSignedStatus() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat bureaucrat);
	void signAForm(const Bureaucrat bureaucrat);
	
	class errFileException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Unable to open file for shrubbery creation.");
			}
	};
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
	virtual void execute(const Bureaucrat& executor) const = 0;
};

std::ostream &operator<<(std::ostream &output, AForm const &obj);

#endif