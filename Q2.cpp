#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        // int* arr;
        Node(int data) : data(data),next(nullptr){

        } 
};

class LinkedList{
    private:
        Node* head;

    public:
        LinkedList(){
            head = nullptr;
        }

        void InsertAtEnd(int val){
            if (head==nullptr)
            {
                Node* newNode = new Node(val);
                newNode->next = nullptr;
                head = newNode;
                return;
            }
            else{
                Node* temp = head;
                while (temp->next!=nullptr)
                {
                    temp = temp->next;
                }

                Node* newNode = new Node(val);
                temp->next = newNode;
                return;
            }
        }

        int CountNodes(){
            Node* temp = head;
            int count = 0;
            if (head==nullptr)
            {
                cout << "List is empty\n";
                return count;
            }
            
            while (temp!=nullptr)
            {
                temp = temp->next;
                count = count+1;
            }
            return count;
        }

        int ReturnNum(int i){
            if (head==nullptr)
            {
                cout << "The list is empty" << endl;
                return -1;
            }
            
            else{
                Node* temp = head;
                for (int j = 0; j < i; j++)
                {
                    temp = temp->next;
                }
                return temp->data;
            }
        }

};

int main() {
   LinkedList l1;
    l1.InsertAtEnd(4);
    l1.InsertAtEnd(4);

   int size = l1.CountNodes();
   int* arr = new int[size];
   int* arr2 = new int[size];
   int count2 = size;
   for (int i = 0; i < size; i++)
   {
    arr[i] = l1.ReturnNum(i);
    arr2[count2-1] = arr[i];
    count2-=1;
   }
   count2 = size;
   bool same;
   for (int i = 0; i < l1.CountNodes(); i++)
   {
    if (arr[i]==arr[count2-1])
    {
        same = true;
    }
    else{
        same = false;
        cout << "Not a palindrome" << endl;
        break;
    }
    count2-=1;
    
   }
   if (same==true)
   {
    cout << "The list contains a palindrome" << endl;
   }
   


//    for (int i = 0; i < l1.CountNodes(); i++)
//    {
//     cout << arr[i] << " " << endl;
//     cout << arr2[i] << " " << endl;

//    }
   return 0;
}