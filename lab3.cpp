#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


class Queue {

    Node* front;

    Node* rear;

    int count;

public:

    Queue()
        : front(nullptr)
        , rear(nullptr)
        , count(0)

    {
    }


    void enqueue(int x)
    {

        Node* newNode = new Node{ x, nullptr };

        if (rear == nullptr) {

            front = rear = newNode;

        }
        else {

            rear->next = newNode;
            rear = newNode;
        }

        count++;
    }


    void dequeue()
    {
        if (count == 0) {
            cout << "Empty Queue" << endl;
            return;
        }

        if (front == nullptr)
            return;

        Node* temp = front;

        front = front->next;

        if (front == nullptr)

            rear = nullptr;

        delete temp;
        count--;
    }


    int top()
    {
        if (count == 0) {
            cout << "Empty Queue" << endl;
            return -1;
        }
        if (!isEmpty())
            return front->data;
        else
            throw runtime_error("Empty Queue");
    }


    bool isEmpty()
    {

        return front == nullptr;
    }

    int size() {
        return count;
    }
};


int main()
{

    Queue q;

    q.enqueue(35);
    cout << "First Element: " << q.top() << endl;
    cout << "Size is: "<<q.size() << endl;
    q.enqueue(40);
    cout << "First Element: " << q.top() << endl;
    cout << "Size is: "<<q.size() << endl;
    q.dequeue();
    cout << "Size is: "<<q.size() << endl;;
    cout << "First Element: " << q.top() << endl;
    cout << "Size is: "<<q.size() << endl;
    cout << (q.isEmpty() ? "Queue is empty":"Queue is not empty")<< endl;
    q.dequeue();
    cout << "Size is: "<<q.size() << endl;
    q.dequeue();
    cout << "First Element: " << q.top() << endl;







    return 0;
}
