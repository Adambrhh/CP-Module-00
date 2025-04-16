/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SearchContact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:56:16 by abarahho          #+#    #+#             */
/*   Updated: 2025/04/16 10:45:56 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	PhoneBook::formatField(const std::string& field) const
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field);
}

void	PhoneBook::displayContactList() const
{
	int	i;
	int	j;

	i = 0;
	if (full)
		j = 8;
	else
		j = index;
	std::cout << "|";
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First name" << "|"
			  << std::setw(10) << "Last name" << "|"
			  << std::setw(10) << "Nickname" << "|" << std::endl;
	while (i < j)
	{
		std::cout << "|";
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
				  << std::setw(10) << formatField(contacts[i].getLastName()) << "|"
				  << std::setw(10) << formatField(contacts[i].getNickname()) << "|" << std::endl;
		i++;		
	};
}

void	PhoneBook::displayContactDetails(const Contact &contact) const
{
	std::cout << "First name:\t" << contact.getFirstName() << std::endl;
	std::cout << "Last name:\t" <<contact.getLastName() << std::endl;
	std::cout << "Nickname:\t" <<contact.getNickname() << std::endl;
	std::cout << "Phone number:\t" <<contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret:\t" <<contact.getDarkestSecret() << std::endl;
}

int	PhoneBook::checkIndex() const
{
	bool		is_num;
	int			i;
	int			max_index;
	std::string	input;

	if (full)
		max_index = 7;
	else
		max_index = index - 1;
	while (true)
	{
		if (std::cin.eof())
		{
			system("clear");
			exit(0);
		}
		std::cout << "Enter contact index (0-" << max_index << "): ";
		std::getline(std::cin, input);
		is_num = true;
		i = 0;
		while (input[i])
		{
			if (!isdigit(input[i]))
			{
				is_num = false;
				break ;
			}
			i++;
		}
		if (is_num && !input.empty())
		{
			if (atoi(input.c_str()) >= 0 && atoi(input.c_str()) <= max_index)
				return (atoi(input.c_str()));
		}
		std::cout << "Invalid index. ";
	}
}
