#include <iostream>
#include <cstring> 
using namespace std;
struct Node {
    char name[50]; 
    Node* next;
};
class FriendList {
private:
    Node* head;
public:
    
    FriendList() {
        head = nullptr;
    }
    int getLength() {
        int length = 0;
        Node* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        return length;
    }
    void addAtBeg(const char* name) {
        Node* newNode = new Node;
        strcpy(newNode->name, name);
        newNode->next = head;
        head = newNode;
    }
    void append(const char* name) {
        Node* newNode = new Node;
        strcpy(newNode->name, name);
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    void addAtPOS(const char* name, int pos) {
        if (pos <= 0 || pos > getLength() + 1) {
            cout << "Invalid position." << endl;
            return;
        }

        if (pos == 1) {
            addAtBeg(name);
            return;
        }

        Node* newNode = new Node;
        strcpy(newNode->name, name);

        Node* current = head;
        for (int i = 1; i < pos - 1; ++i) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->name << " ";
            current = current->next;
        }
        cout << endl;
    }
    void displayMORE() {
        Node* current = head;
        while (current != nullptr) {
            cout << "Address: " << current << ", Name: " << current->name;
            if (current->next != nullptr) {
                cout << ", Next Address: " << current->next;
            }
            cout << endl;
            current = current->next;
        }
    }
    void removeFirst() {
        if (head == nullptr) {
            cout << "Friend list is empty. Cannot remove." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void removeLast() {
        if (head == nullptr) {
            cout << "Friend list is empty. Cannot remove." << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
    void removePOS(int pos) {
        if (pos <= 0 || pos > getLength()) {
            cout << "Invalid position." << endl;
            return;
        }
        if (pos == 1) {
            removeFirst();
            return;
        }
        Node* current = head;
        for (int i = 1; i < pos - 1; ++i) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
};

int main() {
    FriendList myFriends;

    myFriends.addAtBeg("Anshika");
    myFriends.append("Aditi");
    myFriends.append("Riya");
    myFriends.addAtBeg("dinku");
    cout<<endl;
    myFriends.display();
    cout<<endl;
    return 0;
}