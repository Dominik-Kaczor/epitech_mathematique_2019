/*
** EPITECH PROJECT, 2020
** Laws
** File description:
** Laws
*/

#ifndef NEUTRINOS_HPP_
#define NEUTRINOS_HPP_

typedef struct infos_s {
    double n;
    double a;
    double h;
    double sd;
} infos_t;

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>
#include <cstring>

static const std::string HELP = "USAGE\n\t./206neutrinos n a h sd\n\nDESCRIPTION\n\tn\tnumber of values\n\ta\tarithmetic mean\n\th\tharmonic mean\n\tsd\tstandard deviation\n";
void run(char **av);
void loop(infos_t *infos_s, double value);

#endif /* !NEUTRINOS_HPP_ */