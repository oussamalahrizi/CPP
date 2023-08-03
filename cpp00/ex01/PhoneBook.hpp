#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Contact
{
	private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkSecret;
	public:
		Contact();
		Contact(std::string &FirstName, std::string &LastName, std::string &NickName,
				std::string &PhoneNumber, std::string &DarkSecret);
		std::string GetFirstName() const;
		std::string GetLastName() const;
		std::string GetNickName() const;
};

class PhoneBook
{
	private:
		int index;
		int count;
		Contact contacts[8];
	public:
		PhoneBook();
		void AddContact(Contact contact);
		int SearchContact(int index);
		int GetCount() const;
};
#endif 