/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalniko <asalniko@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 19:56:11 by asalniko          #+#    #+#             */
/*   Updated: 2026/03/23 19:56:13 by asalniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include "Contact.hpp"

class PhoneBook
{
    private:
        Contact _contacts[8];
        int _count;
        int _nextIndex;

    public:
        PhoneBook(void);
        void addContact(std::string firstName, std::string lastName, 
            std::string nickname, std::string phoneNumber, 
            std::string darkestSecret);
        void displayContacts(void) const;
        void displayOneContact(int index) const;
        int getCount(void) const;
};

#endif
