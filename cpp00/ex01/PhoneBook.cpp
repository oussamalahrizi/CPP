#include "PhoneBook.hpp"

Contact::Contact() {}

Contact::Contact(std::string &FirstName, std::string &LastName, std::string &NickName,
				std::string &PhoneNumber, std::string &DarkSecret)
{
    this->FirstName = FirstName;
    this->LastName = LastName;
    this->NickName = NickName;
    this->PhoneNumber = PhoneNumber;
    this->DarkSecret = DarkSecret;
}


std::string Contact::GetFirstName() const
{
    return (this->FirstName);
}

std::string Contact::GetLastName() const
{
    return (this->LastName);
}

std::string Contact::GetNickName() const
{
    return (this->NickName);
}

PhoneBook::PhoneBook()
{
    count = 0;
}

int PhoneBook::GetCount() const
{
    return (this->count);
}

void PhoneBook::AddContact(Contact contact)
{
    if(count > 8)
    {
        index = 0;
        contacts[index] = contact;
        index++;
        return ;
    }
    contacts[count] = contact;
    index++;
    count++;
    return;
}

void print_string(const std::string& str)
{
    if (str.length() <= 10)
        std::cout << str;
    else
        std::cout << str.substr(0, 9) << ".";
}

int PhoneBook::SearchContact(int index)
{
    if (index > this->count - 1)
    {
        std::cout << "Out of range\n";
        return 0;
    }
    Contact contact = contacts[index];
    std::cout << index ;
    std::cout << " | ";
    print_string(contact.GetFirstName());
    std::cout << " | ";
    print_string(contact.GetLastName());
    std::cout << " | ";
    print_string(contact.GetNickName());
    std::cout << std::endl;
    return 1;
}
