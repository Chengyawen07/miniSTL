## **1. C++ STL 迭代器（Iterator）用法和原理**

------

### **1️⃣ 什么是迭代器（Iterator）？**

**迭代器（Iterator）** 是 **STL（标准模板库）** 提供的一种 **类似指针的对象**，用于**遍历 STL 容器中的元素**，但比指针更安全、更灵活。

📌 **迭代器的作用**

- **访问 STL 容器中的元素**（如 `vector`, `list`, `map`）。
- **让 STL 算法（`sort`, `find` 等）适用于所有容器**。
- **统一不同数据结构的访问方式**，提高**代码复用性**。

📌 **迭代器的基本概念**

```cpp
std::vector<int> v = {10, 20, 30, 40};
// 获取迭代器
std::vector<int>::iterator it = v.begin();
// 使用迭代器访问元素
std::cout << *it << std::endl;  // 输出 10
```

------



### **2️⃣ 迭代器的分类**

| **迭代器类型**                               | **特点**                             | **适用容器**               |
| -------------------------------------------- | ------------------------------------ | -------------------------- |
| **输入迭代器（Input Iterator）**             | **只能读取，不能修改，只能前进**     | `istream_iterator`         |
| **输出迭代器（Output Iterator）**            | **只能写入，不能读取，只能前进**     | `ostream_iterator`         |
| **前向迭代器（Forward Iterator）**           | **可读可写，只能前进**               | `forward_list`             |
| **双向迭代器（Bidirectional Iterator）**     | **可读可写，可前进后退**             | `list`, `set`, `map`       |
| **随机访问迭代器（Random Access Iterator）** | **支持索引访问（`[]`）、可前进后退** | `vector`, `deque`, `array` |

📌 **支持的操作**

| **操作**     | **输入** | **输出** | **前向** | **双向** | **随机访问** |
| ------------ | -------- | -------- | -------- | -------- | ------------ |
| `++it`       | ✅        | ✅        | ✅        | ✅        | ✅            |
| `it++`       | ✅        | ✅        | ✅        | ✅        | ✅            |
| `--it`       | ❌        | ❌        | ❌        | ✅        | ✅            |
| `it + n`     | ❌        | ❌        | ❌        | ❌        | ✅            |
| `it - n`     | ❌        | ❌        | ❌        | ❌        | ✅            |
| `it1 == it2` | ❌        | ❌        | ✅        | ✅        | ✅            |
| `*it`        | ✅        | ❌        | ✅        | ✅        | ✅            |
| `it[n]`      | ❌        | ❌        | ❌        | ❌        | ✅            |

------



### **3️⃣ 迭代器的基本语法**

```cpp
容器类型<T>::iterator 变量名 = 容器.begin();
```

📌 **示例**

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {10, 20, 30, 40};
    
    std::vector<int>::iterator it;  // 声明迭代器
    for (it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";  // 输出: 10 20 30 40
    }

    return 0;
}
```

**✅ `begin()` 返回指向第一个元素的迭代器，`end()` 返回最后一个元素的后一个位置的迭代器。**

------



### **4️⃣ 迭代器的常见操作**

| **操作**         | **语法**           | **说明**                                                     |
| ---------------- | ------------------ | ------------------------------------------------------------ |
| **获取起始位置** | `it = v.begin();`  | 指向**第一个元素**                                           |
| **获取结束位置** | `it = v.end();`    | 指向**最后一个元素的下一个位置**                             |
| **前进**         | `++it;`            | **前进到下一个元素**                                         |
| **后退**         | `--it;`            | **后退到前一个元素**（仅 `Bidirectional` 和 `Random Access` 支持） |
| **访问元素**     | `*it`              | 读取**当前迭代器指向的元素**                                 |
| **随机跳转**     | `it + 3;`          | **只适用于随机访问迭代器**                                   |
| **比较迭代器**   | `it1 == it2`       | 判断两个迭代器是否**指向相同位置**                           |
| **反向迭代**     | `rbegin(), rend()` | **倒序遍历容器**                                             |

------



### **5️⃣ 迭代器的高级用法**

#### **📌 1. 反向迭代器（Reverse Iterator）**

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    for (auto rit = v.rbegin(); rit != v.rend(); ++rit) {
        std::cout << *rit << " ";  // 输出: 5 4 3 2 1
    }

    return 0;
}
```

📌 **`rbegin()` 指向最后一个元素，`rend()` 指向第一个元素的前一个位置**。

------



#### **📌 2. `const_iterator`（只读迭代器）**

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {10, 20, 30, 40};

    for (std::vector<int>::const_iterator it = v.cbegin(); it != v.cend(); ++it) {
        std::cout << *it << " ";  // 输出: 10 20 30 40
    }

    return 0;
}
```

📌 **`cbegin()` 和 `cend()` 提供不可修改的访问**。

------



#### **📌 3. `map` 迭代器**

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> scores = {{"Alice", 90}, {"Bob", 85}, {"Charlie", 92}};

    for (auto it = scores.begin(); it != scores.end(); ++it) {
        std::cout << it->first << " : " << it->second << std::endl;
    }

    return 0;
}
```

