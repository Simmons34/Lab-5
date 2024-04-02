#include <iostream>

template <typename T>

class BST {
	private:
		int size = 0;

		class Node {
			public:
				T data;
				Node* left;
				Node* right;

				Node(T d) {
					data = d;
					left = nullptr;
					right = nullptr;
				}
		};

		Node* root = nullptr;
	public:
		Node* Search(T item) {
			Node* curr = root;
			while(curr->data != item) {
				if (curr->data < item) {
					curr = curr->left;
				} else {
					curr = curr->right;
				}

				if (curr == nullptr) {
					return nullptr;
				}
			}
			return curr;
		}

		void Add(T item) {
			Node* parent;
			Node* curr = root;
			Node* newItem = new Node(item);

			if (root == nullptr) {
				root = newItem;
				size++;
			} else {
				while(curr != nullptr) {
					parent = curr;
					if (curr->data > item) {
						curr = curr->left;
					} else if (curr->data < item) {
						curr = curr->right;
					} else {
						std::cout << "Item: \"" << item << "\" already in list" << std::endl;
						break;
					}
				}

				if (parent->data > item) {
					parent->left = newItem;
					size++;
				} else if (parent->data < item) {
					parent->right = newItem;
					size++;
				} 
			}
		}

		void Remove(T item) {
			if (root == nullptr) {
				std::cout << "Error: tree is empty." << std::endl;
			} else {
				Node* curr = root;
				if (Search(item) != nullptr) {
					RemoveFromTree(Search(item));
					size--;
				} else {
					std::cout << "Error: Item not found." << std::endl;
				}
			}
		}

		void Print() {
			Node* curr = root;
			if (root != nullptr){
				Print(root);
			}
		}

		void TPrint() {
			Node* curr = root;
			if (root != nullptr){
				TPrint(root);
			}
		}

		void RPrint() {
			Node* curr = root;
			if (root != nullptr){
				RPrint(root);
			}
		}

		int GetSize() {
			return size;
		}

	private:
		void RemoveFromTree(Node* remove) {
			if (remove->left == nullptr && remove->right == nullptr){
				Node* tmp = remove;
				remove = nullptr;
				delete tmp;
			} else if (remove->left != nullptr) {
				Node* parent;
				Node* curr = remove->left;
				while (curr->right != nullptr) {
					parent = curr;
					curr = curr->right;
				}
				remove->data = curr->data;
				parent->right = nullptr;
				delete curr;
			} else {
				Node* parent;
				Node* curr = remove->right;
				while (curr->left != nullptr) {
					parent = curr;
					curr = curr->left;
				}
				remove->data = curr->data;
				parent->left = nullptr;
				delete curr;
			}
		}

		void Print(Node* curr) {
			if (curr->left != nullptr) {
				Print(curr->left);
			}

			PrintItem(curr);

			if (curr->right != nullptr) {
				Print(curr->right);
			}
		}

		void TPrint(Node* curr) {
			PrintItem(curr);

			if (curr->left != nullptr) {
				TPrint(curr->left);
			}

			if (curr->right != nullptr) {
				TPrint(curr->right);
			}

		}

		void RPrint(Node* curr) {
			if (curr->right != nullptr) {
				RPrint(curr->right);
			}

			PrintItem(curr);

			if (curr->left != nullptr) {
				RPrint(curr->left);
			}
		}

		void PrintItem(Node* curr) {
			if (curr != nullptr){
				std::cout << curr->data << std::endl;
			}
		}

		//void Compare(){}
};
