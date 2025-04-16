/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:11:48 by abarahho          #+#    #+#             */
/*   Updated: 2025/04/16 10:46:15 by abarahho         ###   ########.fr       */
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

	if (index == 8)
		index = 0;
	Contact &currentContact = contacts[index];
	std::cout << "======= New contact =======" << std::endl;
	std::cout << "First name: ";
	std::getline(std::cin >> std::ws, input);
	currentContact.setFirstName(input);
	std::cout << "Last name: ";
	std::getline(std::cin >> std::ws, input);
	currentContact.setLastName(input);
	std::cout << "Nickname: ";
	std::getline(std::cin >> std::ws, input);
	currentContact.setNickname(input);
	std::cout << "Phone number: ";
	std::getline(std::cin >> std::ws, input);
	currentContact.setPhoneNumber(input);
	std::cout << "Darkest secret: ";
	std::getline(std::cin >> std::ws, input);
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

void	PhoneBook::searchContact() const
{
	int	selectedIndex;

	if (index == 0 && !full)
	{
		system("clear");
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	displayContactList();
	selectedIndex = checkIndex();
	system("clear");
	displayContactDetails(contacts[selectedIndex]);
}