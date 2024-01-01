#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : name("no name"), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{

	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->grade = grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->grade = other.grade;

	return(*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat&other) : name(other.name)
{
	*this = other;

}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::GetName() const
{
	return (this->name);
}

int Bureaucrat::GetGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	*this = Bureaucrat(this->name, this->grade - 1);
}

void Bureaucrat::decrementGrade()
{
	*this = Bureaucrat(this->name, this->grade + 1);
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& other)
{
	return (stream << other.GetGrade());
}
