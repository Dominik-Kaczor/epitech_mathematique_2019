/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** sfml
*/

#include "Bonus.hpp"

Bonus::Bonus() 
{
    this->window.create(sf::VideoMode(800,800), "Neutrinos");
    this->font.loadFromFile("font.ttf");

    nb_last = "0";
    sd_last = "0";
    a_last = "0";
    h_last = "0";

    nb_new = "0";
    sd_new = "0";
    a_new = "0";
    h_new = "0";

    count = 0;
    biggest = 10;
    sum = 0.0;
    this->list_n.push_back(0);
    this->list_a.push_back(0);
    this->list_h.push_back(0);
    this->list_sd.push_back(0);
    test = false;
    sw_count = 0;
}

Bonus::~Bonus()
{

}

void Bonus::present()
{
    std::string str = "Present :";
    sf::Text text;

    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(20);
    text.setPosition(30, 730);
    window.draw(text);

    text.setFont(font);
    text.setString(input);
    text.setFillColor(sf::Color::Yellow);
    text.setCharacterSize(20);
    text.setPosition(90, 760);
    window.draw(text);
}

void Bonus::new_info()
{
    std::string str = "New :";
    sf::Text text;

    // New //
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(20);
    text.setPosition(30, 640);
    window.draw(text);

    // nb //
    text.setFont(font);
    text.setString(nb_new);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Yellow);
    text.setPosition(370, 645);
    window.draw(text);

    // deviation //
    text.setFont(font);
    text.setString("deviation:" + sd_new);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(20);
    text.setPosition(90, 670);
    window.draw(text);

    // Arithmetic //
    text.setFont(font);
    text.setString("Arithmetic:" + a_new);
    text.setCharacterSize(20);
    text.setPosition(370, 670);
    window.draw(text);

    // Harmonic //
    text.setFont(font);
    text.setString("Harmonic:" + h_new);
    text.setCharacterSize(20);
    text.setPosition(650, 670);
    window.draw(text);
}

void Bonus::last()
{
    std::string str = "Last :";
    sf::Text text;

    // Last //
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(20);
    text.setPosition(30, 550);
    window.draw(text);

    // nb //
    text.setFont(font);
    text.setString(nb_last);
    text.setFillColor(sf::Color::Yellow);
    text.setCharacterSize(20);
    text.setPosition(370, 555);
    window.draw(text);

    // gdeviation //
    text.setFont(font);
    text.setString("deviation:" + sd_last);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(20);
    text.setPosition(90, 580);
    window.draw(text);

    // Arithmetic //
    text.setFont(font);
    text.setString("Arithmetic:" + a_last);
    text.setCharacterSize(20);
    text.setPosition(370, 580);
    window.draw(text);

    // Harmonic //
    text.setFont(font);
    text.setString("Harmonic:" + h_last);
    text.setCharacterSize(20);
    text.setPosition(650, 580);
    window.draw(text);
}

void Bonus::display_curve(std::vector<int> list, sf::Color color)
{
    for (int i = 0; i < (list.size() - 1); i++) {
        if (list[i] == 0 && list[i + 1] != 0) {
            sf::Vertex line_a[] =
            {
                sf::Vertex(sf::Vector2f(70 + (659 / ((count - first_value) + 1)) * i, 500)),
                sf::Vertex(sf::Vector2f(70 + (659 / ((count - first_value) + 1)) * (i + 1), 500 - 395 * (static_cast<float>(list[i + 1]) / biggest)))
            };
            line_a[0].color = color;
            line_a[1].color = color;
            window.draw(line_a, 2, sf::Lines);
        } else if (list[i] != 0 && list[i + 1] == 0) {
            sf::Vertex line_b[] =
            {
                sf::Vertex(sf::Vector2f(70 + (659 / ((count - first_value) + 1)) * i, 500 - 395 * (static_cast<float>(list[i]) / biggest))),
                sf::Vertex(sf::Vector2f(70 + (659 / ((count - first_value) + 1)) * (i + 1), 500))
            };
            line_b[0].color = color;
            line_b[1].color = color;
            window.draw(line_b, 2, sf::Lines);
        } else if (list[i] == 0 && list[i + 1] == 0) {
                sf::Vertex line_c[] =
            {
                sf::Vertex(sf::Vector2f(70 + (659 / ((count - first_value) + 1)) * i, 500)),
                sf::Vertex(sf::Vector2f(70 + (659 / ((count - first_value) + 1)) * (i + 1), 500))
            };
            line_c[0].color = color;
            line_c[1].color = color;
            window.draw(line_c, 2, sf::Lines);
        } else {
            sf::Vertex line_d[] =
            {
                sf::Vertex(sf::Vector2f(70 + (659 / ((count - first_value) + 1)) * i, 500 - 395 * (static_cast<float>(list[i]) / biggest))),
                sf::Vertex(sf::Vector2f(70 + (659 / ((count - first_value) + 1)) * (i + 1), 500 - 395 * (static_cast<float>(list[i + 1]) / biggest)))
            };
            line_d[0].color = color;
            line_d[1].color = color;
            window.draw(line_d, 2, sf::Lines);
        }
    }
}

