#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"


namespace game_framework{
	Map::Map(vector<vector<string> >filenames,int x,int y)  {
		_filenames = filenames;
		_x = x;
		_y = y;
	}
	void Map::LoadMaps() {

	}
	void Map::ShowLayer1() {

	}
	void Map::ShowLayer2() {

	}
	void Map::SetXY() {

	}



}