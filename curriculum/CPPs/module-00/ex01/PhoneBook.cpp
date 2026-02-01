#include "PhoneBook.hpp"

void PhoneBook::setContact(int index, const Contact& contact) {
	contacts[index] = contact;
}

const Contact& PhoneBook::getContact(int index) const {
	return contacts[index];
}
