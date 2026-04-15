#pragma once
#include "CMyString.h"

class CMyStringEx : public CMyString
{
public:
	CMyStringEx();
	explicit CMyStringEx(const char* param);
	~CMyStringEx();
	
	void setData(const char* pParam);
};

