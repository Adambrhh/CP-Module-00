/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:11:48 by abarahho          #+#    #+#             */
/*   Updated: 2025/04/14 17:23:39 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() 
	: index(0), full(false) {}


PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact()
{
	std::string	input;

	if (full)
		index = 0;
	Contact &currentContact = contacts[index];
	std::cout << "======= New contact =======" << std::endl;
	std::cout << "First name: ";
	std::getline(std::cin >> std::ws, input);
	currentContact.setFirstName(input);
	std::cout << "Last name: ";
	std::getline(std::cin, input);
	currentContact.setLastName(input);
	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	currentContact.setNickname(input);
	std::cout << "Phone number: ";
	std::getline(std::cin, input);
	currentContact.setPhoneNumber(input);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, input);
	currentContact.setDarkestSecret(input);
	index++;
	if (index >= 8)
	{
		full = true;
		index = 0;
	}
	system("clear");
	std::cout <<  "Contact added" << std::endl;
}

std::string	PhoneBook::formatField(const std::string& field) const
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field);
}

void	PhoneBook::displayContactList() const
{
	int	i;

	i = 0;
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First name" << "|"
			  << std::setw(10) << "Last name" << "|"
			  << std::setw(10) << "Nickname" << "|" << std::endl;
	while (i < index)
	{
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
				  << std::setw(10) << formatField(contacts[i].getLastName()) << "|"
				  << std::setw(10) << formatField(contacts[i].getNickname()) << std::endl;
		i++;		
	}
}

void	PhoneBook::displayContactDetails(const Contact &contact) const
{
	std::cout << contact.getFirstName() << std::endl;
	std::cout << contact.getLastName() << std::endl;
	std::cout << contact.getNickname() << std::endl;
	std::cout << contact.getPhoneNumber() << std::endl;
	std::cout << contact.getDarkestSecret() << std::endl;
}

void	PhoneBook::searchContact() const
{
	int	selectedIndex;

	selectedIndex = 0;
	if (index == 0 && !full)
	{
		system("clear");
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	displayContactList();
	std::cout << "Enter contact index" << std::endl;
	std::cin >> selectedIndex;
	std::cin.ignore();
	if (selectedIndex >= 0 && selectedIndex <= index)
	{
		system("clear");
		displayContactDetails(contacts[selectedIndex]);
	}
	else
		std::cout << "Invalid index" << std::endl;
}
