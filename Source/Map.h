#pragma once
namespace game_framework {

	class Map {
	public:
		Map(int height,int width);

		void LoadLayer1();
		void LoadLayer2();
		void LoadLayer3();
		void ShowLayer1();
		void ShowLayer2();
		void ShowLayer3();
		void UnShowLayer1();
		void UnShowLayer2();
		void UnShowLayer3();

		void SetXY();
	private:
		vector<vector<CMovingBitmap> > _Layer1;
		vector<vector<CMovingBitmap> > _Layer2;
		vector<vector<CMovingBitmap> > _Layer3;
		int _height;
		int _width;

		int _x;
		int _y;

	};
}