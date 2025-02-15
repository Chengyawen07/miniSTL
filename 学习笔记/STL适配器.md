# **📌 STL 适配器讲解**

你可以把 **STL 适配器（Adapters）** 理解为**“改装工具”**，它**不会创造新东西，而是对现有的 STL 组件（容器、迭代器、仿函数）进行改造，让它们的使用方式变得更符合需求。**

------



## **1️⃣ STL 适配器的分类**

📌 STL 适配器有 **三大类**，你可以把它们类比成**现实生活中的“适配器”**：

| **适配器类型**                        | **作用（现实中的类比）**                                     | **示例**                               |
| ------------------------------------- | ------------------------------------------------------------ | -------------------------------------- |
| **容器适配器（Container Adapters）**  | **改变容器的操作方式**（比如“改装汽车，变成专用车型”）       | `stack<int>`, `queue<int>`             |
| **迭代器适配器（Iterator Adapters）** | **改变迭代器的遍历方式**（比如“给普通鞋子加上滚轮，变成滑轮鞋”） | `reverse_iterator`, `istream_iterator` |
| **函数适配器（Function Adapters）**   | **修改仿函数的行为**（比如“把游戏手柄按键映射成键盘”）       | `bind()`, `not1()`, `mem_fn()`         |

✅ **适配器的核心思想就是“改造”**，不是创造新的东西，而是让现有的东西更易用、更符合需求！

------



## **2️⃣ 容器适配器（Container Adapters）——改装“汽车”**

📌 **STL 容器适配器的作用：**
 **“拿现成的 STL 容器，改装成特定用途的容器”**，比如：

- **普通 `deque`（双端队列）** → **改装成 `stack`（栈）**
- **普通 `deque`** → **改装成 `queue`（队列）**
- **普通 `vector`** → **改装成 `priority_queue`（优先队列）**

### **✅ `stack` 适配器（后进先出 LIFO）**

🚗 **改装示例**：
 **`stack<int>` = `deque<int>` 变成 “只能进出栈” 的数据结构**

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;  // stack 适配 deque

    s.push(10);  // 入栈
    s.push(20);
    s.push(30);

    cout << "栈顶元素: " << s.top() << endl;  // 输出 30
    s.pop();  // 出栈

    cout << "新的栈顶: " << s.top() << endl;  // 输出 20
    return 0;
}
```

✅ **`stack` 适配 `deque`，但屏蔽了 `push_front()`，只能 `push()` 和 `pop()`**

------



### **✅ `queue` 适配器（先进先出 FIFO）**

🚗 **改装示例**：
 **`queue<int>` = `deque<int>` 变成 “只能按队列方式进出”**

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << "队列头: " << q.front() << endl;  // 输出 1
    q.pop();  // 出队

    cout << "新的头: " << q.front() << endl;  // 输出 2
    return 0;
}
```

✅ **`queue` 适配 `deque`，但屏蔽 `push_front()`，只能 `push()` 和 `pop()`**

------



## **3️⃣ 迭代器适配器（Iterator Adapters）—— 给鞋子加滚轮**

📌 **迭代器适配器的作用：**
 **“对原有的迭代器进行改造，改变遍历方式”**，比如：

- **普通迭代器** → **反向迭代器（reverse_iterator）**
- **普通 `cin` 读取输入** → **变成迭代器（istream_iterator）**
- **普通 `cout` 输出** → **变成迭代器（ostream_iterator）**

### **✅ `reverse_iterator` 让 `vector` 反向遍历**

🚶 **普通鞋子 → 滑轮鞋**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        cout << *it << " ";  // 输出: 5 4 3 2 1
    }
    return 0;
}
```

✅ **普通 `vector` 只能正向遍历，加上 `reverse_iterator`，变成支持反向遍历的容器！**

------

### **✅ `istream_iterator` 让 `cin` 变成迭代器**

📝 **改装示例**：
 **普通 `cin` → 变成可迭代对象**

```cpp
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main() {
    vector<int> v;
    cout << "输入 3 个数字: ";
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));

    for (int n : v) cout << n << " ";  
    return 0;
}
```

✅ **让 `cin` 变成一个迭代器，可以直接填充 `vector`，比 `while(cin >> x)` 更简洁！**

------

## **4️⃣ 函数适配器（Function Adapters）—— 改造手柄按键**

📌 **函数适配器的作用：**
 **“对仿函数进行改造，改变它的行为”**，比如：

- **普通函数** → **变成支持部分参数绑定的函数（`bind()`）**
- **普通仿函数** → **变成取反仿函数（`not1()`、`not2()`）**
- **普通成员函数** → **变成可作为参数的函数对象（`mem_fn()`）**

### **✅ `bind()` 绑定参数**

🎮 **手柄按键映射成键盘**

```cpp
#include <iostream>
#include <functional>
using namespace std;

void greet(string name, string msg) {
    cout << msg << ", " << name << endl;
}

int main() {
    auto hello = bind(greet, placeholders::_1, "你好");
    hello("Alice");  // 输出: 你好, Alice
    return 0;
}
```

✅ **`bind()` 让 `greet()` 绑定 `msg = "你好"`，后续只需传 `name`**

------

# **📌 总结**

| **适配器类型**   | **作用（通俗理解）**                       | **示例**                               |
| ---------------- | ------------------------------------------ | -------------------------------------- |
| **容器适配器**   | **“改装汽车”**，封装 `deque`，限制操作方式 | `stack<int>`, `queue<int>`             |
| **迭代器适配器** | **“给鞋子加滚轮”**，改造迭代器行为         | `reverse_iterator`, `istream_iterator` |
| **函数适配器**   | **“改造手柄按键”**，改造仿函数的行为       | `bind()`, `not1()`, `mem_fn()`         |

💡 **STL 适配器的本质就是“改造已有功能”，让 STL 组件更灵活、更好用！**

