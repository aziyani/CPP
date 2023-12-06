/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:50:17 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/06 12:57:56 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 72, 45), target("corombo")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", false, 72, 45), target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	if (this != &obj)
		target = obj.target;
	return(*this);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor)
{
	if (executor.getGrade() <= this->getGradeToExecute() && this->getSignedStatus() == true)
	{
		std::cout << this->target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}
