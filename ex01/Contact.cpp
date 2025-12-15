#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setFirstName(std::string str)
{
	this->_firstName = str;
}

void Contact::setLastName(std::string str)
{
	this->_lastName = str;
}

void Contact::setNickname(std::string str)
{
	this->_nickname = str;
}

void Contact::setPhoneNumber(std::string str)
{
	this->_phoneNumber = str;
}

void Contact::setDarkestSecret(std::string str)
{
	this->_darkestSecret = str;
}

std::string Contact::getFirstName() const
{
	return (this->_firstName);
}

std::string Contact::getLastName() const
{
	return (this->_lastName);
}

std::string Contact::getNickname() const
{
	return (this->_nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (this->_darkestSecret);
}

void Contact::displayView() const
{
	if (this->_firstName.empty() && this->_lastName.empty() && this->_nickname.empty())
		return ;
	std::cout << "First Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}
