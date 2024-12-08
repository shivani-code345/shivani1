#include <iostream>
#include <string>
using namespace std;
struct Contact {
    string name;
    int mobileNumber;
    Contact* next;
};

class ContactList {
private:
    Contact* head; 

public:
    ContactList() {
        head = nullptr;
    }
    void addContact(const string& name, int mobileNumber) {
        Contact* newContact = new Contact;
        newContact->name = name;
        newContact->mobileNumber = mobileNumber;
        newContact->next = nullptr;

        if (head == nullptr) {
            head = newContact;
        } else {
            Contact* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newContact;
        }
    }
    void displayContacts() {
        Contact* current = head;
        while (current != nullptr) {
            cout << "Name: " << current->name << ", Mobile Number: " << current->mobileNumber << endl;
            current = current->next;
        }
    }
    void removeFirstContact() {
        if (head == nullptr) {
            cout << "Contact list is empty. Cannot remove." << endl;
            return;
        }
        Contact* temp = head;
        head = head->next;
        delete temp;
    }
};

int main() {
    ContactList myContacts;

    myContacts.addContact("Alice", 1234567890);
    myContacts.addContact("Bob", 9876543210);
    myContacts.addContact("Charlie", 5551234567);

    cout << "Contact List:" << endl;
    myContacts.displayContacts();

    myContacts.removeFirstContact();
    cout << "After removing the first contact:" << endl;
    myContacts.displayContacts();

    return 0;
}
