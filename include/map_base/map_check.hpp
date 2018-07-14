#include "map_interface.hpp"
#include <map> // ::std::map

namespace WMJTask {
template <typename Key_t,
          typename Value_t>
class mapCheck : public mapInterface<Key_t, Value_t> {
private:
    // 引用std::map本体作为实现
    ::std::map<Key_t, Value_t> base;
public:
    mapCheck() {}
    ~mapCheck() {}

    virtual bool insert(const ::std::pair<Key_t, Value_t> &pair) {
        return this->base.insert(pair).second;
    }

    virtual bool insert(const Key_t &key, const Value_t &value) {
        return this->base.insert(::std::make_pair(key, value)).second;
    }

    Value_t &operator [](const Key_t &key) {
        return this->base[key];
    }

    Value_t &at(const Key_t &key) {
        return this->at(key);
    }

    const bool has(const Key_t &key) {
        return this->base.find(key) == this->base.end();
    }

    const int size() {
        return this->base.size();
    }

    bool erase(const Key_t &key) {
        if(this->has(key)) {
            this->base.erase(key);
            return !this->has(key);
        } else {
            return false;
        }
    }
};
} // namespace WMJTask