
// PlaneGameView.cpp : CPlaneGameView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CPlaneGameView 构造/析构

CPlaneGameView::CPlaneGameView()
{
	// TODO: 在此处添加构造代码

}

CPlaneGameView::~CPlaneGameView()
{
}

BOOL CPlaneGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CPlaneGameView 绘制

void CPlaneGameView::OnDraw(CDC* pDC)
{
	CPlaneGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// 绘制背景
	const CImage &bk = pDoc->GetBkground();
	if (!bk.IsNull())
	{
		bk.Draw(pDC->GetSafeHdc(), 0, 0, 
			pDoc->GetWidth(), pDoc->GetHeight());
	}


	// 绘制玩家飞机
	DrawGameObject(pDoc->GetPlanePlayer(), pDC);

	// 绘制子弹
	for (const auto &b : pDoc->GetBulletList())
	{
		DrawGameObject(b, pDC);
	}

	// 绘制敌机
	for (const auto pe : pDoc->GetEnemyList())
	{
		DrawGameObject(*pe, pDC);
	}

	// 打印成绩
	CString str;
	str.Format(_T("%.4d"), pDoc->GetScore());

	pDC->SetBkMode(TRANSPARENT);

	CFont font;
	font.CreatePointFont(300, _T("微软雅黑"));
	CFont *oldFont = pDC->SelectObject(&font);

	pDC->TextOut(0, 0, str);

	pDC->SelectObject(oldFont);
}


// CPlaneGameView 诊断

#ifdef _DEBUG
void CPlaneGameView::AssertValid() const
{
	CView::AssertValid();
}

void CPlaneGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPlaneGameDoc* CPlaneGameView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlaneGameDoc)));
	return (CPlaneGameDoc*)m_pDocument;
}
#endif //_DEBUG


// CPlaneGameView 消息处理程序


void CPlaneGameView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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

	// TODO: 在此添加专用代码和/或调用基类
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
	// TODO: 在此添加命令处理程序代码
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
	// TODO: 在此添加命令处理程序代码
	AfxGetApp()->m_pMainWnd->SendMessage(WM_CLOSE);
}


BOOL CPlaneGameView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//return CView::OnEraseBkgnd(pDC);
	return TRUE;
}
