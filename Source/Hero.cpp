#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <bitset>
#include "Hero.h"

namespace game_framework {
	enum Direction {
		up,
		down,
		left,
		right
	};
	Hero::Hero() {
		_x = _y = 0;
		_isMovingUp = _isMovingDown = _isMovingLeft = _isMovingRight = false;
		_isMovingUpEnable = _isMovingDownEnable = _isMovingLeftEnable = _isMovingRightEnable = false;
		
		_moveX = _moveY = 0;
		_velocity = 0;

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
	void Hero::OnMove(int deltaX,int deltaY) {
		if (_isMovingLeftEnable)
			_x -= deltaX;
		if (_isMovingRightEnable)
			_x += deltaX;
		if (_isMovingUpEnable)
			_y -= deltaY;
		if (_isMovingDownEnable)
			_y += deltaY;
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
		if (_isMovingDownEnable) {
			_animation.SetAnimation(200, false);
		}
		else {
			_animation.SetAnimation(200,true);
		}
		_animation.ShowBitmap(2);
	}
	void Hero::SetMovingDown(bool flag){_isMovingDown = flag;}
	void Hero::SetMovingLeft(bool flag){_isMovingLeft = flag;}
	void Hero::SetMovingRight(bool flag){_isMovingRight = flag;}
	void Hero::SetMovingUp(bool flag){_isMovingUp = flag;}
	void Hero::SetMovingDownEnable(bool flag){_isMovingDownEnable = flag;}
	void Hero::SetMovingLeftEnable(bool flag){_isMovingLeftEnable = flag;}
	void Hero::SetMovingRightEnable(bool flag){_isMovingRightEnable = flag;}
	void Hero::SetMovingUpEnable(bool flag){_isMovingUpEnable = flag;}
	void Hero::SetXY(int x,int y){
		_x = x;
		_y = y;
	}
	void Hero::LoadBitmap() {
		//vector<string> tmp;
		//for (int i = 1; i < 13; i++) {
		//	tmp.push_back("res/hero_" + to_string(i) + ".bmp");
		//}
		//_animation.LoadBitmapByString(tmp,RGB(255,0,228));
		_animation.LoadBitmap({"res/hero_4.bmp","res/hero_1.bmp" }, RGB(255, 0, 228));
	}
	
	int Hero::getDirection() {
		return _direction;
	}
	bool Hero::IsAnimationDone(){
		return _animation.IsAnimationDone();
	}
	void Hero::SelectShowBitmap(int index) {
		_animation.SelectShowBitmap(index);
	}
	void Hero::SetDirection(int direction) {
		_direction = direction;
	}
}