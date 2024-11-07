
// KUtil1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "KUtil1.h"
#include "KUtil1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CKUtil1Dlg 대화 상자



CKUtil1Dlg::CKUtil1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_KUTIL1_DIALOG, pParent)
	, m_strEnc(_T(""))
	, m_strDec(_T(""))
	, m_strPlain(_T(""))
	, m_strInput(_T(""))
	, m_strPubkey(_T(""))
	, m_strPrivKey(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	setlocale(LC_ALL, "en_US.UTF-8");
}

void CKUtil1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_DEC, m_strDec);
	DDX_Text(pDX, IDC_EDIT_ENC, m_strEnc);
	DDX_Text(pDX, IDC_EDIT_Plain, m_strPlain);
	DDX_Text(pDX, IDC_EDIT_INPUT, m_strInput);
	DDX_Text(pDX, IDC_EDIT_PUBKEY, m_strPubkey);
	DDX_Text(pDX, IDC_EDIT_PRIVKEY, m_strPrivKey);
}

BEGIN_MESSAGE_MAP(CKUtil1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ENC, &CKUtil1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_DEC, &CKUtil1Dlg::OnBnClickedButtonDec)
	ON_BN_CLICKED(IDC_BUTTON_GEN, &CKUtil1Dlg::OnBnClickedButtonGen)
END_MESSAGE_MAP()


// CKUtil1Dlg 메시지 처리기

BOOL CKUtil1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CKUtil1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CKUtil1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CKUtil1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//const CString private_key = _T("-----BEGIN RSA PRIVATE KEY-----\n")
//_T("MIICWwIBAAKBgQCS/OOfTDBnL4kfQNNrwiluyn+2D/nh6EOxR3KiVVqZIFPBNepL\n")
//_T("Vxit18hK6Lw5gHgxMC5rXxQ8NgMY+6GuEYLXzAgHD1vXEp+WGfq8Ql8YqgaexA+0\n")
//_T("deWL0CqewtPOrAYDR8IgPYlMJnCRUwjPDQAjWh+149lsvqxX9hB2pcmmQQIDAQAB\n")
//_T("AoGAUqp7ccmtpzqqybLxtLb8Cl1EuiX+CTlRaNCf/gA29cuijxU9caXIMW0cLlT6\n")
//_T("FvTTpAZO9QACJ2LRFynd4kHi7ZLi9WEFETUWbOSxg+la05pCrIRI3oQbCy6OryvW\n")
//_T("NEioXpGtzRRmjwERPjy/UumMmSN2zGm5xDMk3yy6IugVjwkCQQDbxDzhPYqPTDrp\n")
//_T("sEeZabxRhh4m0cTcEC+EN2JiSQVxyuEji4XTc3SgPkiVioQ8J73VPXx3fX5uJpCz\n")
//_T("PZIO/lPrAkEAqzjbB792YT1Baawew9UrFIRKDpkVh+cshx0M0vfGcXi33CS4UhV8\n")
//_T("H39X2pWeK6e3mfiMWYybJFPPR20yx+HfgwJAOIYIgoYplSGuJVzJjZO8c9ti9ekO\n")
//_T("EOu4zPDRxSWy2Mmtjk7cZL5VSMG8OXoe+LngAXCHCtSkKACTRwaXAnQ3cQJAQnz0\n")
//_T("iOCvbnkj8o308GTRssjgHSUS+FAruVfth+rRc3TGKMVVkgJnza9chTP+VMNvB2o9\n")
//_T("zfRMtmGZJwpfYsDyUwJAZvm3ssoW+FaX4Jvi4kH+CRYiCU5thwgvk4K7rBu+HivD\n")
//_T("A/6kNWn2XHIdp8PTPiMBi+owjbciFIa4ct6GkEoHBA==\n")
//_T("-----END RSA PRIVATE KEY-----\n");

std::pair<CString, CString> CKUtil1Dlg::generate_rsa_keypair(int bits) {
	RSA* rsa = RSA_generate_key(bits, RSA_F4, nullptr, nullptr);

	// 공개키 생성
	BIO* bio_pub = BIO_new(BIO_s_mem());
	PEM_write_bio_RSAPublicKey(bio_pub, rsa);
	size_t pub_len = BIO_pending(bio_pub);
	std::string pub_key(pub_len, '\0');
	BIO_read(bio_pub, (void *)pub_key.data(), pub_len);
	BIO_free_all(bio_pub);

	// 개인키 생성
	BIO* bio_priv = BIO_new(BIO_s_mem());
	PEM_write_bio_RSAPrivateKey(bio_priv, rsa, nullptr, nullptr, 0, nullptr, nullptr);
	size_t priv_len = BIO_pending(bio_priv);
	std::string priv_key(priv_len, '\0');
	BIO_read(bio_priv, (void *)priv_key.data(), priv_len);
	BIO_free_all(bio_priv);

	RSA_free(rsa);
	return { CString(pub_key.c_str()), CString(priv_key.c_str()) };
}


