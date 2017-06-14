
// PlaneGameView.h : CPlaneGameView ��Ľӿ�
//

#pragma once
#include "PlanePlayer.h"
#include "Bullet.h"

class CPlaneGameView : public CView
{
protected: // �������л�����
	CPlaneGameView();
	DECLARE_DYNCREATE(CPlaneGameView)

// ����
public:
	CPlaneGameDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CPlaneGameView();
	

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void ResizeWindow();
	void DrawGameObject(const GameObject &go, CDC *pDC);

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual void OnInitialUpdate();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnGameStart();
	afx_msg void OnGameExit();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnHelpGuide();
};

#ifndef _DEBUG  // PlaneGameView.cpp �еĵ��԰汾
inline CPlaneGameDoc* CPlaneGameView::GetDocument() const
   { return reinterpret_cast<CPlaneGameDoc*>(m_pDocument); }
#endif

