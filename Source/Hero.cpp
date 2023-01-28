#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <bitset>
#include "Hero.h"
#define HERO_DOWN 0
#define HERO_DOWN_WALK_1 1
#define HERO_DOWN_WALK_2 2
#define HERO_DOWN_RUN_1 3
#define HERO_DOWN_RUN_2 4
#define HERO_DOWN_RUN_3 5
#define HERO_UP	6
#define HERO_UP_WALK_1 7
#define HERO_UP_WALK_2 8

#define HERO_LEFT 12
#define HERO_LEFT_WALK_1 13
#define HERO_LEFT_WALK_2 14

#define HERO_RIGHT 18
#define HERO_RIGHT_WALK_1 19
#define HERO_RIGHT_WALK_2 20

namespace game_framework {

	Hero::Hero() {
		_walkiter = true;
		_direction = down;
		_movecounter = 0;
		_stage = true;
		_MovingUp = _MovingDown = _MovingLeft = _MovingRight = false;
		_TurningUp = _TurningDown = _TurningLeft = _TurningRight = false;
		_blocked = false;
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
		if (_blocked) {
			if (_movecounter == 32) {
				_movecounter = 0;
				_walkiter = !_walkiter;
				_MovingUp = _MovingDown = _MovingLeft = _MovingRight = false;
			}
			if (_movecounter < 16) {
				_stage = true;
			}
			else {
				_stage = false;
			}
		}
		else if (_TurningDown || _TurningUp || _TurningLeft || _TurningRight) {
			if (_movecounter == 8) {
				_movecounter = 0;
				if (_TurningUp)
					_direction = up;
				else if (_TurningDown)
					_direction = down;
				else if (_TurningLeft)
					_direction = left;
				else if (_TurningRight)
					_direction = right;
				
				_TurningUp = _TurningDown = _TurningLeft = _TurningRight = false;
			}
			if (_movecounter < 4) {
				_stage = true;
			}
			else {
				_stage = false;
			}
		}
		else if(_MovingUp || _MovingDown ||_MovingLeft || _MovingRight){
			if (_movecounter == 16) {
				_movecounter = 0;
				_walkiter = !_walkiter;
				_MovingUp = _MovingDown = _MovingLeft = _MovingRight = false;
			}
			if (_movecounter < 8) {
				_stage = true;
			}
			else {
				_stage = false;
			}
			if (_MovingLeft) {
					_x -= step;
			}
			else if (_MovingRight) {
					_x += step;
			}
			else if (_MovingUp) {
					_y -= step;
			}
			else if (_MovingDown) {
					_y += step; 
			}
		}
		
		if(_TurningDown || _TurningUp || _TurningLeft || _TurningRight|| _MovingUp || _MovingDown || _MovingLeft || _MovingRight)
			_movecounter++;

	}
	void Hero::OnShow() {
		_animation.SetTopLeft(_x, _y);
		if (_MovingLeft) {
			if (_stage) {
				_walkiter ? _animation.SelectShowBitmap(HERO_LEFT_WALK_1) : _animation.SelectShowBitmap(HERO_LEFT_WALK_2);
			}
			else {
				_animation.SelectShowBitmap(HERO_LEFT);
			}
		}
		else if (_MovingRight) {
			if (_stage) {
				_walkiter ? _animation.SelectShowBitmap(HERO_RIGHT_WALK_1) : _animation.SelectShowBitmap(HERO_RIGHT_WALK_2);
			}
			else {
				_animation.SelectShowBitmap(HERO_RIGHT);
			}
		}
		else if (_MovingUp) {
			if (_stage) {
				_walkiter ? _animation.SelectShowBitmap(HERO_UP_WALK_1) : _animation.SelectShowBitmap(HERO_UP_WALK_2);
			}
			else {
				_animation.SelectShowBitmap(HERO_UP);
			}
		}
		else if (_MovingDown) {
			if (_stage) {
				_walkiter ? _animation.SelectShowBitmap(HERO_DOWN_WALK_1) : _animation.SelectShowBitmap(HERO_DOWN_WALK_2);
			}
			else {
				_animation.SelectShowBitmap(HERO_DOWN);
			}
		}
		if (_TurningLeft) {
			if (_stage) {
				_animation.SelectShowBitmap(HERO_LEFT_WALK_1);
			}
			else {
				_animation.SelectShowBitmap(HERO_LEFT);
			}
		}
		else if (_TurningRight) {
			if (_stage) {
				_animation.SelectShowBitmap(HERO_RIGHT_WALK_1);
			}
			else {
				_animation.SelectShowBitmap(HERO_RIGHT);
			}
		}
		else if (_TurningUp) {
			if (_stage) {
				_animation.SelectShowBitmap(HERO_UP_WALK_1);
			}
			else {
				_animation.SelectShowBitmap(HERO_UP);
			}
		}
		else if (_TurningDown) {
			if (_stage) {
				_animation.SelectShowBitmap(HERO_DOWN_WALK_1);
			}
			else {
				_animation.SelectShowBitmap(HERO_DOWN);
			}
		}
		_animation.ShowBitmap();
	}
	
	void Hero::PressKeyDown(bool flag){
		(_direction == down)?_MovingDown = flag:_TurningDown = flag;
	}
	void Hero::PressKeyUp(bool flag){
		(_direction == up)?	_MovingUp = flag:_TurningUp = flag;
	}
	void Hero::PressKeyLeft(bool flag){
		(_direction == left) ?_MovingLeft = flag:_TurningLeft = flag;
	}
	void Hero::PressKeyRight(bool flag){
		(_direction == right)?_MovingRight = flag:_TurningRight = flag;
	}
	void Hero::test(bool flag) {
		_blocked=flag;
	}
	void Hero::SetXY(int x,int y){
		_x = x;
		_y = y;
	}
	void Hero::LoadBitmap() {
		vector<string> tmp;
		for (int i = 1; i < 37; i++) {
			tmp.push_back("res/hero_blue_170_" + to_string(i) + ".bmp");
		}
		_animation.LoadBitmapByString(tmp,RGB(255,0,228));
	}
	
	int Hero::getDirection() {
		return _direction;
	}
	void Hero::SelectShowBitmap(int index) {
		_animation.SelectShowBitmap(index);
	}
	void Hero::SetDirection(Direction direction) {
		_direction = direction;
	}
	bool Hero::IsMoving() {
		return _MovingLeft || _MovingRight || _MovingUp || _MovingDown ;
	}
}