
///////////////////////////////////////////////////////////////////////////
//  Game implementations
///////////////////////////////////////////////////////////////////////////

#include "Game.h"
#include "globals.h"
#include <iostream>
#include "Pit.h"
#include "Player.h"

Game::Game(int rows, int cols, int nSnakes)
{
	if (nSnakes < 0)
	{
		std::cout << "***** Cannot create Game with negative number of snakes!" << std::endl;
		exit(1);
	}
	if (nSnakes > MAXSNAKES)
	{
		std::cout << "***** Cannot create Game with " << nSnakes
			<< " snakes; only " << MAXSNAKES << " are allowed!" << std::endl;
		exit(1);
	}
	if (rows == 1 && cols == 1 && nSnakes > 0)
	{
		std::cout << "***** Cannot create Game with nowhere to place the snakes!" << std::endl;
		exit(1);
	}

	// Create pit
	m_pit = new Pit(rows, cols);

	// Add player
	int rPlayer = 1 + rand() % rows;
	int cPlayer = 1 + rand() % cols;
	m_pit->addPlayer(rPlayer, cPlayer);

	// Populate with snakes
	while (nSnakes > 0)
	{
		int r = 1 + rand() % rows;
		int c = 1 + rand() % cols;
		// Don't put a snake where the player is
		if (r == rPlayer  &&  c == cPlayer)
			continue;
		m_pit->addSnake(r, c);
		nSnakes--;
	}
}

Game::~Game()
{
	delete m_pit;
}

void Game::play()
{
	Player* p = m_pit->player();
	if (p == nullptr)
	{
		m_pit->display("");
		return;
	}
	std::string msg = "";
	while (!m_pit->player()->isDead() && m_pit->snakeCount() > 0)
	{
		m_pit->display(msg);
		msg = "";
		std::cout << std::endl;
		std::cout << "Move (u/d/l/r//h/q): ";
		std::string action;
		std::getline(std::cin, action);
		if (action.size() == 0)
			p->stand();
		else
		{
			switch (action[0])
			{
			default:   // if bad move, nobody moves
				std::cout << '\a' << std::endl;  // beep
				continue;
			case 'q':
				return;
			case 'h':
				m_pit->history().display();
				std::cout << "Press enter to continue." << std::endl;
				std::cin.ignore(10000, '\n');
				break;
			case 'u':
			case 'd':
			case 'l':
			case 'r':
				p->move(decodeDirection(action[0]));
				break;
			}
		}
		m_pit->moveSnakes();
	}
	m_pit->display(msg);
}