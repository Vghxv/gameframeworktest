#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"


namespace game_framework{
	Map::Map(int x,int y)  {
		_x = x;
		_y = y;
	}
	void Map::LoadLayer1( ) {

	}
	void Map::LoadLayer2() {

	}
	void Map::LoadLayer3() {

	}
	void Map::ShowLayer1() {
		for (int i = 0; i < _height; i++) {
			for (int j = 0; j < _width; j++) {

				_Layer1[i][j].ShowBitmap();
			}
		}
	}
	void Map::ShowLayer2() {
		for (int i = 0; i < _height; i++) {
			for (int j = 0; j < _width; j++) {
				_Layer2[i][j].ShowBitmap();
			}
		}
	}
	void Map::ShowLayer3() {
		for (int i = 0; i < _height; i++) {
			for (int j = 0; j < _width; j++) {
				_Layer3[i][j].ShowBitmap();
			}
		}
	}
	void Map::UnShowLayer1(){
		for (int i = 0; i < _height; i++) {
			for (int j = 0; j < _width; j++) {
				_Layer1[i][j].UnshowBitmap();
			}
		}
	}
	void Map::UnShowLayer2(){
		for (int i = 0; i < _height; i++) {
			for (int j = 0; j < _width; j++) {
				_Layer2[i][j].UnshowBitmap();
			}
		}
	}
	void Map::UnShowLayer3(){
		for (int i = 0; i < _height; i++) {
			for (int j = 0; j < _width; j++) {
				_Layer3[i][j].UnshowBitmap();
			}
		}
	}
	void Map::SetXY() {

	}



}