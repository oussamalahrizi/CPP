/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:39:28 by olahrizi          #+#    #+#             */
/*   Updated: 2023/12/15 21:45:52 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("no_target_PresidentialPardonForm", 25, 5), target("no_target") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm((target + "_PresidentialPardonForm").c_str(), 25, 5),
	target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!this->IsSigned())
		throw AForm::ExecuteException();
	if (this->GetGradeExecute() < executor.GetGrade())
		throw AForm::GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

