#include <iostream>
#include <ncurses.h>
#include "BlocksArena.h"

int stepDelay;

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Program należy uruchomić z jednym parametrem - szybkość spadania bloku." << std::endl;
        exit(1);
    }

    try {
        stepDelay = std::stoi(argv[1]);
    }
    catch (const std::invalid_argument &) {
        std::cout << "Parametr programu musi być liczbą całkowitą." << std::endl;
        exit(2);
    }

    std::cout << "--------------------------------------------------------------------" << std::endl;
    std::cout << "Program:\n\tBlocks Threads" << std::endl;
    std::cout << "Autorzy:\n\tPatryk Zdral & Kamil Cieślik 2018" << std::endl;
    std::cout << "--------------------------------------------------------------------" << std::endl;
    system("read -p 'Naciśnij Enter aby rozpocząć...' var");

    initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));

    int maxHeight = 0, maxWidth = 0;
    getmaxyx(stdscr, maxHeight, maxWidth);
    BlocksArena blocksArena(0, maxWidth, 0, maxHeight, static_cast<__useconds_t>(stepDelay));

    nodelay(stdscr, false);
    getch();
    endwin();
    std::cout << "--------------------------------------------------------------------" << std::endl;
    std::cout << "ZAKOŃCZONO DZIAŁANIE PROGRAMU" << std::endl;
    std::cout << "--------------------------------------------------------------------" << std::endl;
    return 0;
}