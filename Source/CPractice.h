#pragma once
namespace game_framework {
	class CPractice {
	public :
		CPractice();
		void LoadBitmap();
		void OnMove();
		void OnShow();
	private:
		CMovingBitmap pic;
		int x, y;
	};
}