#include "menu_items.hpp"

#include <cstddef>
#include "menu_functions.hpp"

const Menu::MenuItem Menu::STUDY_SUMM = {
    "1 - Хочу научиться складывать", Menu::study_summ, &Menu::STUDY
};

const Menu::MenuItem Menu::STUDY_SUBSTRACT = {
    "2 - Хочу научиться вычитать", Menu::study_substract, &Menu::STUDY
};

const Menu::MenuItem Menu::STUDY_MULTIPLY = {
    "3 - Хочу научиться умножать", Menu::study_multiply, &Menu::STUDY
};

const Menu::MenuItem Menu::STUDY_DIVIDE = {
    "4 - Хочу научиться делить", Menu::study_divide, &Menu::STUDY
};

const Menu::MenuItem Menu::STUDY_GO_BACK = {
    "0 - Выйти в главное меню", Menu::study_go_back, &Menu::STUDY
};

namespace {
    const Menu::MenuItem* const study_children[] = {
        &Menu::STUDY_GO_BACK,
        &Menu::STUDY_SUMM,
        &Menu::STUDY_SUBSTRACT,
        &Menu::STUDY_MULTIPLY,
        &Menu::STUDY_DIVIDE
    };
    const int study_size = sizeof(study_children) / sizeof(study_children[0]);
}

const Menu::MenuItem Menu::STUDY = {
    "1 - Хочу учиться математике", Menu::show_menu, &Menu::MAIN, study_children, study_size
};

const Menu::MenuItem Menu::EXIT = {
    "0 - Я лучше пойду полежу", Menu::exit, &Menu::MAIN
};

namespace {
    const Menu::MenuItem* const main_children[] = {
        &Menu::EXIT,
        &Menu::STUDY
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const Menu::MenuItem Menu::MAIN = {
    nullptr, Menu::show_menu, nullptr, main_children, main_size
};