/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:09:03 by abarahho          #+#    #+#             */
/*   Updated: 2025/04/12 14:35:09 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
	: FirstName(""), LastName(""), Nickname(""), PhoneNumber(""), DarkestSecret("") {}

Contact::~Contact() {}

// getters (to have access to the content)

std::string Contact::getFirstName() const
{
	return (FirstName);
}

std::string Contact::getLastName() const
{
	return (LastName);
}

std::string Contact::getNickname() const
{
	return (Nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (PhoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (DarkestSecret);
}

// setters (to modifie the content)

void Contact::setFirstName(const std::string &firstName)
{
	FirstName = firstName;
}

void Contact::setLastName(const std::string &lastName)
{
	LastName = lastName;
}
void Contact::setNickname(const std::string &nickname)
{
	Nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber)
{
	PhoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret)
{
	DarkestSecret = darkestSecret;
}
	