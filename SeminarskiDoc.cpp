
// SeminarskiDoc.cpp : implementation of the CSeminarskiDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Seminarski.h"
#endif

#include "SeminarskiDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSeminarskiDoc

IMPLEMENT_DYNCREATE(CSeminarskiDoc, CDocument)

BEGIN_MESSAGE_MAP(CSeminarskiDoc, CDocument)
END_MESSAGE_MAP()


// CSeminarskiDoc construction/destruction

CSeminarskiDoc::CSeminarskiDoc()
{
	// TODO: add one-time construction code here
}

CSeminarskiDoc::~CSeminarskiDoc()
{
}

BOOL CSeminarskiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CSeminarskiDoc serialization

void CSeminarskiDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar << 'F' << 'E' << 'S' << 'B';

		std::list<CString>::iterator pos;
		std::list<CPoint>::iterator pos2;
		std::list<CString>::iterator pos3;
		std::list<int>::iterator pos4;

		pos2 = m_poslista.begin();
		pos3 = m_odabirfontlista.begin();
		pos4 = m_velicinafontlista.begin();

		for (pos = m_textlista.begin(); pos != m_textlista.end(); ++pos)
		{
			ar << (*pos);
			ar << (*pos2);
			ar << (*pos3);
			ar << (*pos4);

			++pos2;
			++pos3;
			++pos4;
		}
	}
	else
	{
		// TODO: add loading code here
		char c1, c2, c3, c4;
		ar >> c1 >> c2 >> c3 >> c4;

		if (c1 != 'F' || c2 != 'E' || c3 != 'S' || c4 != 'B')
		{
			AfxMessageBox(L"Ovo nije ispravna datoteka za citanje!");
			return;
		}

			CString p1;
			CPoint p2;
			CString p3;
			int p4;

			while(!ar.IsBufferEmpty())
			{
				ar >> p1 >> p2 >> p3 >> p4;

				m_textlista.push_back(p1);
				m_poslista.push_back(p2);
				m_odabirfontlista.push_back(p3);
				m_velicinafontlista.push_back(p4);
			}
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CSeminarskiDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CSeminarskiDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CSeminarskiDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CSeminarskiDoc diagnostics

#ifdef _DEBUG
void CSeminarskiDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSeminarskiDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSeminarskiDoc commands
