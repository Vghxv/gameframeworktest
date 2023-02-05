namespace game_framework{
	class Hero {
	public :
	enum Direction {
		up,
		down,
		left,
		right
	};
	enum BitmapState { //to specify animation
		s1,
		s2,
		s3,
		s4
	};
	enum MovingState {
		still,
		movingup,
		movingdown,
		movingleft,
		movingright,
		turningup,
		turningdown,
		turningleft,
		turningright,
		fishingup,
		fishingdown,
		fishingleft,
		fishingright
	};
		Hero();
		int getX1();
		int getX2();
		int getY1();
		int getY2();
		int getDirection();
		int getMovingState();
		void OnMove();
		void OnShow();
		void SetDirection(Direction direction);
		void PressKeyUp(bool flag);
		void PressKeyDown(bool flag);
		void PressKeyLeft(bool flag);
		void PressKeyRight(bool flag);
		void PressKeyF(bool flag);
		void SetXY(int, int);
		//bool IsMoving();
		void SelectShowBitmap(int index);
		void LoadBitmap();
		void SetState(MovingState state);
	protected:
		void TimerReset();
		void TimerUpdate();
		int TimerGetCount();
	private:
		CMovingBitmap _animation;
		Direction _direction;
		/*bool _MovingUp;
		bool _TurningUp;
		bool _MovingDown;
		bool _TurningDown;
		bool _MovingLeft;
		bool _TurningLeft;
		bool _MovingRight;
		bool _TurningRight;
		bool _FishingUp;
		bool _FishingDown;
		bool _FishingLeft;
		bool _FishingRight;*/
		MovingState _state;
		BitmapState _bstate;
		int _x, _y;
		bool _walkiter;
		int _counter;
		const int step = 4;
		bool _blocked;
		bool flag;
	};
}