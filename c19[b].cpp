/*Department of Computer Engineering has student's club named 'Pinnacle Club'. 
Students of Second, third and final year of department can be granted membership on request. 
Similarly one may cancel the membership of club. First node is reserved for president of club 
and last node is reserved for secretary of club. 
Write C++ program to maintain club memberâ€˜s information using singly linked list. Store student PRN and Name. 
Write functions to  
a)	Add and delete president and secretary. 
b)	Compute total number of members of club 
c)	Display members 
d)	Two linked lists exists for two divisions. Concatenate two lists. 
*/
#include <iostream>
#include <string>
using namespace std;

// Structure for a club member node
struct Node {
    string prn;   // Student PRN
    string name;  // Student Name
    Node* next; // Pointer to the next member in the list
};

// Class to represent the club
class PinnacleClub {
private:
    Node* head; // Head of the linked list (first member)
    
public:
    PinnacleClub() {
        head = nullptr; // Initially, the club has no members
    }

    // Function to add president
    void addPresident(string prn, string name) {
        Node* newnode = new Node();
        newnode->prn = prn;
        newnode->name = name;
        newnode->next = head;
        head = newnode;
        cout << "President added: " << name << endl;
    }

    // Function to add secretary
    void addSecretary(string prn, string name) {
        Node* newMember = new Node();
        newMember->prn = prn;
        newMember->name = name;
        newMember->next = nullptr;

        if (head == nullptr) {
            head = newMember;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newMember;
        }
        cout << "Secretary added: " << name << endl;
    }

    // Function to delete the president
    void deletePresident() {
        if (head == nullptr) {
            cout << "No members in the club." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "President deleted." << endl;
    }

    // Function to delete the secretary
    void deleteSecretary() {
        if (head == nullptr) {
            cout << "No members in the club." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->next != nullptr) {
            temp = temp->next;
        }

        if (temp->next != nullptr) {
            Node* secretary = temp->next;
            temp->next = nullptr;
            delete secretary;
            cout << "Secretary deleted." << endl;
        } else {
            cout << "Only one member (President) is present. Can't delete secretary." << endl;
        }
    }

    // Function to compute the total number of members
    int totalMembers() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Function to display all members
    void displayMembers() {
        if (head == nullptr) {
            cout << "No members in the club." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << "PRN: " << temp->prn << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

    // Function to concatenate two linked lists (for two divisions)
    void concatenateLists(PinnacleClub& otherClub) {
        if (this->head == nullptr) {
            this->head = otherClub.head;
            return;
        }

        Node* temp = this->head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Link the last node of the first list to the head of the second list
        temp->next = otherClub.head;
        otherClub.head = nullptr; // Clear the other list
    }

    // Destructor to free allocated memory
    ~PinnacleClub() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    PinnacleClub division1, division2;
    int choice;
    string prn, name;
    do {
        // Displaying the menu
        cout << "\n--- Pinnacle Club Menu ---\n";
        cout << "1. Add President\n";
        cout << "2. Add Secretary\n";
        cout << "3. Delete President\n";
        cout << "4. Delete Secretary\n";
        cout << "5. Display Members\n";
        cout << "6. Concatenate Two Lists\n";
        cout << "7. Compute Total Members\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Add president
                cout << "Enter PRN for President: ";
                cin >> prn;
                cout << "Enter Name for President: ";
                cin.ignore();  // To ignore the newline character left in the buffer
                getline(cin, name);
                division1.addPresident(prn, name);
                break;
            }
            case 2: {
                // Add secretary
                cout << "Enter PRN for Secretary: ";
                cin >> prn;
                cout << "Enter Name for Secretary: ";
                cin.ignore();
                getline(cin, name);
                division1.addSecretary(prn, name);
                break;
            }
            case 3: {
                // Delete president
                division1.deletePresident();
                break;
            }
            case 4: {
                // Delete secretary
                division1.deleteSecretary();
                break;
            }
            case 5: {
                // Display members
                cout << "\nMembers of the Pinnacle Club:\n";
                division1.displayMembers();
                break;
            }
            case 6: {
                // Concatenate two lists
                cout << "\nConcatenating division lists...\n";
                division1.concatenateLists(division2);
                cout << "\nAfter concatenation:\n";
                division1.displayMembers();
                break;
            }
            case 7: {
                // Total members
                cout << "\nTotal members in the club: " << division1.totalMembers() << endl;
                break;
            }
            case 8: {
                cout << "\nExiting the program.\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while (choice != 8);

    return 0;
}
