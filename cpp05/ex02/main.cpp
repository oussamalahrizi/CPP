/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:15:36 by olahrizi          #+#    #+#             */
/*   Updated: 2023/12/22 03:34:33 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void function(AForm& form, Bureaucrat& b)
{
	try
	{
		b.signForm(form);
		b.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

int main()
{
	//ShrubberyCreationForm s("shrub");

	RobotomyRequestForm r("robot");
	//PresidentialPardonForm p("larbi");
	Bureaucrat e("employee", 25);
	function(r, e);
	function(r, e);
	function(r, e);
	return (0);
}
