#pragma once
#include "json.h"

enum LST_CHARACTER
{
	LST_CHARACTER_LEFT_DAKUOHAO,
	LST_CHARACTER_RIGHT_DAKUOHAO,
	LST_CHARACTER_LEFT_ZHONGKUOHAO,
	LST_CHARACTER_RIGHT_ZHONGKUOHAO,
	LST_CHARACTER_OTHER
};

class array_custom_format
{
public:
	array_custom_format(void);
	~array_custom_format(void);
public:
	bool OnReceiveStream(char c);
	bool OnBeforeProcessTheComma(rcstring *output, int nIndentation);

private:
	LST_CHARACTER m_lst_character_;
};

