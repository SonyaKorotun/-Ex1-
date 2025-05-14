#pragma once
#include "_str.h";
class Str {
	_str* m_pStr;
public:
	Str() { m_pStr = new _str; }

	Str(const char* p) {
		m_pStr = new _str(p);
	}

	Str(const Str& s)
	{
		m_pStr = s.m_pStr;
		m_pStr->AddRef();
	}

	~Str() {
		m_pStr->Release();
	}

	int len() const {
		return strlen(m_pStr->m_pszData);
	}

	Str& operator = (const Str& s) {
		if (this != &s) {
			s.m_pStr->AddRef();
			m_pStr->Release();
			m_pStr = s.m_pStr;
		}
		return *this;
	}

	Str& operator += (const Str& s) {
		int length = len() + s.len();
		if (s.len() != 0) {
			_str* pstrTmp = new _str;
			delete[] pstrTmp->m_pszData;
			pstrTmp->m_pszData = new char[length + 1];
			strcpy_s(pstrTmp->m_pszData, length + 1, m_pStr->m_pszData);
			strcat_s(pstrTmp->m_pszData, length + 1, s.m_pStr->m_pszData);
			m_pStr->Release();
			m_pStr = pstrTmp;
		}
		return *this;
	}

	int find(const char* t, int off) const {
		if (off < 0 || off >= len()) {
			return -1;
		}

		int tLen = strlen(t);
		if (tLen == 0) {
			return off;
		}

		int i = off;
		int j = 0;
		while (i < len()) {
			if (m_pStr->m_pszData[i] == t[j]) {
				if (j == tLen - 1) {
					return i - j;
				}
				i++;
				j++;
			}
			else {
				i = i - j + 1;
				j = 0;
			}
		}

		return -1;
	}
};
