#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"

namespace game_framework {

	CGameStateInit::CGameStateInit(CGame *g) : CGameState(g) {
	}

	void CGameStateInit::OnInit() {
		ShowInitProgress(0, "Start loading");	
		//logo.LoadBitmap(IDB_BACKGROUND);
		Sleep(300);
		// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
	}
	void CGameStateInit::OnBeginState() {
	}
	void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_ESC = 27;
		const char KEY_SPACE = ' ';
		if (nChar == KEY_SPACE)
			GotoGameState(GAME_STATE_RUN);						// 切換至GAME_STATE_RUN
		else if (nChar == KEY_ESC)								// Demo 關閉遊戲的方法
			PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// 關閉遊戲
	}
	void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
	{
		GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
	}
	void CGameStateInit::OnShow()
	{
		//logo.SetTopLeft((SIZE_X - logo.Width()) / 2, SIZE_Y / 8);
		//logo.ShowBitmap();
		// Demo螢幕字型的使用，不過開發時請盡量避免直接使用字型，改用CMovingBitmap比較好
		CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
		CFont f, *fp;
		f.CreatePointFont(160, "Times New Roman");	// 產生 font f; 160表示16 point的字
		fp = pDC->SelectObject(&f);					// 選用 font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 0));
		pDC->TextOut(120, 220, "Please click mouse or press SPACE to begin.");
		pDC->TextOut(5, 395, "Press Ctrl-F to switch in between window mode and full screen mode.");
		if (ENABLE_GAME_PAUSE)
			pDC->TextOut(5, 425, "Press Ctrl-Q to pause the Game.");
		pDC->TextOut(5, 455, "Press Alt-F4 or ESC to Quit.");
		pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
		CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
	}
	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
	/////////////////////////////////////////////////////////////////////////////
	CGameStateRun::CGameStateRun(CGame *g) : CGameState(g){}
	CGameStateRun::~CGameStateRun() {}
	void CGameStateRun::OnBeginState() {
		CAudio::Instance()->Play(AUDIO_LAKE, true);			// 撥放 WAVE
		CAudio::Instance()->Play(AUDIO_DING, false);		// 撥放 WAVE
		CAudio::Instance()->Play(AUDIO_NTUT, true);			// 撥放 MIDI
	}

	void CGameStateRun::OnMove(){
		// 如果希望修改cursor的樣式，則將下面程式的commment取消即可
		// SetCursor(AfxGetApp()->LoadCursor(IDC_GAMECURSOR))
		//CAudio::Instance()->Stop(AUDIO_LAKE);	// 停止 WAVE
		//CAudio::Instance()->Stop(AUDIO_NTUT);	// 停止 MIDI
		//GotoGameState(GAME_STATE_OVER);
		mycharacter.OnMove();
	}
	void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
	{
	
		ShowInitProgress(33, "hi");	// 接個前一個狀態的進度，此處進度視為33%
		ShowInitProgress(50, "mid");
		Sleep(300); // 放慢，以便看清楚進度，實際遊戲請刪除此
		corner.LoadBitmap(IDB_CORNER);
		transblack.LoadBitmap("RES/transblack.bmp");
		mycharacter.LoadBitmap();
		tt.LoadBitmap("res/Pokemon_Center_map.bmp");
		tt.SetTopLeft(0, 32);
		CAudio::Instance()->Load(AUDIO_DING, "sounds\\ding.wav");	// 載入編號0的聲音ding.wav
		CAudio::Instance()->Load(AUDIO_LAKE, "sounds\\lake.mp3");	// 載入編號1的聲音lake.mp3
		CAudio::Instance()->Load(AUDIO_NTUT, "sounds\\ntut.mid");	// 載入編號2的聲音ntut.mid
		// 此OnInit動作會接到CGameStaterOver::OnInit()，所以進度還沒到100%

	}

	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; // keyboard左箭頭
		const char KEY_UP = 0x26; // keyboard上箭頭
		const char KEY_RIGHT = 0x27; // keyboard右箭頭
		const char KEY_DOWN = 0x28; // keyboard下箭頭
		const char KEY_R = 0x52;
		const char KEY_A = 0x41;
		if(!mycharacter.IsMoving()){
			if (nChar == KEY_LEFT) {
				mycharacter.PressKeyLeft(true);
			}				
			if (nChar == KEY_RIGHT) {
				mycharacter.PressKeyRight(true);
			}
			if (nChar == KEY_UP) {
				mycharacter.PressKeyUp(true);
			}
			if (nChar == KEY_DOWN) {
				mycharacter.PressKeyDown(true);			
			}
		}
		if (nChar == KEY_R) {
			GotoGameState(GAME_STATE_OVER);
		}
	}
	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags){
		const char KEY_LEFT = 0x25; // keyboard左箭頭
		const char KEY_UP = 0x26; // keyboard上箭頭
		const char KEY_RIGHT = 0x27; // keyboard右箭頭
		const char KEY_DOWN = 0x28; // keyboard下箭頭
		const char KEY_A = 0x41; // keyboard下箭頭
	}
	void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point) {}
	void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point){}
	void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point) {}
	void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point) {}
	void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point) {}
	void CGameStateRun::OnShow()
	{
		//  注意：Show裡面千萬不要移動任何物件的座標，移動座標的工作應由Move做才對，
		//        否則當視窗重新繪圖時(OnDraw)，物件就會移動，看起來會很怪。換個術語
		//        說，Move負責MVC中的Model，Show負責View，而View不應更動Model。
		
		tt.ShowBitmap();
		//transblack.ShowBitmap();
		corner.SetTopLeft(0, 0);
		corner.ShowBitmap();
		corner.SetTopLeft(SIZE_X - corner.Width(), SIZE_Y - corner.Height());
		corner.ShowBitmap();
		mycharacter.OnShow();
	}
	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的結束狀態(Game Over)
	/////////////////////////////////////////////////////////////////////////////
	CGameStateOver::CGameStateOver(CGame *g) : CGameState(g) {
	}
	void CGameStateOver::OnMove()
	{
		counter--;
		if (counter < 0)
			GotoGameState(GAME_STATE_INIT);
	}

	void CGameStateOver::OnBeginState()
	{
		counter = 30 * 5; // 5 seconds

	}

	void CGameStateOver::OnInit()
	{
		ShowInitProgress(66, "almost done");	
		Sleep(300);	
		ShowInitProgress(100, "done");
	}
	void CGameStateOver::OnShow(){
		CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
		CFont f, *fp;
		f.CreatePointFont(300, "Times New Roman");	// 產生 font f; 160表示16 point的字
		fp = pDC->SelectObject(&f);					// 選用 font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 0));
		char str[80];								// Demo 數字對字串的轉換
		sprintf(str, "Game Over ! (%d)", counter / 30);
		pDC->TextOut(240, 210, str);
		pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
		CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
	}

}