/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:50:01 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/13 13:05:46 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARADONFORM_HPP
# define PRESIDENTIALPARADONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(PresidentialPardonForm const& obj);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm& obj);

	void execute(const Bureaucrat& executor) const;
};

#endif