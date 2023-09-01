#include "pch.h"
#include "Course.h"
#include "CourseDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <string> // ����������� ����������� ���������� � ���������


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

#include <initguid.h>

DEFINE_GUID(ImageFormatBMP, 0xb96b3cab, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatEMF, 0xb96b3cac, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatWMF, 0xb96b3cad, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatJPEG, 0xb96b3cae, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatPNG, 0xb96b3caf, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatGIF, 0xb96b3cb0, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatTIFF, 0xb96b3cb1, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);

//�������� � ���������� � ���� CAboutDlg

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);

protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()




CCourseDlg::CCourseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
	, m_A(_T(""))
	, m_B(_T(""))
	, m_C(_T(""))
	, m_D(_T(""))
	, m_E(_T(""))
	, m_Acc(_T(""))
	, m_Num(_T(""))
	, m_Scale(_T(""))
	, m_x_left(_T(""))
	, m_x_right(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCourseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDITA, m_Edit_A);
	DDX_Control(pDX, IDC_EDITB, m_Edit_B);
	DDX_Control(pDX, IDC_EDITC, m_Edit_C);
	DDX_Control(pDX, IDC_EDITD, m_Edit_D);
	DDX_Control(pDX, IDC_EDITE, m_Edit_E);
	DDX_Control(pDX, IDC_EDITXDOWN, m_Edit_x_left);
	DDX_Control(pDX, IDC_EDITXUP, m_Edit_x_right);
	DDX_Control(pDX, IDC_EDITE, m_Edit_E);
	DDX_Control(pDX, IDC_EDITCUR, m_Edit_Acc);
	DDX_Control(pDX, IDC_EDITNUM, m_Edit_Num);
	DDX_Control(pDX, IDC_EDITSCALE, m_Edit_Scale);
	DDX_Control(pDX, IDC_COMBOSTYLE, m_ComboStyle);
	DDX_Text(pDX, IDC_EDITA, m_A);
	DDX_Text(pDX, IDC_EDITB, m_B);
	DDX_Text(pDX, IDC_EDITC, m_C);
	DDX_Text(pDX, IDC_EDITD, m_D);
	DDX_Text(pDX, IDC_EDITE, m_E);
	DDX_Text(pDX, IDC_EDITXDOWN, m_x_left);
	DDX_Text(pDX, IDC_EDITXUP, m_x_right);
	DDX_Text(pDX, IDC_EDITCUR, m_Acc);
	DDX_Text(pDX, IDC_EDITNUM, m_Num);
	DDX_Text(pDX, IDC_EDITSCALE, m_Scale);
} // ���� ����������

BEGIN_MESSAGE_MAP(CCourseDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDITA, &CCourseDlg::OnEnChangeEditA)
	ON_EN_CHANGE(IDC_EDITB, &CCourseDlg::OnEnChangeEditB)
	ON_EN_CHANGE(IDC_EDITC, &CCourseDlg::OnEnChangeEditC)
	ON_EN_CHANGE(IDC_EDITD, &CCourseDlg::OnEnChangeEditD)
	ON_EN_CHANGE(IDC_EDITE, &CCourseDlg::OnEnChangeEditE)
	ON_EN_CHANGE(IDC_EDITCUR, &CCourseDlg::OnEnChangeEditCur)
	ON_BN_CLICKED(IDC_BUTTONCALC, &CCourseDlg::OnBnClickedButtonCalc)
	ON_BN_CLICKED(IDC_BUTTONUP, &CCourseDlg::OnBnClickedButtonUp)
	ON_BN_CLICKED(IDC_BUTTONCENTER, &CCourseDlg::OnBnClickedButtonCenter)
	ON_BN_CLICKED(IDC_BUTTONDOWN, &CCourseDlg::OnBnClickedButtonDown)
	ON_BN_CLICKED(IDC_BUTTONLEFT, &CCourseDlg::OnBnClickedButtonLeft)
	ON_BN_CLICKED(IDC_BUTTONRIGHT, &CCourseDlg::OnBnClickedButtonRight)
	ON_EN_CHANGE(IDC_EDITSCALE, &CCourseDlg::OnEnChangeEditScale)
	ON_EN_CHANGE(IDC_EDITNUM, &CCourseDlg::OnEnChangeEditNum)
	ON_EN_CHANGE(IDC_EDITXDOWN, &CCourseDlg::OnEnChangeEditxdown)
	ON_EN_CHANGE(IDC_EDITXUP, &CCourseDlg::OnEnChangeEditxup)
	ON_BN_CLICKED(IDC_BUTTONCLEAN, &CCourseDlg::OnBnClickedButtonClean)
	ON_BN_CLICKED(IDC_BUTTONSAVE, &CCourseDlg::OnBnClickedButtonsave)
	ON_CBN_SELCHANGE(IDC_COMBOSTYLE, &CCourseDlg::OnCbnSelchangeCombostyle)
	ON_BN_CLICKED(IDC_CHECKCOORD, &CCourseDlg::OnBnClickedCheckcoord)
