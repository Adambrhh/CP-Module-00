/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:12:42 by abarahho          #+#    #+#             */
/*   Updated: 2025/04/14 15:59:42 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib> 

void displayHelp()
{
	std::cout << "======= Available commands =======" << std::endl;
	std::cout << "ADD\t- Add a contact" << std::endl;
	std::cout << "SEARCH\t- Search a contact" << std::endl;
	std::cout << "EXIT\t- Exit the program\n" << std::endl;
}

int main()
{
	PhoneBook	phonebook;
	std::string	input;
	
	system("clear");
	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
	displayHelp();
	while (1)
	{
		std::cout << "> ";
		if (!std::getline(std::cin, input))
			break ;
		if (input == "EXIT")
			break;
		else if (input == "ADD")
		{
			system("clear");
			phonebook.addContact();
		}
		else if (input == "SEARCH")
		{
			system("clear");
			phonebook.searchContact();
		}
		else
		{
			system("clear");
			displayHelp();
		}
	}
	system("clear");
	return (0);
}
