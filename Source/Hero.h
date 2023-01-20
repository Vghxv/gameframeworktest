namespace game_framework{
	class Hero {
		enum Direction
		{
			up,
			down,
			left,
			right
		};
	public :
		Hero();
		int getX1();
		int getX2();
		int getY1();
		int getY2();
		void OnMove();
		void OnShow();
		void SetMovingUp(bool flag);
		void SetMovingDown(bool flag);
		void SetMovingLeft(bool flag);
		void SetMovingRight(bool flag);
		void SetXY(int, int);
		void LoadBitmap();
	private:
		int _x, _y;
		Direction _direction;
		CMovingBitmap _animation;
		bool _isMovingDown;			// 是否正在往下移動
		bool _isMovingLeft;			// 是否正在往左移動
		bool _isMovingRight;			// 是否正在往右移動
		bool _isMovingUp;			// 是否正在往上移動
	};
}