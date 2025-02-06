## STL 基础概念和组成

STL（Standard Template Library，标准模板库）是 C++ 标准库的重要组成部分，它提供了许多数据结构和算法，使得开发者可以高效地进行数据处理。

------



## **1. STL 组成**

STL 主要由 **六大组件** 组成：

1. **容器（Container）**：如 `vector`、`list`、`map` 等，用于存储数据。
2. **算法（Algorithm）**：如 `sort`、`find`、`for_each` 等，用于处理数据。
3. **迭代器（Iterator）**：用于遍历容器中的元素，如 `vector<int>::iterator`。
4. **仿函数（Function Object）**：类似函数的对象，可以作为参数传递，如 `greater<int>()`。
5. **适配器（Adapter）**：对容器、迭代器、仿函数进行修改，如 `stack`、`queue`。
6. **空间配置器（Allocator）**：管理内存分配，如 `std::allocator`。





## **2. STL 常见容器**

### **（1）序列式容器**

按存储顺序组织数据：

- `vector`：动态数组，支持随机访问，插入/删除慢。
- `deque`：双端队列，两端都可快速插入/删除。
- `list`：双向链表，支持高效插入/删除，但不支持随机访问。

**示例：vector 的基本操作**

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    v.push_back(6);   // 在末尾添加元素
    v.pop_back();     // 删除末尾元素
    v.insert(v.begin(), 0);  // 在开头插入 0
    v.erase(v.begin());      // 删除开头元素

    for (int num : v) {
        std::cout << num << " ";
    }
    return 0;
}
```

