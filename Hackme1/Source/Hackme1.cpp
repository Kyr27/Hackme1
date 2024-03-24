// Hackme1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Todo:
// 0. Make this into a self-contained dll that handles user creation and management, then put it in a folder alongside a console and gui versions that use the .dll.
// 1. Make a console version (this) that uses the dll. Once logged in just print to the console success.
// 2. Make a GUI version that uses the same dll. Once logged in, the gui should show some info about the person youre logged in as, the bio, birth date, hobbies, etc
// 3. Ensure C# Frontend can read C++ Code, by making a C# wrapper for it

#include "Generator.h"
#include "User.h"
#include "smath.h"

#include <string>
#include <iostream>


constexpr int g_MAX_USERS = 128;


int main()
{
    // Randomize the amount of registered users

    int usersRegistered = Generator::GenerateRandomNumber(4, g_MAX_USERS);


    // Create a dynamic array to hold the list of user objects

    std::vector<User> Users{};


    // Create a fake user, push him into Users vector, and repeat til it reaches usersRegistered

    for (int i = 0; i < usersRegistered; i++)
    {
        User user{};
        Users.push_back(user);
    }


    // Do a quick introduction of each user

    for (int i = 0; i < Users.size(); i++)
    {
        Users[i].Introduction();
    }

    std::cout << "Users registered: " << usersRegistered << '\n';


    // Ask the user to enter their login credentials

    std::string username{};
    std::string password{};
    std::cout << "Input your Username: ";
    std::cin >> username;
    std::cout << '\n';
    std::cout << "Your username is: " << username << '\n';
    std::cout << "Enter your password: " << '\n';
    std::cin >> password;
    std::cout << "\n";


    // Iterate the users array, and check if the inputted credentials match any known credentials

    for (User& iteratedUser : Users)
    {
        if (iteratedUser.GetUsername() != username)
        {
            continue;
        }

        std::cout << "Matching username\n";

        if (iteratedUser.GetPassword() == password)
        {
            std::cout << "Successful login: " << iteratedUser.GetUsername() << " | " << iteratedUser.GetPassword() << '\n';
            break;
        }
    }


    getchar();

    return EXIT_SUCCESS;
}