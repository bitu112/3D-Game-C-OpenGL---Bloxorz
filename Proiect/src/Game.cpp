/*
 * Game.cpp
 *
 *  Created on: May 19, 2020
 *      Author: gabriel
 */

#include "Shape.h"
#include "Player.h"
#include "Plate.h"
#include <stdio.h>
using namespace std;
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

float const unit = 10.0;

#include "Game.h"
Shape *shape;
Player player(0,2,0);
Plate plate1(0,0,0);
Plate plate2(unit,0,0);

Plate finishPlate;
Shape *playerShape;

Plate plates[30];


#define START  0
#define GAME_OVER  -1
#define LEVEL1 1
#define LEVEL2 2
#define LEVEL3 3

int dead = 0;

static int gameStatus = START;



Game::Game() {
	// TODO Auto-generated constructor stub

}

void Game::onMove(int key, int x, int y) {

	if (dead != 1)
		player.onMove(key,x,y);

}

void Game::update(){

}





void Game::level1() {

	glPushMatrix();
	shape = &player;
	//glTranslatef(0, 0, 0);




	shape->spawn();

	int matrice[15][10] = {
			{1,1,1,0,0,0,0,0,0,0},
			{1,1,1,1,1,0,0,0,0,0},
			{1,1,1,1,1,0,0,0,0,0},
			{0,0,1,1,1,0,0,0,0,0},
			{0,0,1,1,1,0,0,0,0,0},
			{0,0,1,1,1,1,0,0,0,0},
			{0,0,0,1,1,1,1,0,0,0},
			{0,0,0,1,1,1,1,0,0,0},
			{0,0,0,1,1,1,1,0,0,0},
			{0,0,0,1,2,1,0,0,0,0},
			{0,0,0,1,1,1,0,0,0,0},
			{0,0,0,0,1,1,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0}
	};


	//shape->setY(20);

	//glTranslatef(0, 0, 0);
	glPopMatrix();
	//shape = &plate2;
	//shape->spawn();

	for (int i = 0; i < 15 ;i++) {
		for (int j = 0;j < 10; j++) {

			if (matrice[i][j] == 1) {

			shape = &plates[i];
			shape->setX(i*10);
			shape->setZ(j*10);
//			glEnable(GL_TEXTURE_2D);
//			LoadTexturePlate();
			shape->spawn();
//			glDisable(GL_TEXTURE_2D);

			}

		}
	}

	shape = &player;

	cout <<"X PLAYER : "<< shape->getX() <<endl;
	cout <<"Z PLAYER : "<< shape->getZ() <<endl;

	if ( shape->getX() == 90 && shape->getZ() == 40) {
		dead = 1;
		cout <<"FINISH"<<endl;
		if (shape->getY() > -18)
			shape->setY(shape->getY() - 0.1) ;
		else {
			dead = 0;
			gameStatus = LEVEL2;
			shape->setX(0);
			shape->setY(0);
			shape->setZ(0);
		}

	}
	//Facut toate cazurile pentru level 1
	if (	(shape->getX() < 0 || shape->getZ()< 0 || shape->getZ()>=100) ||
			(shape->getX()>=90 && shape->getZ() == 60) ||
			(( shape->getX() >= 30 &&  shape->getX() < 130) && (shape->getZ() >= 0 && shape->getZ() <= 10)) ||
			((shape->getX() == 0 )  && (shape->getZ() >= 30 && shape->getZ() <= 90)) ||
			(( shape->getX() >= 10 &&  shape->getX() <= 40) && (shape->getZ() >= 50)) ||
			(( shape->getX() >= 0 &&  shape->getX() <= 120) && (shape->getZ() >= 70)) ||
			(( shape->getX() >= 120)) ||
			(( shape->getX() >= 100)  && (shape->getZ() >= 0 && shape->getZ() <= 30)) ||
			(( shape->getX() >= 60)  && (shape->getZ() >= 0 && shape->getZ() <= 20))
			)


	{
		cout <<"GAME OVER";

//		if (shape->getZ() > -20)
//			shape->setZ(shape->getZ() - 0.1);
		if (shape->getY() > -20.4) {
					dead = 1;
					shape->setY(shape->getY() - 0.1) ;
		}
		else {
			shape = &player;
			gameStatus = GAME_OVER;
			shape->setZ(0);
			shape->setX(0);
			shape->setY(2) ;
			dead = 0;
		}
	}


}

