#pragma once

#include <iostream>
#include <exception>

class Bureaucrat;
class AForm
{
	private:
		const std::string name;
		bool m_signed;
		const int m_grade_sign;
		const int m_grade_execute;

	public:
		AForm();
		AForm(const std::string& name, int grade_sign, int grade_exec);
		AForm(const AForm& other);
		virtual ~AForm();

		AForm& operator=(const AForm& other);

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "AForm Grade too high";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "AForm Grade too low";
				}
		};

		class ExecuteException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "AForm can't be executed : form not signed";
				}
		};
		//accessors
		std::string GetName() const;
		bool IsSigned() const;
		int GetGradesign() const;
		int GetGradeExecute() const;

		// other member functions
		void beSigned(Bureaucrat& B);
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& stream, const AForm& other);