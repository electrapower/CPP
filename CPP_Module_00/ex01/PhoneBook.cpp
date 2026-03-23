/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalniko <asalniko@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 19:56:18 by asalniko          #+#    #+#             */
/*   Updated: 2026/03/23 19:56:20 by asalniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

static std::string formatColumn(const std::string &value)
{
    if (value.length() > 10)
        return value.substr(0, 9) + ".";
    return value;
}

PhoneBook::PhoneBook(void)
{
    _count = 0;
    _nextIndex = 0;
}

void PhoneBook::addContact(std::string firstName, std::string lastName, 
    std::string nickname, std::string phoneNumber, 
    std::string darkestSecret)
{
    _contacts[_nextIndex].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    _nextIndex = (_nextIndex + 1) % 8;
    if (_count < 8)
        _count++;
}

int PhoneBook::getCount(void) const
{
    return _count;
}

void PhoneBook::displayContacts(void) const
{
    std::cout << std::right
        << std::setw(10) << "Index" << "|"
        << std::setw(10) << "First Name" << "|"
        << std::setw(10) << "Last Name" << "|"
        << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < _count; i++)
    {
        std::cout << std::right
            << std::setw(10) << i + 1 << "|"
            << std::setw(10) << formatColumn(_contacts[i].getFirstName()) << "|"
            << std::setw(10) << formatColumn(_contacts[i].getLastName()) << "|"
            << std::setw(10) << formatColumn(_contacts[i].getNickname()) << std::endl;
    }
}

void PhoneBook::displayOneContact(int index) const
{
    if (index < 1 || index > _count)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    const Contact &contact = _contacts[index - 1];
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}
