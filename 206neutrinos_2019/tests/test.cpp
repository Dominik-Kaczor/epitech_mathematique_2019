/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "Neutrinos.hpp"

int main_test(int ac, char **av)
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

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
    cr_redirect_stdin();
}

Test(Generic, Subject, .init = redirect_all_std)
{
    int ac = 5;
    char *av[] = {(char *)"a.out", (char *)"12000", (char *)"297514", (char *)"297912", (char *)"4363", NULL};
    FILE *solved = fopen("tests/files/subject", "r");

    fflush(stdout);
    fprintf(cr_get_redirected_stdin(), "%s", "299042\nEND\n");
    main_test(ac, av);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}

Test(Generic, Stof, .init = redirect_all_std)
{
    int ac = 5;
    char *av[] = {(char *)"a.out", (char *)"12000", (char *)"297514", (char *)"297912", (char *)"4363", NULL};
    FILE *solved = fopen("tests/files/stof", "r");

    fflush(stdout);
    fprintf(cr_get_redirected_stdin(), "%s", "zazaaz\n");
    main_test(ac, av);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}