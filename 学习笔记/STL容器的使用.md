# **STL 各容器的使用方法、操作及用途**

C++ STL 提供了多种容器，每种容器有不同的**数据存储方式**，适用于不同场景。本文详细介绍**顺序容器**和**关联容器**的使用方法、常见操作以及适用场景。

------

# **⭐️  1. 顺序容器（Sequence Containers）**

> **特点**：
>
> - **按插入顺序**存储数据
> - **支持顺序访问**
> - **适用于**需要**动态调整大小、顺序遍历**的场景



## **1️⃣ `vector`（动态数组，支持随机访问）**

### ✅ **用途**

- **随机访问快**（O(1)）
- <u>**适用于存储大量数据，主要在尾部插入/删除**</u>
- **适合：图像处理、数据缓存、数学计算**

### 🔹 **常见操作**

| 方法               | 作用                 |
| ------------------ | -------------------- |
| `push_back(val)`   | **尾部插入**元素     |
| `pop_back()`       | **删除最后一个**元素 |
| `insert(pos, val)` | **指定位置插入**     |
| `erase(pos)`       | **删除指定位置**元素 |
| `size()`           | **获取元素个数**     |
| `clear()`          | **清空所有元素**     |
| `front()`          | **返回第一个元素**   |
| `back()`           | **返回最后一个元素** |

### 🔹 **示例代码**

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3};

    v.push_back(4);      // 插入元素
    v.pop_back();        // 删除最后一个元素
    v.insert(v.begin(), 0); // 头部插入（慢）
    
    for (int num : v) {
        std::cout << num << " "; // 输出: 0 1 2 3
    }
}
```

------



## **2️⃣ `deque`（双端队列）**

### ✅ **用途**

- **支持两端插入/删除（O(1)）**
- **适用于队列、任务调度**
- **适合：消息队列、任务调度、缓冲管理**

### 🔹 **常见操作**

| 方法              | 作用                 |
| ----------------- | -------------------- |
| `push_back(val)`  | **尾部插入**元素     |
| `push_front(val)` | **头部插入**元素     |
| `pop_back()`      | **删除最后一个**元素 |
| `pop_front()`     | **删除第一个**元素   |
| `size()`          | **获取大小**         |
| `clear()`         | **清空**             |

### 🔹 **示例代码**

```cpp
#include <iostream>
#include <deque>

