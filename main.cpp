#include <iostream>
#include <queue>
using namespace std;

template <typename Key, typename Value>
class BST
{
private:
    struct Node{
        Key key;
        Value value;
        Node *left;
        Node *right;
        Node(Key key, Value value)
        {
            this->key = key;
            this->value = value;
            this->left= this->right =NULL;
        }
        Node(Node *node)
        {
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;

        }


       };
        Node *root;
        int count;

    public:
        BST()
        {
            root = NULL;
            count =0;
        }
        ~BST()
        {
            destory(root);

        }
        int size()
        {
            return count;
        }
        bool isEmpty()
        {
            return count == 0;

        }

        void insert(Key key, Value value)
        {
            root = insert(root, key, value);
        }
        bool contain(Key key)
        {
            return contain(root, key);
        }

        Value* search(Key key)
        {
            return search(root, key);
        }


        void preOrder(){
            preOrder(root);
        }
        void inOrder()
        {
            inOrder(root);
        }


        void postOrder()
        {
            postOrder(root);
        }
        void levelOrder(){
            queue<Node*>q;
            q.push(root);
            while(!q.empty())
            {
                Node *node = q.front();
                q.pop();
                cout<<node->key<<endl;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        Key minmum(){
            assert(count!=0);
            Node* minNode = minmum(root);
            return minNode->key;
        }
        Key maxmum(){
            assert(count!=0);
            Node* maxNode = maxmum(root);
            return maxNode->key;

        }


        void removemin()
        {
            if(root)
                root = removemin(root);
        }
        void removemax()
        {
            if(root)
                root = removemax(root);

        }
        void remove(Key key)
        {
            root = remove(root , key);

        }
private:
    Node* insert(Node *node, Key key, Value value)
    {
            if(node == NULL){
                count++;
                return new Node(key, value);
            }
            if(key == node->key)
                node->value = value;
            else if(key < node->key)
                node->left = insert(node->left, key , value);
            else
                node->right = insert(node->right,key, value);
            return node;

    }

    bool contain(Node* node, Key key)
    {
            if(node == NULL)
                return false;
            if(key == node->key)
                return true;
            else if(key <node->key)
                return contain(node->left , key);
            else
                return contain(node->right, key);
    }

    Value* search(Node* node, Key key)
    {
            if(node == NULL)
                return NULL;
            if(key == node->key)
                return &(node->key);
            else if(key < node->key)
                return search(node->left,key);
            else
                return search(node->right,key);

        }

        void preOrder(Node* node)
        {
            if(node!=NULL) {

                cout << node->key << endl;
                preOrder(node->left);
                preOrder(node->right);

            } }
        void inOrder(Node* node)
        {
            if(node!=NULL)
            {
                inOrder(node->left);
                cout<<node->key<<endl;
                inOrder(node->right);
            }
        }

        void postOrder(Node * node)
        {
            if(node!=NULL)
            {
                postOrder(node->left);
                postOrder(node->right);
                cout<<node->key<<endl;
            }
        }

        void destory(Node* node)
        {
            if(node!=NULL){
                destory(node->left);
                destory(node->right);
                delete node;
                count--;


        }}
        Node* minmum(Node* node)
        {
            if(node->left == NULL)
                return node;
            return minmum(node->left);
        }

        Node* maxmum(Node* node)
        {
            if(node->right == NULL)
                return node;
            return maxmum(node->right);
        }

        Node* removemin(Node* node)
        {
            if(node->left == NULL)
            {
                Node* rightnode = node->right;
                delete node;
                count--;
                return rightnode;

            }
            node->left= removemin(node->left);
            return node;

        }
        Node* removemax(Node* node)
        {
            if(node->right == NULL)
            {
                Node* leftnode = node->left;
                delete node;
                count--;
                return leftnode;
            }
            node->right = removemax(node->right);
            return node;

        }

        Node* remove(Node* node, Key key)
        {
            if(node ==NULL)
                return NULL;
            if(key < node->key)
            {
                node->left = remove(node->left , key);
                return node;
            }
            else if(key >node->key)
            {
                node->right = remove(node->right , key);
                return node;

            }
            else
            {
                if(node->left == NULL)
                {
                    Node *rightNode = node->right;
                    delete node;
                    count --;
                    return rightNode;
                }
                if(node->left == NULL)
                {
                    Node *leftNode = node->left;
                    delete node;
                    count--;
                    return leftNode;
                }

                Node *delNode = node;
                Node *successor = new Node(minmum(node->right));

                count++;

                successor->right = removemin(node->right);
                successor->left = node>left;
                delete delNode;
                count--;
                return successor;

            }
        }

    };






template <typename T>
int binaryfind(T arr[], int n, T target)
{
    int l=0;
    int r = n-1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(arr[mid] < target)
            l = mid+1;
        else if(target < arr[mid])
            r = mid-1;
        else
            return mid;

    }
    return -1;
}

int main() {

    int arr[5] = {1,2,4,5,9};
    int t =  binaryfind(arr,5,4);
    cout<<t<<" ";
    std::cout << "Hello, World!" << std::endl;
    return 0;
}