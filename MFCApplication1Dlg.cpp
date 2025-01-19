
// MFCApplication1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include<string>
BOOL    m_fButtonPressed;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1Dlg 대화 상자



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Editin);
	DDX_Control(pDX, IDC_EDIT2, m_Editout);
	DDX_Control(pDX, IDC_BUTTON1, m_Font);
	DDX_Control(pDX, IDC_EDIT3, m_Editout1);
	DDX_Control(pDX, IDC_EDIT4, m_Editout2);
	DDX_Control(pDX, IDC_EDIT6, m_Editout3);

	DDX_Control(pDX, IDC_EDIT7, m_Editin1);
	DDX_Control(pDX, IDC_EDIT8, m_Editout5);
	DDX_Control(pDX, IDC_EDIT9, m_Editout6);
	DDX_Control(pDX, IDC_EDIT10, m_Editout7);
	DDX_Control(pDX, IDC_EDIT11, m_Editout8);
	//DDX_Control(pDX, IDC_EDIT12, m_Editout9);
	DDX_Control(pDX, IDC_EDIT17, m_Editout10);
	DDX_Control(pDX, IDC_EDIT13, m_Editout11);
	DDX_Control(pDX, IDC_EDIT16, m_Editout12);
	DDX_Control(pDX, IDC_EDIT18, m_Editout13);
	DDX_Control(pDX, IDC_EDIT15, m_Editout14);
	DDX_Control(pDX, IDC_EDIT19, m_Editout15);

	DDX_Control(pDX, IDC_EDIT14, m_Editin2);
	DDX_Control(pDX, IDC_EDIT21, m_Editin3);
	DDX_Control(pDX, IDC_EDIT20, m_Editin4);
	DDX_Control(pDX, IDC_EDIT23, m_Editin5);
	DDX_Control(pDX, IDC_EDIT22, m_Editin6);
	DDX_Control(pDX, IDC_EDIT24, m_Editin7);
	DDX_Control(pDX, IDC_EDIT29, m_Editout16);
	DDX_Control(pDX, IDC_EDIT25, m_Editout17);
	DDX_Control(pDX, IDC_EDIT27, m_Editout18);
	DDX_Control(pDX, IDC_EDIT28, m_Editout19);
	DDX_Control(pDX, IDC_EDIT26, m_Editout20);
	DDX_Control(pDX, IDC_EDIT30, m_Editout21);
	DDX_Control(pDX, IDC_EDIT35, m_Editout22);
	DDX_Control(pDX, IDC_EDIT31, m_Editout23);
	DDX_Control(pDX, IDC_EDIT33, m_Editout24);
	DDX_Control(pDX, IDC_EDIT34, m_Editout25);
	DDX_Control(pDX, IDC_EDIT32, m_Editout26);
	DDX_Control(pDX, IDC_EDIT36, m_Editout27);
	DDX_Control(pDX, IDC_EDIT37, m_Editout28);
	DDX_Control(pDX, IDC_EDIT43, m_Editout29);
	DDX_Control(pDX, IDC_EDIT45, m_Editout30);
	DDX_Control(pDX, IDC_EDIT46, m_Editout31);
	DDX_Control(pDX, IDC_EDIT44, m_Editout32);
	DDX_Control(pDX, IDC_EDIT48, m_Editout33);
	DDX_Control(pDX, IDC_EDIT38, m_Editin8);
	DDX_Control(pDX, IDC_EDIT39, m_Editout50);
	

	

}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCApplication1Dlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CMFCApplication1Dlg::OnEnChangeEdit3)
	
	ON_EN_CHANGE(IDC_EDIT7, &CMFCApplication1Dlg::OnEnChangeEdit7)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication1Dlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 메시지 처리기

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.



// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


int i = 0;

void CMFCApplication1Dlg::OnBnClickedButton1()
{

	CString strText;
	CString strText1[4];


	

	m_Editin.GetWindowTextW(strText);
	m_Editin1.GetWindowTextW(strText1[i]);
	i = i % 5;

	if (i == 0) {
		m_Editout.SetWindowTextW(strText);
		m_Editout5.SetWindowTextW(strText1[0]);
		
	}
	if (i == 1) {
		m_Editout1.SetWindowTextW(strText);
		m_Editout6.SetWindowTextW(strText1[1]);
	}
	if (i == 2) {
		m_Editout2.SetWindowTextW(strText);
		m_Editout7.SetWindowTextW(strText1[2]);
	}
	if (i == 3) {
		m_Editout3.SetWindowTextW(strText);
		m_Editout8.SetWindowTextW(strText1[3]);
	}
	
	i++;
}


