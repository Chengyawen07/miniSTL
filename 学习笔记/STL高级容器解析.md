## **C++ STL 高级容器解析：`multiset`、`multimap`、`unordered_multiset`、`unordered_multimap`**

------

这些容器是 **关联式容器（Associative Containers）** 的扩展，主要特点是：

- **允许重复键（Multiple Keys）**
- **提供高效查找**
- `unordered_` 版本使用哈希表，`set/map` 版本使用红黑树（RB-Tree）。

下面，我们逐个解析它们的**用途、特点、常见操作**，并附上**代码示例**。

------

## **1️⃣ `multiset`（允许重复元素的有序集合）**

### ✅ **用途**

- **存储有序集合**，**允许重复元素**（与 `set` 的区别）。
- **适用于统计重复元素的情况**，如存储考试成绩、单词频率等。

### 🔹 **主要特点**

| 特性               | `set`      | `multiset` |
| ------------------ | ---------- | ---------- |
| **是否允许重复值** | ❌ 否       | ✅ 允许     |
| **默认排序方式**   | ✅ 从小到大 | ✅ 从小到大 |
| **查找效率**       | `O(log n)` | `O(log n)` |

### 🔹 **常见操作**

| 操作         | 语法                                               |
| ------------ | -------------------------------------------------- |
| 插入         | `mset.insert(val);`                                |
| 删除         | `mset.erase(val);`（删除所有匹配项）               |
| 统计元素个数 | `mset.count(val);`                                 |
| 查找         | `mset.find(val);`                                  |
| 范围查找     | `mset.lower_bound(val);`、`mset.upper_bound(val);` |

### 🔹 **示例代码**

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> mset = {10, 20, 20, 30, 30, 30};

    mset.insert(20);  // 插入 20
    mset.erase(30);   // 删除所有 30

    std::cout << "20 的个数: " << mset.count(20) << std::endl; // 输出 3

    for (int num : mset) {
        std::cout << num << " ";  // 输出: 10 20 20 20
    }

    return 0;
}
```

------



## **2️⃣ `multimap`（允许重复键的有序映射）**

### ✅ **用途**

- **存储键值对（Key-Value），但允许重复键**。
- 适用于存储一个键对应多个值的情况，例如：
  - **学生和多个考试成绩**
  - **公司和多个雇员**

### 🔹 **主要特点**

| 特性               | `map`         | `multimap`    |
| ------------------ | ------------- | ------------- |
| **是否允许重复键** | ❌ 否          | ✅ 允许        |
| **默认排序方式**   | ✅ 按 key 排序 | ✅ 按 key 排序 |
| **查找效率**       | `O(log n)`    | `O(log n)`    |

### 🔹 **常见操作**

| 操作                  | 语法                                          |
| --------------------- | --------------------------------------------- |
| 插入                  | `mmap.insert({key, val});`                    |
| 删除                  | `mmap.erase(key);`（删除所有相同 key）        |
| 查找                  | `mmap.find(key);`（返回第一个匹配项的迭代器） |
| 统计某个 key 出现次数 | `mmap.count(key);`                            |

### 🔹 **示例代码**

```cpp
#include <iostream>
#include <map>

