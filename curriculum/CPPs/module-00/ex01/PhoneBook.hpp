#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook {
	Contact contacts[8];

	public:
		void setContact(int index, const Contact& contact);
		const Contact& getContact(int index) const;
};

#endif
