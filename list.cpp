// #pragma once

#include <iostream>
#include <stdexcept>  // 提供异常处理支持 
#include <sstream> // 提供 std::istringstream 进行字符串解析
#include <vector>
#include <string>

using namespace std;

class List{

private:
    struct Node{
        int data;
        Node* next; // 指向下一个节点的指针
        Node* prev;
        Node(int val): data(val), next(nullptr), prev(nullptr) {}
    };

    Node* head; // 指向链表头部
    Node* tail; 
    int size; // 记录链表大小

public:
    // 1. List 构造函数
    List() : head(nullptr), tail(nullptr), size(0) {}
    // 2. 析构
    ~List() { clear(); }

    // 3. 清除函数clear
    void clear() {
        while (head) { 
            // head 不是一个 Node，而是一个指向 Node 的指针。它存的是 A 这个节点的地址
            Node* temp = head;  // temp指向A
            head = head->next;  // 移动head指向下一个节点，B
            delete temp;        // 释放原来的head节点
        }

        // 在 clear() 里 重置 tail 和 size，防止悬空指针
        tail = nullptr;  // 清空后 tail 也要置空
        size = 0;  // size也要清空
    }

    // 4. 插入函数 -- 实现 push_back() 和 push_front()
    // (1) 在末尾插入一个元素（push_back）
    void push_back(int value){
        Node* newNode = new Node(value);
        if(!tail) { // 链表为空
            head = tail = newNode;
        } else {  // 链表不为空
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
        size ++;
    }

    // (2) 在开头插入一个元素（push_front）
    void push_front(int value) {
        Node* newNode = new Node(value);
        if(!head){
            head = tail = newNode;
        } else {
            head -> prev = newNode;
            newNode -> next = head;
            head = newNode;
        }
        size++;
    }


    // 5. 删除:实现 pop_back() 和 pop_front()
    // (1) 删除末尾元素（pop_back）
    void pop_back(){
        if (size == 0) {
            head = nullptr;
            tail == nullptr;
        } else {
            Node* temp = tail->prev;
            delete tail;
            tail = temp; // 这里tail已经往前移动一位了

            if(tail) {
                tail->next = nullptr;
            }
            --size;
        }
    }
    
    
    // (2) 删除头部元素（pop_front）   
    void pop_front(){
        if(size == 0){
            head = nullptr;
            tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;

            if(head){
                head -> prev = nullptr;
            }
            --size;
        }
    }


    // 6. 打印功能
    void print() const {

        if(!head) {
            cout << "empty list" << endl;
            return;
        }

        // 用Node->data 来输出
        Node* temp = head;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // 改进的print
    void printElements() const {
        for (Node* current = head; current; current = current->next) {
            cout << current->data << " ";
        }
        cout << endl;
    }



    // 7. remove(val) 链表的指定删除操作
    void remove(int value) {
        Node* node = head;

        // 1. 遍历链表，寻找目标点
        while(node != nullptr && node->data != value){
            node = node->next;
        }

        // 2. 如果node为空，就说明没有Value，直接返回
        if(!node) return;
  
        // 3. 走到这一步骤，说明已经找到了Value
        // 如果node在中间
        if(node->prev) {
            node->prev->next = node->next;
        } else {
            head = node->next;  // 如果是头节点
        }
        
        // 
        if(node->next){
            node->next->prev = node->prev;
        } else { // 如果node->next 不存在，那node就是尾结点
            tail = node->prev;
        }
        
        delete node;
        --size;
        
    }

    bool empty() const {
        return size==0;
    }

    size_t getSize(){
        return size;
    }


};

int main() {
    List myList;
    int N;
    cin >> N;
    getchar();
    string line;

    for (int i = 0; i < N; i++) {
        getline(cin, line);
        istringstream iss(line);
        string command;
        iss >> command;
        int value;

        if (command == "push_back") {
            iss >> value; // 它的作用类似于 cin >> value, 将输入存入Value
            myList.push_back(value);
        } else if (command == "push_front") {
            iss >> value;
            myList.push_front(value);
        } else if (command == "pop_back") {
            myList.pop_back();
        } else if (command == "pop_front") {
            myList.pop_front();
        } else if (command == "remove") {
            iss >> value;
            myList.remove(value);
        } else if (command == "clear") {
            myList.clear();
        } else if (command == "size") {
            cout << myList.getSize() << endl;
        } else if (command == "print") {
            if (myList.empty()) {
                cout << "empty" << endl;
            } else {
                myList.printElements();
            }
        }
    }
    return 0;
}
