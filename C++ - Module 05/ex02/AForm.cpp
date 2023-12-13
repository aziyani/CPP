/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:30:39 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/11 19:15:52 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm() : name("death"), signedStatus(false), gradeToSign(10), gradeToExecute(10)
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	std::cout << "Aform param" << std::endl;

	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const &obj) : name(obj.name), signedStatus(false), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute)
{
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
		throw GradeTooLowException();
}

AForm &AForm::operator=(const AForm &obj)
{
	if (this != &obj)
		this->signedStatus = obj.signedStatus;
	return (*this);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &output, AForm const &obj)
{
	output << "AForm: " << obj.getName() << ", Grade to Sign: " << obj.getGradeToSign() << ", Grade To Execute: " << obj.getGradeToExecute() << ", Signed: " << (obj.getSignedStatus() ? "Yes" : "No");
	return (output);
}