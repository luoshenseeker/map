#pragma once
#include  <utility> // ::std::pair
#include <string> // ::std::string
namespace WMJTask {
template <typename Key_t,
          typename Value_t>
class mapInterface {
public:
    /**
     * @brief 插入一个新的元组
     * 返回值为是否插入成功
     * 如果插入的key已经存在，返回false不改变状态
     * 否则返回true且插入新的对
     * @param pair 待插入的元组
     */
    virtual bool insert(const ::std::pair<Key_t, Value_t> &pair) = 0;

    /**
     * @brief 插入一个新的元组
     * 返回值为是否插入成功
     * 如果插入的key已经存在，返回false不改变状态
     * 否则返回true且插入新的对
     * @param key 寻址用的key
     * @param value 对应的值
     */
    virtual bool insert(const Key_t &key, const Value_t &value) = 0;

    /**
     * @brief 获取一个下标的元素
     * 如果下标在map中不存在，那么就创建他，创建调用默认的构造函数
     * @param key 下标
     * @return Value_t& 下标对应的元素
     */
    virtual Value_t &operator [](const Key_t &key) = 0;

    /**
     * @brief 获取一个下标的元素
     * 如果下标元素不存在，抛出异常
     * 抛出异常选做
     * @param key 下标元素
     * @return Value_t& 下标对应元素
     */
    virtual Value_t &at(const Key_t &key) = 0;

    /**
     * @brief 检查map中是否存在对应的下标元素
     *
     * @param key 下标元素
     * @return true 下标元素对应的对存在
     * @return false 下标元素对应的对不存在
     */
    virtual const bool has(const Key_t &key) = 0;

    /**
     * @brief 获取当前map中所有元素对的数量
     *
     * @return const int 元素数量
     */
    virtual const int size() = 0;

    /**
     * @brief 删除一个下标对应的对
     *
     * @param key 需要删除的下标
     * @return true 删除成功
     * @return false 删除失败,或者元素不存在
     */
    virtual bool erase(const Key_t &key) = 0;

    /**
     * @brief 在这里填入你的名字
     * 
     * @return ::std::string 
     */
    virtual ::std::string author() = 0;
};

} // namespace WMJTask