/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:50:17 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/06 12:52:45 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45), target("corombo")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", false, 72, 45), target(target)
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

void RobotomyRequestForm::execute(const Bureaucrat& executor)
{
	std::srand(time(NULL));
	if (executor.getGrade() <= this->getGradeToExecute() && this->getSignedStatus() == true)
	{
		if(rand() % 2 == 0)
			std::cout << this->target << "has been robotomized successfully" << std::endl;
		else
			std::cout << "robotomy failed" << std::endl;
	}
}