int main() {
    std::multimap<std::string, int> mmap;

    mmap.insert({"Alice", 90});
    mmap.insert({"Alice", 85});
    mmap.insert({"Bob", 78});

    std::cout << "Alice 的成绩:" << std::endl;
    auto range = mmap.equal_range("Alice");
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->second << " ";  // 输出: 90 85
    }

    return 0;
}
```

------



## **3️⃣ `unordered_multiset`（允许重复元素的无序集合）**

### ✅ **用途**

- **存储无序集合**，但允许**重复元素**。
- 适用于**不需要排序**，但**查询需要高效**的情况。

### 🔹 **主要特点**

| 特性               | `unordered_set`      | `unordered_multiset` |
| ------------------ | -------------------- | -------------------- |
| **是否允许重复值** | ❌ 否                 | ✅ 允许               |
| **底层数据结构**   | 哈希表（Hash Table） | 哈希表（Hash Table） |
| **查找效率**       | `O(1)`               | `O(1)`               |
| **是否有序**       | ❌ 无序               | ❌ 无序               |

### 🔹 **常见操作**

| 操作         | 语法                                  |
| ------------ | ------------------------------------- |
| 插入         | `umset.insert(val);`                  |
| 删除         | `umset.erase(val);`（删除所有匹配项） |
| 统计元素个数 | `umset.count(val);`                   |
| 查找         | `umset.find(val);`                    |

### 🔹 **示例代码**

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_multiset<int> umset = {10, 20, 20, 30, 30, 30};

    umset.insert(40);
    umset.erase(30);  // 删除所有 30

    std::cout << "20 的个数: " << umset.count(20) << std::endl; // 输出 2

    for (int num : umset) {
        std::cout << num << " ";  // 无序输出
    }

    return 0;
}
```

------



## **4️⃣ `unordered_multimap`（允许重复键的无序映射）**

### ✅ **用途**

- **存储无序键值对（Key-Value），允许重复键**。
- 适用于高效查询，但不需要排序的情况，如：
  - **标签分类（一个标签对应多个内容）**
  - **日志系统（多个相同时间戳的日志记录）**

### 🔹 **主要特点**

| 特性               | `unordered_map`      | `unordered_multimap` |
| ------------------ | -------------------- | -------------------- |
| **是否允许重复键** | ❌ 否                 | ✅ 允许               |
| **底层数据结构**   | 哈希表（Hash Table） | 哈希表（Hash Table） |
| **查找效率**       | `O(1)`               | `O(1)`               |
| **是否有序**       | ❌ 无序               | ❌ 无序               |

### 🔹 **常见操作**

| 操作                  | 语法                        |
| --------------------- | --------------------------- |
| 插入                  | `ummap.insert({key, val});` |
| 删除                  | `ummap.erase(key);`         |
| 查找                  | `ummap.find(key);`          |
| 统计某个 key 出现次数 | `ummap.count(key);`         |

### 🔹 **示例代码**

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_multimap<std::string, int> ummap;

    ummap.insert({"Alice", 90});
    ummap.insert({"Alice", 85});
    ummap.insert({"Bob", 78});

    std::cout << "Alice 的成绩:" << std::endl;
    auto range = ummap.equal_range("Alice");
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->second << " ";  // 输出: 90 85 （无序）
    }

    return 0;
}
```

------



## **总结**

| 容器                 | 是否有序 | 允许重复 | 适用场景         |
| -------------------- | -------- | -------- | ---------------- |
| `multiset`           | ✅ 有序   | ✅ 允许   | 统计重复元素     |
| `multimap`           | ✅ 有序   | ✅ 允许   | 多值映射         |
| `unordered_multiset` | ❌ 无序   | ✅ 允许   | 高效查询重复元素 |
| `unordered_multimap` | ❌ 无序   | ✅ 允许   | 高效查询多值映射 |

- **选择时：如果不关心顺序，优先使用 `unordered_` 版本，效率更高！** 



## **PS： 红黑树 vs. 哈希表 对比**

| **对比项**    | **红黑树（RB-Tree）**                  | **哈希表（Hash Table）**                                   |
| ------------- | -------------------------------------- | ---------------------------------------------------------- |
| **存储方式**  | **有序存储**（按大小排序）             | **无序存储**（哈希索引）                                   |
| **查找速度**  | `O(log n)`                             | **`O(1)`（最优），`O(n)`（最坏情况）**                     |
| **插入/删除** | `O(log n)`，自动保持平衡               | `O(1)`，但有哈希冲突时可能变慢                             |
| **范围查找**  | ✅ **支持（lower_bound, upper_bound）** | ❌ **不支持范围查找**                                       |
| **内存占用**  | **较高**（维护平衡结构）               | **较低**（直接映射到数组）                                 |
| **适用于**    | **有序存储、范围查找**（`set`、`map`） | **快速查找，无需排序**（`unordered_set`、`unordered_map`） |