END_MESSAGE_MAP()

// ����������� ��������� ����������� ����


BOOL CCourseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX); // ���������� "� ���������"
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	m_graph.SubclassDlgItem(IDC_GRAPH, this);

	CRect rc;
	m_graph.GetClientRect(&rc);
	UpdateData(FALSE);

	CWnd* pN = GetDlgItem(IDC_EDITNUM);
	if (pN)
		pN->SetWindowText(_T("400"));
	m_calc.m_param.Num = 400;

	CWnd* pS = GetDlgItem(IDC_EDITSCALE);
	if (pS)
		pS->SetWindowText(_T("20"));
	m_calc.m_param.Scale = 20;

	CWnd* pA = GetDlgItem(IDC_EDITA);
	if (pA)
		pA->SetWindowText(_T("0"));
	m_calc.m_param.A = 0;

	CWnd* pB = GetDlgItem(IDC_EDITB);
	if (pB)
		pB->SetWindowText(_T("0"));
	m_calc.m_param.B = 0;

	CWnd* pC = GetDlgItem(IDC_EDITC);
	if (pC)
		pC->SetWindowText(_T("0"));
	m_calc.m_param.C = 0;

	CWnd* pD = GetDlgItem(IDC_EDITD);
	if (pD)
		pD->SetWindowText(_T("0"));
	m_calc.m_param.D = 0;

	CWnd* pE = GetDlgItem(IDC_EDITE);
	if (pE)
		pE->SetWindowText(_T("0"));
	m_calc.m_param.E = 0;

	CWnd* pCu = GetDlgItem(IDC_EDITCUR);
	if (pCu)
		pCu->SetWindowText(_T("0.0001"));
	m_calc.m_param.Acc = 0.0001;

	CWnd* pXU = GetDlgItem(IDC_EDITXUP);
	if (pXU)
		pXU->SetWindowText(_T("0"));

	CWnd* pXD = GetDlgItem(IDC_EDITXDOWN);
	if (pXD)
		pXD->SetWindowText(_T("0"));

	int WPB = m_ComboStyle.AddString(_T("White + Blue"));
	m_ComboStyle.SetItemData(WPB, RGB(255, 255, 255));
	int BPG = m_ComboStyle.AddString(_T("Black + Green"));
	m_ComboStyle.SetItemData(BPG, RGB(0, 0, 0));

	CWnd* pCS = GetDlgItem(IDC_COMBOSTYLE);
	if (pCS)
		pCS->SetWindowText(_T("White + Blue"));

	return TRUE;
}//��������� �������� ���� ����� ��������

void CCourseDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

void CCourseDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		//������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		//���������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}
//���������� ����������� �������
HCURSOR CCourseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






