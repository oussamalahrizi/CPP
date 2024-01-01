/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:36:45 by olahrizi          #+#    #+#             */
/*   Updated: 2023/12/15 22:49:42 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other)
{
	(void) other;
	return *this;
}

int get_case(const std::string form)
{
	if (form == "shrubbery request")
		return 1;
	if (form == "robotomy request")
		return 0;
	if (form == "presidential request")
		return 2;
	return(-1);
}

AForm* Intern::makeForm(const std::string &form_name, const std::string& target)
{
	int _case = -1;

	AForm *form;
	_case = get_case(form_name);
	switch(_case)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			std::cerr << "Form name unknown" << std::endl;
			form = NULL;
			break;
	}
	return (form);
}