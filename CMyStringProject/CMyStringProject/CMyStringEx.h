#pragma once
#include "CMyString.h"

class CMyStringEx : public CMyString
{
public:
	CMyStringEx();
	~CMyStringEx();
	
	void setData(const char* pParam);
};

