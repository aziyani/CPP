/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:50:17 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/07 21:57:28 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137), target("corombo")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", false, 145, 137), target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (this != &obj)
		target = obj.target;
	return(*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() <= this->getGradeToExecute() && this->getSignedStatus() == true)
	{
		std::ofstream file(target + "_shrubbery");
		if (file.is_open())
		{
			file << "              # #### ####\
                                ### \\/#|### |/####\
                               ##\\/#/ \\||/##/_/##/_#\
                             ###  \\/###|/ \\/ # ###\
                           ##_\\_#\\_\\## | #/###_/_####\
                          ## #### # \\ #| /  #### ##/##\
                           __#_--###`  |{,###---###-~\
                                     \\ }{\
                                      }}{\
                                      }}{\
                                      {{}\
                                , -=-~{ .-^- _\
                                      `}\
                                       {" << std::endl;
			file.close();
			std::cout << "Shrubbery creation form has been executed successfully by " << executor.getName() << "." << std::endl;
		}
		else
			throw AForm::errFileException();
	}
	else
		throw AForm::GradeTooLowException();
}

 