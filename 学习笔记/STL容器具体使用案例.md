## STL容器的具体使用案例

数据结构在 C++ 软件开发中无处不在，它们决定了**程序的性能、可维护性和扩展性**。下面列举一些**常见数据结构在实际开发中的用途**，并提供相应的 C++ 框架和示例代码。

------

### **1. 数组（Array）**

#### **用途：**

- 适用于**固定大小**的数据存储，如缓存、图像处理、矩阵运算等。

#### **示例：图像存储**

```cpp
const int WIDTH = 1920, HEIGHT = 1080;
unsigned char image[WIDTH][HEIGHT][3];  // 存储 RGB 图像
```

**应用场景：**

- 图像处理：存储像素点
- 数值计算：矩阵运算

------

### **2. 动态数组（Vector）**

#### **用途：**

- 用于**动态增长**的数据存储，常用于日志系统、实时数据采集、消息队列等。

#### **示例：日志存储**

```cpp
#include <vector>
#include <string>
std::vector<std::string> logs;

void addLog(const std::string& msg) {
    logs.push_back(msg);
}
```

**应用场景：**

- 维护一个动态增长的日志系统
- 处理可变长度的用户输入数据

------

### **3. 链表（List）**

#### **用途：**

- 适用于**频繁插入/删除**数据的场景，如操作系统任务调度、网络数据包管理。

#### **示例：任务调度系统**

```cpp
#include <list>
#include <string>

std::list<std::string> taskQueue;

void addTask(const std::string& task) {
    taskQueue.push_back(task);
}

void processTask() {
    if (!taskQueue.empty()) {
        std::string task = taskQueue.front();
        taskQueue.pop_front();
    }
}
```

**应用场景：**

- 任务队列（Task Queue）
- 操作系统的进程管理

------

### **4. 栈（Stack）**

#### **用途：**

- 适用于**回溯、撤销操作**，<u>如文本编辑器的撤销功能、浏览器的返回功能。</u>

#### **示例：浏览器的返回功能**

```cpp
#include <stack>
#include <string>

std::stack<std::string> history;

void visitPage(const std::string& url) {
    history.push(url);
}

std::string goBack() {
    if (!history.empty()) {
        std::string lastPage = history.top();
        history.pop();
        return lastPage;
    }
    return "No history";
}
```

**应用场景：**

- 计算机语言解析（如括号匹配）
- 浏览器的后退/前进功能

------



### **5. 队列（Queue）**

#### **用途：**

- 适用于**任务排队、异步任务处理**，如**多线程任务队列、服务器请求排队**。

#### **示例：任务队列**

```cpp
#include <queue>
#include <string>

std::queue<std::string> requestQueue;

void addRequest(const std::string& request) {
    requestQueue.push(request);
}

void processRequest() {
    if (!requestQueue.empty()) {
        std::string request = requestQueue.front();
        requestQueue.pop();
    }
}
```

**应用场景：**

- 服务器处理 HTTP 请求
- 任务调度（Task Scheduler）

------



### **6. 优先队列（Priority Queue）**

#### **用途：**

- 适用于**任务调度、事件驱动**的系统，如操作系统的进程调度、Dijkstra 最短路径算法。

#### **示例：任务优先级调度**

```cpp
#include <queue>
#include <iostream>

struct Task {
    int priority;
    std::string name;

    bool operator<(const Task& other) const {
        return priority < other.priority; // 低优先级任务排在后面
    }
};

std::priority_queue<Task> taskQueue;

void addTask(int priority, const std::string& name) {
    taskQueue.push({priority, name});
}

void processTask() {
    if (!taskQueue.empty()) {
        Task t = taskQueue.top();
        taskQueue.pop();
        std::cout << "Processing: " << t.name << std::endl;
    }
}
```

**应用场景：**

- 任务管理系统（操作系统的进程调度）
- 网络数据包处理（高优先级数据包先处理）

------



### **7. 哈希表（Unordered Map）**

#### **用途：**

- 适用于**高效数据查找**，如数据库索引、缓存系统、用户认证。

#### **示例：用户密码存储**

```cpp
#include <unordered_map>
#include <string>

std::unordered_map<std::string, std::string> userDatabase;

void addUser(const std::string& username, const std::string& password) {
    userDatabase[username] = password;
}

bool checkPassword(const std::string& username, const std::string& password) {
    return userDatabase.count(username) && userDatabase[username] == password;
}
```

**应用场景：**

- 缓存系统（如 DNS 解析）
- 统计数据（如访问量统计）

------



### **8. 集合（Set）**

#### **用途：**

- 适用于**唯一值存储**，如黑名单、在线用户列表、词典搜索。

#### **示例：在线用户管理**

```cpp
#include <set>
#include <string>

std::set<std::string> onlineUsers;

void userLogin(const std::string& username) {
    onlineUsers.insert(username);
}

void userLogout(const std::string& username) {
    onlineUsers.erase(username);
}
```

**应用场景：**

- 过滤重复数据（如日志去重）
- 在线用户列表

------

### **9. 图（Graph）**

#### **用途：**

- 适用于**关系建模、路径规划**，如社交网络、地图导航、任务依赖管理。

#### **示例：社交网络好友关系**

```cpp
#include <vector>
#include <unordered_map>

std::unordered_map<std::string, std::vector<std::string>> socialNetwork;

void addFriend(const std::string& user, const std::string& friendUser) {
    socialNetwork[user].push_back(friendUser);
    socialNetwork[friendUser].push_back(user);
}
```

**应用场景：**

- 路径规划（如 GPS 导航）
- 任务依赖管理（如编译器解析依赖）

------



## **总结**

| 数据结构           | 实际用途               |
| ------------------ | ---------------------- |
| **数组**           | 图像存储、数值计算     |
| **向量（Vector）** | 日志存储、动态数据管理 |
| **链表（List）**   | 任务调度、网络数据管理 |
| **栈（Stack）**    | 浏览器历史、表达式求值 |
| **队列（Queue）**  | 任务队列、异步消息     |
| **优先队列**       | 进程调度、事件驱动     |
| **哈希表（Map）**  | 缓存、用户认证         |
| **集合（Set）**    | 过滤重复数据、黑名单   |
| **图（Graph）**    | 社交网络、地图导航     |





