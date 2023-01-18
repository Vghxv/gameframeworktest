#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CBouncingBall.h"
#include "CGameMap.h"
namespace game_framework {

	CGameMap::CGameMap():X(20),Y(40),MW(120),MH(100) {
		int map_init[4][5] = {
		{0,0,1,0,0},
		{0,1,2,1,0},
		{1,2,1,2,1},
		{2,1,2,1,2}
		};
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 5; j++) {
				map[i][j] = map_init[i][j];
			}
		}
		random_num = 0;
		bballs = NULL; // when we delete before new a new one, it won't have error
	}
	void CGameMap::LoadBitmap() {
		blue.LoadBitmap(IDB_BLUE);
		green.LoadBitmap(IDB_GREEN);
	}
	void CGameMap::OnShow() {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 4; j++) {
				switch (map[j][i]) {
					case 0:
						break;
					case 1:
						blue.SetTopLeft(X + MW * i, Y + (MH*j));
						blue.ShowBitmap();
						break;
					case 2:
						green.SetTopLeft(X + MW * i, Y + (MH*j));
						green.ShowBitmap();
						break;
					default:
						ASSERT(0);
				}
			}
		}
		for (int i = 0; i < random_num; i++) {
			bballs[i].OnShow();
		}
	}
	void CGameMap::InitializeBouncingBall(int ini_index, int row, int col) {
		const int VELOCITY = 10;
		const int BALL_PIC_HEIGHT = 15;
		int floor = Y + (row + 1)*MH - BALL_PIC_HEIGHT;

		bballs[ini_index].LoadBitmap();
		bballs[ini_index].SetFloor(floor);
		bballs[ini_index].SetVelocity(VELOCITY + col);
		bballs[ini_index].SetXY(X+col*MW + MW / 2,floor);
	}
	void CGameMap::RandomBouncingBall() {
		const int MAX_RAND_NUM = 10;
		random_num = (rand() % MAX_RAND_NUM) + 1;
		delete[] bballs;
		bballs = new CBouncingBall[random_num];
		int ini_index = 0;
		for (int row = 0; row < 5; row++) {
			for (int col = 0; col < 5; col++) {
				if (map[row][col] != 0 && ini_index < random_num) {
					InitializeBouncingBall(ini_index, row, col);
					ini_index++;
				}
			}
		}
	}
	void CGameMap::OnkeyDown(UINT nChar) {
		const int KEY_SPACE = 0x20;
		if (nChar == KEY_SPACE)
			RandomBouncingBall();
	}
	void CGameMap::OnMove() {
		for (int i = 0; i < random_num; i++) {
			bballs[i].OnMove();
		}
	}
	CGameMap::~CGameMap() {
		delete [] bballs;
	}
}

