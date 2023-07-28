// CPP ROT13 Program, Created by Kristopher Pepper in 2023.
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

std::string userInput;
std::string userChoice;
std::string message = {};
char alphabetLetters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

void cipher(const std::string &userChoice)
{
    std::getline(std::cin, userInput);

    for (char &c : userInput)
    {
        c = std::tolower(c);
    }

    std::vector<std::string> lettersVector;

    for (size_t i = 0; i < userInput.length(); ++i)
    {
        lettersVector.push_back(userInput.substr(i, 1));
    }

    for (const std::string &letter : lettersVector)
    {
        bool letterNotFound = true;

        for (int i = 0; i < 26; i++)
        {
            if (letter[0] == alphabetLetters[i])
            {
                message.push_back(alphabetLetters[(i + 13) % 26]);
                letterNotFound = false;
                break;
            }
        }

        if (letterNotFound == true)
        {
            message.push_back(letter[0]);
        }
    }
    std::cout << "Encrypted text: " << message << std::endl;
    message = {};
}

int main()
{
    std::cout << "--- ROT13 ---" << std::endl;

    while (true)
    {
        std::cout << "\nCreate cipher = c | Decrypt cipher = d | Exit = e :";
        std::getline(std::cin, userChoice);

        if (userChoice == "c")
        {
            std::cout << "Enter text to encrypt: ";
            cipher(userChoice);
        }
        else if (userChoice == "d")
        {
            std::cout << "Enter text to decrypt: ";
            cipher(userChoice);
        }
        else if (userChoice == "e")
        {
            std::cout << "Program exited." << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid. Please enter 'c' to create a cipher, 'd' to decrypt a cipher, or 'e' to exit." << std::endl;
        }
        message = {};
    }

    return 0;
}