#pragma once

#include <iostream>
#include <exception>

class Bureaucrat;
class Form
{
	private:
		const std::string name;
		bool m_signed;
		const int m_grade_sign;
		const int m_grade_execute;

	public:
		Form();
		Form(const std::string& name, int grade_sign, int grade_exec);
		Form(const Form& other);
		~Form();

		Form& operator=(const Form& other);

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Form Grade too high";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Form Grade too low";
				}
		};
		//accessors
		std::string GetName() const;
		bool IsSigned() const;
		int GetGradesign() const;
		int GetGradeExecute() const;

		// others
		void beSigned(Bureaucrat& B);
};

std::ostream& operator<<(std::ostream& stream, const Form& other);