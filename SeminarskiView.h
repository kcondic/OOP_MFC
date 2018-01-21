
// SeminarskiView.h : interface of the CSeminarskiView class
//

#pragma once


class CSeminarskiView : public CView
{
protected: // create from serialization only
	CSeminarskiView();
	DECLARE_DYNCREATE(CSeminarskiView)

// Attributes
public:
	CSeminarskiDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CSeminarskiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in SeminarskiView.cpp
inline CSeminarskiDoc* CSeminarskiView::GetDocument() const
   { return reinterpret_cast<CSeminarskiDoc*>(m_pDocument); }
#endif

