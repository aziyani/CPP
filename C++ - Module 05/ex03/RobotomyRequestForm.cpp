/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:50:17 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/11 22:42:13 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45), target("Default")
{
	
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& obj) : AForm(obj), target(obj.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this != &obj)
		target = obj.target;
	return(*this);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	std::srand(time(NULL));
	if (executor.getGrade() <= this->getGradeToExecute() && this->getSignedStatus() == true)
	{
		if(rand() % 2 == 0)
			std::cout << this->target << " has been robotomized successfully 50% of the time" << std::endl;
		else
			std::cout << "informs that the robotomy failed" << std::endl;
	}
}
