/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:06:53 by codespace         #+#    #+#             */
/*   Updated: 2024/11/14 16:05:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(LOWEST)
{
    std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    std::cout << "Bureaucrat constructor called: " << this->_name << std::endl;
    if (grade < HIGHEST)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > LOWEST)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = other;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called: " << this->_name << std::endl;
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->_name = other.getName();
    this->_grade = other.getGrade();
    return *this;
}

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void    Bureaucrat::incrementGrade(int value)
{
    if ((this->_grade - value) < HIGHEST)
        throw Bureaucrat::GradeTooHighException();
    this->_grade -= value;
}

void    Bureaucrat::decrementGrade(int value)
{
    if ((this->_grade + value) > LOWEST)
        throw Bureaucrat::GradeTooLowException();
    this->_grade += value;
}

const char  *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too High!";
}

const char  *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat)
{
	return (str << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}
