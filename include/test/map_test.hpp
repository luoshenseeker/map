#include "map_base/map_check.hpp"
#include <string>


namespace WMJTask {

bool mapTest(::WMJTask::mapInterface < ::std::string, int> &yourmap) {
    yourmap.insert(std::make_pair("10", 10));
    yourmap["10"] = 9;
    return true;
}

} // namespace WMJTask