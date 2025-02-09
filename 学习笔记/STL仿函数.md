# **📌 STL 仿函数（Functors）详解**

**仿函数（Functor）** 其实就是 **一个像函数一样能被调用的对象**。它的本质是**一个重载了 `operator()` 的类**，可以像普通函数一样使用，但比普通函数更强大，因为它可以**存储状态**。

------

## **1️⃣ 什么是仿函数？**

📌 **仿函数（Functors）= 重载 `operator()` 的类**

- **普通函数** 只能调用，不能保存状态。
- **仿函数** 是**一个类对象**，通过 **重载 `operator()`** 让它像函数一样使用。
- <u>**仿函数比普通函数更灵活**，可以作为 STL 算法的回调函数，或者存储状态。</u>

📌 **简单理解**

- 普通函数：只能**执行逻辑**，不能保存状态。
- 仿函数（Functor）：**可以执行逻辑，也可以存储状态**，并且能被多次调用。

✅ **示例：定义一个仿函数**

```cpp
#include <iostream>
using namespace std;

// 定义仿函数（Functor）
class Add {
public:
    int operator()(int a, int b) {  
        return a + b;
    }
};

int main() {
    Add add;  // 创建对象
    cout << add(3, 5) << endl;  // 像函数一样调用，输出 8
    return 0;
}
```

📌 **分析**

- `class Add` **重载 `operator()`**，使对象 `add` 可以像 `add(3,5)` 这样调用。
- **本质：仿函数是一个可调用对象（Callable Object）。**

------



## **2️⃣ 仿函数的主要作用**

📌 **STL 中的主要用途**

1. **作为算法的比较函数**（如 `sort()`、`set` 自定义排序）
2. **存储状态**（比普通函数更强）
3. **结合 STL 算法（`for_each()`、`transform()`）**
4. **适用于 `function<>` 作为回调函数**

✅ **示例：作为 STL 算法的回调**

📌 **仿函数最常用于 STL 算法，比如 `sort()`、`for_each()`**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 降序排序的仿函数
class Descending {
public:
    bool operator()(int a, int b) {
        return a > b;  // 降序排序
    }
};

int main() {
    vector<int> v = {5, 2, 8, 1, 3};
    
    sort(v.begin(), v.end(), Descending());  // 使用仿函数排序

    for (int n : v) cout << n << " ";  // 输出: 8 5 3 2 1
    return 0;
}

```

📌 **分析**

- `Descending` **是一个仿函数，作为 `sort()` 的比较函数**，实现**降序排序**。

------



## **3️⃣ STL 内置的仿函数**

STL 提供了一些**常用的仿函数**，位于 `<functional>` 头文件：

| **类别**     | **仿函数**         | **作用** |
| ------------ | ------------------ | -------- |
| **算术运算** | `plus<T>`          | `a + b`  |
|              | `minus<T>`         | `a - b`  |
|              | `multiplies<T>`    | `a * b`  |
|              | `divides<T>`       | `a / b`  |
|              | `modulus<T>`       | `a % b`  |
| **比较运算** | `greater<T>`       | `a > b`  |
|              | `less<T>`          | `a < b`  |
|              | `greater_equal<T>` | `a >= b` |
|              | `less_equal<T>`    | `a <= b` |
|              | `equal_to<T>`      | `a == b` |
|              | `not_equal_to<T>`  | `a != b` |
| **逻辑运算** | `logical_and<T>`   | `a && b` |
|              | `logical_or<T>`    | `a       |
|              | `logical_not<T>`   | `!a`     |

✅ **示例：使用 STL 仿函数 `greater<>` 进行降序排序**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>  // 引入仿函数库
using namespace std;

int main() {
    vector<int> v = {5, 2, 8, 1, 3};
    sort(v.begin(), v.end(), greater<int>());  // 使用 STL 内置仿函数

    for (int n : v) cout << n << " ";  // 输出: 8 5 3 2 1
    return 0;
}
```

📌 **`greater<int>()` 代替了自定义仿函数，简洁高效！**

------



## **4️⃣ 仿函数存储状态**

📌 **普通函数不能存储状态，但仿函数可以！**

```cpp
#include <iostream>
using namespace std;

class Counter {
private:
    int count;
public:
    Counter() : count(0) {}  
    int operator()(int x) {  
        count += x;
        return count;
    }
};

int main() {
    Counter c;
    cout << c(3) << endl;  // 输出 3
    cout << c(5) << endl;  // 输出 8
    cout << c(2) << endl;  // 输出 10
    return 0;
}
```

📌 **`Counter` 维护 `count` 变量，每次调用 `operator()` 都会累加！** ✅ **相比于普通函数，仿函数可以存储状态，提高灵活性！**

------



## **5️⃣ STL 算法与仿函数结合**

📌 **`for_each()` 使用仿函数**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Print {
public:
    void operator()(int x) {
        cout << x << " ";
    }
};

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    for_each(v.begin(), v.end(), Print());  // 传入仿函数
    return 0;
}
```

📌 **分析**

- `for_each()` **遍历 `vector`，对每个元素执行 `Print()`**。
- **仿函数可以存状态，使 `for_each()` 更强大！**

------



## **6️⃣ Lambda vs. 仿函数**

📌 **C++11 之后，Lambda 函数比仿函数更简洁** ✅ **Lambda 替代仿函数**

```cpp
for_each(v.begin(), v.end(), [](int x) { cout << x << " "; });
```

📌 **何时用 Lambda，何时用仿函数？**

| **方式**   | **优点**                     | **缺点**           |
| ---------- | ---------------------------- | ------------------ |
| **仿函数** | **可存储状态，可复用**       | 代码较长，需定义类 |
| **Lambda** | **语法简洁，适用于简单操作** | 不能存储状态       |

**💡 结论：**

- **简单操作 → Lambda**
- **需要存状态 → 仿函数**

------



## **📌 总结**

1️⃣ **仿函数是重载 `operator()` 的类，可以像函数一样调用。**
 2️⃣ **相比普通函数，仿函数可以存储状态，更灵活。**
 3️⃣ **仿函数在 STL 中主要用于自定义排序、`for_each()`、`transform()` 等算法。**
 4️⃣ **STL 提供内置仿函数，如 `greater<>`, `less<>`, `plus<>`，简化代码。**
 5️⃣ **C++11 之后，Lambda 语法简洁，适用于简单操作，但仿函数更适用于存储状态的情况。**

💡 **记住**：**仿函数 = 带状态的可调用对象，能提升 STL 算法的灵活性！** 🚀



