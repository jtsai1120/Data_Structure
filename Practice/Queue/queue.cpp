#include<iostream>
#include<vector>
using namespace std;

template <class T>
class MyNode {
    public:
        MyNode(): rlink(NULL) {}
        T value;
        MyNode<T> *llink, *rlink;
};

template <class T>
class MyQueue {
    private:
        MyNode<T> *front_ptr, *back_ptr;
        size_t queueSize;
    public:
        MyQueue(): queueSize(0) {}
        const size_t size() { return queueSize; }
        const bool empty() { return (queueSize == 0); }
        const T front() {
            if (empty()) {
                cerr << "Empty Queue" << endl;
                return 0;
            } else {
                return front_ptr->value;
            }
        }
        const T back() {
            if (empty()) {
                cerr << "Empty Queue" << endl;
                return 0;
            } else {
                return back_ptr->value;
            }
        }
        void push(T n) {
            if (empty()) {
                front_ptr = new MyNode<T>;
                front_ptr->value = n;
                back_ptr = front_ptr;
            } else {
                MyNode<T> *tmp = new MyNode<T>;
                tmp->value = n;
                back_ptr->rlink = tmp;
                tmp->llink = back_ptr;
                back_ptr = tmp;
            }
            queueSize++;
        }
        void pop() {
            if (empty()) {
                cerr << "Empty Queue" << endl;
            } else if (queueSize == 1) {
                delete front_ptr;
                front_ptr = NULL;
                back_ptr = NULL;
                queueSize = 0;
            } else {
                MyNode<T> *del = front_ptr;
                front_ptr = front_ptr->rlink;
                front_ptr->llink = NULL;
                delete del;
                queueSize--;
            }
        }
};

int main() {
    MyQueue<int> q;
    cout << q.size() << q.empty() << endl;
    for (int i = 5; i <= 10; i++) { 
        q.push(i);
        cout << q.size() << " ";
    }
    cout << endl;
    for (int i = 0; i <= 5; i++) {
        cout << q.front() << " " << q.size() << endl;
        q.pop();
    }
}