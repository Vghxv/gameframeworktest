#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <fstream>

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
		// ��OnInit�ʧ@�|����CGameStaterRun::OnInit()�A�ҥH�i���٨S��100%
	}
	void CGameStateInit::OnBeginState() {
	}
	void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_ESC = 27;
		const char KEY_SPACE = ' ';
		if (nChar == KEY_SPACE)
			GotoGameState(GAME_STATE_RUN);						// ������GAME_STATE_RUN
		else if (nChar == KEY_ESC)								// Demo �����C������k
			PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// �����C��
	}
	void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)	{
		GotoGameState(GAME_STATE_RUN);		// ������GAME_STATE_RUN
	}
	void CGameStateInit::OnShow()
	{
		//logo.SetTopLeft((SIZE_X - logo.Width()) / 2, SIZE_Y / 8);
		//logo.ShowBitmap();
		// Demo�ù��r�����ϥΡA���L�}�o�ɽкɶq�קK�����ϥΦr���A���CMovingBitmap����n
		CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
		CFont f, *fp;
		f.CreatePointFont(160, "Times New Roman");	// ���� font f; 160���16 point���r
		fp = pDC->SelectObject(&f);					// ��� font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 0));
		pDC->TextOut(120, 220, "Please click mouse or press SPACE to begin.");
		pDC->TextOut(5, 395, "Press Ctrl-F to switch in between window mode and full screen mode.");
		if (ENABLE_GAME_PAUSE)
			pDC->TextOut(5, 425, "Press Ctrl-Q to pause the Game.");
		pDC->TextOut(5, 455, "Press Alt-F4 or ESC to Quit.");
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	}
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
	/////////////////////////////////////////////////////////////////////////////
	CGameStateRun::CGameStateRun(CGame *g) : CGameState(g){}
	CGameStateRun::~CGameStateRun() {}
	void CGameStateRun::OnBeginState() {
		CAudio::Instance()->Play(AUDIO_LAKE, false);			// ���� WAVE
		CAudio::Instance()->Play(AUDIO_DING, false);		// ���� WAVE
		CAudio::Instance()->Play(AUDIO_NTUT, false);			// ���� MIDI
	}

	void CGameStateRun::OnMove(){
		// �p�G�Ʊ�ק�cursor���˦��A�h�N�U���{����commment�����Y�i
		// SetCursor(AfxGetApp()->LoadCursor(IDC_GAMECURSOR))
		//CAudio::Instance()->Stop(AUDIO_LAKE);	// ���� WAVE
		//CAudio::Instance()->Stop(AUDIO_NTUT);	// ���� MIDI
		//GotoGameState(GAME_STATE_OVER);
		mycharacter.OnMove();
	}
	void CGameStateRun::OnInit()  {
		
		ShowInitProgress(10, "hi22222222222222");	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���33%
		Sleep(300); // ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����
		ShowInitProgress(50, "mid");
		corner.LoadBitmap(IDB_CORNER);
		transblack.LoadBitmap("RES/transblack.bmp");
		mycharacter.LoadBitmap();
		tt.LoadBitmap("res/Pokemon_Center_map.bmp");
		tt.SetTopLeft(0, 32);
		CAudio::Instance()->Load(AUDIO_DING, "sounds\\ding.wav");	// ���J�s��0���n��ding.wav
		CAudio::Instance()->Load(AUDIO_LAKE, "sounds\\lake.mp3");	// ���J�s��1���n��lake.mp3
		CAudio::Instance()->Load(AUDIO_NTUT, "sounds\\ntut.mid");	// ���J�s��2���n��ntut.mid
		// ��OnInit�ʧ@�|����CGameStaterOver::OnInit()�A�ҥH�i���٨S��100%

	}

	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; // keyboard���b�Y
		const char KEY_UP = 0x26; // keyboard�W�b�Y
		const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
		const char KEY_DOWN = 0x28; // keyboard�U�b�Y
		const char KEY_R = 0x52;
		const char KEY_A = 0x41;
		const char KEY_F = 0x09;

		if(mycharacter.getMovingState()==Hero::MovingState::still){
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
			if (nChar == KEY_F) {
				mycharacter.PressKeyF(true);			
			}
		}
		if (nChar == KEY_R) {
			GotoGameState(GAME_STATE_OVER);
		}
	}
	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags){
		const char KEY_LEFT = 0x25; // keyboard���b�Y
		const char KEY_UP = 0x26; // keyboard�W�b�Y
		const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
		const char KEY_DOWN = 0x28; // keyboard�U�b�Y
		const char KEY_A = 0x41; // keyboard�U�b�Y
	}
	void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point) {}
	void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point){}
	void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point) {}
	void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point) {}
	void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point) {}
	void CGameStateRun::OnShow()
	{
		//  �`�N�GShow�̭��d�U���n���ʥ��󪫥󪺮y�СA���ʮy�Ъ��u�@����Move���~��A
		//        �_�h��������sø�Ϯ�(OnDraw)�A����N�|���ʡA�ݰ_�ӷ|�ܩǡC���ӳN�y
		//        ���AMove�t�dMVC����Model�AShow�t�dView�A��View�������Model�C
		
		tt.ShowBitmap();
		//transblack.ShowBitmapAlpha(0.5);
		corner.SetTopLeft(0, 0);
		corner.ShowBitmap();
		corner.SetTopLeft(SIZE_X - corner.Width(), SIZE_Y - corner.Height());
		corner.ShowBitmap();
		mycharacter.OnShow();
	}
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����������A(Game Over)
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
		CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
		CFont f, *fp;
		f.CreatePointFont(300, "Times New Roman");	// ���� font f; 160���16 point���r
		fp = pDC->SelectObject(&f);					// ��� font f
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 0));
		char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
		sprintf(str, "Game Over ! (%d)", counter / 30);
		pDC->TextOut(240, 210, str);
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	}

}