
// SeminarskiView.cpp : implementation of the CSeminarskiView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Seminarski.h"
#endif

#include "SeminarskiDoc.h"
#include "SeminarskiView.h"
#include "TxtDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSeminarskiView

IMPLEMENT_DYNCREATE(CSeminarskiView, CView)

BEGIN_MESSAGE_MAP(CSeminarskiView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CSeminarskiView construction/destruction

CSeminarskiView::CSeminarskiView()
{
	// TODO: add construction code here

}

CSeminarskiView::~CSeminarskiView()
{
}

BOOL CSeminarskiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSeminarskiView drawing

void CSeminarskiView::OnDraw(CDC* pDC)
{
	CSeminarskiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	std::list<CString>::iterator pos;
	std::list<CPoint>::iterator pos2;
	std::list<CString>::iterator pos3;
	std::list<int>::iterator pos4;

	pos2 = pDoc->m_poslista.begin();
	pos3 = pDoc->m_odabirfontlista.begin();
	pos4 = pDoc->m_velicinafontlista.begin();

	pDC->TextOut(0, 0, L"Kliknite na prvo slovo teksta za pomicanje.");

	for (pos = pDoc->m_textlista.begin(); pos != pDoc->m_textlista.end(); ++pos)
	{

		// TODO: add draw code for native data here
		CFont m_font;

		VERIFY(m_font.CreatePointFont((*pos4) * 10, (*pos3), pDC));

		// Do something with the font just created...
		CFont* def_font = pDC->SelectObject(&m_font);
		pDC->TextOut((*pos2).x, (*pos2).y, (*pos));
		pDC->SelectObject(def_font);

		// Done with the font. Delete the font object.
		m_font.DeleteObject();

		++pos2;
		++pos3;
		++pos4;
	}
}


// CSeminarskiView printing

BOOL CSeminarskiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSeminarskiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSeminarskiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CSeminarskiView diagnostics

#ifdef _DEBUG
void CSeminarskiView::AssertValid() const
{
	CView::AssertValid();
}

void CSeminarskiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSeminarskiDoc* CSeminarskiView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSeminarskiDoc)));
	return (CSeminarskiDoc*)m_pDocument;
}
#endif //_DEBUG


// CSeminarskiView message handlers


void CSeminarskiView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CSeminarskiDoc* pDoc = GetDocument();
	CTxtDlg dlg;

	int response = dlg.DoModal();

	if (IDOK == response)
	{
		if (dlg.m_text.IsEmpty())
			AfxMessageBox(L"Unijeli ste prazan tekst");
		else
		{
			pDoc->m_poslista.push_back(point);
			pDoc->m_textlista.push_back(dlg.m_text);
			pDoc->m_velicinafontlista.push_back(dlg.m_izborvelicinefonta);
			pDoc->m_odabirfontlista.push_back(dlg.m_izborfonta);
		}
		Invalidate();
	}

	CView::OnRButtonDown(nFlags, point);
}


void CSeminarskiView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CSeminarskiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	CPoint odabir = point;

	static int pomocna = 0;
	std::list<CPoint>::iterator pos;
	static std::list <CPoint>::iterator pamtilo;

	for (pos = pDoc->m_poslista.begin(); pos != pDoc->m_poslista.end(); ++pos)
	{
		if (odabir.x > (*pos).x && odabir.x < ((*pos).x+30) &&
			odabir.y > (*pos).y && odabir.y < ((*pos).y+40) && pomocna == 0)
		{
			AfxMessageBox(L"Odaberite novu poziciju za odabrani tekst.");
			pamtilo = pos;
			pomocna = 1;
			break;
		}
		else if (pomocna == 1)
		{
			CPoint odabir2 = point;
			(*pamtilo).x = odabir2.x;
			(*pamtilo).y = odabir2.y;
			pomocna = 0;
			break;
		}
	}
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}
