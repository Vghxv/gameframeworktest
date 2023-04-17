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
	void Map::LoadLayer( ) {

	}
	void Map::ShowLayer(int a) {
		for (int i = 0; i < _height; i++) {
			for (int j = 0; j < _width; j++) {

				_Layer[a][i][j].ShowBitmap();
			}
		}
	}
	
	void Map::UnShowLayer(int a){
		for (int i = 0; i < _height; i++) {
			for (int j = 0; j < _width; j++) {
				_Layer[a][i][j].UnshowBitmap();
			}
		}
	}
	
	void Map::SetXY(int x, int y) {
		_x = x;
		_y = y;
	}



}