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
		_isMovingUp = _isMovingDown = _isMovingLeft = _isMovingRight = false;
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
		const int STEP_X = 70;
		const int STEP_Y = 55;
		if (_isMovingLeft)
			_x -= STEP_X;
		if (_isMovingRight)
			_x += STEP_X;
		if (_isMovingUp)
			_y -= STEP_Y;
		if (_isMovingDown)
			_y += STEP_Y;
	}
	void Hero::OnShow() {
		_animation.SetTopLeft(_x, _y);
		if (_isMovingLeft) {
			_animation.SelectShowBitmap(2);
		}
		if (_isMovingRight) {
			_animation.SelectShowBitmap(9);
		}
		if (_isMovingUp) {
			_animation.SelectShowBitmap(1);
		}
		if (_isMovingDown) {
			_animation.SelectShowBitmap(0);
		}
		
		_animation.ShowBitmap();
	}
	void Hero::SetMovingDown(bool flag)
	{
		_isMovingDown = flag;
	}

	void Hero::SetMovingLeft(bool flag)
	{
		_isMovingLeft = flag;
	}

	void Hero::SetMovingRight(bool flag)
	{
		_isMovingRight = flag;
	}

	void Hero::SetMovingUp(bool flag)
	{
		_isMovingUp = flag;
	}
	void Hero::SetXY(int x,int y){
		_x = x;
		_y = y;
	}
	void Hero::LoadBitmap() {
		vector<string> tmp;
		for (int i = 1; i < 13; i++) {
			tmp.push_back("res/hero_" + to_string(i) + ".bmp");
		}
		_animation.LoadBitmapByString(tmp,RGB(255,0,228));
	}

}