📌 **`it->first` 访问键，`it->second` 访问值**。

------



#### **📌 4. `advance()` 让迭代器前进**

```cpp
#include <iostream>
#include <list>
#include <iterator>

int main() {
    std::list<int> l = {10, 20, 30, 40, 50};
    auto it = l.begin();
    std::advance(it, 3);  // 前进 3 个位置
    std::cout << *it << std::endl;  // 输出: 40
}
```



#### **📌 5. `distance()` 计算迭代器间距离**

```cpp
#include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> v = {10, 20, 30, 40, 50};
    std::cout << std::distance(v.begin(), v.end());  // 输出: 5
}
```

------



### **6️⃣  STL 迭代器适配的本质**

**📌 迭代器适配的核心原理：** 

✅ **不同容器内部定义了自己的 `iterator`，并继承 `iterator_category`**。
✅ **`iterator_traits<T>::iterator_category` 负责查询迭代器类型**，确定是 `random_access_iterator` 还是 `bidirectional_iterator`。
✅ **STL 通过 `iterator_traits` 统一了迭代器的使用方式**，不同容器的迭代器可以自动适配 STL 算法（如 `sort()`）。

✅ **STL 迭代器适配原理：每个容器提供自己的 `iterator` 类型，`iterator_traits` 统一识别，STL 算法根据迭代器类别自动适配。**



### **7️⃣ 总结**

| **迭代器类型**     | **特点**                      | **常见容器**               |
| ------------------ | ----------------------------- | -------------------------- |
| **输入迭代器**     | **只读，只能前进**            | `istream_iterator`         |
| **输出迭代器**     | **只写，只能前进**            | `ostream_iterator`         |
| **前向迭代器**     | **可读可写，只能前进**        | `forward_list`             |
| **双向迭代器**     | **可读可写，可前后移动**      | `list`, `set`, `map`       |
| **随机访问迭代器** | **支持索引 `[]`，可前后移动** | `vector`, `deque`, `array` |



## 2. 迭代器除了遍历，还被哪些地方用到？

虽然 **迭代器（Iterator）** 主要用于 **遍历 STL 容器**，但在 STL 和 C++ 标准库中，它还有许多其他重要的用途！以下是迭代器的 **主要使用场景**：

------

## **1️⃣ STL 算法（Algorithms）**

📌 **STL 提供的算法（`sort()`、`find()`、`for_each()` 等）都依赖迭代器，而不是直接操作容器。**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {5, 1, 3, 4, 2};

    std::sort(v.begin(), v.end());  // 使用迭代器进行排序
    for (auto it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";  // 输出: 1 2 3 4 5

    return 0;
}
```

✅ **所有 STL 算法都依赖迭代器！**

- **`sort(begin, end)`** → 依赖 **随机访问迭代器（Random Access Iterator）**
- **`find(begin, end, value)`** → 适用于所有迭代器类型
- **`for_each(begin, end, func)`** → 适用于所有迭代器

------

## **STL 算法如何使用迭代器？**

📌 **关键点**

- **算法不直接操作容器，而是通过迭代器访问容器的数据**。
- **不同的容器有不同的迭代器，算法能自动适配不同迭代器**。
- **算法使用 `begin()` 和 `end()` 迭代器定义数据范围**。



## **2️⃣ 插入与删除（Insert & Erase）**

📌 **迭代器可以用于指定位置插入或删除元素，而不仅仅是 `push_back()`！**

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {10, 20, 30, 40};

    auto it = v.begin() + 2;  // 指向索引 2（30）
    v.insert(it, 25);  // 在 30 之前插入 25

    v.erase(v.begin() + 1);  // 删除索引 1（20）

    for (int n : v) std::cout << n << " ";  // 输出: 10 25 30 40
    return 0;
}
```

✅ **迭代器控制 `insert()` 和 `erase()` 位置**

- `insert(it, value)` → 在 `it` 位置前插入 `value`
- `erase(it)` → 删除 `it` 位置的元素

------

## **3️⃣ 反向遍历（Reverse Traversal）**