int main() {
    std::deque<int> dq = {2, 3, 4};

    dq.push_front(1); // 头部插入
    dq.push_back(5);  // 尾部插入
    dq.pop_front();   // 头部删除

    for (int num : dq) {
        std::cout << num << " "; // 输出: 2 3 4 5
    }
}
```

------

## **3️⃣ `list`（双向链表）**

### ✅ **用途**

- **支持高效插入/删除（O(1)）**
- **不支持随机访问**
- **适合：频繁插入/删除，如音乐播放列表、任务调度**

### 🔹 **常见操作**

| 方法               | 作用                  |
| ------------------ | --------------------- |
| `push_back(val)`   | **尾部插入**          |
| `push_front(val)`  | **头部插入**          |
| `pop_back()`       | **删除最后一个**元素  |
| `pop_front()`      | **删除第一个**元素    |
| `insert(pos, val)` | **在 pos 位置插入**   |
| `erase(pos)`       | **删除 pos 位置元素** |

### 🔹 **示例代码**

```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> lst = {2, 3, 4};

    lst.push_front(1);
    lst.push_back(5);
    lst.insert(++lst.begin(), 10); // 在第二个位置插入

    for (int num : lst) {
        std::cout << num << " "; // 输出: 1 2 10 3 4 5
    }
}
```

------

# **⭐️ 2. 关联容器（Associative Containers）**

> **特点**：
>
> - **通过键值存储数据**
> - **查找效率高**
> - **适用于：需要高效查找、排序的场景**

## **1️⃣ `set`（有序集合，去重）**

### ✅ **用途**

- **自动排序**
- **存储唯一元素**
- **适合：去重、自动排序的数据集合**

### 🔹 **常见操作**

| 方法          | 作用                     |
| ------------- | ------------------------ |
| `insert(val)` | **插入元素（自动排序）** |
| `erase(val)`  | **删除元素**             |
| `find(val)`   | **查找元素，返回迭代器** |
| `size()`      | **获取元素个数**         |

### 🔹 **示例代码**

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

------

## **2️⃣ `map`（键值对，自动排序）**

### ✅ **用途**

- **存储键值对，按 key 自动排序**
- **O(log n) 查找**
- **适合：键值映射，如学生成绩表**

### 🔹 **常见操作**

| 方法                 | 作用                    |
| -------------------- | ----------------------- |
| `insert({key, val})` | **插入键值对**          |
| `erase(key)`         | **删除 key 对应的数据** |
| `find(key)`          | **查找 key 对应的值**   |
| `size()`             | **获取大小**            |

### 🔹 **示例代码**

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

------

## **3️⃣ `unordered_map`（无序映射，查找快）**

### ✅ **用途**

- **哈希表实现，O(1) 查找**
- **适合：高效查询，如缓存存储**

### 🔹 **示例代码**

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

## **总结**

| 容器            | 适用场景                      |
| --------------- | ----------------------------- |
| `vector`        | **动态数组**，支持随机访问    |
| `deque`         | **双端队列**，两端插入删除快  |
| `list`          | **双向链表**，中间插入删除快  |
| `set`           | **有序集合**，去重，自动排序  |
| `map`           | **有序键值映射**，按 key 查找 |
| `unordered_map` | **无序映射**，O(1) 查找       |



# **⭐️  STL 容器操作函数分类对比表**

下面是按照 **操作类型** 分类的 STL 容器函数，方便记忆和查找不同容器的相同操作。

------

### **1️⃣ 插入操作**

| 操作         | `vector`           | `deque`            | `list`             | `set`         | `map`                | `unordered_map`      |
| ------------ | ------------------ | ------------------ | ------------------ | ------------- | -------------------- | -------------------- |
| **尾部插入** | `push_back(val)`   | `push_back(val)`   | `push_back(val)`   | `insert(val)` | `insert({key, val})` | `insert({key, val})` |
| **头部插入** | ❌                  | `push_front(val)`  | `push_front(val)`  | ❌             | ❌                    | ❌                    |
| **中间插入** | `insert(pos, val)` | `insert(pos, val)` | `insert(pos, val)` | ❌             | ❌                    | ❌                    |

------

### **2️⃣ 删除操作**

| 操作             | `vector`     | `deque`       | `list`        | `set`        | `map`        | `unordered_map` |
| ---------------- | ------------ | ------------- | ------------- | ------------ | ------------ | --------------- |
| **删除尾部元素** | `pop_back()` | `pop_back()`  | `pop_back()`  | ❌            | ❌            | ❌               |
| **删除头部元素** | ❌            | `pop_front()` | `pop_front()` | ❌            | ❌            | ❌               |
| **删除指定元素** | `erase(pos)` | `erase(pos)`  | `erase(pos)`  | `erase(val)` | `erase(key)` | `erase(key)`    |
| **清空容器**     | `clear()`    | `clear()`     | `clear()`     | `clear()`    | `clear()`    | `clear()`       |

------

### **3️⃣ 访问元素**

| 操作                 | `vector`  | `deque`   | `list`    | `set`           | `map`             | `unordered_map`   |
| -------------------- | --------- | --------- | --------- | --------------- | ----------------- | ----------------- |
| **获取第一个元素**   | `front()` | `front()` | `front()` | ❌               | `begin()->first`  | `begin()->first`  |
| **获取最后一个元素** | `back()`  | `back()`  | `back()`  | ❌               | `rbegin()->first` | `rbegin()->first` |
| **访问指定元素**     | `v[i]`    | `d[i]`    | ❌         | **`find(val)`** | **`map[key]`**    | **`umap[key]`**   |

------

### **4️⃣ 迭代器支持**

| 操作               | `vector`              | `deque`               | `list`                | `set`                 | `map`                 | `unordered_map` |
| ------------------ | --------------------- | --------------------- | --------------------- | --------------------- | --------------------- | --------------- |
| **获取头部迭代器** | `begin()`             | `begin()`             | `begin()`             | `begin()`             | `begin()`             | `begin()`       |
| **获取尾部迭代器** | `end()`               | `end()`               | `end()`               | `end()`               | `end()`               | `end()`         |
| **反向迭代器**     | `rbegin()` / `rend()` | `rbegin()` / `rend()` | `rbegin()` / `rend()` | `rbegin()` / `rend()` | `rbegin()` / `rend()` | ❌               |

------

### **5️⃣ 查找操作**

| 操作         | `vector`                         | `deque`                          | `list`                           | `set`        | `map`        | `unordered_map` |
| ------------ | -------------------------------- | -------------------------------- | -------------------------------- | ------------ | ------------ | --------------- |
| **查找元素** | `find(v.begin(), v.end(), val)`  | `find(d.begin(), d.end(), val)`  | `find(l.begin(), l.end(), val)`  | `find(val)`  | `find(key)`  | `find(key)`     |
| **统计元素** | `count(v.begin(), v.end(), val)` | `count(d.begin(), d.end(), val)` | `count(l.begin(), l.end(), val)` | `count(val)` | `count(key)` | `count(key)`    |

------

### **6️⃣ 排序操作**

| 操作     | `vector`                      | `deque`                       | `list`      | `set`        | `map`        | `unordered_map` |
| -------- | ----------------------------- | ----------------------------- | ----------- | ------------ | ------------ | --------------- |
| **排序** | `sort(v.begin(), v.end())`    | `sort(d.begin(), d.end())`    | `sort()`    | **自动排序** | **自动排序** | **无序**        |
| **反转** | `reverse(v.begin(), v.end())` | `reverse(d.begin(), d.end())` | `reverse()` | ❌            | ❌            | ❌               |

------

### **7️⃣ 统计大小**

| 操作         | `vector`  | `deque`   | `list`    | `set`     | `map`     | `unordered_map` |
| ------------ | --------- | --------- | --------- | --------- | --------- | --------------- |
| **获取大小** | `size()`  | `size()`  | `size()`  | `size()`  | `size()`  | `size()`        |
| **是否为空** | `empty()` | `empty()` | `empty()` | `empty()` | `empty()` | `empty()`       |

------

### **8️⃣ 交换容器**

| 操作         | `vector`   | `deque`    | `list`     | `set`      | `map`      | `unordered_map` |
| ------------ | ---------- | ---------- | ---------- | ---------- | ---------- | --------------- |
| **交换容器** | `swap(v2)` | `swap(d2)` | `swap(l2)` | `swap(s2)` | `swap(m2)` | `swap(um2)`     |

------



## **📌 总结**

1. **插入、删除**
   - `vector`：**只能尾部插入快**，`insert()` **慢**
   - `deque`：**头尾插入都快**
   - `list`：**中间插入最快**
   - `set/map`：**按顺序插入，自动排序**
   - `unordered_map`：**O(1) 插入**
2. **访问**
   - **支持索引：** `vector`、`deque`
   - <u>**仅支持迭代器：** `list`、`set`、`map`</u>
   - **键值访问：** `map[key]`、`unordered_map[key]`
3. **查找**
   - **线性搜索（O(n)）：** `vector`、`deque`、`list`
   - **二叉搜索（O(log n)）：** `set`、`map`
   - **哈希表查找（O(1)）：** `unordered_map`
4. **排序**
   - **自动排序**：`set`、`map`
   - **需要手动排序**：`vector`（`sort()`）、`list`（`sort()`）

------



### **🔥 记忆技巧**

📌 **如果数据要** **有序存储** ➝ `set/map`
 📌 **如果要** **索引访问** ➝ `vector/deque`
 📌 **如果插入/删除频繁** ➝ `list`
 📌 **如果查找要快** ➝ `unordered_map` 🚀



