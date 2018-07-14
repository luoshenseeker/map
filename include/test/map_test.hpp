#include "map_base/map_check.hpp"
#include <string>


namespace WMJTask {
/**
 * @brief 用于检查map编写的各种insert方法是否正确
 * 会使用at方法检查下标插入的正确性 
 * @param yourmap 需要测试的map实例
 * @return true 测试通过
 * @return false 测试不通过
 */
bool mapInsertTest(::WMJTask::mapInterface < ::std::string, int> &yourmap);

} // namespace WMJTask