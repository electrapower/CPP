/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalniko <asalniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 19:56:26 by asalniko          #+#    #+#             */
/*   Updated: 2026/04/19 18:44:24 by asalniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include "PhoneBook.hpp"

static bool askNonEmptyField(const std::string &label, std::string &out)
{
	while (true)
	{
		std::cout << label;
		if (!std::getline(std::cin, out))
			return false;
		if (!out.empty())
			return true;
		std::cout << "Field cannot be empty." << std::endl;
	}
}

static bool parseIndex(const std::string &text, int &index)
{
	std::stringstream inputStream(text);

	inputStream >> index;
	if (inputStream.fail() || !inputStream.eof())
		return false;
	return true;
}

int main(void)
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break;
		if (command == "ADD")
		{
			std::string firstName;
			std::string lastName;
			std::string nickname;
			std::string phoneNumber;
			std::string darkestSecret;

			if (!askNonEmptyField("First name: ", firstName))
				break;
			if (!askNonEmptyField("Last name: ", lastName))
				break;
			if (!askNonEmptyField("Nickname: ", nickname))
				break;
			if (!askNonEmptyField("Phone number: ", phoneNumber))
				break;
			if (!askNonEmptyField("Darkest secret: ", darkestSecret))
				break;
			phoneBook.addContact(firstName, lastName, nickname,
				phoneNumber, darkestSecret);
		}
		else if (command == "SEARCH")
		{
			std::string input;
			int index;

			if (phoneBook.getCount() == 0)
			{
				std::cout << "PhoneBook is empty." << std::endl;
				continue;
			}
			phoneBook.displayContacts();
			std::cout << "Enter index: ";
			if (!std::getline(std::cin, input))
				break;
			if (!parseIndex(input, index) || index < 1
				|| index > phoneBook.getCount())
			{
				std::cout << "Invalid index." << std::endl;
				continue;
			}
			phoneBook.displayOneContact(index);
		}
		else if (command == "EXIT")
			break;
	}
	return 0;
}