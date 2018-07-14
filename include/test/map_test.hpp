#include "map_base/map_check.hpp"
#include <string>
#include <functional>


namespace WMJTask {
/**
 * @brief 用于检查map编写的各种insert方法是否正确
 * 会使用at方法检查下标插入的正确性 
 * @param yourmap 需要测试的map实例
 * @return true 测试通过
 * @return false 测试不通过
 */
bool mapInsertTest(::WMJTask::mapInterface < ::std::string, int> &yourmap);

/**
 * @brief 基于c++11的计时函数
 * 使用样例
 * cout << timeCount([&a,&b](){
 *      testFunc(a,b);
 *      testFunc2(a,b);
 * }) << endl;
 * @param func 待测试的函数类
 * @return double 测试函数执行的时间，单位为秒
 */
double timeCount(const std::function<void()> &func);

/**
 * @brief 计算一个map的插入和查询的性能
 * 
 * @param yourmap 用于测试的map
 * @return double 程序运行的时间，如果程序有误，会返回-1.0
 */
double mapPerformanceTest(::WMJTask::mapInterface<int, int> &yourmap);

} // namespace WMJTask