// CDlgimage.cpp: 구현 파일
//

#include "pch.h"
#include "mfcprt.h"
#include "afxdialogex.h"
#include "CDlgimage.h"


// CDlgimage 대화 상자

IMPLEMENT_DYNAMIC(CDlgimage, CDialogEx)

CDlgimage::CDlgimage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CDlgimage, pParent)
{
	m_pParent = pParent;
}

CDlgimage::~CDlgimage()
{
}

void CDlgimage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgimage, CDialogEx)
	ON_BN_CLICKED(IDC_btn_up, &CDlgimage::OnBnClickedbtnup)
END_MESSAGE_MAP()


// CDlgimage 메시지 처리기

#include "mfcprtDlg.h"
void CDlgimage::OnBnClickedbtnup()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	static int n = 100;
	CmfcprtDlg* pdlg = (CmfcprtDlg*)m_pParent;
	pdlg->callfunc(n++);
}