void CKUtil1Dlg::OnBnClickedButton1()
{
	UpdateData(TRUE);

	/*MessageBox(pkeys.first, _T("pub_key"), MB_ICONEXCLAMATION);
	MessageBox(pkeys.second, _T("priv_key"), MB_ICONEXCLAMATION);*/
	
	/*const CString plainText = _T("PLAIN");
	const CString private_key = pkeys.second;*/

	const CString plainText = m_strPlain;
	const CString& private_key = m_privKey;

	RSA* rsa = NULL;
	BIO* bio = NULL;

	const CStringA privateKeyA(private_key);
	bio = BIO_new_mem_buf((void*)static_cast<const char*>(privateKeyA), -1);

	{ char szTemp[256] = { 0, }; sprintf_s(szTemp, "[%s][%d] gunoo22_bio[%p]\n", __FUNCTION__, __LINE__, bio); OutputDebugStringA(szTemp); }
	if (bio == NULL) {
		CString strTmp;
		strTmp.Format(_T("Error in BIO_new_mem_buf : %ld"), ERR_get_error());
		MessageBox(strTmp, _T("message"), MB_ICONERROR);
		return;
	}
	

	PEM_read_bio_RSAPrivateKey(bio, &rsa, NULL, NULL);
	BIO_free_all(bio);

	{ char szTemp[256] = { 0, }; sprintf_s(szTemp, "[%s][%d] gunoo22_ rsa[%p]\n", __FUNCTION__, __LINE__, rsa); OutputDebugStringA(szTemp); }
	if (rsa == NULL) {
		CString strTmp;
		strTmp.Format(_T("Error in PEM_read_bio_RSAPrivateKey : %ld"), ERR_get_error());
		MessageBox(strTmp, _T("message"), MB_ICONERROR);
		return;
	}

	int rsa_size = RSA_size(rsa);
	std::vector<unsigned char> encrypted(rsa_size);

	int result = RSA_private_encrypt(plainText.GetLength(),
		reinterpret_cast<const unsigned char*>(static_cast<LPCTSTR>(plainText)),
		encrypted.data(),
		rsa,
		RSA_PKCS1_PADDING);

	if (result == -1) {
		CString strTmp;
		strTmp.Format(_T("Error in RSA_private_encrypt : %ld"), ERR_get_error());
		MessageBox(strTmp, _T("message"), MB_ICONERROR);
		RSA_free(rsa);
		return;
	}

	RSA_free(rsa);
	/*CString strRet;
	for (auto c : encrypted) {
		strRet.AppendChar(c);
	}
	MessageBox(strRet, _T("message"), MB_ICONINFORMATION);*/

	m_strEnc = _T("");
	for (auto c : encrypted) {
		m_strEnc.AppendChar(c);
	}

	m_strInput = m_strEnc;

	m_encrypted = encrypted;
	UpdateData(FALSE);
}


void CKUtil1Dlg::OnBnClickedButtonDec()
{
	UpdateData(TRUE);
	m_strDec = _T("");

	RSA* rsa = NULL;
	BIO* bio = NULL;
	
	const CStringA publicKeyA(m_pubKey);
	bio = BIO_new_mem_buf((void*)static_cast<const char*>(publicKeyA), -1);
	PEM_read_bio_RSAPublicKey(bio, &rsa, NULL, NULL);
	BIO_free_all(bio);

	int rsa_size = RSA_size(rsa);
	std::vector<unsigned char> decrypted(rsa_size);

	/*CStringA strInputA(m_strInput);
	int result = RSA_public_decrypt(m_strInput.GetLength(),
		(unsigned char*)m_strInput.GetBuffer(),
		decrypted.data(),
		rsa,
		RSA_PKCS1_PADDING);*/


	int result = RSA_public_decrypt(m_encrypted.size(),
		m_encrypted.data(),
		decrypted.data(),
		rsa,
		RSA_PKCS1_PADDING);

#if 0  //test
	m_strDec.Format(_T("m_encpyted.size[%d] m_encrypted.data[%s], m_decypted.data[%s]"), m_encrypted.size(), m_encrypted.data(), decrypted.data());
	RSA_free(rsa);
	UpdateData(FALSE);
	return;
#endif

	if (result == -1) {
		int err_code = ERR_get_error();
		char szBuff[256];
		memset(szBuff, 0, sizeof(szBuff));
		//ERR_error_string_n(err_code, szBuff, 256);
		ERR_error_string(err_code, szBuff);

		m_strDec.Format(_T("ERR_get_error: %s"), szBuff);

	}
	else {
#if 0
		m_strDec.Format(_T("size=[%d] value=[%s]"), result, reinterpret_cast<char*>(decrypted.data()));
#else
		// 복호화된 크기 출력
		m_strDec.Format(_T("Decrypted size: %d"), result);

		// 패딩을 제거한 유효한 데이터만 사용
		// 복호화된 결과에서 유효한 부분을 추출
		std::string decrypted_str(reinterpret_cast<char*>(decrypted.data()), result);

		// UTF-8로 변환하여 출력
		m_strDec.AppendFormat(_T("\nDecrypted value: %S"), decrypted_str.c_str());

		// 유효한 부분만 잘라내어 출력
		size_t pos = decrypted_str.find("\0");  // Null terminator (혹은 복호화된 문자열의 끝을 찾음)
		if (pos != std::string::npos) {
			decrypted_str = decrypted_str.substr(0, pos);  // 유효한 부분만 잘라내기
		}

		// 복호화된 메시지 출력
		m_strDec.AppendFormat(_T("\nValid Decrypted value: %S"), decrypted_str.c_str());

#endif
	}

	RSA_free(rsa);


	UpdateData(FALSE);
}


void CKUtil1Dlg::OnBnClickedButtonGen()
{
	std::pair<CString, CString> pkeys = generate_rsa_keypair();
	m_pubKey = pkeys.first;
	m_privKey = pkeys.second;

	m_strPubkey = m_pubKey;
	m_strPrivKey = m_privKey;

	UpdateData(FALSE);
}
