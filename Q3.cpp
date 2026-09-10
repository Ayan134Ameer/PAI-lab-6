#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    string name;
    Node* next;
    Node(string val) : name(val), next(nullptr){}
};

class CircularList{
private:
    Node* head;
    Node* tail;
public:
    CircularList(){
        head = nullptr;
        tail = nullptr;
    }
    void insertPlayer(string name){
        Node* newNode = new Node(name);
        if(head==nullptr){
            head = newNode;
            tail = newNode;
            tail->next = head;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
    void displayPlayers(){
        if(head==nullptr){
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        do{
            cout << temp->name << " ";
            temp = temp->next;
        }while(temp!=head);
        cout << "\n";
    }
    void removePlayers(){
        if(head==nullptr){
            cout << "List is empty" << endl;
            return;
        }
        if(head->next==head){
            cout << "Only one player: " << head->name << endl;
            return;
        }
        Node* current = head;
        Node* prev = tail;
        int count = 1;
        while(current->next!=current){
            if(count==3){
                Node* toDelete = current;
                prev->next = current->next;
                if(current==head){
                    head = current->next;
                }
                if(current==tail){
                    tail = prev;
                }
                current = current->next;
                delete toDelete;
                count = 1;
            }
            else{
                prev = current;
                current = current->next;
                count++;
            }
        }
        head = current;
        tail = current;
        cout << "The surviving player is: " << current->name << endl;
    }
};

int main(){
    CircularList team;
    int n;
    cout << "Enter number of players (at least 11): ";
    cin >> n;
    cin.ignore();
    while(n<11){
        cout << "Please enter at least 11 players: ";
        cin >> n;
        cin.ignore();
    }
    for(int i=0;i<n;i++){
        string name;
        cout << "Enter name of player " << i+1 << ": ";
        getline(cin, name);
        team.insertPlayer(name);
    }
    cout << "Batting rotation: ";
    team.displayPlayers();
    team.removePlayers();
    return 0;
}