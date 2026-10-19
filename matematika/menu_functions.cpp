#include "menu_functions.hpp"
#include "menu_items.hpp"

#include <cstdlib>
#include <iostream>
#include <limits>

const Menu::MenuItem* Menu::show_menu(
    const Menu::MenuItem* current
) {
    if (current == &Menu::MAIN) {
        std::cout << "Главное меню:\n";
    }
    else if (current == &Menu::ART) {
        std::cout << "Второй уровень меню:\n";
    }
    else if (current == &Menu::RUSSIAN_ARTISTS) {
        std::cout << "Третий уровень: Русские художники\n";
    }

    for (int i = 1; i < current->children_count; i++) {
        std::cout << current->children[i]->title << '\n';
    }

    std::cout << current->children[0]->title << '\n';

    std::cout << "Введите номер пункта: ";

    int user_input;

    if (!(std::cin >> user_input)) {
        std::cin.clear();

        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );

        std::cout << "Ошибка: необходимо ввести число.\n\n";
        return current;
    }

    if (user_input < 0 ||
        user_input >= current->children_count) {
        std::cout << "Такого пункта меню нет.\n\n";
        return current;
    }

    std::cout << '\n';

    return current->children[user_input];
}

const Menu::MenuItem* Menu::exit_program(
    const Menu::MenuItem* current
) {
    std::exit(0);
}

const Menu::MenuItem* Menu::go_back(
    const Menu::MenuItem* current
) {
    std::cout << current->title << "\n\n";

    if (current->parent != nullptr &&
        current->parent->parent != nullptr) {
        return current->parent->parent;
    }

    return &Menu::MAIN;
}

const Menu::MenuItem* Menu::show_artist(
    const Menu::MenuItem* current
) {
    std::cout << "Вы выбрали художника:\n";
    std::cout << current->title << "\n\n";

    return current->parent;
}

const Menu::MenuItem* Menu::show_not_implemented(
    const Menu::MenuItem* current
) {
    std::cout << "Раздел «Русские музыканты» "
              << "пока не заполнен.\n\n";

    return current->parent;
}