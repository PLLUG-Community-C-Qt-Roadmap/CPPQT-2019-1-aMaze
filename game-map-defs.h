#ifndef GAME_MAP_DEFS_H
#define GAME_MAP_DEFS_H

#include <array>

const int cMazeColumns = 20;
const int cMazeRows = 20;

const char cEmptySymbol = ' ';
const char cWallSymbol = 'X';
const char cCharacterSymbol = '@';
const char cExitSymbol = '#';
const char cKeySymbol = '&';
const char cScore1Symbol = '1';
const char cScore2Symbol = '2';
const char cScore3Symbol = '3';

using Map = std::array<std::array<char, cMazeColumns>, cMazeRows>;

#endif //GAME_MAP_DEFS_H
