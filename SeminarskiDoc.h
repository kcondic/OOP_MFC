
// SeminarskiDoc.h : interface of the CSeminarskiDoc class
//


#pragma once

#include<list>

class CSeminarskiDoc : public CDocument
{
protected: // create from serialization only
	CSeminarskiDoc();
	DECLARE_DYNCREATE(CSeminarskiDoc)

// Attributes
public:
	std::list<CString> m_textlista;
	std::list<CPoint> m_poslista;
	std::list<int> m_velicinafontlista;
	std::list<CString> m_odabirfontlista;

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CSeminarskiDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
