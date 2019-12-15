#include "localization.hpp"
#include "hello_map.hpp"
#include <algorithm>

std::string get_hello(const std::string& str)
{
    return hello_map.at(str);
}

std::set<std::string> available_langs()
{
    std::set<std::string> ret;
    std::transform(hello_map.begin(),hello_map.end(),std::inserter(ret,ret.end()),
                [](auto&& pr) {
                auto&& [lang,str] = pr;
                return lang;
                });
    return ret;
}
