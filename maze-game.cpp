#include <iostream>
#include <string>
#include <random>
#include <cstdio>
#include "game-map-defs.h"
#include "game-map-utils.h"

// Generates maze
// Parameters:
//       maze - reference to maze field that will be modified
//              (walls added, added character and exit)
void generateMaze(Map &prMaze)
{
    for (int row = 0; row < cMazeRows; row++)
    {
        for (int column = 0; column < cMazeColumns; column++)
        {
            if ((row == 0) || (row == cMazeRows - 1) || (column == 0) || (column == cMazeColumns - 1))
            {
                prMaze[row][column] = cWallSymbol;
            }
            else
            {
                prMaze[row][column] = cEmptySymbol;
            }
        }
    }


    prMaze[1][1] = cCharacterSymbol;
    prMaze[cMazeRows - 2][cMazeColumns - 2] = cExitSymbol;
}

// Moves character according to given command and retuns eaten symbol (if any)
// Parameters:
//      row - character row position
//      column - character column position
//      command - test string with given command ("l" - left, "r" - right, "u" - up, "d" - down)
//      prMaze - reference to maze field; will be modified as a result of command execution
char moveAndGather(int row,
                   int column,
                   int command,
                   Map &prMaze)
{
    char rCharMovedOnto = cEmptySymbol;

    // Take character out from map
    prMaze[row][column] = cEmptySymbol;

    if (command == 'l')
    {
        rCharMovedOnto = prMaze[row][column - 1];

        if (rCharMovedOnto != cWallSymbol)
        {
            column--;
        }
    }

    if (command == 'r')
    {
        rCharMovedOnto = prMaze[row][column + 1];

        if (rCharMovedOnto != cWallSymbol)
        {
            column++;
        }
    }

    if (command == 'u')
    {
        rCharMovedOnto = prMaze[row - 1][column];

        if (rCharMovedOnto != cWallSymbol)
        {
            row--;
        }
    }

    if (command == 'd')
    {
        rCharMovedOnto = prMaze[row + 1][column];

        if (rCharMovedOnto != cWallSymbol)
        {
            row++;
        }
    }

    // Place character back with new position
    prMaze[row][column] = cCharacterSymbol;

    return rCharMovedOnto;
}

// Prints message to player.
// Parameters:
//      message - text message to player
void gameMessage(const std::string& message)
{
    std::cout << std::endl << message << std::endl << std::endl;
}

// Moves character and check if exit was found as a result of that move.
// Parameters:
//      prMaze - reference to maze field; will be modified while player moves.
bool moveCharacterAndCheckIfExitFound(Map &prMaze)
{
    bool rExitFound = false;

    int charRow = 1;
    int charColumn = 1;
    if (scanForChar(prMaze, cCharacterSymbol, charRow, charColumn))
    {
	int command = getchar();

        const char charMovedOnto = moveAndGather(charRow, charColumn, command, prMaze);

        if (charMovedOnto == cWallSymbol)
        {
            gameMessage("Cannot move here!");
        }

        if (charMovedOnto == cExitSymbol)
        {
            gameMessage("Exit found!");
            rExitFound = true;
        }
    }
    else
    {
        gameMessage("Error: cannot find char!");
    }

    return rExitFound;
}

// Executes one round of the game
void playMazeGame()
{
    Map maze;
    generateMaze(maze);

    do
    {
        drawMaze(maze);
    }
    while (!moveCharacterAndCheckIfExitFound(maze));
}

int main()
{
    playMazeGame();
}

