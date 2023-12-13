/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:29:41 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/12 21:59:18 by aziyani          ###   ########.fr       */
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

Bureaucrat::Bureaucrat(Bureaucrat const &obj) : name(obj.name)
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

void	Bureaucrat::signForm(AForm &form)
{
	if (form.getSignedStatus() == true)
    {
        std::cout << name <<  " signed " << form.getName() << std::endl;
    }
    else
    {
        std::cout << name << " couldn't sign " << form.getName() << " because wsf" << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const & form)
{
    if (grade <= form.getGradeToExecute())
        std::cout << name << " executed " << form.getName() << std::endl;
    else
        std::cout << name << " don't executed " << form.getName() << std::endl;
        
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &obj)
{
	output << "Bureaucrat: " << obj.getName() << ", garde :" << obj.getGrade() << ".";
	return output;
}