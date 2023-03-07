#include <iostream>

#include "note.hpp"
#include "converter.hpp"
#include "helpers.hpp"

int main() {
    BanksInit();

    std::cout << "Ocarina of Time 64 to 3D Drum Note Conversion Helper" << std::endl;

    int bank = 0;

    while (true) {
        std::cout << std::endl << "Enter 3D bank index: " << std::endl;
        std::string input;
        std::cin >> input;
        if (StrIsInt(input)) {
            bank = std::stoi(input);

            bool validBank = IsBankValid(bank);
            if (validBank) {
                break;
            }

            std::cout << "Unsupported bank." << std::endl;
            continue;
        }
        std::cout << "Invalid input." << std::endl;
    }

    while (true) {
        std::cout << std::endl << "Enter N64 note: " << std::endl;
        Note n64_note(std::cin);
        Note n3D_note(GetConverted(bank, n64_note.Int()));

        std::cout << "N64 note " << n64_note.Str() << " (" << n64_note.Int() << ")";
        if (n3D_note.IsInvalid()) {
            std::cout << " does not have a counterpart on 3D." << std::endl;
        } else {
            std::cout << " is " << n3D_note.Str() << " (" << n3D_note.Int() << ") on 3D." << std::endl;
        }
    }
}
