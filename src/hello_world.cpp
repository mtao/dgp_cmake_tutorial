#include <iostream>
#include "localization.hpp"
#include <boost/filesystem.hpp>

std::string get_dir(const std::string& str) {
    using namespace boost::filesystem;
    path p(str);
    if(exists(p)) {
        return canonical(p.parent_path()).string();
    } else {
        return "UNKNOWN?";
    }

}

int main(int argc, char * argv[])
{
    std::string dir = get_dir(argv[0]);
    std::cout << "From [" << dir << "]: world!" << std::endl;
    std::cout << "I know some languages!" << std::endl;
    for(auto&& lang: available_langs()) {
        std::cout << get_hello(lang) << " world!" << std::endl;
    }
    return 0;
}

