#include <iostream>
#include <string>
#include <limits>
#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string getInfo(std::string placeholder) {
	std::string value;
	std::cout << placeholder;
	std::getline(std::cin, value);
	return value;
}

int getInfo() {
	int value;
	std::cout << "index: ";
	std::cin >> value;
	return value;
}

std::string truncate(std::string str) {
	if (str.length() > 10) {
		str.resize(9);
		return str + ".";
	}
	std::string padded = std::string(10 - str.size(), ' ') + str;
	return padded;
}

int main(void) {
	const std::string ADD = "ADD";
	const std::string SEARCH = "SEARCH";
	const std::string EXIT = "EXIT";
	const std::string firstnamePlaceholder = "first name: ";
	const std::string lastnamePlaceholder = "last name: ";
	const std::string nicknamePlaceholder = "nickname: ";
	const std::string phonePlaceholder = "phone number: ";
	const std::string secretPlaceholder = "darkest secret: ";

	std::string input;

	int counter = 0;
	PhoneBook phoneBook;
	do {
		std::cin >> input;
		if (input == ADD) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::string firstname = getInfo(firstnamePlaceholder);
			std::string lastname = getInfo(lastnamePlaceholder);
			std::string nickname = getInfo(nicknamePlaceholder);
			std::string phone = getInfo(phonePlaceholder);
			std::string secret = getInfo(secretPlaceholder);

			Contact contact(firstname, lastname, nickname, phone, secret);

			if (counter != 8) counter++;
			phoneBook.setContact(counter - 1, contact);

		} else if (input == SEARCH) {
			for (int i = 0; i < counter; i++) {
				const Contact& contact = phoneBook.getContact(i);
				std::string firstname = contact.getFirstname();
				std::string lastname = contact.getLastname();
				std::string nickname= contact.getNickname();

				std::cout << i << "| " + truncate(firstname) + "| " + truncate(lastname) + "| " + truncate(nickname) << std::endl;
			}

			int index = getInfo();
			if (index > counter || index < 0) {
				std::cout << "Invalid index." << std::endl;
				continue;
			}

			const Contact& contact = phoneBook.getContact(index);
			std::string firstname = contact.getFirstname();
			std::string lastname = contact.getLastname();
			std::string nickname= contact.getNickname();
			std::string phone= contact.getPhone();
			std::string secret= contact.getSecret();

			std::cout << firstnamePlaceholder + firstname << std::endl;
			std::cout << lastnamePlaceholder + lastname << std::endl;
			std::cout << nicknamePlaceholder + nickname << std::endl;
			std::cout << phonePlaceholder + phone << std::endl;
			std::cout << secretPlaceholder + secret << std::endl;
		}
	} while (input != EXIT);

	return 0;
}
