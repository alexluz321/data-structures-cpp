//
//  doublyLinkedList.cpp
//  Doubly Linked List
//
//  Created by Alexandre Costa
//  Copyright © 2017 Alexandre Costa. All rights reserved.
//

#include <iostream>

using namespace std;

struct node{
    int value;
    node * next;
    node * previous;
};

class LinkedList{
private:
    node * head;
    node * tail;
    int size;
public:
    LinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    ~LinkedList(){
        node * current = head;
        node * toDelete;
        while(current != tail){
            toDelete = current;
            current = current->next;
            delete toDelete;
        }
        delete current;
        size = 0;
    }
    int numElements(){
        return size;
    }
    void add(int value){
        if(size > 0){
            node * newNode = new node;
            newNode->value = value;
            newNode->next = head;
            tail->next = newNode;
            head->previous = newNode;
            newNode->previous = tail;
            tail = newNode;
            ++size;
        }
        else{
            node * newNode = new node;
            newNode->value = value;
            newNode->next = newNode;
            newNode->previous = newNode;
            head = newNode;
            tail = newNode;
            ++size;
        }
    }
    bool add(int value, int index){
        if(index >= 0 && index < size){
            node * newNode = new node;
            newNode->value = value;
            node * oldNode = at(index);
            (oldNode->previous)->next = newNode;
            newNode->next = oldNode;
            oldNode->previous = newNode;
            if(index == 0){
                head = newNode;
                tail->next = newNode;
            }
            else if(index == size){
                tail = newNode;
                head->previous = newNode;
            }
            return true;
        }else{
            return false;
        }
    }
    bool remove(int index){
        if(index >= 0 && index < size){
            node * temp = at(index);
            (temp->previous)->next = temp->next;
            (temp->next)->previous = temp->previous;
            if(index == 0){
                head = temp->next;
                tail->next = head;
            }
            else if(index == size){
                tail = temp->previous;
                head->previous = tail;
            }
            delete temp;
            --size;
            return true;
        }
        else
            return false;
    }
    bool remove(struct node *element){
        node * current = head;
        if(head == element){
            tail->next = head->next;
            head = tail->next;
            head->previous = tail;
            delete element;
            --size;
            return true;
        }
        else if(tail == element){
            head->previous = tail->previous;
            tail = head->previous;
            tail->next = head;
            delete element;
            --size;
            return true;
        }
        while(current != tail){
            if(current == element){
                (element->previous)->next = element->next;
                (element->next)->previous = element->previous;
                delete element;
                --size;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    struct node * at(int index){
        node * wanted = head;
        if(index < size && index >= 0){
            for(int i = 0; i < index; ++i){
                wanted = wanted->next;
            }
        }
        return wanted;
    }
    void printList(){
        if(size > 0){
            node * temp = head;
            for(int i = 0; i < size; ++i){
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    
};

int main(int argc, const char * argv[]) {
    LinkedList l;
    l.add(5);
    l.add(4);
    l.printList();
    l.remove(0);
    l.printList();
    l.add(10);
    l.printList();
    l.add(20);
    l.printList();
    l.remove(1);
    l.printList();
    l.remove(l.at(0));
    l.printList();
    l.add(1,1);
    cout << "number of elements = " << l.numElements() << endl;
    l.printList();
    return 0;
}
