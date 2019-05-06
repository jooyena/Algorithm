#include <iostream>
#define null 0
using namespace std;
template <typename T>
class Tree;
template <typename T>

class TreeNode {
    friend class Tree<T>;
private:
    T data;
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode(T data = 0, TreeNode* left = null, TreeNode* right = null) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
 //���� �Ȱ���...   
    friend ostream& operator<<(ostream& os, const TreeNode<T>& node) {
        os << "[data] " << node.data << endl;
        if (node.left != null) {
            os << "[left] " << node.left->data << endl;
        }
        if (node.right != null) {
            os << "[right] " << node.right->data << endl;
        }
        return os;
    } //�̰� ����..... 
};
class Tree {
	private:
		TreeNode <T> * root;//����ؼ� ������ ��� 
	public:
		Tree(T data){
			root = new TreeNode<T>(data);	
		}
		
		TreeNode <T> * insertNode(TreeNode<T> * child){
			//1. �� ó�� ��Ʈ ������� Ȯ���Ѵ�
			//2. �ߺ��� �ִ��� Ȯ���Ѵ�. 
			//3. �ӽ� TreeNode�� �ڸ��� ��´� 
			if(search())
			
		}
		
		/* ���� �� ���� �� search 
		TreeNode <T> * search(TreeNode<T> * root,  T data){
			if(root == null) return null;
			while(root =!null){
				if(root -> data == node -> data) return * root;
				
				if(root->data < node->data){
					root=root -> right;
				}
				else root =root -> left;
			}
		}
		*/
		
		TreeNode<T>* search(TreeNode<T>* current, T data) {
	        if (current == null) return null;
	        if (data == current->data) {
	            return current;
	        }
	        else if (data < current->data) {
	            search(current->left, data);
	        }
	        else {
	            search(current->right, data);
	        }
		}
	
};
