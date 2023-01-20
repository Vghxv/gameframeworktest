namespace game_framework{
	class Hero {
	public :
		Hero();
		int getX1();
		int getX2();
		int getY1();
		int getY2();
		int getDirection();
		void OnMove(int deltaX, int deltaY);
		void OnShow();
		void SetDirection(int direction);
		void SetMovingUp(bool flag);
		void SetMovingDown(bool flag);
		void SetMovingLeft(bool flag);
		void SetMovingRight(bool flag);
		void SetMovingUpEnable(bool flag);
		void SetMovingDownEnable(bool flag);
		void SetMovingLeftEnable(bool flag);
		void SetMovingRightEnable(bool flag);
		void SetXY(int, int);
		bool IsAnimationDone();
		void SelectShowBitmap(int index);
		void LoadBitmap();

	protected:
		int _x, _y;
		int _direction;
		CMovingBitmap _animation;
		bool _isMovingUp;			
		bool _isMovingDown;			
		bool _isMovingLeft;			
		bool _isMovingRight;		
		bool _isMovingUpEnable;
		bool _isMovingDownEnable;
		bool _isMovingLeftEnable;
		bool _isMovingRightEnable;

	private:
		int _velocity;
		int _moveX;
		int _moveY;

	};
}