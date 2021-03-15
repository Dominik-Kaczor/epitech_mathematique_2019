/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "Neutrinos.hpp"

int main(int ac, char **av)
{
    if (ac == 2 && std::strcmp(av[1], "-help")) {
        printf("%s", HELP.c_str());
        return 84;
    } else if (ac == 5) {
        try {
            run(av);
            return 0;
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            return 84;
        }
    } else {
        return 84;
    }
    return 0;
}
