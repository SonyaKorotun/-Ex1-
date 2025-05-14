#include "Str.h"
#include <string.h>

_str::_str() {
	m_pszData = new char[1] {0}; m_nCount = 1;
}

_str::_str(const char* p) {
	m_nCount = 1;
	m_pszData = new char[strlen(p) + 1];
	strcpy_s(m_pszData, strlen(p) + 1, p);
}

_str::~_str() { 
	delete[] m_pszData; 
}

void _str::AddRef() { 
	m_nCount++; 
}

void _str::Release() { 
	m_nCount--; 
	if (m_nCount == 0) 
		delete this; 
}

Str::Str() { 
	m_pStr = new _str(); 
}

Str::Str(const char* p) {
	m_pStr = new _str(p);
}

Str::Str(const Str& s) {
	m_pStr = s.m_pStr;
	m_pStr->AddRef();
}

Str::~Str() {
	m_pStr->Release();
}

Str& Str::operator = (const Str& s) {
	if (this != &s) {
		s.m_pStr->AddRef();
		m_pStr->Release();
		m_pStr = s.m_pStr;
	}
	return *this;
}

Str& Str::operator+ (const Str& s) {
	int length = len() + s.len();
	if (s.len() != 0) {
		_str* pstrTmp = new _str();
		delete[] pstrTmp->m_pszData;
		pstrTmp->m_pszData = new char[length + 1];
		strcpy_s(pstrTmp->m_pszData, length + 1, m_pStr->m_pszData);
		strcat_s(pstrTmp->m_pszData, length + 1, s.m_pStr->m_pszData);
		m_pStr->Release();
		m_pStr = pstrTmp;
	}
	return *this;
}

int Str::len() const {
	return strlen(m_pStr->m_pszData);
}