📌 **STL 容器支持 `rbegin()` 和 `rend()`，允许反向遍历**

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    for (auto it = v.rbegin(); it != v.rend(); ++it)
        std::cout << *it << " ";  // 输出: 5 4 3 2 1

    return 0;
}
```

✅ `rbegin()` **指向最后一个元素**，`rend()` **指向第一个元素的前一个位置**。

------

## **4️⃣ 流迭代器（I/O Stream Iterator）**

📌 **迭代器不仅能遍历容器，还可以用于** **文件流输入输出**！

```cpp
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main() {
    std::vector<int> v;
    std::cout << "Enter numbers: ";

    std::istream_iterator<int> input(std::cin);
    std::istream_iterator<int> eof;  // 结束标志

    while (input != eof) {
        v.push_back(*input);
        ++input;
    }

    std::cout << "Numbers: ";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));

    return 0;
}
```

✅ **`istream_iterator<int>(std::cin)`** → 让迭代器从 `cin` 读取数据
 ✅ **`ostream_iterator<int>(std::cout, " ")`** → 让迭代器向 `cout` 输出数据

📌 **这在文件流处理中非常有用！**

------

## **5️⃣ 迭代器适配器（Iterator Adapters）**

📌 **`back_inserter` 让 `push_back()` 适用于 `copy()`**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    std::vector<int> src = {1, 2, 3, 4, 5};
    std::vector<int> dest;

    std::copy(src.begin(), src.end(), std::back_inserter(dest));

    for (int n : dest) std::cout << n << " ";  // 输出: 1 2 3 4 5
    return 0;
}
```

✅ `std::back_inserter(dest)` **自动调用 `push_back()`，避免手动写 `resize()`**

📌 **迭代器适配器让算法更灵活！**

------

## **6️⃣ `distance()` & `advance()` 操作**

📌 **迭代器不仅能遍历，还能计算距离、调整位置**

```cpp
#include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> v = {10, 20, 30, 40, 50};

    auto it = v.begin();
    std::advance(it, 3);  // 向前移动 3 个位置
    std::cout << *it << std::endl;  // 输出: 40

    std::cout << "Distance: " << std::distance(v.begin(), it) << std::endl;  // 输出: 3
}
```

✅ **`std::advance(it, n)`** → 让迭代器前进 `n` 步
 ✅ **`std::distance(it1, it2)`** → 计算两个迭代器的距离

------



## **7️⃣ `std::next()` 和 `std::prev()`**

📌 **在某些情况下，比 `advance()` 更方便**

```cpp
#include <iostream>
#include <list>
#include <iterator>

int main() {
    std::list<int> l = {10, 20, 30, 40, 50};

    auto it = std::next(l.begin(), 2);  // 获取索引 2 位置的迭代器
    std::cout << *it << std::endl;  // 输出: 30

    auto it2 = std::prev(it);  // 获取前一个元素
    std::cout << *it2 << std::endl;  // 输出: 20

    return 0;
}
```

✅ **`std::next(it, n)`** → 返回 `it` 之后 `n` 个元素的迭代器
 ✅ **`std::prev(it, n)`** → 返回 `it` 之前 `n` 个元素的迭代器

------



### **📌 迭代器的应用总结（含英文术语）**

| **用途（Purpose）** | **示例（Example）**                                          | **英文术语（English Term）**          |
| ------------------- | ------------------------------------------------------------ | ------------------------------------- |
| **遍历容器**        | `for (auto it = v.begin(); it != v.end(); ++it) {}`          | **Container Traversal**               |
| **STL 算法**        | `std::sort(v.begin(), v.end());`                             | **STL Algorithm**                     |
| **插入 & 删除**     | `v.insert(it, 25); v.erase(it);`                             | **Insertion & Deletion**              |
| **反向遍历**        | `for (auto it = v.rbegin(); it != v.rend(); ++it) {}`        | **Reverse Iteration**                 |
| **流迭代器**        | `std::istream_iterator<int> input(std::cin);`                | **Stream Iterator**                   |
| **迭代器适配器**    | `std::copy(src.begin(), src.end(), std::back_inserter(dest));` | **Iterator Adapters**                 |
| **计算距离**        | `std::distance(it1, it2);`                                   | **Distance Calculation**              |
| **前进 & 后退**     | `std::advance(it, n); std::next(it); std::prev(it);`         | **Iterator Advancement & Retraction** |

📌 **解释**

- **遍历容器（Container Traversal）**：使用 `begin()` 和 `end()` 进行迭代遍历容器中的元素。
- **STL 算法（STL Algorithm）**：如 `std::sort()` 直接作用于迭代器，而不是容器本身。
- **插入 & 删除（Insertion & Deletion）**：使用 `insert()` 和 `erase()` 在迭代器位置进行修改。
- **反向遍历（Reverse Iteration）**：使用 `rbegin()` 和 `rend()` 进行倒序遍历。
- **流迭代器（Stream Iterator）**：用于流输入输出的迭代器，如 `istream_iterator` 读取输入流。
- **迭代器适配器（Iterator Adapters）**：`back_inserter()` 让 `std::copy()` 可以直接调用 `push_back()`。
- **计算距离（Distance Calculation）**：`std::distance()` 计算两个迭代器之间的距离。
- **前进 & 后退（Iterator Advancement & Retraction）**：`std::advance()` 让迭代器前进 `n` 步，`std::next()` 和 `std::prev()` 获取相邻位置。