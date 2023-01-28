#pragma once
namespace game_framework {

	class Map {
	public:
		Map(vector<vector<string> > filenames,int x,int y);
		void LoadMaps();
		void ShowLayer1();
		void ShowLayer2();
		void SetXY();
	private:
		CMovingBitmap _main_map;
		vector<CMovingBitmap> _animations;
		vector<vector<string>  > _filenames;
		int _x;
		int _y;

	};
}