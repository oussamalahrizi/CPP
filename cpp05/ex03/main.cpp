/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:15:36 by olahrizi          #+#    #+#             */
/*   Updated: 2023/12/15 22:50:25 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main()
{
	Intern random;

	AForm *ref = random.makeForm("presidential request", "bender");
	if (ref)
		std::cout << *ref << std::endl;
	return (0);
}