void CCourseDlg::OnEnChangeEditA()//��� ��������� ���������
{
	CWnd* pE = GetDlgItem(IDC_EDITA);//������� ��������� ������ ��������
	if (pE)
	{
		pE->GetWindowText(m_A); // ����� �������� �� ������� �����
		m_calc.m_param.A = _wtof(m_A); // �������� ��� � ���������
		m_calc.Calculate(); // ��������� ���������� � ����� ����������
		m_graph.Invalidate(); // �������� ������
	}
}


void CCourseDlg::OnEnChangeEditB() // ����� � ����� - ����������
{
	CWnd* pE = GetDlgItem(IDC_EDITB);
	if (pE)
	{
		pE->GetWindowText(m_B);
		m_calc.m_param.B = _wtof(m_B);
		m_calc.Calculate();
		m_graph.Invalidate();
	}
}


void CCourseDlg::OnEnChangeEditC()
{
	CWnd* pE = GetDlgItem(IDC_EDITC);
	if (pE)
	{
		pE->GetWindowText(m_C);
		m_calc.m_param.C = _wtof(m_C);
		m_calc.Calculate();
		m_graph.Invalidate();
	}
}


void CCourseDlg::OnEnChangeEditD()
{
	CWnd* pE = GetDlgItem(IDC_EDITD);
	if (pE)
	{
		pE->GetWindowText(m_D);
		m_calc.m_param.D = _wtof(m_D);
		m_calc.Calculate();
		m_graph.Invalidate();
	}
}


void CCourseDlg::OnEnChangeEditE()
{
	CWnd* pE = GetDlgItem(IDC_EDITE);
	if (pE)
	{
		pE->GetWindowText(m_E);
		m_calc.m_param.E = _wtof(m_E);
		m_calc.Calculate();
		m_graph.Invalidate();
	}
}


void CCourseDlg::OnEnChangeEditCur()
{
	CWnd* pE = GetDlgItem(IDC_EDITCUR);
	if (pE)
	{
		pE->GetWindowText(m_Acc);
		m_calc.m_param.Acc = _wtof(m_Acc);
		m_calc.Calculate();
		m_graph.Invalidate();
	}
}


void CCourseDlg::OnBnClickedButtonCalc()//��� ������� "����������"
{
	if (m_calc.m_param.Acc <= 0) GetDlgItem(IDC_STATICSOLUT)->SetWindowText(_T("�������� �������� ������ ��� ����� ����. ����������, �������� �������� � ��������� �������."));
	else
	{
		m_calc.cleanSolv(m_calc.m_param); // ����� ������ ������
		CString Text = _T(""); // ������� ���������� ��� ������
		GetDlgItem(IDC_STATICSOLUT)->SetWindowText(Text);//���������� ���� ������
		CString ResS; // ��� ���������� ������ � ��������� �������
		CString IterS; // ��� ���������� ���������� �������� � ��������� �������
		double Res; // ��� ���������� ������
		int Iter; // ���. ���������� ���������� ��������
		int size = *m_calc.GetSize(); // ��� ���������� ���������� ������ � ������� �������
		if (size <= 5)
			for (int i = 0; i < size; i++) {// ���� �� ����� �� ����� �������
				Res = *m_calc.GetResult(i);// �������� �� ������� ������
				Iter = *m_calc.GetIteration(i);// �������� �� ������� ���������� ��������
				ResS.Format(L"%f", Res);// ��������������� ����� ����� � �����
				IterS.Format(_T("%d"), Iter);// ��������������� ���������� �������� � �����
				Text += ResS;
				Text += _T(" ");
				Text += IterS;
				Text += "\n";// ������������ ���������� � ������� ������� "������ - ���������� ��������"
				GetDlgItem(IDC_STATICSOLUT)->SetWindowText(Text);// ��������� ����� ��������
			}
		else {
			Text = _T(" ");
			GetDlgItem(IDC_STATICSOLUT)->SetWindowText(_T("������ ������ ����. ����������, ��������� ������� ������."));// ��������������
		}
		if (Text == "") GetDlgItem(IDC_STATICSOLUT)->SetWindowText(_T("������ ��� ��� �� ����������� ���������. ����������, �������� ��������� ���������."));// ��������������

		GetDlgItem(IDC_STATICODZ)->SetWindowText(_T("(-inf ; +inf)"));// ������� ���
	}
}

