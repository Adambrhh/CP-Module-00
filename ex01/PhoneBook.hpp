/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:11:59 by abarahho          #+#    #+#             */
/*   Updated: 2025/04/14 15:25:54 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

class PhoneBook
{
private:
	Contact 	contacts[8];
	int			index;
	bool		full;
	void		displayContactList() const;
	void		displayContactDetails(const Contact &c) const;
	std::string	formatField(const std::string& field) const;
public:
	PhoneBook();
	~PhoneBook();
	
	void	addContact();
	void	searchContact() const;
};

#endif