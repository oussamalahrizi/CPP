#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("No name"), m_grade_sign(150), m_grade_execute(150)
{
	this->m_signed = false;
}

AForm::AForm(const std::string& name, int grade_sign, int grade_exec) : name(name),
	m_grade_sign(grade_sign), m_grade_execute(grade_exec)
{
	m_signed = false;
	if (m_grade_sign < 1 || m_grade_execute < 1)
		throw GradeTooHighException();
	else if (m_grade_sign > 150 || m_grade_execute > 150)
		throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		m_signed = other.m_signed;
	return (*this);
}

AForm::AForm(const AForm& other) : name(other.name), m_grade_sign(other.m_grade_sign),
		m_grade_execute(other.m_grade_execute)
{
	*this = other;
}

AForm::~AForm()
{
}

std::string AForm::GetName() const
{
	return (this->name);
}

bool AForm::IsSigned() const
{
	return (m_signed);
}

int AForm::GetGradesign() const
{
	return (this->m_grade_sign);
}


int AForm::GetGradeExecute() const
{
	return (this->m_grade_execute);
}


void AForm::beSigned(Bureaucrat& B)
{
	if (B.GetGrade() > this->m_grade_sign)
		throw GradeTooLowException();
	std::cout << B.GetName() << " signed " << this->name << std::endl;
	m_signed = true;
}

std::ostream& operator<<(std::ostream& stream, const AForm& other)
{
	stream << "AForm name : " << other.GetName() << std::endl;
	stream << "Grade required to sign : " << other.GetGradesign() << std::endl;
	stream << "Grade required to execute : " << other.GetGradeExecute() << std::endl;
	stream << "Is signed : " << other.IsSigned();
	return (stream);
}