/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalniko <asalniko@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 19:55:53 by asalniko          #+#    #+#             */
/*   Updated: 2026/03/23 19:55:56 by asalniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setContact(std::string firstName, std::string lastName, 
    std::string nickname, std::string phoneNumber, 
    std::string darkestSecret)
{
    _firstName = firstName;
    _lastName = lastName;
    _nickname = nickname;
    _phoneNumber = phoneNumber;
    _darkestSecret = darkestSecret;
}

std::string Contact::getFirstName(void) const
{
    return _firstName;
}

std::string Contact::getLastName(void) const
{
    return _lastName;
}

std::string Contact::getNickname(void) const
{
    return _nickname;
}

std::string Contact::getPhoneNumber(void) const
{
    return _phoneNumber;
}

std::string Contact::getDarkestSecret(void) const
{
    return _darkestSecret;
}
