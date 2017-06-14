
// PlaneGameView.cpp : CPlaneGameView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "PlaneGame.h"
#endif

#include "PlaneGameDoc.h"
#include "PlaneGameView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPlaneGameView

IMPLEMENT_DYNCREATE(CPlaneGameView, CView)

BEGIN_MESSAGE_MAP(CPlaneGameView, CView)
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_COMMAND(ID_GAME_START, &CPlaneGameView::OnGameStart)
	ON_COMMAND(ID_GAME_EXIT, &CPlaneGameView::OnGameExit)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CPlaneGameView ����/����

CPlaneGameView::CPlaneGameView()
{
	// TODO: �ڴ˴���ӹ������

}

CPlaneGameView::~CPlaneGameView()
{
}

BOOL CPlaneGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CPlaneGameView ����

void CPlaneGameView::OnDraw(CDC* pDC)
{
	CPlaneGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// ���Ʊ���
	const CImage &bk = pDoc->GetBkground();
	if (!bk.IsNull())
	{
		bk.Draw(pDC->GetSafeHdc(), 0, 0, 
			pDoc->GetWidth(), pDoc->GetHeight());
	}


	// ������ҷɻ�
	DrawGameObject(pDoc->GetPlanePlayer(), pDC);

	// �����ӵ�
	for (const auto &b : pDoc->GetBulletList())
	{
		DrawGameObject(b, pDC);
	}

	// ���Ƶл�
	for (const auto pe : pDoc->GetEnemyList())
	{
		DrawGameObject(*pe, pDC);
	}

	// ��ӡ�ɼ�
	CString str;
	str.Format(_T("%.4d"), pDoc->GetScore());

	pDC->SetBkMode(TRANSPARENT);

	CFont font;
	font.CreatePointFont(300, _T("΢���ź�"));
	CFont *oldFont = pDC->SelectObject(&font);

	pDC->TextOut(0, 0, str);

	pDC->SelectObject(oldFont);
}


// CPlaneGameView ���

#ifdef _DEBUG
void CPlaneGameView::AssertValid() const
{
	CView::AssertValid();
}

void CPlaneGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPlaneGameDoc* CPlaneGameView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlaneGameDoc)));
	return (CPlaneGameDoc*)m_pDocument;
}
#endif //_DEBUG


// CPlaneGameView ��Ϣ�������


void CPlaneGameView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CPlaneGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	////  Get the size of the client area and the window
	//CRect rcClient;
	//GetClientRect(&rcClient);
	switch (nChar)
	{
		case VK_LEFT: case 'A':
			pDoc->PlayerMove(LEFT);
			break;
		case VK_RIGHT: case 'D':
			pDoc->PlayerMove(RIGHT);
			break;
		case VK_UP: case 'W':
			pDoc->PlayerMove(UP);
			break;
		case VK_DOWN: case 'S':
			pDoc->PlayerMove(DOWN);
			break;
		case VK_SPACE:
		{
			pDoc->Shoot();
			break;
		}
		default:
			break;
			//pDoc->PlayerMove(c2d(nChar));
	}

	//  Force the view to redraw
	//Invalidate();
	//UpdateWindow();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CPlaneGameView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	ResizeWindow();

}

void CPlaneGameView::ResizeWindow()
{
	//  First get a pointer to the document
	CPlaneGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//  Get the size of the client area and the window
	CRect rcClient, rcWindow;
	GetClientRect(&rcClient);
	GetParentFrame()->GetWindowRect(&rcWindow);
	//  Calculate the difference
	int nWidthDiff = rcWindow.Width() - rcClient.Width();
	int nHeightDiff = rcWindow.Height() - rcClient.Height();
	//  Change the window size based on the size of the game board
	rcWindow.right = rcWindow.left +
		pDoc->GetWidth() + nWidthDiff;
	rcWindow.bottom = rcWindow.top +
		pDoc->GetHeight() + nHeightDiff;
	//  The MoveWindow function resizes the frame window
	GetParentFrame()->MoveWindow(&rcWindow);
}

void CPlaneGameView::DrawGameObject(const GameObject & go, CDC * pDC)
{
	const CImage &img = go.getImage();
	if (!img.IsNull())
	{
		img.Draw(pDC->GetSafeHdc(), go.getX(), go.getY(), 
			go.getWidth(), go.getHeight());
	}
}


void CPlaneGameView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//  First get a pointer to the document
	CPlaneGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	switch (nIDEvent)
	{
		case 1:
			pDoc->UpdateBullets();
			pDoc->UpdateEnemies();
			pDoc->BulletHitPlane();

			if (pDoc->IsGameOver())
			{
				KillTimer(1);
				KillTimer(2);
				MessageBox(_T("GameOver"), 0, MB_ICONWARNING);
			}		

			break;
		case 2:
			pDoc->AddEnemy();
			break;
		default:
			break;
	}

	Invalidate();

	CView::OnTimer(nIDEvent);
}


void CPlaneGameView::OnGameStart()
{
	// TODO: �ڴ���������������
	//  First get a pointer to the document
	CPlaneGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->Init();

	SetTimer(1, 40, 0);
	SetTimer(2, 500, 0);
}


void CPlaneGameView::OnGameExit()
{
	// TODO: �ڴ���������������
	AfxGetApp()->m_pMainWnd->SendMessage(WM_CLOSE);
}


BOOL CPlaneGameView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//return CView::OnEraseBkgnd(pDC);
	return TRUE;
}
