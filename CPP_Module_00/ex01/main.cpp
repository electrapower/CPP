/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalniko <asalniko@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 19:56:26 by asalniko          #+#    #+#             */
/*   Updated: 2026/03/23 19:56:27 by asalniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include "PhoneBook.hpp"

static bool isEmptyField(const std::string &value)
{
	return value.empty();
}

static bool askNonEmptyField(const std::string &label, std::string &out)
{
	std::cout << label;
	if (!std::getline(std::cin, out))
		return false;
	if (isEmptyField(out))
	{
		std::cout << "Field cannot be empty." << std::endl;
		return false;
	}
	return true;
}

static bool parseIndex(const std::string &text, int &index)
{
	// Treat the input string as an input stream.
	std::stringstream inputStream(text);

	// Try to read one integer from the stream.
	inputStream >> index;

	// Invalid if integer read failed, or if extra characters remain (example: "12abc").
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

			if (!askNonEmptyField("First name: ", firstName)
				|| !askNonEmptyField("Last name: ", lastName)
				|| !askNonEmptyField("Nickname: ", nickname)
				|| !askNonEmptyField("Phone number: ", phoneNumber)
				|| !askNonEmptyField("Darkest secret: ", darkestSecret))
			{
				if (std::cin.eof())
					break;
				continue;
			}
			phoneBook.addContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
			std::cout << "Contact added." << std::endl;
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
			if (!parseIndex(input, index))
			{
				std::cout << "Invalid index." << std::endl;
				continue;
			}
			phoneBook.displayOneContact(index);
		}
		else if (command == "EXIT")
		{
			break;
		}
		else
		{
			std::cout << "Unknown command." << std::endl;
		}
	}
	return 0;
}
