#include "PhoneBook.hpp"

int addContact(PhoneBook* phoneBook)
{
	Contact newContact;
	char firstName[50];
	char lastName[50];
	char nickName[50];
	char phoneNumber[15];
	char darkestSecret[100];

	std::cout << "Enter the first name: ";
	std::cin >> firstName;
	std::cout << "Enter the last name: ";
	std::cin >> lastName;
	std::cout << "Enter the nickname: ";
	std::cin >> nickName;
	std::cout << "Enter the phone number: ";
	std::cin >> phoneNumber;
	std::cout << "Enter the darkest secret: ";
	std::cin >> darkestSecret;
	if (!parseNum(phoneNumber))
		return (std::cout << "Invalid phone number. It should contain only digits." << std::endl, 1);
	if (!parseStr(firstName))
		return (std::cout << "Invalid first name. It should contain only letters." << std::endl, 1);
	if (!parseStr(lastName))
		return (std::cout << "Invalid last name. It should contain only letters." << std::endl, 1);
	if (!parseStr(nickName))
		return (std::cout << "Invalid nickname. It should contain only letters." << std::endl, 1);
	strncpy(newContact.FirstName, firstName, sizeof(newContact.FirstName) - 1);
	strncpy(newContact.LastName, lastName, sizeof(newContact.LastName) - 1);
	strncpy(newContact.NickName, nickName, sizeof(newContact.NickName) - 1);
	strncpy(newContact.PhoneNumber, phoneNumber, sizeof(newContact.PhoneNumber) -	 1);
	strncpy(newContact.DarkestSecret, darkestSecret, sizeof(newContact.DarkestSecret) - 1);
	if (phoneBook->ContactCount == 8)
	{
		phoneBook->oldestOne += 1;
		if (phoneBook->oldestOne > 7)
			phoneBook->oldestOne = 0;
		phoneBook->Contacts[phoneBook->oldestOne] = newContact;
	}
	else
	{
		phoneBook->lastAddedIndex += 1;
		phoneBook->Contacts[phoneBook->lastAddedIndex] = newContact;
		phoneBook->ContactCount++;
	}
	std::cout << "Contact added successfully!" << std::endl;
	return (0);
}

int printContacts(PhoneBook *phonBook)
{
	std::cout << "Index | First Name       | Last Name        | Nickname        " << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	for (int i = 0; i < phonBook->ContactCount; i++)
	{
		std::cout << "  " << i << "  | ";
		std::cout.width(15);
		std::cout << std::right << phonBook->Contacts[i].FirstName << " | ";
		std::cout.width(15);
		std::cout << std::right << phonBook->Contacts[i].LastName << " | ";
		std::cout.width(15);
		std::cout << std::right << phonBook->Contacts[i].NickName << std::endl;
	}
	return (0);
}

int searchContact(PhoneBook *phoneBook)
{
	int index;

	std::cout << "Search contact by index: ";
	std::cin >> index;
	if (index < 0 || index >= phoneBook->ContactCount)
		return (std::cout << "Invalid index." << std::endl, 1);
	std::cout << "Index | First Name       | Last Name        | Nickname        " << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "  " << index << "  | ";
	std::cout.width(15);
	std::cout << std::right << phoneBook->Contacts[index].FirstName << " | ";
	std::cout.width(15);
	std::cout << std::right << phoneBook->Contacts[index].LastName << " | ";
	std::cout.width(15);
	std::cout << std::right << phoneBook->Contacts[index].NickName << std::endl;
	return (0);
}

int main () {

	PhoneBook myPhoneBook;
	char command[10];

	myPhoneBook.ContactCount = 0;
	myPhoneBook.lastAddedIndex = -1;
	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::cin >> command;
		if (std::string(command) == "ADD")
			addContact(&myPhoneBook);
		else if (std::string(command) == "SEARCH")
		{
			printContacts(&myPhoneBook);
			searchContact(&myPhoneBook);
		}
		else if (std::string(command) == "EXIT")
			break ;
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	return 0;
}