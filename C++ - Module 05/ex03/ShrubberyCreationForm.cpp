/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:50:17 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/13 13:16:55 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137), target("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& obj) : AForm(obj), target(obj.target)
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
		std::ofstream file((target + "_shrubbery").c_str());
		if (file.is_open())
		{
			file << "              # #### ####\\ \n";
        	file << "            ### \\/#|### |/####\\ \n";
        	file << "           ##\\/#/ \\||/##/_/##/_#\\ \n";
        	file << "         ###  \\/###|/ \\/ # ###\\ \n";
        	file << "       ##_\\_#\\_\\## | #/###_/_####\\ \n";
        	file << "      ## #### # \\ #| /  #### ##/##\\ \n";
        	file << "       __#_--###`  |{,###---###-~\\ \n";
        	file << "                 \\ }{\\ \n";
        	file << "                  }}{\\ \n";
        	file << "                  }}{\\ \n";
        	file << "                  {{}\\ \n";
        	file << "            , -=-~{ .-^- _\\ \n";
        	file << "                  `}\\ \n";
			file.close();
			std::cout << "Shrubbery creation form has been executed successfully by " << executor.getName() << "." << std::endl;
		}
		else
			throw ShrubberyCreationForm::errFileException();
	}
	else
		throw AForm::GradeTooLowException();
}

 