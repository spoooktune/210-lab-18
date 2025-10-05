// COMSC-210 | Lab 18 | Amrutha Sriprasana
// Made w/ VSCode

#include <iostream>
#include <string>

using namespace std;

// Movie review node for linked list
struct Review{
    double rating;
    string comment;
    Review * next;
};

// prototypes (probably will have more)
Review * addFront(Review * head, double r, string c);
Review * addBack(Review * head, double r, string c);
double calcAverage(Review * head);
void displayAll(Review * head);

// create reviews, add to linked list based on preferred method, display all reviews and average
int main(){
    Review * head = nullptr;
    int inputMethod;
    char cont = 'y';
    double r;
    string c;

    cout << "[1] - New reviews are added to front of linked list\n[2] - New reviews are added to back of linked list" << endl;
    cout << "Choose preferred method for adding reviews: ";
    cin >> inputMethod;

    while (cont != 'n'){ // checks if still want to input reviews
        switch (inputMethod){ // checks preferred input method
            case 1: // adds in front
                if (cont == 'y'){
                    cout << "Enter review rating: ";
                    cin >> r;
                    cin.ignore();
                    cout << "Enter review comments: ";
                    getline(cin, c);
                    head = addFront(head, r, c);
                    cout << "Enter another review? [y/n]: ";
                    cin >> cont;
                    cont = tolower(cont);
                }
                else if (cont != 'n'){ // runs if cont is anything other than 'y' or 'n'
                    cout << "Invalid input. Please enter [y/n]: ";
                    cin >> cont;
                    cont = tolower(cont);
                }
                break;
            case 2: // adds in back
                if (cont == 'y'){
                    cout << "Enter review rating: ";
                    cin >> r;
                    cin.ignore();
                    cout << "Enter review comments: ";
                    getline(cin, c);
                    head = addBack(head, r, c);
                    cout << "Enter another review? [y/n]: ";
                    cin >> cont;
                    cont = tolower(cont);
                }
                else if (cont != 'n'){ // runs if cont is anything other than 'y' or 'n'
                    cout << "Invalid input. Please enter [y/n]: ";
                    cin >> cont;
                    cont = tolower(cont);
                }
                break;
            default: // runs if inputMethod is number other than 1 or 2
                cout << "Invalid choice. Please enter 1 or 2: ";
                cin >> inputMethod;
        }
    }
    cout << "\nDisplaying all reviews:" << endl;
    displayAll(head);
}

// Adds new node in front
Review * addFront(Review * head, double r, string c){
    Review * newR = new Review;
    if (!head){
        newR->next = nullptr;
        newR->rating = r;
        newR->comment = c;
        head = newR;
    }
    else{
        newR->next = head;
        newR->rating = r;
        newR->comment = c;
        head = newR;
    }
    //cout << head->rating << " " << head->comment << endl;
    return head;
}

// Adds new node in back
Review * addBack(Review * head, double r, string c){
    Review * newR = new Review;
    Review * last = head;
    if (!head){
        newR->next = nullptr;
        newR->rating = r;
        newR->comment = c;
        head = newR;
    }
    else{
        while (last->next != nullptr){
            last = last->next;
        }
        newR->next = nullptr;
        newR->rating = r;
        newR->comment = c;
        last->next = newR;
    }
    //cout << head->rating << " " << head->comment << endl;
    return head;
}

// Calculates average of all reviews
double calcAverage(Review * head){
    Review * current = head;
    double average = 0;
    int size = 0;
    while (current){
        average += current->rating;
        current = current->next;
        size++;
    }
    average /= size;
    return average;
}

// Displays all reviews in formatted way
void displayAll(Review * head){
    Review * current = head;
    int i = 1;
    while(current){
        cout << "> Review " << i << ": " << current->rating << ", " << current->comment << endl;
        current = current->next;
        i++;
    }
    cout << "> Average Rating: " << calcAverage(head) << endl;
}