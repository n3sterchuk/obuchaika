#pragma once
namespace NSemyon {
    struct MenuItem {
        const char* const title;
        void (*func)();
    };
}