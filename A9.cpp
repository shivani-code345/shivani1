#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class OddEvenList {
private:
    Node* oddHead; 
    Node* evenHead;

public:
    OddEvenList() {
        oddHead = nullptr;
        evenHead = nullptr;
    }
    void append(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = nullptr;

        if (x % 2 == 1) { 
            if (oddHead == nullptr) {
                oddHead = newNode;
            } else {
                Node* current = oddHead;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
            }
        } else { 
            if (evenHead == nullptr) {
                evenHead = newNode;
            } else {
                Node* current = evenHead;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }
    }
    void display() {
        Node* current = oddHead;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        current = evenHead;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
    void removeFirstOdd() {
        if (oddHead == nullptr) {
            cout << "Odd list is empty. Cannot remove." << endl;
            return;
        }
        Node* temp = oddHead;
        oddHead = oddHead->next;
        delete temp;
    }
    void removeFirstEven() {
        if (evenHead == nullptr) {
            cout << "Even list is empty. Cannot remove." << endl;
            return;
        }
        Node* temp = evenHead;
        evenHead = evenHead->next;
        delete temp;
    }
};

int main() {
    OddEvenList myList;

    myList.append(3);
    myList.append(8);
    myList.append(5);
    myList.append(2);
    myList.append(7);

    myList.display();

    myList.removeFirstOdd();
    myList.removeFirstEven();

    myList.display();

    return 0;
}
