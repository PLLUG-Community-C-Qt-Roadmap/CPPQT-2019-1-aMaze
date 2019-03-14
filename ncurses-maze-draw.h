#ifndef NCURSES_MAZE_DRAW_H
#define NCURSES_MAZE_DRAW_H

bool initScreen();
void shutdownScreen();
int colorForChar(char ch);
void drawChar(int row, int column, int ch);
void refreshScreen();
void clearScreen();
int getScreenKey();
void showMessage(int row, int column, const std::string &message);

#endif // NCURSES_MAZE_DRAW_H
