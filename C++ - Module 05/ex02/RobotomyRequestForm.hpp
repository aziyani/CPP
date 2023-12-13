/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:50:01 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/13 13:00:53 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTGORM_HPP
# define ROBOTOMYREQUESTGORM_HPP

# include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(RobotomyRequestForm const& obj);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm& obj);

	void execute(const Bureaucrat& executor) const;
};

#endif