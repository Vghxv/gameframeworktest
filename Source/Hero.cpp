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
	
	Hero::Hero() {
		_x = _y = 0;
		_walkiter = true;
		_direction = down;
		_action_stage=true;
		_MovingUp=_MovingDown=_MovingLeft=_MovingRight=false;
		count = 0;
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
		if (_movecounter == 16) {
			_movecounter = 0;
			_MovingLeft = _MovingRight = _MovingUp = _MovingDown = false;
		}
		if (_MovingLeft) {
			_x -= step;
		}
		else if (_MovingRight) {
			_x += step;
		}
		else if (_MovingUp ) {
			_y -= step;
		}
		else if (_MovingDown) {
			_y += step;
		}
		_movecounter++;
	}
	void Hero::OnShow() {
		_animation.SetTopLeft(_x, _y);
		if (count > 8) {
			_action_stage = false;
			_walkiter = !_walkiter;
		}
		
		count++;
		_animation.ShowBitmap(0.8);
	}
	
	void Hero::PressKeyDown(bool flag){
		if (_direction == down) {
			_MovingDown = flag;
		}
		else {
			_TurningDown = flag;
		}
	}
	void Hero::PressKeyUp(bool flag){
		if (_direction == up) {
			_MovingUp = flag;
		}
		else {
			_TurningUp = flag;
		}
	}
	void Hero::PressKeyLeft(bool flag){
		if (_direction == left) {
			_MovingLeft = flag;
		}
		else {
			_TurningLeft = flag;
		}
	}
	void Hero::PressKeyRight(bool flag){
		if (_direction == right) {
			_MovingRight = flag;
		}
		else {
			_TurningRight = flag;
		}
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
		//_animation.LoadBitmap({"res/hero_1.bmp","res/hero_4.bmp","res/hero_1.bmp","res/hero_7.bmp" }, RGB(255, 0, 228));
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
		return _MovingDown || _MovingUp ;
	}
}