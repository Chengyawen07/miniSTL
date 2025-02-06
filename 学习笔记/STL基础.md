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

### （2）关联式容器

基于 **二叉搜索树（红黑树）** 或 **哈希表** 组织数据：

- `set` / `multiset`：自动排序，不允许/允许重复元素。
- `map` / `multimap`：键值对存储，默认按键排序。
- `unordered_set` / `unordered_map`：基于哈希表，无序访问，查找快。

**示例：map 的基本操作**

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> students;
    students["Alice"] = 90;
    students["Bob"] = 85;
    students["Charlie"] = 92;

    for (const auto &pair : students) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }

    return 0;
}
```

**特点**：

- `map` 默认按 key 递增排序。
- `unordered_map` 基于哈希表，插入和查找更快，但无序。

------



## **3. 迭代器（Iterator）**

用于遍历容器，如 `begin()` 和 `end()`。 **迭代器种类**：

- **输入迭代器**：`istream_iterator`
- **输出迭代器**：`ostream_iterator`
- **前向迭代器**：`forward_list`
- **双向迭代器**：`list`
- **随机访问迭代器**：`vector`、`deque`

**示例：使用迭代器遍历 vector**

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    
    std::vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    
    return 0;
}
```

------

## **4. STL 常用算法**

STL 提供了一系列算法，如：

- **查找算法**：`find`、`binary_search`
- **排序算法**：`sort`、`stable_sort`
- **变换算法**：`for_each`、`transform`
- **数值算法**：`accumulate`
- **集合算法**：`set_union`、`set_intersection`

**示例：使用 `sort` 排序**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {5, 3, 8, 1, 6};
    
    std::sort(nums.begin(), nums.end()); // 默认升序排序

    for (int num : nums) {
        std::cout << num << " ";
    }
    return 0;
}
```

**示例：使用 `find` 查找元素**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {10, 20, 30, 40, 50};
    auto it = std::find(nums.begin(), nums.end(), 30);
    
    if (it != nums.end()) {
        std::cout << "Found: " << *it << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
    return 0;
}
```

------

## **5. STL 适配器（Adapter）**

**简单理解**：适配器就是**“改装”STL组件**，让它们更适合某些场景的工具。

**STL 适配器的作用**：

- **改变容器行为**（如 `stack`、`queue`）。
- **修改函数行为**（如 `not1` 取反）。
- **让普通函数变成 STL 能用的函数**（如 `ptr_fun`）。

### **（1）容器适配器**

- `stack`（栈）：先进后出（LIFO）
- `queue`（队列）：先进先出（FIFO）
- `priority_queue`（优先队列）：自动排序。

**示例：使用 `stack`**

```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Top: " << s.top() << std::endl;
    s.pop();
    std::cout << "Top after pop: " << s.top() << std::endl;

    return 0;
}
```

### **（2）仿函数适配器**

STL 内建仿函数：

- **算术仿函数**：`plus<int>`、`minus<int>`、`multiplies<int>`
- **关系仿函数**：`greater<int>`、`less<int>`
- **逻辑仿函数**：`logical_and<bool>`、`logical_or<bool>`。

**示例：使用 `greater<int>` 排序**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    std::vector<int> nums = {5, 3, 8, 1, 6};
    
    std::sort(nums.begin(), nums.end(), std::greater<int>()); // 降序排序

    for (int num : nums) {
        std::cout << num << " ";
    }
    return 0;
}
```

------



### 6. **仿函数（Function Object）**

**简单理解**：仿函数就是**“像函数一样使用的对象”**。它本质上是一个**重载了 `operator()` 的类**，可以像普通函数一样被调用。

**为什么要用仿函数？**

- 普通函数是固定的，仿函数可以**存储状态**。
- 结合 STL **算法（如 `sort`）** 进行灵活的定制。



### **7. 空间配置器（Allocator）**

**简单理解**：STL 容器默认使用 **`std::allocator<T>`** 来**管理内存分配和释放**。

**为什么需要空间配置器？**

- `new`/`delete` 申请释放内存会调用系统 API，效率较低。
- 空间配置器**预分配**一块大内存，按需管理，减少 `malloc/free` 开销，提高性能。

