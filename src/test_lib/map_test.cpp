#include "test/map_test.hpp"
#include <iostream>
#include <chrono>

namespace WMJTask {

using ::std::cout;
using ::std::endl;

double timeCount(const std::function<void()> &func) {
    auto start = ::std::chrono::system_clock::now();
    func();
    auto end   = ::std::chrono::system_clock::now();
    auto duration = ::std::chrono::duration_cast<::std::chrono::microseconds>(end - start);
    return double(duration.count()) * ::std::chrono::microseconds::period::num / ::std::chrono::microseconds::period::den;
}

bool mapInsertTest(::WMJTask::mapInterface<::std::string, int> &yourmap) {
    if(!yourmap.insert(std::make_pair("10", 9))) {
        cout << "插入pair失败" << endl;
        return false;
    } else if(yourmap.at("10") != 9) {
        cout << "插入pair失败" << endl;
        return false;
    } else if(yourmap.insert("10", 7) || yourmap.at("10") == 7) {
        cout << "插入重复数据" << endl;
        return false;
    } else if(yourmap.size() != 1) {
        cout << "size计算错误" << endl;
        return false;
    } else {
        return true;
    }
}

double mapPerformanceTest(::WMJTask::mapInterface<int, int> &yourmap) {
    bool result = true;
    auto time = timeCount([&yourmap, &result]() {
        for(int i = 0; i < 1000; ++i) {
            yourmap.insert(std::make_pair(i, i));
        }
        for(int i = 0; i < yourmap.size(); ++i) {
            if(yourmap.at(i) != i) {
                cout << "map映射错误" << endl;
                result = false;
                return;
            } else {
                yourmap.at(i) = 10;
                if(yourmap[i] != 10) {
                    cout << "修改数据失败" << endl;
                    result = false;
                    return;
                }
            }
        }
    });
    if(result) {
        return time;
    } else {
        return -1.0;
    }
}
} // namespace WMJTask
