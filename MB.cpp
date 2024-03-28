#include <iostream>
#include <map>
#include <string>
#include <regex>
#include <utility>
#include <algorithm>
using namespace std;

#define STR(text) #text
#define PRINT_TASK(STR)                                                        \
  std::cout << STR(                                                            \
      26.4 Practical work. Task 2. Implementation of a mobile phone simulation program\n\n)
class Phone
{
public:

    class AddressBook
    {
    public:
        std::string name;
        std::string phone;
        AddressBook()
        {
            name = std::move(name);
            phone = std::move(phone); 
        }
    };
   
    static std::string CheckingLineEntry(std::string t) {
        while (!std::all_of(t.begin(), t.end(),
            [](char c) { return std::isalpha(c); })) {
            std::cout << "Enter the string correctly -> " << std::endl;
            std::cin >> t;
        }
        return t;
    }
    static std::string CheckingPhone(std::string t) {
        std::regex rgx{ "^((\\+7|7|8)?([0-9]{3})?-([0-9]{3})?-([0-9]{2})?-([0-9]{2}))$" };
        while (!(std::regex_match(t, rgx)))
        {
            std::cout << "Invalid \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> t;
        }
        std::cout << "This is an int: " << t << std::endl;
        return t;
    }
       static void InputDirectory(AddressBook ab,std::map<std::string, std::string> &m, std::multimap<std::string, std::string> mm)
       {
           int n;
           std::cout << "Specify the number of subscribers to enter -> ";
           std::cin >> n;
           for (int i(0); i < n; ++i) {
              std::string _ph, _ln;
               std::cout << "Ente Phone (for example: +7123-456-78-90) -> ";
               std::cin >>_ph;
               ab.phone = _ph;
               ab.phone = CheckingPhone(ab.phone);
               while (m.find(ab.phone) != m.end()) {
                   std::cout << "This phone already exists,\nenter another -> ";
                   std::cin >> ab.phone;
                   ab.phone = CheckingPhone(ab.phone);
               }
               std::cout << "Enter Last Name (for example: Ivanov) -> ";
               std::cin >> ab.name;
               ab.name = CheckingLineEntry(ab.name);
               m.insert(std::make_pair(ab.phone, ab.name));
               mm.insert(std::make_pair(ab.name, ab.phone));
           }
           std::cout << "~~~~~~~~~~\nDirectory\n~~~~~~~~~~\n";
           for (auto & it : m) {
               std::cout << it.first << "-> " << it.second << std::endl;
           }
       }
    //        static void LastName_Phone()//(const std::map<std::string, std::string > &m)
    //        {
    //      //  std::string name;
    //        std::cout << "Enter Last Name -> ";
    //        std::cin >> A.name;
    //        A.name = CheckingLineEntry(A.name);
    //        auto it =mm.find(A.name);
    //        if (it != mm.end()) {
    //            size_t number_keys = mm.count(A.name);
    //            for (size_t c = 0; c < number_keys; ++c) {
    //                std::cout << it->first << " " << it->second << std::endl;
    //                ++it;
    //            }
    //        } else {
    //            std::cout << "The Last Name is not in the Telephone Directory" << std::endl;
    //        }
    //        std::cout << std::endl;
    //    }
    static void Phone_LastName(AddressBook ab, std::map<std::string, std::string>& m, std::multimap<std::string, std::string> mm)//(const std::map<std::string, std::string> &m)
    {
        std::string _ph, _ln;
        std::cout << "Ente Phone -> ";
        std::cin >> _ph;
       // AddressBook ab;
        ab.phone =  _ph;
        ab.phone = CheckingPhone(ab.phone);
        if (m.find(ab.phone) != m.end()) {
            std::cout << m.find(ab.phone)->first << " " << m.find(ab.phone)->second
                << std::endl;
        }
        else {
            std::cout << "The Phone is not in the Telephone Directory" << std::endl;
        }
    }
   static void menu()
    {
        std::string menu{};
        std::cout << "+----------------------------------------------------------------------+\n"
            << "| (add) - Adds a new phone number and contact name to the address book |\n"
            << "| (call) - Enter the name of the contact or the phone number to call.  |\n"
            << "| (sms) - Enter your phone number (or contact name) to send a message. |\n"
            << "| (exit)  - Exit the program                                           |\n"
            << "+----------------------------------------------------------------------+"
            << std::endl;
        AddressBook ab;
        std::map<std::string, std::string> m;
        std::multimap<std::string, std::string> mm;
        while (true) {
            std::cout << "     Enter the command !!!\n";
            std::cout << "     ~~~~~~~~~~~~~~~~~~~~~\n";
            std::cin >> menu;
            if (CheckingLineEntry(menu) == "add") {
                InputDirectory(ab, m, mm);
            }
            if (Phone::CheckingLineEntry(menu) == "call") {
                //   Phone::LastName_Phone();//(Phone::AddressBook::m);
            }
            if (CheckingLineEntry(menu) == "sms") {
                Phone_LastName( ab, m, mm);
            }
            if (CheckingLineEntry(menu) == "exit") {
                std::cout << "     +-----+\n";
                std::cout << "     | END |\n";
                std::cout << "     +-----+\n";
                return ;
            }
        }
}
};

int main() {
    PRINT_TASK(STR);
    
    Phone mP;
    mP.menu();
}