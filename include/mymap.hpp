#pragma once
#include <map_base/map_interface.hpp>


namespace WMJTrain {

template <typename Key_t,
          typename Value_t>
class map : public WMJTask::mapInterface<Key_t, Value_t>  {
// 写在这里
};

} // namespace WMJTrain
