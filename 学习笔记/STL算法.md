# **📌 STL 算法（Standard Template Library Algorithms）详解**

STL（标准模板库）中的**算法（Algorithms）提供了一组通用操作**，用于操作不同的**STL 容器（`vector`、`list`、`map` 等）**，但**算法本身不直接操作容器，而是通过迭代器访问数据**。

📌 **STL 算法的特点**：

1. **基于迭代器（Iterators）**，而不是容器本身。
2. **适用于不同的容器**（`vector`, `list`, `deque`, `map` 等）。
3. **不会修改容器结构，只会修改元素内容**（如 `sort()` 只是调整元素顺序，不会改变 `vector` 的大小）。
4. **大多数 STL 算法位于 `<algorithm>` 头文件中**。

------



## **1️⃣ STL 算法的分类**

| **类别**                        | **常见算法**                                                 | **作用**                     |
| ------------------------------- | ------------------------------------------------------------ | ---------------------------- |
| **非修改算法（Non-Modifying）** | `find()`, `count()`, `search()`, `equal()`                   | 查找、统计、比较，不改变数据 |
| **修改算法（Modifying）**       | `copy()`, `fill()`, `replace()`, `remove()`                  | 修改数据但不改变容器结构     |
| **排序算法（Sorting）**         | `sort()`, `stable_sort()`, `partial_sort()`, `nth_element()` | 对数据进行排序               |
| **排列组合算法（Permutation）** | `next_permutation()`, `prev_permutation()`                   | 计算排列方式                 |
| **数值算法（Numeric）**         | `accumulate()`, `inner_product()`, `partial_sum()`, `adjacent_difference()` | 计算数值                     |
| **最小最大值（Min/Max）**       | `min()`, `max()`, `min_element()`, `max_element()`           | 计算最值                     |
| **查找算法（Searching）**       | `binary_search()`, `lower_bound()`, `upper_bound()`          | 在有序容器中查找             |
| **集合操作（Set Operations）**  | `set_union()`, `set_intersection()`, `set_difference()`      | 计算集合关系                 |
| **变换算法（Transformation）**  | `for_each()`, `transform()`                                  | 逐个元素执行操作             |
| **堆操作（Heap）**              | `push_heap()`, `pop_heap()`, `make_heap()`, `sort_heap()`    | 管理堆结构                   |

📌 **所有 STL 算法都是通用的，不依赖具体的容器，而是通过迭代器操作数据！** 🚀

------



## **2️⃣ 常见 STL 算法详细解析**

### **✅ 1. 查找 & 统计**

📌 **`find()`：查找指定元素**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {10, 20, 30, 40, 50};
    
    auto it = std::find(v.begin(), v.end(), 30);  // 查找 30
    if (it != v.end()) 
        std::cout << "Found: " << *it << std::endl;  // 输出: Found: 30

    return 0;
}
```

✅ `find()` 遍历容器，返回**第一个匹配的迭代器**。

📌 **`count()`：统计某个值出现的次数**

```cpp
int count_30 = std::count(v.begin(), v.end(), 30);  
std::cout << "30 出现了 " << count_30 << " 次" << std::endl;
```

------



### **✅ 2. 复制 & 替换**

📌 **`copy()`：复制范围数据**

```cpp
std::vector<int> src = {1, 2, 3, 4, 5};
std::vector<int> dest(5);

std::copy(src.begin(), src.end(), dest.begin());

for (int n : dest) std::cout << n << " ";  // 输出: 1 2 3 4 5
```

✅ `copy()` 需要 **目标容器有足够的空间**，否则 `dest.begin()` 会导致未定义行为。

📌 **`replace()`：替换元素**

```cpp
std::replace(v.begin(), v.end(), 30, 99);  // 将 30 替换为 99
```

------



### **✅ 3. 排序**

📌 **`sort()`：快速排序（QuickSort 或 HeapSort）**

```cpp
std::sort(v.begin(), v.end());  // 从小到大排序
```

✅ **`sort()` 需要 `Random Access Iterator`（随机访问迭代器），适用于 `vector`, `deque`。**

📌 **`stable_sort()`：稳定排序（保留相同元素的相对顺序）**

```cpp
std::stable_sort(v.begin(), v.end());  // O(n log n) 复杂度
```

------



### **✅ 4. 查找**

📌 **`binary_search()`：二分查找**

```cpp
std::sort(v.begin(), v.end());  // 必须排序
bool found = std::binary_search(v.begin(), v.end(), 30);
```

✅ **必须先排序**，然后才能使用 `binary_search()`。

📌 **`lower_bound()` 和 `upper_bound()`**

```cpp
auto lb = std::lower_bound(v.begin(), v.end(), 30);  // 第一个 ≥ 30 的位置
auto ub = std::upper_bound(v.begin(), v.end(), 30);  // 第一个 > 30 的位置
```

------



### **✅ 5. 变换**

📌 **`for_each()`：对每个元素执行操作**

```cpp
std::for_each(v.begin(), v.end(), [](int &n) { n *= 2; });
```

✅ `for_each()` 用于遍历和修改元素。

📌 **`transform()`：对每个元素执行操作，并写入另一个容器**

```cpp
std::transform(v.begin(), v.end(), dest.begin(), [](int n) { return n * 2; });
```

✅ **`transform()` 可以创建新的数据，而不会修改原容器！**

------



### **✅ 6. 计算最值**

📌 **`min()` & `max()`**

```cpp
std::cout << "Min: " << std::min(10, 20) << std::endl;  
std::cout << "Max: " << std::max(10, 20) << std::endl;  
```

📌 **`min_element()` & `max_element()`**

```cpp
auto min_it = std::min_element(v.begin(), v.end());
auto max_it = std::max_element(v.begin(), v.end());
```

✅ **适用于整个容器，返回迭代器。**

------



## **3️⃣ STL 算法如何与迭代器交互？**

📌 **STL 算法的参数是迭代器，而不是容器**

```cpp
std::sort(v.begin(), v.end());  // sort() 只需要迭代器，不关心容器类型
```

📌 **STL 算法自动适配不同容器**

```cpp
std::list<int> l = {5, 3, 8, 1, 2};
l.sort();  // ✅ 不能用 std::sort()，必须用 list 自带的 sort()
```

✅ `list` 只能用 `list.sort()`，因为 `std::sort()` 需要随机访问迭代器，而 `list` 只有双向迭代器。

------



## **📌 结论**

1️⃣ **STL 算法不直接操作容器，而是通过迭代器访问数据。**

2️⃣ **不同的算法适用于不同的迭代器类型（如 `sort()` 需要 `Random Access Iterator`）。**

3️⃣ **STL 算法主要位于 `<algorithm>`，是标准库的一部分，而不是容器自带的功能。**

4️⃣ **常见算法包括排序（`sort()`）、查找（`find()`）、复制（`copy()`）、变换（`for_each()`）等。**

- STL 算法通过迭代器操作数据，保证了算法的通用性，让所有 STL 容器都能使用相同的算法！









