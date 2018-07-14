#pragma once
#include <map_base/map_interface.hpp>


namespace WMJTrain {

template <typename Key_t, // 下标类型
          typename Value_t> // 值类型
          
class map : public WMJTask::mapInterface<Key_t, Value_t>  {
// 写在这里
};

} // namespace WMJTrain
