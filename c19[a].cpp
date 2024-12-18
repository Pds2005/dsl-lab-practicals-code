/*Department of Computer Engineering has student's club named 'Pinnacle Club'. 
Students of Second, third and final year of department can be granted membership on request. 
Similarly one may cancel the membership of club. 
First node is reserved for president of club and last node is reserved for secretary of club. 
Write C++ program to maintain club memberâ€˜s information using singly linked list. 
Store student PRN and Name. Write functions to  
a)	Add the members as well as president and even secretary. 
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

    // Function to add a member, president, or secretary
    void addMember(string prn, string name) {
        Node* newnode = new Node();
        newnode->prn = prn;
        newnode->name = name;
        newnode->next = nullptr;

        if (head == nullptr) {
            head = newnode; // If the list is empty, this member is the first (president)
        } else {
            // Traverse to the last node and add the new member
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newnode;
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
    int choice, n;
    string prn, name;

    do {
        // Displaying the menu
        cout << "\n--- Pinnacle Club Menu ---\n";
        cout << "1. Add Members\n";
        cout << "2. Display Members\n";
        cout << "3. Concatenate Two Lists\n";
        cout << "4. Compute Total Members\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Add members to division 1
                cout << "Enter the number of members for Division 1: ";
                cin >> n;
                cout << "Enter the PRN and Name of the members for Division 1:" << endl;
                for (int i = 0; i < n; i++) {
                    cout << "Enter PRN: ";
                    cin >> prn;
                    cout << "Enter Name: ";
                    cin.ignore(); // To ignore the newline character left in the buffer
                    getline(cin, name); // Read full name including spaces
                    division1.addMember(prn, name);
                }

                // Add members to division 2
                cout << "Enter the number of members for Division 2: ";
                cin >> n;
                cout << "Enter the PRN and Name of the members for Division 2:" << endl;
                for (int i = 0; i < n; i++) {
                    cout << "Enter PRN: ";
                    cin >> prn;
                    cout << "Enter Name: ";
                    cin.ignore(); // To ignore the newline character left in the buffer
                    getline(cin, name); // Read full name including spaces
                    division2.addMember(prn, name);
                }
                break;
            }
            case 2: {
                // Display members of division 1
                cout << "\nMembers of Division 1:\n";
                division1.displayMembers();

                // Display members of division 2
                cout << "\nMembers of Division 2:\n";
                division2.displayMembers();
                break;
            }
            case 3: {
                // Concatenate two lists
                cout << "\nConcatenating the lists...\n";
                division1.concatenateLists(division2);

                // Display members after concatenation
                cout << "\nMembers after concatenation:\n";
                division1.displayMembers();
                break;
            }
            case 4: {
                // Compute total members in the club
                cout << "\nTotal members in the club: " << division1.totalMembers() << endl;
                break;
            }
            case 5: {
                cout << "\nExiting the program.\n";
                break;
            }
            default: {
                cout << "\nInvalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 5);

    return 0;
}
