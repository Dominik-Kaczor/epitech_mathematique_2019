/*
** EPITECH PROJECT, 2019
** 206neutrinos_2019
** File description:
** neutrinos.cpp
*/

#include "Neutrinos.hpp"

void loop(infos_t *infos, double value)
{
    double total = infos->n * infos->a;
    double tmp = (std::pow(infos->sd, 2) + std::pow(infos->a, 2)) * infos->n;
    double mean_square = 0.0;

    infos->n += 1;
    infos->a = (total + value) / infos->n;
    infos->sd = std::sqrt(((tmp + pow(value, 2)) / infos->n) - pow(infos->a, 2));
    mean_square = std::sqrt((tmp + std::pow(value, 2)) / infos->n);
    infos->h = infos->n / ((1 / value) + ((infos->n - 1) / infos->h));
    printf("\tNumber of values:\t%d\n", (int)infos->n);
    printf("\tStandard deviation:\t%.2f\n", infos->sd);
    printf("\tArithmetic mean:\t%.2f\n", infos->a);
    printf("\tRoot mean square:\t%.2f\n", mean_square);
    printf("\tHarmonic mean:\t\t%.2f\n\n", infos->h);
}

void run(char **av)
{
    infos_t infos;
    std::string str;
    double val = 0;

    infos.n = std::stof(av[1]);
    infos.a = std::stof(av[2]);
    infos.h = std::stof(av[3]);
    infos.sd = std::stof(av[4]);
    if (infos.n <= 0 || infos.a <= 0 || infos.h <= 0 || infos.sd <= 0)
        throw std::runtime_error("Pls give positives arguments");
    printf("Enter next value: ");
    while (std::getline(std::cin, str)) {
        if (!str.compare(std::string("END")) || !str.compare(std::string("")))
            break;
        if ((val = std::stof(str)) < 0)
            throw std::runtime_error("Value need to be 0 or more");
        loop(&infos, val);
        printf("Enter next value: ");
    }
}