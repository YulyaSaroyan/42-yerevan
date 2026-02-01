#include <string>
#include "Contact.hpp"

Contact::Contact(
	std::string firstname,
	std::string lastname,
	std::string nickname,
	std::string phone,
	std::string secret
) {
	this->firstname = firstname;
	this->lastname = lastname;
	this->nickname = nickname;
	this->phone = phone;
	this->secret = secret;
}

std::string Contact::getFirstname() const {
	return this->firstname;
}

std::string Contact::getLastname() const {
	return this->lastname;
}

std::string Contact::getNickname() const {
	return this->nickname;
}

std::string Contact::getPhone() const {
	return this->phone;
}

std::string Contact::getSecret() const {
	return this->secret;
}
