#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phone;
	std::string secret;

	public:
		Contact() {}
		Contact(
			std::string firstname,
			std::string lastname,
			std::string nickname,
			std::string phone,
			std::string secret
		);
		std::string getFirstname() const;
		std::string getLastname() const;
		std::string getNickname() const;
		std::string getPhone() const;
		std::string getSecret() const;
};

#endif
