#include <iostream>
#include <algorithm>
using namespace std;

class Node {
    public:
        Node(int v = 0, int e = 0):value(v), ext(e), next(NULL) {}

        int value;
        int ext;
        class Node* next;
};

typedef Node* Link;

class Poly {
    public:
        Poly():size(0), head(NULL) {}
        Poly(int v, int e):size(0), head(NULL) { newNode(v, e); }
        ~Poly() {
            Link del = head;
            while (head != NULL) {
                head = head->next;
                delete del;
                del = head;
            }
        }

        void newNode(int v, int e) {
            if (head == NULL) {
                head = new Node(v, e);
                tail = head;
            } else {
                Link tmp = new Node;
                tail->next = tmp;
                tail = tmp;
                tail->value = v;
                tail->ext = e;
            }
            size++;
        }

        void print() {
            Link cur = head;
            cout << cur->value << "x^" << cur->ext;
            cur = cur->next;
            while (cur != NULL) {
                cout << " + " << cur->value;
                if (cur->ext > 0) cout << "x^" << cur->ext;
                cur = cur->next;
            }
            cout << endl;
        }

        void addTwoPoly(Poly* A, Poly* B) {
            Link a = A->head;
            Link b = B->head;
            
            while (a != NULL || b != NULL) {
                if (a->ext > b->ext) {
                    newNode(a->value, a->ext);
                    a = a->next;
                } else if (b->ext > a->ext) {
                    newNode(b->value, b->ext);
                    b = b->next;
                } else {
                    newNode(a->value + b->value, a->ext);
                    a = a->next;
                    b = b->next;
                }
            }
        }
    
    private:
        Link head, tail;
        int size;
};

int main() {
    Poly A(3,3);
    A.newNode(4,1);
    A.newNode(2,0);

    Poly B(6,3);
    B.newNode(8,2);
    B.newNode(6,1);
    B.newNode(9,0);

    cout << "Initial:" << endl;
    A.print();
    B.print();

    Poly C;

    C.addTwoPoly(&A, &B);

    C.print();
}
