#pragma once
namespace game_framework {

	class Map {
	public:
		Map(int height,int width);

		void LoadLayer();
		void ShowLayer(int a);
	
		void UnShowLayer(int a);

		void SetXY();
	private:
		vector<vector<vector<CMovingBitmap> >> _Layer;
		int _height;
		int _width;

		int _x;
		int _y;

	};
}