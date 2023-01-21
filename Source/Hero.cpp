#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <bitset>
#include "Hero.h"
#define HERO_DOWN 0
#define HERO_UP	1
#define HERO_LEFT 2
#define HERO_DOWN_WALK_1 3
#define HERO_UP_WALK_1 4
#define HERO_LEFT_WALK_1 5
#define HERO_DOWN_WALK_2 6
#define HERO_UP_WALK_2 7
#define HERO_LEFT_WALK_2 8
#define HERO_RIGHT 9
#define HERO_RIGHT_WALK_1 10
#define HERO_RIGHT_WALK_2 11

namespace game_framework {
	void Hero::init() {
		_isMovingUpEnable = _isMovingDownEnable = _isMovingLeftEnable = _isMovingRightEnable = false;

	}
	Hero::Hero() {
		_x = _y = 0;
		_walkiter = true;
		move = 0;
		_direction = down;
		_walkfirst=true;
		_isMovingUp=_isMovingDown=_isMovingLeft=_isMovingRight=false;
		init();
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

		int step = 8;

		if (move == 64) {
			move = 0;
			_isMovingUp = _isMovingDown = _isMovingLeft = _isMovingRight = false;
			_walkiter = !_walkiter;
		}
		if (_isMovingLeft && _direction==left) {
			_x -= step;
			move += step;
		}
		else if (_isMovingRight && _direction==right) {
			_x += step;
			move += step;
		}
		else if (_isMovingUp && _direction==up) {
			_y -= step;
			move += step;
		}
		else if (_isMovingDown && _direction==down) {
			_y += step;
			move+=step;
		}
	}
	void Hero::OnShow() {
	
		_animation.SetTopLeft(_x, _y);
		if (_isMovingDown) {
			if (_direction == down) {
				_walkiter?_animation.SelectShowBitmap(HERO_DOWN_WALK_1): _animation.SelectShowBitmap(HERO_DOWN_WALK_2);
			}
			else {
				_animation.SelectShowBitmap(HERO_DOWN);
				_direction = down;			
			}
		}
		if (_direction == down&& !_isMovingDown) {
			_animation.SelectShowBitmap(HERO_DOWN);
		}
		if (_isMovingUp) {
			if (_direction == up) {
				_walkiter?_animation.SelectShowBitmap(HERO_UP_WALK_1): _animation.SelectShowBitmap(HERO_UP_WALK_2);
			}
			else {
				_animation.SelectShowBitmap(HERO_UP);
				_direction = up;
			}
		}
		if (_direction == up&& !_isMovingUp) {
			_animation.SelectShowBitmap(HERO_UP);
		}
		if (_isMovingLeft) {
			if (_direction == left) {
				_walkiter?_animation.SelectShowBitmap(HERO_LEFT_WALK_1): _animation.SelectShowBitmap(HERO_LEFT_WALK_2);
			}
			else {
				_animation.SelectShowBitmap(HERO_LEFT);
				_direction = left;
			}
		}
		if (_direction == left&& !_isMovingLeft) {
			_animation.SelectShowBitmap(HERO_LEFT);
		}
		if (_isMovingRight) {
			if (_direction == right) {
				_walkiter?_animation.SelectShowBitmap(HERO_RIGHT_WALK_1): _animation.SelectShowBitmap(HERO_RIGHT_WALK_2);
			}
			else {
				_animation.SelectShowBitmap(HERO_RIGHT);
				_direction = right;
			}
		}
		if (_direction == right&& !_isMovingRight) {
			_animation.SelectShowBitmap(HERO_RIGHT);
		}
		if (_isMovingUpEnable&& clock() -last_time>=1) {
			_isMovingUp = true;
			last_time = clock();
		}
		if (_isMovingDownEnable&& clock() -last_time>=1) {
			_isMovingDown = true;
			last_time = clock();
		}
		if (_isMovingLeftEnable&& clock() -last_time>=1) {
			_isMovingLeft = true;
			last_time = clock();
		}
		if (_isMovingRightEnable&& clock() -last_time>=1) {
			_isMovingRight = true;
			last_time = clock();
		}
		_animation.ShowBitmap(0.8);
	}
	void Hero::SetMovingDown(bool flag){_isMovingDown = flag;}
	void Hero::SetMovingLeft(bool flag){_isMovingLeft = flag;}
	void Hero::SetMovingRight(bool flag){_isMovingRight = flag;}
	void Hero::SetMovingUp(bool flag){_isMovingUp = flag;}
	void Hero::SetMovingDownEnable(bool flag){_isMovingDown = flag;}
	void Hero::SetMovingLeftEnable(bool flag){_isMovingLeft = flag;}
	void Hero::SetMovingRightEnable(bool flag){_isMovingRight = flag;}
	void Hero::SetMovingUpEnable(bool flag){_isMovingUp = flag;}
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
		//_animation.LoadBitmap({"res/hero_1.bmp","res/hero_4.bmp","res/hero_1.bmp","res/hero_7.bmp" }, RGB(255, 0, 228));
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
	void Hero::SetDirection(Direction direction) {
		_direction = direction;
	}
}