/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:15:36 by olahrizi          #+#    #+#             */
/*   Updated: 2023/12/15 22:20:07 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

# define CASE 0

int main()
{
	#if CASE == 0
		try
		{
			Bureaucrat a("test", 200);
			a.decrementGrade();
			std::cout << a << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	#elif CASE == 1
		try
		{
			Bureaucrat a("test", 200);
			a.decrementGrade();
			std::cout << a << std::endl;
		}
		catch (const Bureaucrat::GradeTooHighException & e)
		{
			std::cerr << e.what() << std::endl;
		}
	#elif CASE == 2
		try
		{
			Bureaucrat a("test", 200);
			a.decrementGrade();
			std::cout << a << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException & e)
		{
			std::cerr << e.what() << std::endl;
		}
	#endif
	return (0);
}