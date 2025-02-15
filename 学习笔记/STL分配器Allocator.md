## **C++ STL 分配器（Allocator）**

------

### **1️⃣ 什么是 `allocator`？**

在 C++ STL 中，**分配器（Allocator）** 是一种 **内存管理机制**，负责 **动态分配、构造、释放和销毁对象**。STL 容器默认使用 `std::allocator<T>` 来管理内存，但也可以自定义分配器优化性能。

**作用**：

- 负责**内存分配（allocate）和对象构造（construct）**。
- 负责**对象析构（destroy）和 内存释放（deallocate）**。
- 适用于**定制化内存管理**（如优化性能、减少碎片化）。

------



### **2️⃣ `std::allocator` 的基本用法**

#### ✅ **常见接口**

| 方法                    | 作用                                         |
| ----------------------- | -------------------------------------------- |
| `allocate(n)`           | 分配 `n` 个 `T` 类型的内存，但不调用构造函数 |
| `construct(p, args...)` | 在 `p` 指向的内存位置上构造对象              |
| `destroy(p)`            | 调用对象 `p` 的析构函数                      |
| `deallocate(p, n)`      | 释放 `p` 指向的 `n` 个 `T` 类型的内存        |

#### 🔹 **示例代码**

```cpp
#include <iostream>
#include <memory>  // 需要包含 allocator 头文件

int main() {
    std::allocator<int> alloc; // 创建一个 int 类型的分配器

    int* p = alloc.allocate(5);  // 分配 5 个 int 空间
    alloc.construct(p, 42);      // 在分配的空间上构造对象（赋值 42）

    std::cout << *p << std::endl;  // 输出: 42

    alloc.destroy(p);              // 析构对象
    alloc.deallocate(p, 5);        // 释放内存
    return 0;
}
```

------

### **3️⃣ 常见的分配器类型**

除了 `std::allocator<T>`，C++ 还提供了多种不同类型的分配器，它们各有特点，适用于不同场景。

#### **📌 STL 中的默认分配器**

| 分配器                               | 作用                             |
| ------------------------------------ | -------------------------------- |
| `std::allocator<T>`                  | **标准分配器**，STL 容器默认使用 |
| `std::pmr::polymorphic_allocator<T>` | **多态分配器**，支持不同内存资源 |

------

#### **📌 自定义分配器**

| 自定义分配器                             | 适用场景                                     |
| ---------------------------------------- | -------------------------------------------- |
| `std::allocator_traits<T>`               | **封装分配器的通用接口**                     |
| `std::scoped_allocator_adaptor<T>`       | **嵌套容器（如 `vector<vector<int>>`）优化** |
| `std::pmr::memory_resource`              | **用于定制内存池**                           |
| `std::pmr::monotonic_buffer_resource`    | **单次分配，生命周期结束后统一释放**         |
| `std::pmr::unsynchronized_pool_resource` | **线程不安全的内存池**                       |
| `std::pmr::synchronized_pool_resource`   | **线程安全的内存池**                         |

------

### **4️⃣ `std::pmr`（多态分配器）**

C++17 引入了 **`std::pmr`（polymorphic memory resource）**，允许**多个对象共享内存池**，**减少内存碎片化**，提高性能。

#### 🔹 **示例代码**

```cpp
#include <iostream>
#include <memory_resource>
#include <vector>

int main() {
    char buffer[1024];  // 预分配 1KB 的内存
    std::pmr::monotonic_buffer_resource pool(buffer, sizeof(buffer));

    std::pmr::vector<int> vec(&pool);  // 绑定内存池
    vec.push_back(42);

    std::cout << vec[0] << std::endl;  // 输出: 42
    return 0;
}
```

**适用场景**：

- **游戏开发**（减少动态分配次数，提高效率）
- **嵌入式系统**（控制内存分配）
- **高性能计算**（减少碎片化）

------

### **5️⃣ `std::scoped_allocator_adaptor`（嵌套容器优化）**

如果 `vector<vector<int>>` 里的 **每个 `vector<int>`** 需要单独分配内存，可能会造成碎片化。`std::scoped_allocator_adaptor` **可以共享内存池，提高效率**。

#### 🔹 **示例代码**

```cpp
#include <iostream>
#include <vector>
#include <scoped_allocator>

int main() {
    std::allocator<int> alloc;  // 默认分配器
    std::scoped_allocator_adaptor<std::allocator<std::vector<int>>, std::allocator<int>> myAlloc(alloc);

    std::vector<std::vector<int>, decltype(myAlloc)> vec(10, std::vector<int>{}, myAlloc);

    vec[0].push_back(42);
    std::cout << vec[0][0] << std::endl;  // 输出: 42
    return 0;
}
```

**适用场景**：

- **嵌套容器**，如 `vector<list<int>>`
- **减少嵌套分配，提高内存局部性**

------

## **6️⃣ `std::allocator` vs. `std::pmr` vs. 自定义分配器 对比**

| 特性                      | `std::allocator<T>` | `std::pmr::polymorphic_allocator<T>` | `std::scoped_allocator_adaptor<T>` |
| ------------------------- | ------------------- | ------------------------------------ | ---------------------------------- |
| **内存管理**              | **默认分配器**      | **支持定制内存池**                   | **嵌套容器优化**                   |
| **适用场景**              | **通用 STL 容器**   | **减少碎片化，高效管理**             | **`vector<vector<int>>` 等**       |
| **性能**                  | **一般**            | **更快（减少分配次数）**             | **更快（减少嵌套分配）**           |
| **适用于游戏/高性能计算** | ❌                   | ✅                                    | ✅                                  |
| **适用于多线程**          | ✅                   | ✅（部分资源不安全）                  | ✅                                  |

------

## **📌 7️⃣ 什么时候该用哪种分配器？**

| 需求                     | 选择的分配器                          |
| ------------------------ | ------------------------------------- |
| **普通 STL 容器**        | `std::allocator<T>`（默认）           |
| **减少碎片化，优化性能** | `std::pmr::polymorphic_allocator<T>`  |
| **优化嵌套容器**         | `std::scoped_allocator_adaptor<T>`    |
| **优化单次分配**         | `std::pmr::monotonic_buffer_resource` |
| **自定义内存池**         | `std::pmr::memory_resource`           |

------

## **总结**

- `std::allocator<T>`：**STL 默认分配器**，适用于一般场景。
- `std::pmr::polymorphic_allocator<T>`：**适用于需要优化内存管理的场景**（如游戏、实时系统）。
- `std::scoped_allocator_adaptor<T>`：**优化嵌套容器**，减少内存碎片化，提高局部性。
- `std::pmr::monotonic_buffer_resource`：**适用于高效的短期对象存储**。

💡 **如果你不确定该用哪个，`std::allocator<T>` 足够应对大多数情况！** 