#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("No name"), m_grade_sign(150), m_grade_execute(150)
{
	this->m_signed = false;
}

Form::Form(const std::string& name, int grade_sign, int grade_exec) : name(name),
	m_grade_sign(grade_sign), m_grade_execute(grade_exec)
{
	m_signed = false;
	if (m_grade_sign < 1 || m_grade_execute < 1)
		throw GradeTooHighException();
	else if (m_grade_sign > 150 || m_grade_execute > 150)
		throw GradeTooLowException();
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		m_signed = other.m_signed;
	return (*this);
}

Form::Form(const Form& other) : name(other.name), m_grade_sign(other.m_grade_sign),
		m_grade_execute(other.m_grade_execute)
{
	*this = other;

}

Form::~Form()
{

}

std::string Form::GetName() const
{
	return (this->name);
}

bool Form::IsSigned() const
{
	return (m_signed);
}

int Form::GetGradesign() const
{
	return (this->m_grade_sign);
}


int Form::GetGradeExecute() const
{
	return (this->m_grade_execute);
}


void Form::beSigned(Bureaucrat& B)
{
	if (B.GetGrade() > this->m_grade_sign)
		throw GradeTooLowException();
	m_signed = true;
	std::cout << B.GetName() << " signed " << this->name << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const Form& other)
{
	stream << "Form name : " << other.GetName() << std::endl;
	stream << "Grade required to sign : " << other.GetGradesign() << std::endl;
	stream << "Grade required to execute : " << other.GetGradeExecute() << std::endl;
	stream << "Is signed : " << other.IsSigned();
	return (stream);
}