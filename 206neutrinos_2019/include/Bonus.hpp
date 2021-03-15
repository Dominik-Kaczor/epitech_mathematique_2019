/*
** EPITECH PROJECT, 2020
** my_sfml
** File description:
** include
*/

#ifndef MY_SFML
#define MY_SFML

#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <algorithm>
#include <exception>
#include <cmath>
#include <iomanip>
#include <SFML/Graphics.hpp>

class Bonus
{
    public:
        Bonus();
        ~Bonus();
        void head();
        void graduation_left();
        void graduation_down();
        void display_curve(std::vector<int>, sf::Color);
        void uptade(std::string);
        void last();
        void graph();
        void new_info();
        void present();
        void loop(double, double, double, double);
        void neutrinos(double);
    private:
        std::string nb_last;
        std::string sd_last;
        std::string a_last;
        std::string h_last;

        std::string nb_new;
        std::string sd_new;
        std::string a_new;
        std::string h_new;

        sf::RenderWindow window;
        sf::Font font;

        int biggest;
        int count;
        int first_value;
        std::vector<float> infos;
        sf::Event event;
        std::string input;
        bool test;
        int sw_count;
        std::string tmp;
        float sum;
        int periode;
        std::vector<int> list_n;
        std::vector<int> list_a;
        std::vector<int> list_h;
        std::vector<int> list_sd;
        std::vector<float> file;

        double _n;
        double _a;
        double _h;
        double _sd;
};

#endif /* !MY_SFML */
