#include "custom_cfg.h"
#include <boost/property_tree/ptree_fwd.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>


custom_cfg::custom_cfg(void)
{
}


custom_cfg::~custom_cfg(void)
{
}

bool custom_cfg::load_cfg()
{
	using namespace boost::property_tree;

	ptree root;
	read_json<ptree>("cfg.json", root);

	auto startWithItems = root.get_child("startWith");
	BOOST_FOREACH(auto it,startWithItems)
	{
		vecStartWith.push_back(it.second.get_value<std::string>());
	}

	auto headItems = root.get_child("head");
	BOOST_FOREACH(auto it,headItems)
	{
		vecHead.push_back(it.second.get_value<std::string>());
	}

	return true;
}

bool custom_cfg::is_startWith(const std::string& str)
{
	auto found = std::find_if(vecStartWith.begin(),vecStartWith.end(),[=](std::string s){return str.find(s)==0;});
	return found!=vecStartWith.end();
}
