## 1. 📌 **OOP（面向对象编程） vs. GP（泛型编程）**

------

### **比较**

| **编程范式** | **OOP（面向对象编程）**   | **GP（泛型编程）**                            |
| ------------ | ------------------------- | --------------------------------------------- |
| **核心思想** | **通过类和对象** 组织代码 | **通过模板（template）** 让代码适用于任意类型 |
| **主要目标** | **封装、继承、多态**      | **代码复用、类型无关**                        |
| **代码结构** | **类 & 继承层次**         | **模板 & 泛型算法**                           |
| **适用场景** | **软件架构、GUI、游戏**   | **STL、数学计算、容器**                       |

------



## **📌2.  C++ 泛型编程（Generic Programming）**

------

## **1️⃣ 什么是泛型编程？**

**泛型编程（Generic Programming, GP）** 是 C++ 提供的一种 **“类型无关”** 的编程方式，它让代码可以适用于**不同的数据类型**，提高复用性。
 **核心概念**：

- **使用 `template` 关键字** 实现**函数、类、变量等泛型化**。
- **让算法适用于不同的数据类型**（如 `std::sort` 适用于 `int`、`double`、`string`）。
- **避免代码重复**（不用分别写 `int` 版、`double` 版的函数）。

------



## **2️⃣ C++ 泛型编程的主要组成部分**

| **类别**          | **概念**                                                     | **说明**                      |
| ----------------- | ------------------------------------------------------------ | ----------------------------- |
| **模板**          | `template<typename T>`                                       | 让代码支持**不同数据类型**    |
| **函数模板**      | `template<typename T> T func(T a, T b);`                     | 让**函数**支持泛型            |
| **类模板**        | `template<typename T> class MyClass {}`                      | 让**类**支持泛型              |
| **模板特化**      | `template<> class MyClass<int> {}`                           | **针对特定类型提供特殊实现**  |
| **模板偏特化**    | `template<typename T1, typename T2> class MyClass<T1, T2*> {}` | 让**部分模板参数特殊化**      |
| **可变模板参数**  | `template<typename... Args>`                                 | 让**模板支持不定参数**        |
| **别名模板**      | `template<typename T> using Ptr = T*;`                       | 让**模板支持 `typedef` 语法** |
| **概念（C++20）** | `template<typename T> requires std::is_integral<T>::value`   | **约束模板参数类型**          |

------



## **3️⃣ 函数模板（Function Template）**

**✅ 作用**：

- 让**函数**支持任意数据类型，而**不必重复写多个版本**。

**📌 示例 1：简单的函数模板**

```cpp
#include <iostream>

// 定义一个通用的加法函数
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(3, 5) << std::endl;      // int: 8
    std::cout << add(2.5, 1.5) << std::endl;  // double: 4.0
    return 0;
}
```

📌 **这里的 `T` 是泛型类型，编译器会根据传入的数据类型自动推导**。

------



## **4️⃣ 类模板（Class Template）**

**✅ 作用**：

- 让**类支持不同的数据类型**，避免重复实现 `int` 版、`double` 版等。

**📌 示例 2：简单的类模板**

```cpp
#include <iostream>

// 定义一个通用的 Box 类
template <typename T>
class Box {
private:
    T value;
public:
    Box(T val) : value(val) {}
    void show() { std::cout << "Value: " << value << std::endl; }
};

int main() {
    Box<int> intBox(42);      
    Box<std::string> strBox("Hello");  

    intBox.show();  // 输出: Value: 42
    strBox.show();  // 输出: Value: Hello
    return 0;
}
```

📌 **让 `Box<int>`、`Box<std::string>` 都能工作，而不用重复写代码！**

------



## **5️⃣ 模板特化（Template Specialization）**

**✅ 作用**：

- **针对某个特定类型提供不同的实现**。

C++ 里的**特化（Specialization）就是给某些特殊情况**单独写一个版本，而不是使用通用模板的版本。

你可以把**模板**理解成一个**万能模具**，它能适应不同的类型。但有时候，某些类型需要特别对待，比如：

- 处理 `int` 类型和 `double` 类型的方式可能不一样
- 处理数组和处理单个元素的方式不同
- 某些类型的计算方式更简单，可以优化

这时候，就可以**特化**模板，给某些类型**定制专属版本**。

------

## **1. 函数模板特化**

普通模板：

```cpp
template <typename T>
void print(T value) {
    std::cout << "通用版本: " << value << std::endl;
}
```

调用：

```cpp
print(10);         // 10
print(3.14);       // 3.14
print("Hello");    // Hello
```

但如果 `char*` 类型（C 风格字符串）用这个模板，它会打印一个**指针地址**，而不是字符串内容！
 所以，我们可以**特化** `char*` 版本：

```cpp
template <>
void print<char*>(char* value) {
    std::cout << "特化版本: " << value << std::endl;
}
```

调用：

```cpp
print("Hello");  // 特化版本: Hello
```

这样，`char*` 类型就有了自己的专属 `print` 版本，而其他类型还是用通用模板。

------



## **2. 类模板特化**

