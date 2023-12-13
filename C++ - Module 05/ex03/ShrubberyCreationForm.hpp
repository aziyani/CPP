/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:50:01 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/13 13:14:08 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"

	class ShrubberyCreationForm : public AForm
	{
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const& obj);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm& obj);

		class errFileException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Unable to open file for shrubbery creation.");
				}
		};
		const std::string& getTarget() const
		{
			return target;
		}

		void execute(const Bureaucrat& executor) const;
	};

#endif
