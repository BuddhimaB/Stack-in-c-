#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

class Node {
public:
    int key;
    Node *next;
};

class Stack {
private:
    Node *top;

public:
    Stack() {
        top = NULL;
    }

    bool is_empty() {
        return top == NULL;
    }

    void push(int value) {
        Node *newNode = new Node();
        newNode->key = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (is_empty()) {
            cout << "Stack underflow" << endl;
            return;
        }
        cout << top->key << endl;
        top = top->next;
    }

    void peek() {
        if (is_empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << top->key << endl;
    }

    void display() {
        cout << "[ ";
        Node *temp = top;
        while (temp != NULL) {
            cout << temp->key << " ";
            temp = temp->next;
        }
        cout << "]" << endl;
    }

};

int main() {
    Stack stack;

    auto start = high_resolution_clock::now();

    stack.push(23);
    stack.push(12);
    stack.push(8);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(6);
    stack.push(5);

    stack.display();
    cout << endl;

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    cout << endl;

    stack.display();

    stack.push(100);
    stack.push(121);
    stack.push(81);
    stack.push(11);
    cout << endl;

    stack.display();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time taken by the stack implemented using linkedlists: " << duration.count() << " microseconds" << endl;

    return 0;
}
