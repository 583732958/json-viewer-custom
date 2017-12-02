#include "array_custom_format.h"
#include "json.h"

array_custom_format::array_custom_format(void)
{
}


array_custom_format::~array_custom_format(void)
{
}

bool array_custom_format::OnReceiveStream(char c)
{
	switch (c)
	{
	case '[':
		m_lst_character_ = LST_CHARACTER_LEFT_ZHONGKUOHAO;
		break;
	case ']':
		m_lst_character_ = LST_CHARACTER_RIGHT_ZHONGKUOHAO;
		break;
	case '{':
		m_lst_character_ = LST_CHARACTER_LEFT_DAKUOHAO;
		break;
	case '}':
		m_lst_character_ = LST_CHARACTER_RIGHT_DAKUOHAO;
		break;
	default:
		break;
	}

	return true;
}

bool array_custom_format::OnBeforeProcessTheComma(rcstring *output, int nIndentation)
{
	extern rstring_code rcs_catcs (rcstring * pre, const char *pos, const size_t length);
	extern rstring_code rcs_catc (rcstring * pre, const char c);

	static long nTheCommaCount = 0;
	if(m_lst_character_ != LST_CHARACTER_LEFT_ZHONGKUOHAO)
	{
		nTheCommaCount = 0;
		return false;
	}
	
	nTheCommaCount++;
	if ((nTheCommaCount%32)!=0)
	{
		rcs_catcs (output, ", ", 2);
	}
	else
	{
		rcs_catcs (output, ",\n", 2);
		for (auto i = 0; i < nIndentation; i++)
		{
			rcs_catc (output, '\t');
		}
	}
	return true;
}
