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

	}
	void Hero::OnShow() {
		_animation.SetTopLeft(_x, _y);
		_animation.SelectShowBitmap(0);
		_animation.ShowBitmap();
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