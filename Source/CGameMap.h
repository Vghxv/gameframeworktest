namespace game_framework {

	class CGameMap {
	public :
		CGameMap();
		void LoadBitmap();
		void OnShow();
		void OnMove();
		void OnkeyDown(UINT);
		void RandomBouncingBall();
		void InitializeBouncingBall(int, int, int);
		~CGameMap();
	protected:
		CMovingBitmap blue, green;
		int map[4][5];
		const int X, Y;
		const int MW, MH;
		CBouncingBall* bballs;
		int random_num;
	};

}