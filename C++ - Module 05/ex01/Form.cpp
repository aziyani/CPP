/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:30:39 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/04 11:06:55 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form() : name("death"), gradeToSign(10), gradeToExecute(10)
{
}

Form::Form(std::string name, bool signedStatus, int gradeToSign, int gradeToExecute) : name(name), signedStatus(signedStatus), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooHighException();
}

Form::Form(Form const &obj) : name(obj.name), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute)
{
	*this = obj;
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return name;
}

bool Form::getSignedStatus()const
{
	return signedStatus;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

void	Form::beSigned(const Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() <= gradeToSign)
		signedStatus = true;
	else
		throw GradeTooHighException();
}

void	Form::signForm(const Bureaucrat bureaucrat)
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

Form &Form::operator=(const Form &obj)
{
	if (this != &obj)
		this->signedStatus = obj.signedStatus;
	return (*this);
}

std::ostream &operator<<(std::ostream &output, Form const &obj)
{
	output << "Form: " << obj.getName() << ", Grade to Sign: " << obj.getGradeToSign() << ", Grade To Execute: " << obj.getGradeToExecute() << ", Signed: " << (obj.getSignedStatus() ? "Yes" : "No");
	return (output);
}