
// BTRee.h : BTRee Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CBTReeApp:
// �йش����ʵ�֣������ BTRee.cpp
//

class CBTReeApp : public CWinApp
{
public:
	CBTReeApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBTReeApp theApp;
