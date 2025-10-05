#include <iostream>

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

int main(){
    // create reviews, add to linked list, display each one, calc and display average
    Review * head = nullptr;
    head = addFront(head, 4.8, "Oscar Contender");
    head = addBack(head, 4.1, "Brilliant lead acting");
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

double calcAverage(Review * head){
    // calculate average of all review
}