#include<iostream>
using namespace std;

template <class T>
class Stack {
    private:
        T *stack;
        int top;
        int size;
    public:
        Stack(int size = 1): top(0) {
            this->size = size;
            stack = new T[size];
        }

        ~Stack() {
            delete[] stack;
        }

        bool full() {
            return top == size;
        }

        bool empty() {
            return top == 0;
        }

        void push(T data) {
            if (full()) {
                cout << "Stack is full" << endl;
                return;
            } else {
                stack[top++] = data;
            }
        }

        T pop() {
            if (empty()) {
                cout << "Stack is empty" << endl;
                return -1;
            } else {
                return stack[--top];
            }
        }
};

int main() {
    Stack<int> st(20);
    for (int i = 0; i < 10; i++) {
        st.push(i);
    }
    while (!st.empty()) {
        cout << st.pop() << endl;
    }
}