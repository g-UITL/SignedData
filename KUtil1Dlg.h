
// KUtil1Dlg.h: 헤더 파일
//

#pragma once

#include "openssl_1.1.1k/include/openssl/rsa.h"
#include "openssl_1.1.1k/include/openssl/pem.h"
#include "openssl_1.1.1k/include/openssl/err.h"
#include <vector>
#include <string>
#include <cstring>
#include <locale.h>


// CKUtil1Dlg 대화 상자
class CKUtil1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CKUtil1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KUTIL1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_strEnc;
	CString m_strDec;
	CString m_strPlain;
	CString m_strInput;


	CString m_pubKey, m_privKey;

	std::vector<unsigned char> m_encrypted;

	std::pair<CString, CString> generate_rsa_keypair(int bits = 2048);
	afx_msg void OnBnClickedButtonDec();
	CString m_strPubkey;
	CString m_strPrivKey;
	afx_msg void OnBnClickedButtonGen();
};