假设我们有一个 `Box` 类，它可以存储任何类型的数据：

```cpp
template <typename T>
class Box {
public:
    Box(T v) : value(v) {}
    void show() { std::cout << "通用 Box: " << value << std::endl; }

private:
    T value;
};
```

**但如果 `T = bool`，我们希望只存 `true/false`，不用 `int` 来表示，这时可以特化：**

```cpp
template <>
class Box<bool> {
public:
    Box(bool v) : value(v) {}
    void show() { std::cout << "特化 Box: " << (value ? "true" : "false") << std::endl; }

private:
    bool value;
};
```

调用：

```cpp
Box<int> b1(42);
b1.show();  // 通用 Box: 42

Box<bool> b2(true);
b2.show();  // 特化 Box: true
```

这样，`bool` 类型的 `Box` 有了自己的**专属实现**。

------





## **6️⃣ 模板偏特化-局部特化（Template Partial Specialization）**

**✅ 作用**：

- **部分参数特化，而不是整个特化**。
- 有时候，我们不是针对**某个特定类型**，而是针对某个**模式**，比如：
- template <typename T, typename U>

```cpp
template <typename T, typename U>
class Pair {
public:
    Pair(T a, U b) : first(a), second(b) {}
    void show() { std::cout << "通用 Pair: " << first << ", " << second << std::endl; }

private:
    T first;
    U second;
};
```

如果 `T` 和 `U` 是**相同的类型**，我们可以提供**偏特化**：

```cpp
template <typename T>
class Pair<T, T> {
public:
    Pair(T a, T b) : first(a), second(b) {}
    void show() { std::cout << "偏特化 Pair（相同类型）: " << first << ", " << second << std::endl; }

private:
    T first;
    T second;
};
```

调用：

```cpp
Pair<int, double> p1(1, 2.5);
p1.show();  // 通用 Pair: 1, 2.5

Pair<int, int> p2(3, 4);
p2.show();  // 偏特化 Pair（相同类型）: 3, 4
```

这样，当 `T` 和 `U` 相同时，就会用**偏特化版本**。



**总结**

- **函数模板特化**：给某个特定类型的函数模板写一个专属版本
- **类模板特化**：给某个特定类型的类模板写一个专属版本
- **偏特化（局部特化）**：不针对单个类型，而是针对某些模式进行特化

### **记住口诀**

✅ **模板是万能模具**，适用于各种类型
 ✅ **特化是定制版**，针对特定情况优化
 ✅ **偏特化是模式优化**，对部分情况提供更好实现



## **7️⃣ 可变模板参数（Variadic Templates）**

**✅ 作用**：

- **支持不定数量的模板参数**，用于可变参数函数。

### **📌 示例 5：可变模板参数**

```cpp
#include <iostream>

// 递归终止情况
void print() { std::cout << "End of arguments" << std::endl; }

// 递归展开
template <typename T, typename... Args>
void print(T first, Args... rest) {
    std::cout << first << " ";
    print(rest...);  // 递归调用，直到参数为空
}

int main() {
    print(1, 2.5, "Hello", 'A');  
    // 输出: 1 2.5 Hello A End of arguments
}
```

📌 **可以处理任意数量的参数，STL `tuple` 就是用这种方式实现的！**

------



## **8️⃣ 别名模板（Alias Templates）**

**✅ 作用**：

- **让模板支持 `typedef` 语法，简化代码**。

### **📌 示例 6：别名模板**

```cpp
#include <iostream>

template <typename T>
using Ptr = T*;  // 定义一个类型别名

int main() {
    Ptr<int> p = new int(10);  // 等价于 `int* p = new int(10);`
    std::cout << *p << std::endl;  // 输出: 10
    delete p;
}
```

📌 **类似 `typedef`，但可以用于模板类型**。

------

## **9️⃣ 概念（C++20 新特性）**

**✅ 作用**：

- **限制模板参数的类型，提高代码安全性**。

### **📌 示例 7：使用概念**

```cpp
#include <iostream>
#include <concepts>

// 限制 T 必须是整数类型
template <std::integral T>
T square(T x) {
    return x * x;
}

int main() {
    std::cout << square(5) << std::endl;  // ✅ OK
    // std::cout << square(5.5) << std::endl;  ❌ 编译报错（5.5 不是整数）
}
```

📌 **让模板更加安全，避免意外的类型使用！**

------

## **📌 10. 总结：C++ 泛型编程完整梳理**

| **泛型编程概念**  | **作用**                     |
| ----------------- | ---------------------------- |
| **函数模板**      | 让**函数支持不同数据类型**   |
| **类模板**        | 让**类支持不同数据类型**     |
| **模板特化**      | **针对特定类型提供不同实现** |
| **模板偏特化**    | **部分参数特化**             |
| **可变模板参数**  | **支持可变参数**             |
| **别名模板**      | **简化 `typedef`**           |
| **概念（C++20）** | **约束模板参数类型**         |

💡 **泛型编程就是让代码适用于不同数据类型，减少重复，提高复用性！** 🚀 这样梳理是不是更清晰了？😃