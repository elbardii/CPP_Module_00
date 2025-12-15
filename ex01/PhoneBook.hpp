#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <cstdlib>

class PhoneBook
{
	private:
		Contact _contacts[8];
		int _currentIndex;
		int _contactCount;

		std::string _readInput(std::string prompt);
		std::string _formatColumn(std::string str);
		void _displayList();

	public:
		PhoneBook();
		~PhoneBook();

		void add();
		void search();
};

#endif