void Bonus::graduation_left()
{
    sf::Text text;
    int nbr = 0;

    for (int nb = 0; nb <= 10; nb ++) {
        nbr = (static_cast<float>(biggest) / 10) * nb;
        text.setFont(font);
        text.setString(std::to_string(nbr));
        text.setFillColor(sf::Color(0,255,0));
        text.setCharacterSize(15);
        int x = 65 - (std::to_string(nbr).size()) * 5;
        text.setPosition(x, 490 - 39.5 * nb);
        window.draw(text);
    }
}

void Bonus::graduation_down()
{
    sf::Text text;

    for (int nb = first_value; nb <= count + 1;nb ++) {
        text.setFont(font);
        if (nb + 1 > count + 1)
            text.setString("x");
        else
            text.setString(std::to_string(nb));
        text.setFillColor(sf::Color(0,255,0));
        text.setCharacterSize(10);
        text.setPosition(70 + (659 / ((count - first_value) + 1)) * (nb - first_value), 500);
        window.draw(text);
    }
}

void Bonus::graph()
{
    // BIG rectangle //
    sf::RectangleShape block(sf::Vector2f(660, 400));
    block.setFillColor(sf::Color(0, 102, 255));
    block.setPosition(70, 100);
    this->window.draw(block);

    // little rectangle//
    sf::RectangleShape block_d(sf::Vector2f(654, 394));
    block_d.setFillColor(sf::Color(0, 0, 0));
    block_d.setPosition(73, 103);
    this->window.draw(block_d);

    graduation_down();
    graduation_left();
    display_curve(list_n, sf::Color::Yellow);
    display_curve(list_a, sf::Color::Red);
    display_curve(list_h, sf::Color::Cyan);
    display_curve(list_sd, sf::Color::Magenta);
}

void Bonus::head()
{
    std::string str = "NEUTRINOS";

    sf::Text text;
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(70);
    text.setPosition(280, -7);
    window.draw(text);
}

void Bonus::neutrinos(double value)
{
    double total = _n * _a;
    double tmp = (std::pow(_sd, 2) + std::pow(_a, 2)) * _n;

    _n += 1;
    _a = (total + value) / _n;
    _sd = std::sqrt(((tmp + pow(value, 2)) / _n) - pow(_a, 2));
    _h = _n / ((1 / value) + ((_n - 1) / _h));
}

void Bonus::uptade(std::string str)
{
    if (!str.compare(std::string("STOP")))
        window.close();
    for (int i = 0; i < str.size(); i++) {
        if (isdigit(str[i]) == 0 && str[i] != '.') {
            window.close();
            exit (84);
        }
    }
    infos.push_back(std::stof(str));
    list_n.push_back(std::atoi(str.c_str()));
    if (str.size() != 0 && test)
        file.push_back(std::stof(str) - std::stof(tmp));
    else if(str.size() != 0)
        tmp = "0.00";
    if (biggest < std::atoi(str.c_str()))
        biggest = std::atoi(str.c_str());
    sum += infos[count];
    tmp = str;
    test = true;

    neutrinos(std::atoi(str.c_str()));
    list_a.push_back(_a);
    list_h.push_back(_h);
    list_sd.push_back(_sd);
    nb_last = nb_new;
    sd_last = sd_new;
    a_last = a_new;
    h_last = h_new;
    nb_new = str;
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << _sd;
    sd_new = stream.str();
    std::stringstream stream_a;
    stream_a << std::fixed << std::setprecision(2) << _a;
    a_new = stream_a.str();
    std::stringstream stream_h;
    stream_h << std::fixed << std::setprecision(2) << _h;
    h_new = stream_h.str();
    
    count += 1;
}

void Bonus::loop(double n, double a, double h, double sd)
{
    if (n <= 0 || a <= 0 || h <= 0 || sd <= 0) {
        std::cout << "Pls give positives arguments" << std::endl;
        exit (84);
    }
    first_value = n;
    count = n;
    _n = n;
    _a = a;
    _h = h;
    _sd = sd;
    while(window.isOpen()){
        window.clear(sf::Color::Black);
        head();
        graph();
        last();
        new_info();
        present();
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::TextEntered){
                if (event.text.unicode == 27)
                    window.close();
                else if(event.KeyPressed == sf::Keyboard::BackSpace && input.size()!=0)
                    input.pop_back();
                else if (event.text.unicode == 13) {
                    uptade(input);
                    input = "";
                } else if (event.text.unicode == 8)
                    input = input.substr(0, input.size()-1);
                else if (event.text.unicode < 128)
                    input.push_back((char)event.text.unicode);
            }
        }
        window.display();
    }
}

int main(int ac, char **av)
{
    Bonus *neutrinos = new Bonus();

    if (ac != 5 || (ac == 2 && !std::string("-h").compare(std::string(av[1])))) {
        printf("SYNOPSIS\n\t./groundhog period\n\nDESCRIPTION\n\tperiod\tthe number of days defining a period\n");
        return 84;
    }
    neutrinos->loop(std::stof(av[1]), std::stof(av[2]), std::stof(av[3]), std::stof(av[4]));
    return 0;
}

