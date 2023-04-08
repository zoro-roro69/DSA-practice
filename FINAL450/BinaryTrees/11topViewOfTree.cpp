 #include <bits/stdc++.h> 
 using namespace std;  

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};


struct Pair{
    Node *node;
    int distance;

    Pair(Node *n = NULL, int d = 0){
        node = n;
        distance = d;
    }
    
};

vector <int> topView(Node *root){
    if (root == NULL)
        return {};

    queue <Pair *> q;

    q.push(new Pair(root, 0));

    stack <int> left;
    vector <int> right;

    int min_ = 0; //min distance for left side
    int max_ = 0; //max distance for right side

    while(!q.empty()){
        Pair *front = q.front(); q.pop();

        if (front->distance < min_){
            min_ = front->distance;
            left.push(front->node->data);
        }

        if (front->distance > max_){
            max_ = front->distance;
            right.push_back(front->node->data);
        }

        if (front->node->left){
            q.push(new Pair(front->node->left, front->distance-1));
            // cout << "ghere" <<endl;
        }
        if (front->node->right){
            q.push(new Pair(front->node->right, front->distance+1));
            // cout << "ghere" <<endl;
        }
    }
    vector <int> res;
    while(!left.empty()){
        res.push_back(left.top()); left.pop();
    }

    res.push_back(root->data);

    for (auto x:right)
        res.push_back(x);

    return res;
}

int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    vector <int> res = topView(root);

    for (auto x:res)
        cout << x << " ";
    
    cout << endl;

}