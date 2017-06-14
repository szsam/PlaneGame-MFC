
// PlaneGameDoc.h : CPlaneGameDoc ��Ľӿ�
//


#pragma once
#include "GameCtrl.h"

class CPlaneGameDoc : public CDocument
{
protected: // �������л�����
	CPlaneGameDoc();
	DECLARE_DYNCREATE(CPlaneGameDoc)

// ����
public:

// ����
public:
	int GetHeight() { return m_gameCtrl.getHeight(); }
	int GetWidth() { return m_gameCtrl.getWidth(); }
	void DrawPlayer(CDC *pDC) { m_gameCtrl.drawPlayer(pDC); }
	void PlayerMove(Dir d) { m_gameCtrl.playerMove(d); }
	void Shoot() { m_gameCtrl.shoot(); }
	void DrawBullets(CDC *pDC) { m_gameCtrl.drawBullets(pDC); }
	void UpdateBullets() { m_gameCtrl.updateBullets(); }
	void UpdateEnemies() { m_gameCtrl.updateEnemies(); }
	void AddEnemy() { m_gameCtrl.addEnemy(); }
	void DrawEnemies(CDC *pDC) { m_gameCtrl.drawEnemies(pDC); }
	void BulletHitPlane() { m_gameCtrl.bulletHitPlane(); }
	bool IsGameOver() { return m_gameCtrl.gameOver(); }
	void PrintScore(CDC *pDC) { m_gameCtrl.printScore(pDC); }
	void Init() { m_gameCtrl.init(); }
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CPlaneGameDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	GameCtrl m_gameCtrl;

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
