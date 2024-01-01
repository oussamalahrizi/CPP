/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:01:02 by olahrizi          #+#    #+#             */
/*   Updated: 2023/12/15 22:47:00 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() : AForm("no_target_RobotomyRequestForm", 72, 45), target("no target") {}


RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :  AForm((target + "_RobotomyRequestForm").c_str(), 72, 45) ,
	target(target) {}


RobotomyRequestForm::~RobotomyRequestForm() {}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
	*this = other;
}


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	std::string error("robotomy failed. ");
	if (!this->IsSigned())
	{
		std::cerr << error;
		throw AForm::ExecuteException();
	}
	if (this->GetGradeExecute() < executor.GetGrade())
	{
		std::cerr << error ;
		throw AForm::GradeTooLowException();
	}
	std::cout << this->target << " makes some drilling noises" << std::endl;
	std::cout << this->target << " has been robotomized successfully 50% of the time" << std::endl;
}