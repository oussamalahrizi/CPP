#include "PhoneBook.hpp"

int input(std::string &str, std::string message)
{
    std::string read;
    std::cout << message;
    std::getline(std::cin, read);
    if (std::cin.eof() || read.empty())
    {
        std::cin.clear();
        std::cout << "Error\n";
        return (0);
    }
    str = read;
    return (1);
}

void CaseAdd(PhoneBook &book)
{
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string darksecret;
    std::string phonenumber;

    if(!input(firstname, "first name : "))
        return;
    if(!input(lastname, "last name : "))
        return;
    if(!input(nickname, "nick name : "))
        return;
    if(!input(darksecret, "dark secret : "))
        return;
    if(!input(phonenumber, "phone number : "))
        return;
    Contact contact(firstname, lastname, nickname, phonenumber, darksecret);
    book.AddContact(contact);
}

void CaseSearch(PhoneBook &book)
{
    std::string read;
    if (book.GetCount() == 0)
    {
        std::cout << "Contact list is empty\n";
        return ;
    }
    int i = 0;

    while (i < book.GetCount())
    {
        book.SearchContact(i);
        i++;
    }
    std::cout << "Enter index 0 - " << book.GetCount() - 1 << " : ";
    std::getline(std::cin, read);
    if (std::cin.eof() || read.empty())
    {
        std::cin.clear();
        std::cout << "Error\n";
        return ;
    }
    int index = std::atoi(read.data());
    if(index < 0 || index > 7)
    {
        std::cout << "invalid index\n";
        return;
    }
    if (book.SearchContact(index) == 0)
        return;
}

int main(void)
{
    PhoneBook book;
    std::string input;

    std::cout << "WELCOME TO 80s PHONEBOOK \n";
    std::cout << "Available commands : ADD, SEARCH, EXIT \n";
    while (1)
    {
        std::cout << "> ";
        std::getline(std::cin, input);
        if (std::cin.eof())
            std::exit(0);
        if(input.empty())
        {
            std::cin.clear();
            continue;
        }
        if (input == "ADD")
            CaseAdd(book);
        else if (input == "SEARCH")
            CaseSearch(book);
        else if (input == "EXIT")
            std::exit(0);
        std::cin.clear();
    }
    return (0);
}