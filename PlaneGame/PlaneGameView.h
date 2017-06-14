
// PlaneGameView.h : CPlaneGameView 类的接口
//

#pragma once
#include "PlanePlayer.h"
#include "Bullet.h"

class CPlaneGameView : public CView
{
protected: // 仅从序列化创建
	CPlaneGameView();
	DECLARE_DYNCREATE(CPlaneGameView)

// 特性
public:
	CPlaneGameDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CPlaneGameView();
	

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void ResizeWindow();
	void DrawGameObject(const GameObject &go, CDC *pDC);

// 生成的消息映射函数
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

#ifndef _DEBUG  // PlaneGameView.cpp 中的调试版本
inline CPlaneGameDoc* CPlaneGameView::GetDocument() const
   { return reinterpret_cast<CPlaneGameDoc*>(m_pDocument); }
#endif

