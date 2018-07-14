#include "test/map_test.hpp"
#include <iostream>

namespace WMJTask {

using ::std::cout;
using ::std::endl;
bool mapInsertTest(::WMJTask::mapInterface < ::std::string, int> &yourmap) {
    yourmap.insert(std::make_pair("10", 9));
    if(yourmap.at("10") != 9) {
        cout << "插入pair失败" << endl;
        return false;
    }

    if(yourmap.insert("10", 9)) {
        cout << "插入重复数据" << endl;
        return false;
    }
    return true;
}
} // namespace WMJTask
