#include <iostream>
#include <string>

using namespace std;

const int SIZE = 3;

struct Review{
    double rating;
    string comment;
    Review * next;
};

// prototypes (probably will have more)
Review * addFront(Review * head, double r, string c);
Review * addBack(Review * head, double r, string c);
double calcAverage(Review * head);

// create reviews, add to linked list, display each one, calc and display average
int main(){
    Review * head = nullptr;
    int inputMethod;
    char cont = 'y';
    double r;
    string c;

    cout << "[1] - New reviews are added to front of linked list\n[2] - New reviews are added to back of linked list" << endl;
    cout << "Choose preferred method for adding reviews: ";
    cin >> inputMethod;

    switch (inputMethod){
        // add case to check if char is other than y/n
        case 1:
            while (cont == 'y'){
                cout << "Enter review rating: ";
                cin >> r;
                cout << "Enter review comments: ";
                getline(cin, c);
                head = addFront(head, r, c);
                cout << "Enter another review? [y/n]: ";
                cin >> cont;
                cin.ignore();
            }
        case 2:
            while (cont == 'y'){
                cout << "Enter review rating: ";
                cin >> r;
                cout << "Enter review comments: ";
                getline(cin, c);
                head = addFront(head, r, c);
                cout << "Enter another review? [y/n]: ";
                cin >> cont;
                cin.ignore();
            }
    }
}

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
    cout << head->rating << " " << head->comment << endl;
    return head;
}

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
    cout << head->rating << " " << head->comment << endl;
    return head;
}

// Calculates average of all reviews
double calcAverage(Review * head){
    Review * current = head;
    double average = 0;
    for (int i = 0; i < SIZE; i++){
        average += current->rating;
        current = current->next;
    }
    average /= SIZE;
    return average;
}