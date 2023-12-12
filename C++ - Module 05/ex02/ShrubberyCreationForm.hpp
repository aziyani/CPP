/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:50:01 by aziyani           #+#    #+#             */
/*   Updated: 2023/12/12 19:27:04 by aziyani          ###   ########.fr       */
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
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm& obj);

		class errFileException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Unable to open file for shrubbery creation.");
				}
		};

		void execute(const Bureaucrat& executor) const;
	};

#endif
