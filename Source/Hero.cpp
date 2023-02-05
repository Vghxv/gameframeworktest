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
		_x = -59 + 64 * 7;
		_y = -33 + 64 * 4;
		_walkiter = true;
		_direction = down;
		_state = still;
		_bstate = s1;
		/*_MovingUp = _MovingDown = _MovingLeft = _MovingRight = false;
		_TurningUp = _TurningDown = _TurningLeft = _TurningRight = false;*/
		_blocked = false;
		TimerReset();
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
			if (TimerGetCount() < 16) {
				_bstate = s1;
			}
			else {
				_bstate = s2;
			}
			if (TimerGetCount() == 32) {
				TimerReset();
				_walkiter = !_walkiter;
				_state = still;
				//_MovingUp = _MovingDown = _MovingLeft = _MovingRight = false;
			}
		}
		//else if 
		else if (_state>4 &&_state<9 ) {
			if (TimerGetCount() < 4) {
				_bstate = s1;
			}
			else {
				_bstate = s2;
			}
			if (TimerGetCount() == 8) {
				TimerReset();
				if (_state==turningup )
					_direction = up;
				else if (_state == turningdown)
					_direction = down;
				else if (_state == turningleft)
					_direction = left;
				else if (_state == turningright)
					_direction = right;
				_state = still;
				//_TurningUp = _TurningDown = _TurningLeft = _TurningRight = false;
			}
		}
		else if(_state>0&&_state<5){
			if (TimerGetCount() < 8) {
				_bstate = s1;
			}
			else {
				_bstate = s2;
			}
			if (TimerGetCount() == 16) {
				TimerReset();
				_walkiter = !_walkiter;
				_state = still;
				//_MovingUp = _MovingDown = _MovingLeft = _MovingRight = false;
			}
			else if (_state==movingup) {
					_y -= step;
			}
			else if (_state==movingdown) {
					_y += step; 
			}
			else if (_state==movingleft) {
					_x -= step;
			}
			else if (_state==movingright) {
					_x += step;
			}
		}
		if(_state!=0)
			TimerUpdate();

	}
	void Hero::OnShow() {
		_animation.SetTopLeft(_x, _y);
		switch (_state) {
		case movingup:
			if (_bstate == s1) {
				_walkiter ? _animation.SelectShowBitmap(HERO_UP_WALK_1) : _animation.SelectShowBitmap(HERO_UP_WALK_2);
			}
			else {
				_animation.SelectShowBitmap(HERO_UP);
			}
			break;


		case movingdown:
			if (_bstate == s1) {
				_walkiter ? _animation.SelectShowBitmap(HERO_DOWN_WALK_1) : _animation.SelectShowBitmap(HERO_DOWN_WALK_2);
			}
			else {
				_animation.SelectShowBitmap(HERO_DOWN);
			}
			break;
		
		case movingleft: 
			if (_bstate == s1) {
				_walkiter ? _animation.SelectShowBitmap(HERO_LEFT_WALK_1) : _animation.SelectShowBitmap(HERO_LEFT_WALK_2);
			}
			else {
				_animation.SelectShowBitmap(HERO_LEFT);
			}
			break;
		
		case movingright:
			if (_bstate == s1) {
				_walkiter ? _animation.SelectShowBitmap(HERO_RIGHT_WALK_1) : _animation.SelectShowBitmap(HERO_RIGHT_WALK_2);
			}
			else {
				_animation.SelectShowBitmap(HERO_RIGHT);
			}
			break;
		case turningup:
			if (_bstate == s1) {
				_animation.SelectShowBitmap(HERO_UP_WALK_1);
			}
			else {
				_animation.SelectShowBitmap(HERO_UP);
			}
			break;
		case turningdown:
			if (_bstate == s1) {
				_animation.SelectShowBitmap(HERO_DOWN_WALK_1);
			}
			else {
				_animation.SelectShowBitmap(HERO_DOWN);
			}
			break;
		case turningleft:
			if (_bstate == s1) {
				_animation.SelectShowBitmap(HERO_LEFT_WALK_1);
			}
			else {
				_animation.SelectShowBitmap(HERO_LEFT);
			}
			break;
		case turningright:
			if (_bstate == s1) {
				_animation.SelectShowBitmap(HERO_RIGHT_WALK_1);
			}
			else {
				_animation.SelectShowBitmap(HERO_RIGHT);
			}
			break;
		default:
			__asm {nop}
		}
		_animation.ShowBitmap();
	}
	
	void Hero::PressKeyDown(bool flag){
		_state = (_direction == down)?movingdown:turningdown;
	}
	void Hero::PressKeyUp(bool flag){
		_state=(_direction == up)?	movingup:turningup;
	}
	void Hero::PressKeyLeft(bool flag){
		_state=(_direction == left) ?movingleft:turningleft;
	}
	void Hero::PressKeyRight(bool flag){
		_state=(_direction == right)?movingright:turningright;
	}
	void Hero::PressKeyF(bool flag) {
		switch (_direction) {
			case up:
				_state = fishingup;
				break;
			case down:
				_state=fishingdown;
				break;
			case left:
				_state=fishingleft;
				break;
			case right:
				_state=fishingright;
				break;
			default:
				__asm {nop};
		}
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
	void Hero::TimerReset() {
		_counter = 0;
	}
	void Hero::TimerUpdate() {
		_counter++;
	}
	int Hero::TimerGetCount() {
		return _counter;
	}
	void Hero::SelectShowBitmap(int index) {
		_animation.SelectShowBitmap(index);
	}
	void Hero::SetDirection(Direction direction) {
		_direction = direction;
	}
	void Hero::SetState(MovingState state) {
		_state = state;
	}
	int Hero::getMovingState() {
		return _state;
	}
	/*bool Hero::IsMoving() {
		return _MovingLeft || _MovingRight || _MovingUp || _MovingDown||_TurningLeft || _TurningRight || _TurningUp || _TurningDown;
	}*/
}