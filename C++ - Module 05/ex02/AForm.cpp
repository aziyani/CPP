/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:30:39 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/04 14:57:38 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm() : name("death"), gradeToSign(10), gradeToExecute(10)
{
}

AForm::AForm(std::string name, bool signedStatus, int gradeToSign, int gradeToExecute) : name(name), signedStatus(signedStatus), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooHighException();
}

AForm::AForm(AForm const &obj) : name(obj.name), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute)
{
	*this = obj;
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getSignedStatus()const
{
	return signedStatus;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

void	AForm::beSigned(const Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() <= gradeToSign)
		signedStatus = true;
	else
		throw GradeTooHighException();
}

void	AForm::signAForm(const Bureaucrat bureaucrat)
{
	try
	{
		beSigned(bureaucrat);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

AForm &AForm::operator=(const AForm &obj)
{
	if (this != &obj)
		this->signedStatus = obj.signedStatus;
	return (*this);
}

std::ostream &operator<<(std::ostream &output, AForm const &obj)
{
	output << "AForm: " << obj.getName() << ", Grade to Sign: " << obj.getGradeToSign() << ", Grade To Execute: " << obj.getGradeToExecute() << ", Signed: " << (obj.getSignedStatus() ? "Yes" : "No");
	return (output);
}