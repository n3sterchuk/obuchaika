#!/bin/sh
set -eu

SCRIPT_DIR=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
cd "$SCRIPT_DIR"

g++ -std=c++17 -Wall -Wextra -pedantic \
    main.cpp menu_items.cpp menu_functions.cpp \
    -o main

exec ./main
