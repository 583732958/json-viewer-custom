#include "queue_string.h"


queue_string::queue_string(int nCapacityLen)
{
	m_nCapacityLen = nCapacityLen;
}


queue_string::~queue_string(void)
{
}

void queue_string::push_back(char c)
{
	std::string::push_back(c);
	if(std::string::length()>m_nCapacityLen)
	{
		std::string::erase(0);
	}
}
