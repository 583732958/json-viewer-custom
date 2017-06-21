#pragma once
#include <string>
#include <vector>

class custom_cfg
{
public:
	custom_cfg(void);
	~custom_cfg(void);
public:
	bool load_cfg();
public:
	bool is_startWith(const std::string& str);
private:
	std::vector<std::string> vecStartWith;
	std::vector<std::string> vecHead;
};

