namespace game_framework{
	class Hero {
	enum Direction {
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
		int getDirection();
		void OnMove();
		void OnShow();
		void SetDirection(Direction direction);
		void PressKeyUp(bool flag);
		void PressKeyDown(bool flag);
		void PressKeyLeft(bool flag);
		void PressKeyRight(bool flag);
		void SetXY(int, int);
		bool IsMoving();
		void SelectShowBitmap(int index);
		void LoadBitmap();
		void test(bool flag);

	protected:
		CMovingBitmap _animation;
		bool _MovingUp;
		bool _TurningUp;
		bool _MovingDown;
		bool _TurningDown;
		bool _MovingLeft;
		bool _TurningLeft;
		bool _MovingRight;
		bool _TurningRight;
		bool _stage;
	private:
		int _x, _y;
		Direction _direction;
		bool _walkiter;
		int _movecounter;
		int _showcounter;
		const int step = 4;
		bool _blocked;
		bool flag;
	};
}