#include <iostream>
#include <string>
using namespace std;

struct Icecream {
    string name[10];
    int price[10];
    int count;
};

// Function to display the Menu
void displayMenu(const Icecream &p) {
    for (int i = 0; i < p.count; i++) {
        cout << i + 1 << ". " << p.name[i] << " - " << p.price[i] << endl;
    }
}

// Function to calculate the bill
int calculateBill(const Icecream &p, int choice) {
    int price = p.price[choice - 1];
    int tax = (price * 5) / 100; // 5% tax
    return price + tax;
}

// Function to add a new menu item
void addItem(Icecream &p) {
    if (p.count >= 10) {
        cout << "No space to add new items!" << endl;
        return;
    }

    cout << "Enter name for new item: ";
    cin.ignore();
    getline(cin, p.name[p.count]);

    cout << "Enter price for new item: ";
    cin >> p.price[p.count];

    while (p.price[p.count] < 0) {
        cout << "Invalid input. Enter the correct price for the item: ";
        cin >> p.price[p.count];
    }

    p.count++;
}

// Function to edit a menu item
void editMenu(Icecream &p) {
    int index;
    cout << "Enter the index (1-" << p.count << ") of the item you want to edit: ";
    cin >> index;

    if (index < 1 || index > p.count) {
        cout << "Invalid index!" << endl;
        return;
    }

    index--;
    cin.ignore();
    cout << "Enter new name for item " << index + 1 << ": ";
    getline(cin, p.name[index]);

    cout << "Enter new price for item " << index + 1 << ": ";
    cin >> p.price[index];

    while (p.price[index] < 0) {
        cout << "Invalid input. Enter the correct price for the item: ";
        cin >> p.price[index];
    }
}

int main() {
    int site;

    Icecream cone = {
        {"Waffle cone", "Oreo Waffle", "Cookie Waffle", "Simple Vanilla cone", "Choco dip cone"},
        {120, 170, 190, 150, 220},
        5
    };

    Icecream cup = {
        {"Super cup", "Super oreo cup", "Super Brownie cup", "Super Dip cone", "Waffle Dip cup"},
        {190, 230, 250, 260, 270},
        5
    };

    Icecream sundae = {
        {"Blue berry", "Vanilla", "Caramel", "Toffee popcorn", "Special Nutty"},
        {350, 300, 350, 360, 350},
        5
    };

repeat:
    cout << "______ WELCOME TO SWEET CREAM ______" << endl;
    cout << "Do you want to login to the admin site or customer site?" << endl;
    cout << "Press 1 for admin site" << endl;
    cout << "Press 2 for customer site" << endl;
    cin >> site;

    if (site == 1) {
        int adminChoice;
        do {
            cout << "\n--- Admin Menu ---" << endl;
            cout << "1. View Cones Menu" << endl;
            cout << "2. View Cups Menu" << endl;
            cout << "3. View Sundaes Menu" << endl;
            cout << "4. Edit Cones Menu" << endl;
            cout << "5. Edit Cups Menu" << endl;
            cout << "6. Edit Sundaes Menu" << endl;
            cout << "7. Add Item to Cones Menu" << endl;
            cout << "8. Add Item to Cups Menu" << endl;
            cout << "9. Add Item to Sundaes Menu" << endl;
            cout << "10. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> adminChoice;

            switch (adminChoice) {
                case 1: cout << "Cones Menu:" << endl; displayMenu(cone); break;
                case 2: cout << "Cups Menu:" << endl; displayMenu(cup); break;
                case 3: cout << "Sundaes Menu:" << endl; displayMenu(sundae); break;
                case 4: cout << "Edit Cones Menu:" << endl; editMenu(cone); break;
                case 5: cout << "Edit Cups Menu:" << endl; editMenu(cup); break;
                case 6: cout << "Edit Sundaes Menu:" << endl; editMenu(sundae); break;
                case 7: cout << "Add Item to Cones Menu:" << endl; addItem(cone); break;
                case 8: cout << "Add Item to Cups Menu:" << endl; addItem(cup); break;
                case 9: cout << "Add Item to Sundaes Menu:" << endl; addItem(sundae); break;
                case 10: cout << "Exiting admin site..." << endl; break;
                default: cout << "Invalid choice! Please try again." << endl;
            }
        } while (adminChoice != 10);

    } else if (site == 2) {
        char ans;
        int totalbill = 0;

        do {
            int choice;

            cout << "\n--- Menus ---" << endl;
            cout << "Cones Menu:" << endl; displayMenu(cone);
            cout << "Cups Menu:" << endl; displayMenu(cup);
            cout << "Sundaes Menu:" << endl; displayMenu(sundae);

            do {
                cout << "\nSelect your favorite category:" << endl;
                cout << "1. Cones" << endl;
                cout << "2. Cups" << endl;
                cout << "3. Sundaes" << endl;
                cin >> choice;

                if (choice > 3 || choice < 1) {
                    cout << "Invalid input, please enter correct number" << endl;
                }
            } while (choice > 3 || choice < 1);

            if (choice == 1) {
                displayMenu(cone);
                do {
                    cout << "Select any item of your choice: ";
                    cin >> choice;
                } while (choice < 1 || choice > cone.count);
                totalbill += calculateBill(cone, choice);

            } else if (choice == 2) {
                displayMenu(cup);
                do {
                    cout << "Select any item of your choice: ";
                    cin >> choice;
                } while (choice < 1 || choice > cup.count);
                totalbill += calculateBill(cup, choice);

            } else if (choice == 3) {
                displayMenu(sundae);
                do {
                    cout << "Select any item of your choice: ";
                    cin >> choice;
                } while (choice < 1 || choice > sundae.count);
                totalbill += calculateBill(sundae, choice);
            }

            cout << "Do you want to order more? (y/n): ";
            cin >> ans;

        } while (ans == 'y' || ans == 'Y');

        cout << "Your total bill is: " << totalbill << endl;
        cout << "Thank you for your order!" << endl;

        char editChoice;
        cout << "Do you want to go to the admin site to edit the menu? (y/n): ";
        cin >> editChoice;
        if (editChoice == 'y' || editChoice == 'Y') {
            goto repeat;
        }

    } else {
        cout << "Invalid input" << endl;
        goto repeat;
    }

    return 0;
}
