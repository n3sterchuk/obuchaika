#include "menu_items.hpp"
#include "menu_functions.hpp"

const Menu::MenuItem Menu::ART_BACK_TO_MAIN = {
    "0 — Выйти в главное меню",
    Menu::go_back,
    &Menu::ART
};

const Menu::MenuItem Menu::RUSSIAN_MUSICIANS = {
    "2 — Русские музыканты",
    Menu::show_not_implemented,
    &Menu::ART
};

const Menu::MenuItem Menu::ARTISTS_GO_BACK = {
    "0 — Выйти в предыдущее меню",
    Menu::go_back,
    &Menu::RUSSIAN_ARTISTS
};


const Menu::MenuItem Menu::RUBLEV = {
    "1 — Андрей Иванов сын Рублёв",
    Menu::show_artist,
    &Menu::RUSSIAN_ARTISTS
};

const Menu::MenuItem Menu::POLENOV = {
    "2 — Василий Дмитриевич Поленов",
    Menu::show_artist,
    &Menu::RUSSIAN_ARTISTS
};

const Menu::MenuItem Menu::AIVAZOVSKY = {
    "3 — Иван Константинович Айвазовский",
    Menu::show_artist,
    &Menu::RUSSIAN_ARTISTS
};

namespace {
    const Menu::MenuItem* const artists_children[] = {
        &Menu::ARTISTS_GO_BACK,
        &Menu::RUBLEV,
        &Menu::POLENOV,
        &Menu::AIVAZOVSKY
    };

    const int artists_count =
        sizeof(artists_children) / sizeof(artists_children[0]);
}

const Menu::MenuItem Menu::RUSSIAN_ARTISTS = {
    "1 — Русские художники",
    Menu::show_menu,
    &Menu::ART,
    artists_children,
    artists_count
};

namespace {
    const Menu::MenuItem* const art_children[] = {
        &Menu::ART_BACK_TO_MAIN,
        &Menu::RUSSIAN_ARTISTS,
        &Menu::RUSSIAN_MUSICIANS
    };

    const int art_count =
        sizeof(art_children) / sizeof(art_children[0]);
}

const Menu::MenuItem Menu::ART = {
    "1 — Искусство России",
    Menu::show_menu,
    &Menu::MAIN,
    art_children,
    art_count
};

const Menu::MenuItem Menu::EXIT = {
    "0 — Выйти",
    Menu::exit_program,
    &Menu::MAIN
};

namespace {
    const Menu::MenuItem* const main_children[] = {
        &Menu::EXIT,
        &Menu::ART
    };

    const int main_count =
        sizeof(main_children) / sizeof(main_children[0]);
}

const Menu::MenuItem Menu::MAIN = {
    "Главное меню",
    Menu::show_menu,
    nullptr,
    main_children,
    main_count
};