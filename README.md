# 📌 C++ STL 

## 🚀 项目介绍

本仓库致力于收集和整理 C++ STL（标准模板库）的重要知识点、使用方法、代码示例以及最佳实践。无论你是 C++ 初学者还是希望深入 STL 细节的开发者，这里都能提供高质量的学习资源。

---

## 📚 STL 主要知识点

### 1️⃣ STL 组成部分
- **容器（Containers）**：`vector`, `list`, `deque`, `map`, `set`, `unordered_map` 等。
- **算法（Algorithms）**：`sort`, `find`, `count`, `accumulate`, `for_each` 等。
- **迭代器（Iterators）**：`begin()`, `end()`, `rbegin()`, `rend()` 等。
- **仿函数（Functors）**：自定义运算规则，可用于 `sort` 的比较规则等。
- **适配器（Adapters）**：`stack`, `queue`, `priority_queue` 等。
- **空间配置器（Allocators）**：管理容器的内存分配，如 `std::allocator<T>`。

### 2️⃣ 重要概念
- **泛型编程（Generic Programming）**：函数模板、类模板、模板特化、模板偏特化等。
- **操作符重载（Operator Overloading）**：如何让 STL 容器支持自定义类型。
- **C++20 概念（Concepts）**：约束模板参数，提高代码安全性。
- **STL 内存管理**：`std::allocator<T>`, `pmr::memory_resource`。

---

## 💡 代码示例

### 📌 **函数模板示例**
```cpp
#include <iostream>
template <typename T>
T add(T a, T b) { return a + b; }
int main() {
    std::cout << add(3, 5) << std::endl; // 8
    return 0;
}
```

### 📌 **类模板示例**
```cpp
#include <iostream>
template <typename T>
class Box {
    T value;
public:
    Box(T val) : value(val) {}
    void show() { std::cout << "Value: " << value << std::endl; }
};
int main() {
    Box<int> b(42); b.show(); // Value: 42
    return 0;
}
```

---

## 📂 目录结构
```
C++-STL-Repo/
│── README.md        # 项目介绍
│── docs/            # 详细文档
│── examples/        # 代码示例
│   ├── containers/  # 各种 STL 容器示例
│   ├── algorithms/  # STL 算法示例
│   ├── iterators/   # 迭代器示例
│   ├── functors/    # 仿函数示例
│   ├── concepts/    # C++20 Concepts 示例
│── src/             # 实践项目源码
│── LICENSE          # 许可证
```

---



## 🔧 贡献指南

欢迎任何人提交 PR 或 Issue，共同完善 C++ STL 知识库！
1. **Fork 仓库**
2. **Clone 项目**：
   ```sh
   git clone https://github.com/your_username/C++-STL-Repo.git
   ```
3. **提交代码**：
   ```sh
   git add .
   git commit -m "增加 STL 迭代器示例"
   git push origin main
   ```
4. **提交 PR（Pull Request）**

---

## 📖 参考资料
- **[C++ 官方文档](https://en.cppreference.com/w/cpp)**
- **[C++ STL 教程](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/)**
- **《Effective STL》 - Scott Meyers**

