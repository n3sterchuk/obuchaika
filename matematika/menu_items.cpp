#include "menu_items.hpp"

#include <cstddef>
#include "menu_functions.hpp"

const Menu::MenuItem Menu::RUBLEV = {
    "1 — Андрей Иванов сын Рублёв", Menu::art_artists_rublev, &Menu::ARTISTS
};

const Menu::MenuItem Menu::POLENOV = {
    "2 — Василий Дмитриевич Поленов", Menu::art_artists_polenov, &Menu::ARTISTS
};

const Menu::MenuItem Menu::AIVAZOVSKY = {
    "3 — Иван Константинович Айвазовский", Menu::art_artists_aivazovsky, &Menu::ARTISTS
};

const Menu::MenuItem Menu::ARTISTS_GO_BACK = {
    "0 — Выйти в предыдущее меню", Menu::art_go_back, &Menu::ARTISTS
};

namespace {
    const Menu::MenuItem* const artists_children[] = {
        &Menu::ARTISTS_GO_BACK,
        &Menu::RUBLEV,
        &Menu::POLENOV,
        &Menu::AIVAZOVSKY
    };
    const int artists_size = sizeof(artists_children) / sizeof(artists_children[0]);
}

const Menu::MenuItem Menu::ARTISTS = {
    "1 — Русские художники", Menu::show_menu, &Menu::ART, artists_children, artists_size
};

const Menu::MenuItem Menu::MUSICIANS = {
    "2 — Русские музыканты", Menu::art_musicians, &Menu::ART
};

const Menu::MenuItem Menu::ART_GO_BACK = {
    "0 — Выйти в главное меню", Menu::art_go_back, &Menu::ART
};

namespace {
    const Menu::MenuItem* const art_children[] = {
        &Menu::ART_GO_BACK,
        &Menu::ARTISTS,
        &Menu::MUSICIANS
    };
    const int art_size = sizeof(art_children) / sizeof(art_children[0]);
}

const Menu::MenuItem Menu::ART = {
    "1 — Искусство России", Menu::show_menu, &Menu::MAIN, art_children, art_size
};

const Menu::MenuItem Menu::EXIT = {
    "0 — Выйти", Menu::exit, &Menu::MAIN
};

namespace {
    const Menu::MenuItem* const main_children[] = {
        &Menu::EXIT,
        &Menu::ART
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const Menu::MenuItem Menu::MAIN = {
    nullptr, Menu::show_menu, nullptr, main_children, main_size
};