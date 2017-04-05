#include <iostream>
using namespace std;

class Tree{
private:
 	struct node{
  		int key;
  		node * leftChild;
  		node * rightChild;
 	};
 	node * root;
public:
 	Tree(){
  		root = NULL;
 	}
 
	~Tree(){
 
	}
 
	void insert(int key){
  		if(root == NULL){
			node * newNode = new node;
			newNode->key = key;
			newNode->leftChild = NULL;
			newNode->rightChild = NULL;
			root = newNode;
		}
		else{
			node * current = root;
			node * newNode = new node;
			newNode->key = key;
			newNode->leftChild = NULL;
			newNode->rightChild = NULL;
			while(1){
				if(key > current->key){
					if(current->rightChild == NULL){
						current->rightChild = newNode;
						return;
					}
					else{
						current = current->rightChild;
					}
				}
				else{
					if(current->leftChild == NULL){
						current->leftChild = newNode;
						return;
					}
					else{
						current = current->leftChild;
					}
				}
			}
		}
	}

	node * search(int key){
		node * current = root;
		while(current != NULL){
			if(key == current->key){
				return current;
			}
			else if(key > current->key){
				current = current->rightChild;
			}
			else{
				current = current->leftChild;
			}
		}
		return current;
	}

	node * remove(node * root, int key){
		if(root == NULL)
			return root;
		else if(key < root->key)
			root->leftChild = remove(root->leftChild, key);
		else if(key > root->key)
			root->rightChild = remove(root->rightChild, key);
		else{
			//if has no child
			if(root->leftChild == NULL && root->rightChild == NULL){
				delete root;
				root = NULL;
			}
			//has one child
			else if(root->leftChild == NULL){
				node * temp = root;
				root = root->rightChild;
				delete temp;
			}
			else if(root->rightChild == NULL){
				node * temp = root;
				root = root->leftChild;
				delete temp;
			}
			//has two children
			else{
				node * temp = findMin(root->rightChild);
				root->key = temp->key;
				root->rightChild = remove(root->rightChild, temp->key);
			}
		}
		return root;
	}

	node * findMin(node * root){
		if(root->leftChild == NULL)
			return root;
		else
			findMin(root->leftChild);
	}
	
	node * getRoot(){
		return root;
	}
};

int main(){
 	Tree tree;
	tree.insert(15);
	tree.insert(10);
	tree.insert(5);
	tree.insert(17);
	cout << (tree.search(10)->leftChild)->key << endl;
	tree.remove(tree.getRoot(), 5);	
	if(tree.search(5) == NULL)
		cout << "5 deleted" << endl;
	else
		cout << "5 not deleted" << endl;
	return 0;
}
