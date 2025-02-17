#include<iostream>
using namespace std;

class node {
    public:
        node(int num = 0, class node* nxt = NULL) { next = nxt; n = num; }
        int n;
        class node* next;
};

typedef node* link;

int main() {
    link head, nw, cur, del, swap1, swap2;

    head = new node(0);
    cur = head;

    for (int i = 1; i <= 5; i++) {
        nw = new node(i*2);
        cur->next = nw;
        cur = nw;
    }

    cur = head;
    while (cur != NULL) {
        cout << cur->n << " ";
        cur = cur->next;
    }
    cout << endl;

    link p, q, r;
    p = head;
    q = 0;
    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;

    cout << "after reverse:" << endl;
    cur = head;
    while (cur != NULL) {
        cout << cur->n << " ";
        cur = cur->next;
    }
    cout << endl;

}



