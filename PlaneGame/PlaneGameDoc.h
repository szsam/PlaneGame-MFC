
// PlaneGameDoc.h : CPlaneGameDoc 类的接口
//


#pragma once
#include "GameCtrl.h"

class CPlaneGameDoc : public CDocument
{
protected: // 仅从序列化创建
	CPlaneGameDoc();
	DECLARE_DYNCREATE(CPlaneGameDoc)

// 特性
public:

// 操作
public:
	int GetHeight() { return m_gameCtrl.getHeight(); }
	int GetWidth() { return m_gameCtrl.getWidth(); }
	void PlayerMove(Dir d) { m_gameCtrl.playerMove(d); }
	void Shoot() { m_gameCtrl.shoot(); }
	void UpdateBullets() { m_gameCtrl.updateBullets(); }
	void UpdateEnemies() { m_gameCtrl.updateEnemies(); }
	void AddEnemy() { m_gameCtrl.addEnemy(); }
	void BulletHitPlane() { m_gameCtrl.bulletHitPlane(); }
	bool IsGameOver() { return m_gameCtrl.gameOver(); }
	void Init() { m_gameCtrl.init(); }
	const std::list<Bullet> &GetBulletList() const { return m_gameCtrl.getBulletList(); }
	const std::list<PlaneEnemy> &GetEnemyList() const { return m_gameCtrl.getEnemyList(); }
	const PlanePlayer &GetPlanePlayer() const { return m_gameCtrl.getPlanePlayer(); }
	int GetScore() const { return m_gameCtrl.getScore(); }
	const CImage& GetBkground() const { return m_bkground; }

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CPlaneGameDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	GameCtrl m_gameCtrl;
	CImage m_bkground;

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
