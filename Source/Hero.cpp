#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <bitset>
#include "Hero.h"

namespace game_framework {
	Hero::Hero() {
		_x = _y = 0;

	}
	int Hero::getX1() {
		return _x;
	}
	int Hero::getX2() {
		return _x + _animation.Width();
	}
	int Hero::getY1() {
		return _y;
	}
	int Hero::getY2() {
		return _y + _animation.Height();
	}
	void Hero::OnMove() {
		const int STEP_SIZE = 2;
		if (isMovingLeft)
			_x -= STEP_SIZE;
		if (isMovingRight)
			_x += STEP_SIZE;
		if (isMovingUp)
			_y -= STEP_SIZE;
		if (isMovingDown)
			_y += STEP_SIZE;
	}
	void Hero::OnShow() {
		_animation.SetTopLeft(_x, _y);
		_animation.SetAnimation(200,false);
		_animation.ShowBitmap();
	}
	void Hero::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void Hero::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void Hero::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void Hero::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
	}
	void Hero::SetXY(int x,int y){
		_x = x;
		_y = y;
	}
	void Hero::LoadBitmap() {
		vector<string> tmp;
		for (int i = 1; i < 13; i++) {
			tmp.push_back("Bitmaps/hero_" + to_string(i) + ".bmp");
		}
		_animation.LoadBitmapByString(tmp,RGB(255,0,228));
	}

}