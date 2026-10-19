#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

const Menu::MenuItem* Menu::show_menu(const MenuItem* current){
    std::cout << "Обучайка приветсвует тебя, юный ученик" << std::endl;
    for (int i = 1; i < current->children_count; i++){
        std::cout << current->children[i]->title << std::endl;
    }
    std::cout << current->children[0]->title << std::endl;
    std::cout << "Обучайка > ";

    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    return current->children[user_input];

}

const Menu::MenuItem* Menu::exit(const MenuItem* current){
    std::exit(0);
}

const Menu::MenuItem* Menu::study_summ(const MenuItem* current){
    std::cout << current->title << std::endl << std::endl;
    return current;
}

const Menu::MenuItem* Menu::study_substract(const MenuItem* current){
    std::cout << current->title << std::endl << std::endl;
    return current;
}

const Menu::MenuItem* Menu::study_multiply(const MenuItem* current){
    std::cout << current->title << std::endl << std::endl;
    return current;
}

const Menu::MenuItem* Menu::study_divide(const MenuItem* current){
    std::cout << current->title << std::endl << std::endl;
    return current;
}

const Menu::MenuItem* Menu::study_go_back(const MenuItem* current){
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}