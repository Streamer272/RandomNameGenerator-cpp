#include <iostream>
#include <string>
#include <ctime>

std::string samohlasky[6] = { "a", "e", "i", "y", "o", "u" };
std::string spoluhlasky[20] = { "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t",
                                "v", "w", "x", "z" };


int random(int min, int max) {
   return min + rand() % ((max + 1) - min);
}


std::string get_random_name(int length) {
    std::string name;
    bool even = true;

    for (int i = 0; i < length; i++) {
        if (!even) {
            name += samohlasky[random(0, 6)];
        }
        else {
            name += spoluhlasky[random(0, 20)];
        }

        even = !even;
    }

    return name;
}


[[noreturn]] int main() {
    srand(time(nullptr));

    while (true) {
        std::cout << "Press enter";
        std::string useless;
        std::cin >> useless;

        int length;
        std::string name;

        do {
            length = random(5, 10);
            name = get_random_name(length);
        }
        while (name.length() > length);

        std::cout << name << std::endl;
    }
}