void CCourseDlg::OnBnClickedButtonUp()// ��� ������� ������ �������� �����
{
	Param_values par = m_calc.m_param;// ������� ��������� ������ ��������
	par.y_i += 1;// ������ �������� �����
	m_calc.SetParams(par);// ������������ ���������� ��������
	m_calc.Calculate();// ��������� ����� ������
	m_graph.Invalidate();// �������� ������
}


void CCourseDlg::OnBnClickedButtonDown()// ����� � ����� - ����������
{
	Param_values par = m_calc.m_param;
	par.y_i -= 1;
	m_calc.SetParams(par);
	m_calc.Calculate();
	m_graph.Invalidate();
}


void CCourseDlg::OnBnClickedButtonLeft()
{
	Param_values par = m_calc.m_param;
	par.x_i += 1;
	m_calc.SetParams(par);
	m_calc.Calculate();
	m_graph.Invalidate();
}


void CCourseDlg::OnBnClickedButtonRight()
{
	Param_values par = m_calc.m_param;
	par.x_i -= 1;
	m_calc.SetParams(par);
	m_calc.Calculate();
	m_graph.Invalidate();
}

void CCourseDlg::OnBnClickedButtonCenter() // ����� ���� �����. �����
{
	Param_values par = m_calc.m_param;// ������� ��������� ������ ��������
	par.x_i = 0;// ������ �������� �� ����������, ������ 0
	par.y_i = 0;// ������ �������� �� ���������, ������ 0
	m_calc.SetParams(par);// ������������ ���������� ���������
	m_calc.Calculate();// ��������� ����� ������
	m_graph.Invalidate();// �������� ������
}


void CCourseDlg::OnEnChangeEditScale() // ����� � ����� ����� ����������
{
	CWnd* pE = GetDlgItem(IDC_EDITSCALE);
	if (pE)
	{
		pE->GetWindowText(m_Scale);
		m_calc.m_param.Scale = _wtof(m_Scale);
		m_calc.Calculate();
		m_graph.Invalidate();
	}
}


void CCourseDlg::OnEnChangeEditNum()
{
	CWnd* pE = GetDlgItem(IDC_EDITNUM);
	if (pE)
	{
		pE->GetWindowText(m_Num);
		m_calc.m_param.Num = _wtof(m_Num);
		m_calc.Calculate();
		m_graph.Invalidate();
	}
}

void CCourseDlg::OnEnChangeEditxdown()
{
	CWnd* pE = GetDlgItem(IDC_EDITXDOWN);
	if (pE)
	{
		pE->GetWindowText(m_x_left);
		m_calc.m_param.x_left = _wtof(m_x_left);
		m_calc.Calculate();
		m_graph.Invalidate();
	}
}


void CCourseDlg::OnEnChangeEditxup()
{
	CWnd* pE = GetDlgItem(IDC_EDITXUP);
	if (pE)
	{
		pE->GetWindowText(m_x_right);
		m_calc.m_param.x_right = _wtof(m_x_right);
		m_calc.Calculate();
		m_graph.Invalidate();
	}
}


void CCourseDlg::OnBnClickedButtonClean()// ��� ������� ������ �������
{
	GetDlgItem(IDC_STATICSOLUT)->SetWindowText(_T(""));// �������� ����� � ���� �������
}


