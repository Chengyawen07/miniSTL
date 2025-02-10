#include <iostream>
#include <set>
#include <string>
#include <sstream>
using namespace std;


class Set{
private:
    set<int> s;  // std::set 作为底层存储

public:

    // 1. 构造函数 & 析构函数
    Set() = default;
    ~Set() = default;

    // 插入
    void insert(int val) {
        s.insert(val);
    }

    // 删除
    void erase(int val){
        s.erase(val);
    }

    // 判断元素是否存在
    bool contains(int val) const {
        return s.find(val) != s.end();
    }

    // 判断set是否为空
    bool empty() const {
        return s.empty();
    }

    size_t size() const {
        return s.size();
    }

};

int main() {
    Set mySet;
    
    // 测试 insert
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    cout << "After inserts, size: " << mySet.size() << endl;
    
    // 测试 contains
    cout << "Contains 20? " << (mySet.contains(20) ? "true" : "false") << endl;
    cout << "Contains 40? " << (mySet.contains(40) ? "true" : "false") << endl;
    
    // 测试 erase
    mySet.erase(20);
    cout << "After erase 20, contains 20? " << (mySet.contains(20) ? "true" : "false") << endl;
    cout << "Size after erase: " << mySet.size() << endl;
    
    // 测试 empty
    mySet.erase(10);
    mySet.erase(30);
    cout << "Is set empty? " << (mySet.empty() ? "true" : "false") << endl;
    
    return 0;
}
