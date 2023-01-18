#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CPractice.h"

namespace game_framework {
	CPractice::CPractice() {
		x = y = 0;
	}
	void CPractice::OnMove() {
		if (y <= SIZE_Y) {
			x += 3;
			y += 3;
		}
		else {
			x = y = 0;
		}
	}
	void CPractice::LoadBitmap() {
		pic.LoadBitmap(IDB_PRACTICE);
	}
	void CPractice::OnShow() {
		pic.SetTopLeft(x, y);
		pic.ShowBitmap();
	}
}