/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:41:12 by olahrizi          #+#    #+#             */
/*   Updated: 2023/12/15 22:23:43 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("no_target_ShrubberyForm", 145, 137), target("not target") {}


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm((target + "_ShrubberyForm").c_str(), 145, 137),
	target(target) {}


ShrubberyCreationForm::~ShrubberyCreationForm() {}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
	*this = other;
}
	
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	
	if (!this->IsSigned())
		throw ShrubberyCreationForm::ExecuteException();
	if (executor.GetGrade() > this->GetGradeExecute())
		throw ShrubberyCreationForm::GradeTooLowException();
	std::ofstream file((this->target + "_shrubbery").c_str());
	if (!file.is_open() || !file.good())
		throw std::runtime_error("couldn't create target file");
	const char* tree =
        "	       _-_\n"
        "    /~~   ~~\\\n"
        " /~~         ~~\\\n"
        "{               }\n"
        " \\  _-     -_  /\n"
        "   ~  \\ \\ //  ~\n"
        "_- -   | | _- _\n"
        "  _ -  | |   -_\n"
        "      // \\\\";
	file << tree << std::endl;
	file.close();
}