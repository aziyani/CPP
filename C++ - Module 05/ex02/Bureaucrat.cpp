/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:29:41 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/04 14:38:38 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("ayoub"), grade(100)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj) : name(obj.name) // hit const maghatcopach flcopy assingment (list initializar)
{
   *this = obj;
}

Bureaucrat::~Bureaucrat()
{
}

void    Bureaucrat::incrementGrade()
{
    if (grade == 1)
        throw GradeTooHighException();
    else
        this->grade--;
}

void    Bureaucrat::decrementGrade()
{
    if (grade == 150)
        throw GradeTooLowException();
    else 
        this->grade++;
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    if (this != &obj)
        this->grade = obj.grade;
    return (*this);
}


std::ostream &operator<<(std::ostream &output, Bureaucrat const &obj)
{
	output << "Bureaucrat: " << obj.getName() << ", garde :" << obj.getGrade() << ".";
	return output;
}