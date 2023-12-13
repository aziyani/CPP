/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:30:49 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/11 22:14:14 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

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
	AForm(std::string name, int gradeToSing, int gradeToExecute);
	~AForm();

	AForm &operator=(const AForm &obj);

	std::string getName() const;
	bool getSignedStatus() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;
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

std::ostream &operator<<(std::ostream &output, AForm const &obj);

#endif