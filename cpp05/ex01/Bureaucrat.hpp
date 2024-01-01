#pragma once

#include <iostream>
#include <exception>
#include "Form.hpp"

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& other);

		// accessors
		std::string GetName() const;
		int GetGrade() const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Grade too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Grade too low");
				}
		};
		void incrementGrade();
		void decrementGrade();
		void signForm(Form& form);
};


std::ostream& operator<<(std::ostream& stream, const Bureaucrat& other);
