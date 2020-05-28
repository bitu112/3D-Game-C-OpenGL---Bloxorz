/*
 * Game.h
 *
 *  Created on: May 19, 2020
 *      Author: gabriel
 */

#ifndef GAME_H_
#define GAME_H_
#include <string>
#include <iostream>

class Game {
public:

	Game();

	void onMove(int key, int x, int y);
	void update();
	void display();
	void start();
	void level1();
	void level2();
	virtual ~Game();

};

#endif /* GAME_H_ */
