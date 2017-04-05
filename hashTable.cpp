//
//  hashTable.cpp
//  HashTable
//
//  Created by Alexandre Costa
//  Copyright © 2017 Alexandre Costa. All rights reserved.
//

#include <iostream>

using namespace std;

class HashTable{
private:
    static const int tableSize = 128;
    
    struct bucketItem{
        string key;
        int value;
        bucketItem * next;
    };
    
    bucketItem **hashTable;
    
    int hash(string key){
        int index = 0, value = 0;
        for (int i = 0; i < key.length(); ++i) {
            value += key[i];
        }
        index = value % tableSize;
        return index;
    }
    
public:
    HashTable(){
        hashTable = new bucketItem*[tableSize];
        for(int i = 0; i < tableSize; ++i){
            bucketItem * newItem = new bucketItem;
            hashTable[i] = newItem;
            hashTable[i]->key = "";
            hashTable[i]->value = NULL;
            hashTable[i]->next = NULL;
        }
    }
    
    ~HashTable(){
        delete[] hashTable;
    }
    
    void put(string key, int value){
        int index = hash(key);
        if(hashTable[index]->key == ""){//table empty
            hashTable[index]->key = key;
            hashTable[index]->value = value;
        }
        else{//table not empty
            bucketItem * current = hashTable[index];
            while (current->next != NULL) {
                current = current->next;
            }
            bucketItem * newItem = new bucketItem;
            newItem->key = key;
            newItem->value = value;
            newItem->next = NULL;
            current->next = newItem;
        }
    }
    
    struct bucketItem * get(string key){
        int index = hash(key);
        if(hashTable[index]->key == "" ){
            return (struct bucketItem*)NULL;
        }
        else{
            if(hashTable[index]->key == key ){
                return hashTable[index];
            }else{
                bucketItem * current = hashTable[index];
                while (current->key != key) {
                    current = current->next;
                }
                return current;
            }
        }
    }
        
    bool remove(string key){
        int index = hash(key);
        if(hashTable[index]->key == "" ){
            return false;
        }
        else{
            bucketItem * temp;
            if(hashTable[index]->key == key){
                temp = hashTable[index];
                hashTable[index] = hashTable[index]->next;
                delete temp;
            }
            else{
                temp = hashTable[index];
                while ((temp->next)->key != key && temp->next != NULL) {
                    temp = temp->next;
                }
                if(temp->next == NULL)
                    return false;
                else{
                    bucketItem * toDelete = temp->next;
                    temp->next = toDelete->next;
                    delete toDelete;
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    HashTable table;
    table.put("alex", 10);
    cout << "key = " << table.get("alex")->key << " value = " << table.get("alex")->value << endl;
    table.put("xeal", 11);
    cout << "key = " << table.get("xeal")->key << " value = " << table.get("xeal")->value << endl;
    if(table.get("any") != NULL)
        cout << "key = " << table.get("any")->key << " value = " << table.get("any")->value << endl;
    return 0;
}
