#pragma once
#include <string>
class queue_string :
	public std::string
{
public:
	explicit queue_string(int nCapacityLen=256);
	~queue_string(void);
public:
	void push_back(char c);
private:
	int m_nCapacityLen;
};

