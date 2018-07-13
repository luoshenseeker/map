#pragma once
#include  <utility> // ::std::pair
namespace WMJTask {

template <typename Key_t,
          typename Value_t>
class mapInterface {
public:
    /**
     * @brief 插入一个新的元组
     * 返回值为是否插入成功
     * @param pair 待插入的元组
     */
    virtual bool insert(const ::std::pair<Key_t, Value_t> &pair) = 0;

    /**
     * @brief 插入一个新的元组
     * 返回值为是否插入成功
     * @param key 寻址用的key
     * @param value 对应的值
     */
    virtual bool insert(const Key_t &key, const Value_t &value) = 0;
};

} // namespace WMJTask