void CMFCApplication1Dlg::OnPaint()
{
	CPaintDC dc(this);
	CRect r;
	CRect rect;

	
	
	GetClientRect(r);
	dc.Rectangle(r);


	POINT arPt1[2] = { { 470, 340 }, { 500, 280 } };
	dc.Polygon(arPt1, 2);
	POINT arPt2[2] = { { 470, 335 }, { 520, 350 } };
	dc.Polygon(arPt2, 2);
	POINT arPt3[2] = { { 470, 340 }, { 470, 380 } };
	dc.Polygon(arPt3, 2);
	POINT arPt4[2] = { { 470, 335 }, { 400, 340 } };
	dc.Polygon(arPt4, 2);
	POINT arPt5[2] = { { 540, 240 }, { 600, 120 } };
	dc.Polygon(arPt5, 2);
	POINT arPt6[2] = { { 570, 365 }, { 670, 400 } };
	dc.Polygon(arPt6, 2);
	POINT arPt7[2] = { { 470, 400 }, { 460, 450 } };
	dc.Polygon(arPt7, 2);
	POINT arPt8[2] = { { 300, 335 }, { 350, 340 } };
	dc.Polygon(arPt8, 2);
	
	

}

void CMFCApplication1Dlg::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnEnChangeEdit3()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnEnChangeEdit7()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

int j = 0;



void CMFCApplication1Dlg::OnEnChangeEdit29()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnEnChangeEdit17()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnEnChangeEdit14()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnBnClickedButton5()
{
	CString strText;
	CString strText1;
	CString strText2;
	CString strText3;
	CString strText4;
	CString strText5;
	CString strText6;

	m_Editin8.GetWindowTextW(strText6);
	
	j = j % 4;

	if (j == 0) {
		m_Editout50.SetWindowTextW(strText6);
		m_Editin2.GetWindowTextW(strText);
		m_Editout10.SetWindowTextW(strText);
		

		m_Editin3.GetWindowTextW(strText1);
		m_Editout11.SetWindowTextW(strText1);

		m_Editin4.GetWindowTextW(strText2);
		m_Editout12.SetWindowTextW(strText2);

		m_Editin5.GetWindowTextW(strText3);
		m_Editout13.SetWindowTextW(strText3);

		m_Editin6.GetWindowTextW(strText4);
		m_Editout14.SetWindowTextW(strText4);

		m_Editin7.GetWindowTextW(strText5);
		m_Editout15.SetWindowTextW(strText5);
	}
	if (j == 1) {
		
		m_Editin2.GetWindowTextW(strText);
		m_Editout16.SetWindowTextW(strText);

		m_Editin3.GetWindowTextW(strText1);
		m_Editout17.SetWindowTextW(strText1);

		m_Editin4.GetWindowTextW(strText2);
		m_Editout18.SetWindowTextW(strText2);

		m_Editin5.GetWindowTextW(strText3);
		m_Editout19.SetWindowTextW(strText3);

		m_Editin6.GetWindowTextW(strText4);
		m_Editout20.SetWindowTextW(strText4);

		m_Editin7.GetWindowTextW(strText5);
		m_Editout21.SetWindowTextW(strText5);
		
	}
	if (j == 2) {
		
		m_Editin2.GetWindowTextW(strText);
		m_Editout22.SetWindowTextW(strText);

		m_Editin3.GetWindowTextW(strText1);
		m_Editout23.SetWindowTextW(strText1);

		m_Editin4.GetWindowTextW(strText2);
		m_Editout24.SetWindowTextW(strText2);

		m_Editin5.GetWindowTextW(strText3);
		m_Editout25.SetWindowTextW(strText3);

		m_Editin6.GetWindowTextW(strText4);
		m_Editout26.SetWindowTextW(strText4);

		m_Editin7.GetWindowTextW(strText5);
		m_Editout27.SetWindowTextW(strText5);
	}
	if (j == 3) {
		
		m_Editin2.GetWindowTextW(strText);
		m_Editout28.SetWindowTextW(strText);

		m_Editin3.GetWindowTextW(strText1);
		m_Editout29.SetWindowTextW(strText1);

		m_Editin4.GetWindowTextW(strText2);
		m_Editout30.SetWindowTextW(strText2);

		m_Editin5.GetWindowTextW(strText3);
		m_Editout31.SetWindowTextW(strText3);

		m_Editin6.GetWindowTextW(strText4);
		m_Editout32.SetWindowTextW(strText4);

		m_Editin7.GetWindowTextW(strText5);
		m_Editout33.SetWindowTextW(strText5);
	}
	if (j == 4) {
		
		m_Editin2.GetWindowTextW(strText);
		m_Editout28.SetWindowTextW(strText);

		m_Editin3.GetWindowTextW(strText1);
		m_Editout29.SetWindowTextW(strText1);

		m_Editin4.GetWindowTextW(strText2);
		m_Editout30.SetWindowTextW(strText2);

		m_Editin5.GetWindowTextW(strText3);
		m_Editout31.SetWindowTextW(strText3);

		m_Editin6.GetWindowTextW(strText4);
		m_Editout32.SetWindowTextW(strText4);

		m_Editin7.GetWindowTextW(strText5);
		m_Editout33.SetWindowTextW(strText5);
	}



	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	j++;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
