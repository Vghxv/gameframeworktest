#pragma once
namespace game_framework {

	class Map {
	enum {
		layer1,
		layer2,
		layer3
	};
	public:
		Map(int height,int width);
		void LoadLayer();
		void ShowLayer(int a);
		void UnShowLayer(int a);
		void SetXY(int x,int y);
	private:
		vector<vector<vector<CMovingBitmap> >> _Layer;
		int _height; //map size 
		int _width;  //map size
		int _x; //map top left coordinate
		int _y; //map top left coordinate 

	};
}