void Game::level2() {

	glPushMatrix();
		shape = &player;
		//glTranslatef(0, 0, 0);
		shape->spawn();

		int matrice[15][10] = {
				{1,0,0,0,0,0,0,0,1,2},
				{1,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,1,1,0,0,0,1},
				{0,0,0,1,1,1,0,0,0,1},
				{0,0,0,1,0,0,0,0,0,1},
				{0,0,0,1,0,0,1,1,1,1},
				{0,0,0,1,0,1,1,0,0,0},
				{0,0,0,1,0,1,1,0,0,0},
				{0,0,0,1,1,1,1,0,0,0},
				{0,0,0,1,1,1,1,0,0,0},
				{0,0,0,0,0,0,0,0,0,0}
		};
		glPopMatrix();

		for (int i = 0; i < 15 ;i++) {
			for (int j = 0;j < 10; j++) {
				if (matrice[i][j] == 1) {
				shape = &plates[i];
				shape->setX(i*10);
				shape->setZ(j*10);
				shape->spawn();
				}

			}
		}

		shape = &player;

		cout <<"X PLAYER : "<< shape->getX() <<endl;
		cout <<"Z PLAYER : "<< shape->getZ() <<endl;

		if ( shape->getX() == 0 && shape->getZ() == 90) {
			dead = 1;

			cout <<"FINISH"<<endl;
			if (shape->getY() > -18)
				shape->setY(shape->getY() - 0.1) ;
			else {
				dead = 0;
							gameStatus = START;
							shape->setX(0);
							shape->setY(0);
							shape->setZ(0);
			}

		}
		//Facut toate cazurile pentru level 1
		if ( (shape->getX() < 0 || shape->getZ()< 0) ||
				(shape->getX() >= 130) ||
				(shape->getX()>=100 && shape->getZ() == 70) ||
				((shape->getX()>=0 && shape->getX() <= 50) && (shape->getZ()>=10 && shape->getZ() <= 70)) ||
				((shape->getX()>=70 ) && (shape->getZ()>=0 && shape->getZ() <= 20)) ||
				((shape->getX()>=70 && shape->getX() <= 110) && (shape->getZ()==40)) ||
				((shape->getX()>=70 && shape->getX() <= 90) && (shape->getZ()==50)) ||
				((shape->getX()>=60 && shape->getX() <= 80) && (shape->getZ() >= 60 && shape->getZ() <= 70)) ||
				(( shape->getX() >= 100) && (shape->getZ() >= 80)) ||
				((shape->getX()>=0 && shape->getX() <= 80) && (shape->getZ() == 80))
				)


		{
			cout <<"GAME OVER";

	//		if (shape->getZ() > -20)
	//			shape->setZ(shape->getZ() - 0.1);
			if (shape->getY() > -20.4) {
						dead = 1;
						shape->setY(shape->getY() - 0.1) ;
			}
			else {
				gameStatus = GAME_OVER;
				shape->setY(2) ;
				dead = 0;
			}
		}
}



void Game::display()
{

	switch (gameStatus)
	{
	case START:
		//this->start();
		break;
	case LEVEL1:
		this->level1();
		break;
	case LEVEL2:
		shape = &player;
		this->level2();
		break;
	case LEVEL3:

		break;
	case GAME_OVER:
		gameStatus = START;
		shape = &player;
		shape->setX(0);
		shape->setZ(0);
		break;
	}

}
void Game::start()
{
	gameStatus = LEVEL1;
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

