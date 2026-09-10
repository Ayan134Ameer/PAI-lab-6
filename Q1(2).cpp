#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val) : data(val),next(nullptr){
    }
};

class LinkedList{
private:
    Node* head;
    Node* evenhead;
    Node* oddhead;
    Node* eventail;
    Node* oddtail;
public:
    LinkedList(){
        head = nullptr;
        evenhead = nullptr;
        oddhead = nullptr;
        eventail = nullptr;
        oddtail = nullptr;
    }

    void Insert_Tail(int val){
        if(head==nullptr){
            Node* newNode = new Node(val);
            head = newNode;
            newNode->next = nullptr;
            return;
        }
        Node* temp = head;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        temp->next = newNode;
        return;
    }

    void display_list(){
        if (head==nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        while(temp!=nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n" << endl;
        return;
    }

    void Arrange(){
        if(head==nullptr){ //Empty list case
            cout << "Empty list" << endl;
            return;
        }
        else if(head->next==nullptr){ //Single Node case
            cout << "List has only one node" << endl;
            display_list();
        }
        else{
            Node* temp = head;
            while(temp!=nullptr){
                if (temp->data%2==0)
                {
                    if (evenhead==nullptr)
                    {
                        evenhead = temp;
                        eventail = temp;
                        temp = temp->next;
                        eventail->next = nullptr;

                    }
                    else if(evenhead!=nullptr){
                        eventail->next = temp;
                        eventail = temp;
                        temp = temp->next;
                        eventail->next = nullptr;

                    }
                }
                else{
                    if (oddhead==nullptr)
                    {
                        oddhead = temp;
                        oddtail = temp;
                        temp = temp->next;
                        oddtail->next = nullptr;


                    }
                    else if (oddhead!=nullptr)
                    {
                        oddtail->next = temp;
                        oddtail = temp;
                        temp = temp->next;
                        oddtail->next = nullptr;

                    }
                }      
            }

            if(evenhead==nullptr){
                // Node* temp = oddhead;
                // while(temp!=nullptr){
                //     cout << temp->data << " ";
                //     temp = temp->next;
                // }
                // cout << "\n";
                // return;
                head = oddhead;
                display_list();
            }
            else{
                eventail->next = oddhead;
                // Node* temp = evenhead;
                // while (temp!=nullptr)
                // {
                //     cout << temp->data << " ";
                //     temp = temp->next;
                // }
                // cout << "\n";
                // return;
                head = evenhead;
                display_list();
            }
        }

    }
    

};


int main() {
   
    LinkedList l1;
    l1.Insert_Tail(1);
    l1.Insert_Tail(2);
    l1.Insert_Tail(4);
    l1.Arrange();

   return 0;
}