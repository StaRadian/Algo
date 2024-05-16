#include <iostream>
#include <string>

using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
    Node(char data): data(data) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    
    LinkedList() {
        Node* head_node = new Node(0);
        head_node -> next = nullptr;
        head_node -> prev = nullptr;
        head = head_node;
        tail = head_node;
    }
    
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current -> next;
            delete current;
            current = next;
        }
    }

    void append(char data) {
        Node* new_node = new Node(data);
        new_node -> next = nullptr;
        new_node -> prev = tail;
        tail -> next = new_node;
        tail = new_node;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int m;
    char order;

    cin >> s >> m;

    LinkedList list;

    for(char c : s) {
        list.append(c);
    }

    Node* curser = list.tail;

    for(int i = 0; i < m; i++) {
        cin >> order;
        switch (order) {
        case 'L':
            if(curser != list.head) { 
                curser = curser -> prev;
            }
            break;
        case 'D':
            if(curser != list.tail) {
                curser = curser -> next;
            }   

            break;
        case 'B': {
            if(curser != list.head) {
                Node* curser_temp = curser;
                if(curser != list.tail) {
                    curser->prev->next = curser->next;
                    curser->next->prev = curser->prev;
                    curser = curser->prev;
                } else {
                    curser -> prev -> next = nullptr;
                    curser = curser->prev;
                    list.tail = curser;
                }
                delete curser_temp;
            }
            break;
        }
        case 'P': {
            char value;
            cin >> value;
            Node* new_node = new Node(value);
            if(list.tail == curser) {
                curser -> next = new_node;
                new_node -> next = nullptr;
                new_node -> prev = curser;
                list.tail = new_node;
            } else {
                new_node -> next = curser -> next;
                new_node -> prev = curser;
                curser -> next -> prev = new_node;
                curser -> next = new_node;
            }
            curser = new_node;
            break;
        }
        }
    }

    Node* current = list.head -> next;
    while (current != nullptr) {
        cout << current -> data;
        current = current -> next; 
    }

    return 0;
}