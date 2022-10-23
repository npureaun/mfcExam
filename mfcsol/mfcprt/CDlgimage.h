#pragma once
#include "afxdialogex.h"

// CDlgimage 대화 상자

class CDlgimage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgimage)

public:
	CDlgimage(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgimage();

	CImage m_image;
	CWnd* m_pParent = NULL;

	int m_nDataCnt = 0;
	CPoint m_ptData[100];

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CDlgimage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	void drawData(CDC* pdc) {
		CRect rect;
		CPen pen;
		pen.CreatePen(PS_SOLID, 5, RGB(0xff, 0, 0));
		CPen* poldpen = pdc->SelectObject(&pen);
		for (int i = 0; i < m_nDataCnt; i++) {
			rect.SetRect(m_ptData[i], m_ptData[i]);
			rect.InflateRect(5, 10);
			pdc->Ellipse(rect);
		}
		pdc->SelectObject(poldpen);
	}
	DECLARE_MESSAGE_MAP()


public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();

	void initimage() {
		int nwidth = 640;
		int nheigth = 480;
		int nbpp = 8;
		m_image.Create(nwidth, -nheigth, nbpp);
		if (nbpp == 8) {
			static RGBQUAD rgb[256];
			for (int i = 0; i < 256; i++) {
				rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
				m_image.SetColorTable(0, 256, rgb);
			}
		}
		int npitch = m_image.GetPitch();
		unsigned char* fm = (unsigned char*)m_image.GetBits();
		memset(fm, 0xff, nwidth * nheigth);
	}

};