void CCourseDlg::OnBnClickedButtonsave()// ��� ������� ������ ����������
{
	CWnd* pWn = GetDlgItem(IDC_GRAPH);// ������� ��������� ������ ��������
	if (!pWn)// ���� ������ ���
		return;// ��������� �������
	CWindowDC winDC(pWn);// �������� ������ �� ���� ������� ����������� ����
	CRect rc;// ������� ���������� ������ CRect
	pWn->GetClientRect(&rc);// ����� ������� ������� �������
	CDC memDC;// ������� ���������� ������ CDC
	memDC.CreateCompatibleDC(&winDC);// ������� �������� ���������� � ������ DC
	CBitmap bitMap;// �������� ���������� ������ CBitmap
	bitMap.CreateCompatibleBitmap(&winDC, rc.Width(), rc.Height());// ������� ����. �����. � ������ 
	HGDIOBJ pOld = memDC.SelectObject(&bitMap);// ������� ����������
	memDC.FillSolidRect(&rc, RGB(0, 255, 0));// ������ ����������
	memDC.BitBlt(0, 0, rc.Width(), rc.Height(), &winDC, 0, 0, SRCCOPY);// ���������� ��������� �����������
	memDC.SelectObject(pOld);// ������� �����

	static TCHAR szFilter[] = _T("BMP Files (*.bmp)|*.bmp|")
		_T("PNG Files (*.png)|*.png|GIF Files (*.gif)|*.gif|")
		_T("JPG Files (*.jpg)|*.jpg|All Files (*.*)|*.*||");
	CFileDialog dlg(FALSE, _T(".bmp"), NULL, 6UL, szFilter);// ����� ���������� � �������� ������
	if (IDOK == dlg.DoModal())// ������� ���������� �������
	{
		CImage image;// ������� ���������� ������ CImage
		image.Attach(HBITMAP(bitMap));// ���������� ������������� ����
		CString strFull = dlg.GetOFN().lpstrFile;// ������� ���������� ������ CString
		HRESULT hr;// ������� ���������� ������ ������ � ��������������
		if (-1 != strFull.Find(_T(".png")))// ���� ����������� � ���� �������
			hr = image.Save(strFull, ImageFormatPNG);// ��������� � ������ �����������
		else if (-1 != strFull.Find(_T(".jpg")))// �����... (������ �������)
			hr = image.Save(strFull, ImageFormatJPEG);
		else if (-1 != strFull.Find(_T(".gif")))
			hr = image.Save(strFull, ImageFormatGIF);
		else if (-1 != strFull.Find(_T(".bmp")))
			hr = image.Save(strFull, ImageFormatBMP);
		else
		{
			strFull += _T(".bmp");
			hr = image.Save(strFull, ImageFormatBMP);
		}

		if (FAILED(hr))// ���� ������
		{
			CString strErr;// ������� ���������� ������ CString
			strErr.Format(L" �� ������� ��������� ����: %s, %x ", (LPCTSTR)strFull, hr);// �� ���� ���������
			AfxMessageBox(strErr, MB_OK | MB_ICONERROR);// ���� �� ������
		}
	}
}

void CCourseDlg::OnCbnSelchangeCombostyle()// ��� ��������� ��������� ComboBox
{
	int nStyl = m_ComboStyle.GetCurSel();// �������� ID ���������� ���������
	if (CB_ERR != nStyl)// ����������� ������
	{
		CString strSty;// ������� ���������� ������ CString
		m_ComboStyle.GetLBText(nStyl, strSty);// �������� �� ID ��������� ��������
		m_graph.m_Col = m_ComboStyle.GetItemData(nStyl);// �������� ������ � ���������
		m_graph.Invalidate();// �������� ������
	}
}


void CCourseDlg::OnBnClickedCheckcoord()// ����� CheckBox
{
	CButton* pW = (CButton*)GetDlgItem(IDC_CHECKCOORD);// �������� ���������� ������ ��������
	if (pW->GetCheck())// ���� ������ ������
	{
		m_graph.Coords = true;// �������� �������� ���������� ���������� ����������� ������������ ����� (�������������)
		m_graph.Invalidate();// �������� ������
	}
	else m_graph.Coords = false;// �������� �������� ���������� ���������� ����������� ������������ ����� (�������������)
	m_graph.Invalidate();// �������� ������
}