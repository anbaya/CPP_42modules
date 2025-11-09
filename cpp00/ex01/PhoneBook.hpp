#ifndef PHONEBOOK_HPP

#include <iostream>
#include <cstring>

class Contact {
	public:
		char FirstName[50];
		char LastName[50];
		char NickName[50];
		char PhoneNumber[15];
		char DarkestSecret[100];
};
class PhoneBook {
	public:
		Contact	Contacts[8];
		int		ContactCount;
		int lastAddedIndex;
		int oldestOne;
};

int parseStr(char str[50]);
int parseNum(char str[15]);

# define PHONEBOOK_HPP
#endif // !PHONEBOOK_HPP