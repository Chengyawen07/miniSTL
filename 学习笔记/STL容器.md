# **STL 容器分类及对比**

C++ STL（标准模板库）中的容器主要分为两大类：

1. **顺序容器（Sequence Containers）**：数据按存入顺序存储，支持按顺序访问。
2. **关联容器（Associative Containers）**：数据通过**键值对**存储，支持高效查找、排序。

------

## **1. 顺序容器（Sequence Containers）**

**特点**：

- 存储数据时**按插入顺序**排列。
- 适用于需要**按索引访问**或**顺序遍历**的场景。

### **（1）常见顺序容器**

| 容器           | 结构         | 访问方式                         | 适用场景                     |
| -------------- | ------------ | -------------------------------- | ---------------------------- |
| `vector`       | 动态数组     | **随机访问 O(1)**                | 需要高效**随机访问**         |
| `deque`        | 双端队列     | **随机访问 O(1)**                | 需要**两端高效插入删除**     |
| `list`         | 双向链表     | **不支持随机访问**，只能顺序遍历 | 频繁**中间插入/删除**        |
| `forward_list` | 单向链表     | **只能前向遍历**                 | 内存占用小，适合**简单链表** |
| `array`        | 固定大小数组 | **随机访问 O(1)**                | 需要**定长数组**，性能稳定   |

### **（2）顺序容器的使用**

#### **1️⃣ `vector`（动态数组，支持随机访问）**

**特点**：

- **支持索引**访问，`v[i]` **O(1)**
- 插入 `push_back()` 快，`insert()` 慢
- 适用于：**元素动态增长，但不频繁插入删除**

**示例**：

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3};
    v.push_back(4); // 尾部插入
    v.pop_back();   // 删除最后一个元素
    v.insert(v.begin(), 0); // 头部插入（慢）

    for (int num : v) {
        std::cout << num << " "; // 输出: 0 1 2 3
    }
}
```

#### **2️⃣ `deque`（双端队列，两端操作快）**

**特点**：

- **支持索引**访问，`d[i]` **O(1)**
- **头部/尾部插入删除快**
- 适用于：**频繁从头/尾插入数据**

**示例**：

```cpp
#include <iostream>
#include <deque>

int main() {
    std::deque<int> d = {2, 3, 4};
    d.push_front(1); // 头部插入
    d.push_back(5);  // 尾部插入
    d.pop_front();   // 头部删除

    for (int num : d) {
        std::cout << num << " "; // 输出: 2 3 4 5
    }
}
```

#### **3️⃣ `list`（双向链表，中间插入快）**

**特点**：

- **不支持索引访问**，**只能遍历**
- **中间插入/删除 O(1)**（比 `vector` 快）
- 适用于：**需要频繁插入/删除，但不关心随机访问**

**示例**：

```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> lst = {2, 3, 4};
    lst.push_front(1); // 头部插入
    lst.push_back(5);  // 尾部插入
    lst.insert(++lst.begin(), 10); // 在第二个位置插入

    for (int num : lst) {
        std::cout << num << " "; // 输出: 1 2 10 3 4 5
    }
}
```

#### **4️⃣ `forward_list`（单向链表，轻量）**

**特点**：

- **只能前向遍历**（比 `list` 轻量）
- 适用于：**内存紧张的场景，如嵌入式系统**

**示例**：

```cpp
#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> fl = {2, 3, 4};
    fl.push_front(1); // 头部插入

    for (int num : fl) {
        std::cout << num << " "; // 输出: 1 2 3 4
    }
}
```

------

## **2. 关联容器（Associative Containers）**

**特点**：

- **基于二叉搜索树（红黑树）** 或 **哈希表**
- **自动排序（红黑树）或无序存储（哈希）**
- 适用于**高效查找、排序、键值映射**

### **（1）常见关联容器**

| 容器            | 结构   | 访问方式           | 适用场景                 |
| --------------- | ------ | ------------------ | ------------------------ |
| `set`           | 红黑树 | **有序，O(log n)** | **唯一**键，自动排序     |
| `multiset`      | 红黑树 | **有序，O(log n)** | **允许重复**键           |
| `map`           | 红黑树 | **有序，O(log n)** | **键值对存储**，按键排序 |
| `multimap`      | 红黑树 | **有序，O(log n)** | **允许重复键**           |
| `unordered_set` | 哈希表 | **无序，O(1)**     | **唯一键，查询快**       |
| `unordered_map` | 哈希表 | **无序，O(1)**     | **键值对，查询快**       |

------

### **（2）关联容器的使用**

#### **1️⃣ `set`（有序集合，不重复）**

**特点**：

- **有序存储**
- **自动去重**
- 适用于：**去重、自动排序**

**示例**：

```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> s = {3, 1, 4, 2, 3};
    s.insert(5);

    for (int num : s) {
        std::cout << num << " "; // 输出: 1 2 3 4 5
    }
}
```

#### **2️⃣ `map`（有序键值对）**

**特点**：

- **按键排序**
- **O(log n) 查询**
- 适用于：**需要排序的键值映射**

**示例**：

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> scores;
    scores["Alice"] = 90;
    scores["Bob"] = 85;

    for (const auto &p : scores) {
        std::cout << p.first << ": " << p.second << std::endl;
    }
}
```

#### **3️⃣ `unordered_map`（无序键值对，查找快）**

**特点**：

- **基于哈希表**
- **O(1) 查找**
- 适用于：**高效查询，无需排序**

**示例**：

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> scores;
    scores["Alice"] = 90;
    scores["Bob"] = 85;

    std::cout << "Alice's score: " << scores["Alice"] << std::endl;
}
```

------

## **总结：顺序 vs. 关联容器**

| 类型     | 访问方式    | 插入删除                                       | 查找            | 是否排序 |
| -------- | ----------- | ---------------------------------------------- | --------------- | -------- |
| 顺序容器 | 按存入顺序  | `list` 快，`vector` 慢                         | O(n)            | ❌        |
| 关联容器 | 按 key 查找 | O(log n) (`set`/`map`)，O(1) (`unordered_map`) | O(log n) / O(1) | ✅        |



