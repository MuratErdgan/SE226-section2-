#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* head;     // Points to top element of stack.
    int num;        // Number of elements (index-style tracking).
    int capacity;   // Fixed size limit (resized when full).

public:
    Stack(int initialCapacity) {  // You can set any initial size.
        head = nullptr;
        num = 0;
        capacity = initialCapacity;
    }

    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;

        if (!newNode) {
            cout << "Stack overflow" << endl;
            return;
        }
        
        if (num >= capacity) {
            increaseCapacity();
        }

        newNode->next = head;
        head = newNode;
        num++;
    }

    int pop() {
        if (this->isEmpty()) {
            cout << "Stack underflow" << endl;
            return -1;
        }

        Node* temp = head;
        int poppedValue = head->data;
        head = head->next;
        delete temp;
        num--;
        return poppedValue;
    }

    int peek() {
        if (!this->isEmpty()) {
            return head->data;
        } else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return num == 0;
    }

    void increaseCapacity() {
        capacity *= 2;
        cout << "Capacity increased to " << capacity << endl;
    }

    void printStack() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool deleteElement(int val) {
        if (this->isEmpty()) {
            cout << "Stack is empty. Cannot delete element." << endl;
            return false;
        }

        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->data == val) {
                if (previous == nullptr) {  // Element is at the head.
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
                num--;
                cout << "Element " << val << " deleted successfully." << endl;
                return true;
            }
            previous = current;
            current = current->next;
        }

        cout << "Element " << val << " not found." << endl;
        return false;
    }
};

int main() {
    Stack stack(3);
    stack.push(5);
    stack.push(10);
    stack.push(15);
    stack.push(20);

    stack.printStack();

    cout << "Peek: " << stack.peek() << endl;

    stack.push(40);
    stack.push(50);

    stack.printStack();

    stack.pop();
    stack.pop();

    stack.printStack();

    stack.deleteElement(10);
    stack.deleteElement(15);
    stack.deleteElement(100);

    stack.printStack();

    stack.pop();
    stack.printStack();
    stack.pop();
    stack.pop();

    return 0;
}
