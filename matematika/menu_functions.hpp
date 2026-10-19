#pragma once
#include "menu.hpp"

namespace Menu {
    const MenuItem* show_menu(const MenuItem* current);
    const MenuItem* exit_program(const MenuItem* current);
    const MenuItem* go_back(const MenuItem* current);
    const MenuItem* show_artist(const MenuItem* current);
    const MenuItem* show_not_implemented(const MenuItem* current);
}
