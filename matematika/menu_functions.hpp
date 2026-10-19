#pragma once 

#include "menu.hpp"

namespace Menu {
    const MenuItem* show_menu(const MenuItem* current);

    const MenuItem* exit(const MenuItem* current);

    const MenuItem* art_musicians(const MenuItem* current);

    const MenuItem* art_artists_rublev(const MenuItem* current);
    const MenuItem* art_artists_polenov(const MenuItem* current);
    const MenuItem* art_artists_aivazovsky(const MenuItem* current);

    const MenuItem* art_go_back(const MenuItem* current);
}