#include <iostream>

using namespace std;

struct Review{
    double rating;
    string comment;
    Review * next;
};

// prototypes (probably will have more)
Review * addFront(Review * head, double r, string c);
Review * addBack(Review * head, double r, string c);

int main(){
    // create reviews, add to linked list, display each one, calc and display average
}