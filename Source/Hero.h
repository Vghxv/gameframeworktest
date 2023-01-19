namespace game_framework{
	class Hero {
	public :
		Hero();
		int getX1();
		int getX2();
		int getY1();
		int getY2();
		void OnMove();
		void OnShow();
		void SetXY(int, int);
		void LoadBitmap();
	private:
		int _x, _y;
		CMovingBitmap _animation;
	};
}