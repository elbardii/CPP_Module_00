#include "PhoneBook.hpp"

static bool isNumeric(const std::string& str)
{
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

PhoneBook::PhoneBook() : _currentIndex(0), _contactCount(0)
{
}

PhoneBook::~PhoneBook()
{
}

std::string PhoneBook::_readInput(std::string prompt)
{
	std::string input;

	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
			exit(0);
		if (!input.empty())
			return (input);
		std::cout << "Field cannot be empty." << std::endl;
	}
}

void PhoneBook::add()
{
	Contact newContact;

	std::cout << "Adding new contact:" << std::endl;
	newContact.setFirstName(this->_readInput("First Name: "));
	newContact.setLastName(this->_readInput("Last Name: "));
	newContact.setNickname(this->_readInput("Nickname: "));
	newContact.setPhoneNumber(this->_readInput("Phone Number: "));
	newContact.setDarkestSecret(this->_readInput("Darkest Secret: "));

	this->_contacts[this->_currentIndex] = newContact;
	this->_currentIndex = (this->_currentIndex + 1) % 8;
	if (this->_contactCount < 8)
		this->_contactCount++;
	std::cout << "Contact added successfully." << std::endl;
}

std::string PhoneBook::_formatColumn(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void PhoneBook::_displayList()
{
	std::cout << "|   Index  |First Name| Last Name| Nickname |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < this->_contactCount; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10) << this->_formatColumn(this->_contacts[i].getFirstName());
		std::cout << "|" << std::setw(10) << this->_formatColumn(this->_contacts[i].getLastName());
		std::cout << "|" << std::setw(10) << this->_formatColumn(this->_contacts[i].getNickname());
		std::cout << "|" << std::endl;
	}
}

void PhoneBook::search()
{
	std::string input;
	int index;

	if (this->_contactCount == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return ;
	}
	this->_displayList();
	std::cout << "Enter index to view details: ";
	if (!std::getline(std::cin, input))
		exit(0);
	if (!isNumeric(input))
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	index = std::atoi(input.c_str());
	if (index > 0 && index <= this->_contactCount)
	{
		this->_contacts[index - 1].displayView();
	}
	else
	{
		std::cout << "Invalid index." << std::endl;
	}
}
