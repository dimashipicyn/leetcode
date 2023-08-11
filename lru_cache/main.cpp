#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <list>

class LRUCache
{
public:
    LRUCache(int capacity)
        : capacity_(capacity)
    {
        data_.reserve(capacity);
    }

    int get(int key)
    {
        auto it = data_.find(key);
        if (it != data_.end())
        {
            Key key = std::move(*it->second.queueItem);
            queue_.push_front(key);
            queue_.erase(it->second.queueItem);

            it->second.queueItem = queue_.begin();

            return it->second.data;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if (auto it = data_.find(key); it != data_.end())
        {
            Key key = std::move(*it->second.queueItem);
            queue_.push_front(key);
            queue_.erase(it->second.queueItem);
            
            it->second.data = value;
            it->second.queueItem = queue_.begin();
        }
        else
        {
            if (data_.size() == capacity_)
            {
                auto back_element = std::move(queue_.back());
                queue_.pop_back();

                data_.erase(back_element);
            }

            queue_.push_front(key); 

            DataItem item;
            item.data = value;
            item.queueItem = queue_.begin();

            data_[key] = item;
        }
    }

private:
    int capacity_;

    using Key = int;

    using QueueItem = std::list<Key>::iterator;
    std::list<Key> queue_;

    struct DataItem
    {
        int data = 0;
        QueueItem queueItem;
    };

    std::unordered_map<Key, DataItem> data_;
};

int main()
{
    LRUCache lRUCache(2);

    lRUCache.put(2, 1);
    lRUCache.put(1, 1);
    lRUCache.put(2, 3);
    lRUCache.put(4, 1);

    std::cout << lRUCache.get(1) << std::endl;
    std::cout << lRUCache.get(2) << std::endl;

    std::cout << sizeof(std::list<int>) << std::endl;
}