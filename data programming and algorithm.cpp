#include<iostream>
#include <cstring>
#define MAX_DATA_SIZE 1000

using namespace std;

// The following section implements List ..................................
class ListType {
   public :
    ListType(int n) {
    	MAX_ITEMS = n;
    	nbItems = 0;
    };
    
    void MakeEmpty() {
    	nbItems=0;
    };
    
    bool IsEmpty() const {
    	return (nbItems == 0);
    };
    
    bool IsFull() const {
    	return (nbItems == MAX_ITEMS-1);
    };
    
    void FindNode (int searchItem) {
    	int i=0;
    	while (!((items[i]==searchItem) || (i>= nbItems)))
    		i++;
    	if (i>=nbItems)
    		cout << "\nThe item : " << searchItem << " is not found !\n";
    	else 	cout << "\nThe item : " << searchItem << "is found at position " << i << "\n";
    };
    
    void InsertNode (int position, int newItem) {
    	if (!(nbItems == MAX_ITEMS-1)) {
    	 for (int i = nbItems; i>position; i--)
    	       items[i] = items[i-1];
    	 items[position] = newItem;
    	 nbItems++;
    	}
    };
    
    void DeleteNode(int position) {
    	if (!(nbItems == 0)) {
    	 for (int i=position; i<nbItems; i++)
    	     items[i] = items[i + 1];
    	 items[MAX_ITEMS-1] = NULL;
    	 nbItems--;
    	}
    };
    
    void Display() {
    	cout << "\nContent of the List : \n";
    	for (int i=0; i < nbItems; i++)
    	    cout << "\n" << i << "\t" << items[i];
    	cout << "\n";
    };
    
    void RandomNodes() {
    	for (int i = 0; i < MAX_ITEMS; i++) items[i] = rand()%100+1;
    	nbItems = MAX_ITEMS;
    };
    ~ListType() {}
    
  private:
     int MAX_ITEMS, nbItems;
     int items[MAX_DATA_SIZE];
};

// The following section implements Stack...................................

class StackType {
  private:
    int MAX_ITEMS;
    int *items;
    int top;
  public:
    StackType(int n) {
        MAX_ITEMS = n;
        items = new int[MAX_ITEMS];
        top = -1;
    }
    ~StackType() {
        delete[] items;
    }
    void MakeEmpty() {
        top = -1;
    }
    bool IsEmpty() const {
        return (top == -1);
    }
    bool IsFull() const {
        return (top == MAX_ITEMS - 1);
    }
    void Push(int newItem) {
        if (!IsFull()) {
            top++;
            items[top] = newItem;
        } else {
            cout << "\nStack overflow! Cannot push " << newItem << "\n";
        }
    }
    void Pop() {
        if (!IsEmpty()) {
            cout << "\nPopped item: " << items[top] << "\n";
            top--;
        } else {
            cout << "Stack underflow! Cannot pop.\n";
        }
    }
    void Peek() const {
        if (!IsEmpty()) {
            cout << "\nTop item: " << items[top] << "\n";
        } else {
            cout << "\nStack is empty.\n";
        }
    }
    void DisplayStack() const {
        if (IsEmpty()) {
            cout << "\nStack is empty.\n";
            return;
        }
        cout << "\nContent of the Stack:\n";
        for (int i = 0; i <= top; i++) {
            cout << i << "\t" << items[i] << endl;
        }
    }
    
    void FindItem(int target) const {
        if (IsEmpty()) {
            cout << "\nStack is empty.\n";
            return;
        }
        for (int i = 0; i <= top; i++) {
            if (items[i] == target) {
                cout << "\nItem " << target << " found at index " << i << "\n";
                return;
            }
        }
        cout << "\nItem " << target << " NOT found in stack\n";
    }
    
    void RandomNodes() {
        srand(time(0));
        top = -1; 
        
        for (int i = 0; i < MAX_ITEMS; i++) {
            items[i] = rand() % 100 + 1; 
            top++;
        }
        
        cout << "\nStack filled with " << MAX_ITEMS << " random values.\n";
    }
};
         
#include<iostream>
#include <cstring>
#define MAX_ITEMS 1000	
// The following section implements Queue ..................................
class QueueType {
  private:
    int data[MAX_ITEMS];
    int front, rear;

  public:
    void MakeEmpty() {
        front = 0;
        rear = -1;
    }
  
    QueueType() {      
        MakeEmpty();
    }                  

    
    bool IsEmpty() {
        return front > rear;
    }

    bool IsFull() {
        return rear == MAX_ITEMS - 1;
    }

    void Enqueue(int item) {
        if (IsFull()) {
            cout << "Queue Overflow! cannot Enqueue." << endl;
            return;
        }
        rear++;
        data[rear] = item;
        cout << "Enqueued: " << item << endl;
    }

    int Dequeue() {
        if (IsEmpty()) {
            cout << "Queue Underflow! Cannot dequeue." << endl;
            return -1;
        }
        int item = data[front];
        front++;
        cout << "Dequeued: " << item << endl;
        return item;
    }

    void DisplayQueue() {
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};   
 
 // The following section implements MergeSort ..................................
#include <iostream>
#include <vector>

  void merge(std::vector<int>& arr, int left, int mid, int right) {
      int n1 = mid - left + 1;
      int n2 = right - mid;

      std::vector<int> leftArr(n1), rightArr(n2);

      for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];

      for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

      int i = 0, j = 0, k = left;

      while (i < n1 && j < n2) {
          if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
          } else {
            arr[k] = rightArr[j];
            j++;
          }
          k++;
      }

      while (i < n1) {
          arr[k] = leftArr[i];
          i++;
          k++;
      }

      while (j < n2) {
          arr[k] = rightArr[j];
          j++;
          k++;
      }
}

  void MergeSort(std::vector<int>& arr, int left, int right) {
      if (left >= right)
          return;

      int mid = left + (right - left) / 2;

      MergeSort(arr, left, mid);
      MergeSort(arr, mid + 1, right);

      merge(arr, left, mid, right);
}

  void printArray(const std::vector<int>& arr) {
      for (int i = 0; i < arr.size(); i++)
          std::cout << arr[i] << " ";
      std::cout << std::endl;
}

	

// The following section implements Binary Search ..................................
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

	int binarySearch(int arr[], int left, int right, int target) {
    	if (left > right) {
        return -1;
    }
    
    	int mid = left + (right - left) / 2;
    
    	if (arr[mid] == target) {
        return mid;
    }
    	else if (arr[mid] > target) {
        return binarySearch(arr, left, mid - 1, target);
    }
    	else {
        return binarySearch(arr, mid + 1, right, target);
    }
}

// THe following section implements Binary tree traversals
class BinaryTree {
private:
    Node* root;

    void preorderTraversal(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void inorderTraversal(Node* node) {
        if (!node) return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void postorderTraversal(Node* node) {
        if (!node) return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!root) {
            root = newNode;
            return;
        }

        Node* temp;
        Node* queue[100];
        int front = 0, rear = 0;
        queue[rear++] = root;

        while (front < rear) {
            temp = queue[front++];
            if (!temp->left) {
                temp->left = newNode;
                return;
            } else {
                queue[rear++] = temp->left;
            }

            if (!temp->right) {
                temp->right = newNode;
                return;
            } else {
                queue[rear++] = temp->right;
            }
        }
    }

    void preorder() {
        cout << "Preorder traversal: ";
        preorderTraversal(root);
        cout << endl;
    }

    void inorder() {
        cout << "Inorder traversal: ";
        inorderTraversal(root);
        cout << endl;
    }

    void postorder() {
        cout << "Postorder traversal: ";
        postorderTraversal(root);
        cout << endl;
    }
};

//THe following section implements Graph Traversals

#include <iostream>
#include <queue>

using namespace std;

class GraphTraversals {
private:
    int V;
    vector<vector<int>> adj;

public:
 
    GraphTraversals(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);  
    }

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int u : adj[v]) {
            if (!visited[u]) DFSUtil(u, visited);
        }
    }
	void displayGraph() {
    	cout << "\nGraph adjacency list :\n";
    	for (int i = 0; i < V; i++) {
    		cout << i << " : ";
    		for (int v : adj[i])
    			cout << v << " ";
    			cout << endl;
    			}
    			}
    			
    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS: ";
        DFSUtil(start, visited);
        cout << endl;
    }
    

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS: ";

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int u : adj[v]) {
                if (!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
        cout << endl;
    }
};

//Main program begins here.

int main() {
    char choice = '+';
    char option = '+';
    
    while (!((choice == 'E')||(choice == 'e'))) {
        cout << "\nSelect an option : ";
        cout << "\nl : List";
        cout << "\ns : StackType";
        cout << "\nq : QueueType";
        cout << "\nm : Mergesort";
        cout << "\nb : Binarysearch";
        cout << "\nt : Binarytreetraversals";
        cout << "\ng : Graphtraversals";
        cout << "\ne : Exit";
        cout << "\nEnter your choice : ";
        cin >> choice;
        choice = toupper(choice);
        
        if (choice == 'L') {
            // List operations (your existing code)
            int size = 0;
            cout << "\nEnter the size of the list : ";
            cin >> size;
            ListType list(size);
            option = '+';
            while (!(option == '0')) {
                cout << "\nSelect a List operation : ";
                cout << "\n1 : Create a list";
                cout << "\n2 : Insert a new item";
                cout << "\n3 : Delete an item";
                cout << "\n4 : Find an item";
                cout << "\n5 : Empty the list";
                cout << "\n6 : Test whether the list is empty";
                cout << "\n7 : Test whether the list is full";
                cout << "\n8 : Fill the list randomly";
                cout << "\n9 : Display the content of the list";
                cout << "\n0 : Stop";
                cout << "\nEnter option : ";
                cin >> option;
                switch (option) {
                    case '1': {ListType list(size); break;}
                    case '2': {
                        int position, item;
                        cout << "\nEnter a position and an item : ";
                        cin >> position >> item;
                        list.InsertNode(position, item);
                        break;
                    }
                    case '3': {
                        int position;
                        cout << "\nEnter the position of the item to delete : ";
                        cin >> position;
                        list.DeleteNode(position);
                        break;
                    }
                    case '4': {
                        int item;
                        cout << "\nEnter the item to find : ";
                        cin >> item;
                        list.FindNode(item);
                        break;
                    }
                    case '5': {list.MakeEmpty(); cout << "\nThe list is emptied\n"; break;}
                    case '6': {if (list.IsEmpty()) cout << "\nThe list is empty\n"; else cout << "\nThe list is not empty\n"; break;}
                    case '7': {if (list.IsFull()) cout << "\nThe list is full\n"; else cout << "\nThe list is not full\n"; break;}
                    case '8': {list.RandomNodes(); break;}
                    case '9': {list.Display(); break;}
                    default:;
                }
            }
        } 
        else if (choice == 'S') {
            int size;
            cout << "\nEnter the size of the stack : ";
            cin >> size;
            StackType stack(size);
            option = '+';
            while (!(option == '0')) {
                cout << "\nSelect a Stack operation : ";
                cout << "\n1 : Create a stack";
                cout << "\n2 : Push";
                cout << "\n3 : Pop";
                cout << "\n4 : Find an item";
                cout << "\n5 : Empty the stack";
                cout << "\n6 : Test whether the stack is empty";
                cout << "\n7 : Test whether the stack is full";
                cout << "\n8 : Fill the stack randomly";
                cout << "\n9 : Display the content of the stack";
                cout << "\n0 : Stop";
                cout << "\nEnter option : ";
                cin >> option;
                
                switch (option) {
                    case '1': {
                        stack.MakeEmpty();
                        cout << "\nA new empty stack is created.\n";
                        break;
                    }
                    case '2': {
                        int item;
                        cout << "\nEnter an item to push : ";
                        cin >> item;
                        stack.Push(item);
                        break;
                    }
                    case '3': {
                        stack.Pop();
                        break;
                    }
                    case '4': { 
                        int item;
                        cout << "\nEnter item to find: ";
                        cin >> item;
                        stack.FindItem(item);
                        break;
                    }
                    case '5': {stack.MakeEmpty(); cout << "\nThe stack is emptied\n"; break;}
                    case '6': {if (stack.IsEmpty()) cout << "\nThe stack is empty\n"; else cout << "\nThe stack is not empty\n"; break;}
                    case '7': {if (stack.IsFull()) cout << "\nThe stack is full\n"; else cout << "\nThe stack is not full\n"; break;}
                    case '8': {stack.RandomNodes(); break;}
                    case '9': {stack.DisplayStack(); break;}
                    default:
                        break;
                }
            }
        } 
        else if (choice == 'Q') {
            QueueType q;
            option = '+';
            
            while (!(option == '0')) {
                cout << "\n===== QUEUE MENU =====\n";
                cout << "1. MakeEmpty\n";
                cout << "2. IsEmpty\n";
                cout << "3. IsFull\n";
                cout << "4. Enqueue\n";
                cout << "5. Dequeue\n";
                cout << "6. Display the content of the queue\n";
                cout << "0. Stop\n";
                cout << "\nEnter option : ";
                cin >> option;

                switch (option) {
                    case '1':  
                        q.MakeEmpty();
                        cout << "Queue emptied.\n";
                        break;
                    case '2':  
                        if (q.IsEmpty())
                            cout << "Queue is EMPTY.\n";
                        else
                            cout << "Queue is NOT empty.\n";
                        break;
                    case '3':  
                        if (q.IsFull())
                            cout << "Queue is FULL.\n";
                        else
                            cout << "Queue is NOT full.\n";
                        break;
                    case '4':  {
                        int value;
                        cout << "Enter value to enqueue: ";
                        cin >> value;
                        q.Enqueue(value);
                        break;
                    }
                    case '5': 
                        q.Dequeue();
                        break;
                    case '6':
                        q.DisplayQueue();
                        break;
                    default:
                        break;
                }
            }
        } 
        else if (choice == 'M') {
           
            int n;
            cout << "Enter the number of elements in the array: ";
            cin >> n;

            std::vector<int> arr(n);

            cout << "Enter the elements of the array:\n";
            for (int i = 0; i < n; i++) {
                cout << "Element " << i + 1 << ": ";
                cin >> arr[i];
            }
    
            cout << "\nOriginal array: ";
            printArray(arr);
            MergeSort(arr, 0, arr.size() - 1);

            cout << "\nSorted array: ";
            printArray(arr);
        }    
        else if (choice == 'B') {
            
            int n, target; 
            
            cout << "\n=== Binary Search ===\n";
            cout << "Enter the number of elements: ";
            cin >> n;
            
            int arr[n];
            
            cout << "Enter " << n << " elements in SORTED order:\n";
            
            for (int i = 0; i < n; i++) {
                cout << "Element " << (i + 1) << ": ";
                cin >> arr[i];
            }
            
            cout << "\nSorted Array: ";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << "\n";
            
            cout << "\nEnter the element to search: ";
            cin >> target;
            
            int result = binarySearch(arr, 0, n - 1, target);
            
            if (result != -1) {
                cout << "\nElement " << target << " found at index " << result << endl;
            } else {
                cout << "\nElement " << target << " not found in the array" << endl;
            }
        }  
        else if (choice == 'T') {
            
            BinaryTree tree;
            int n, value;
            char treeOption;
            
            do {
                cout << "\n=== Binary Tree Operations ===\n";
                cout << "1. Insert elements\n";
                cout << "2. Display Preorder\n";
                cout << "3. Display Inorder\n";
                cout << "4. Display Postorder\n";
                cout << "5. Display All Traversals\n";
                cout << "6. Stop\n";
                cout << "Enter your choice: ";
                cin >> treeOption;
                
                switch(treeOption) {
                    case '1':
                        cout << "How many elements do you want to insert? ";
                        cin >> n;
                        cout << "Enter " << n << " elements:\n";
                        for (int i = 0; i < n; i++) {
                            cout << "Element " << (i + 1) << ": ";
                            cin >> value;
                            tree.insert(value);
                        }
                        cout << "Elements inserted successfully!\n";
                        break;
                        
                    case '2':
                        tree.preorder();
                        break;
                        
                    case '3':
                        tree.inorder();
                        break;
                        
                    case '4':
                        tree.postorder();
                        break;
                        
                    case '5':
                        tree.preorder();
                        tree.inorder();
                        tree.postorder();
                        break;
                        
                    case '6':
                        cout << "Returning to main menu...\n";
                        break;
                        
                    default:
                        cout << "Invalid choice!\n";
                        break;
                }
            } while (treeOption != '6');
        }
		else if (choice == 'G') {

            int V;
            cout << "\nEnter number of vertices in the graph: ";
            cin >> V;

            GraphTraversals g(V);
            int graphOption;

            while (true) {
                cout << "\n--- GRAPH MENU ---\n";
                cout << "1. Add Edge\n";
                cout << "2. DFS\n";
                cout << "3. BFS\n";
                cout << "4. Generate random edges\n";
                cout << "5. Display Graph\n";
                cout << "6. Return to Main Menu\n";
                cout << "Enter option: ";
                cin >> graphOption;

                if (graphOption == 1) {
                    int u, v;
                    cout << "Enter edge (u v): ";
                    cin >> u >> v;
                    g.addEdge(u, v);
                }
                else if (graphOption == 2) {
                    int start;
                    cout << "Enter starting node: ";
                    cin >> start;
                    g.DFS(start);
                }
                else if (graphOption == 3) {
                    int start;
                    cout << "Enter starting node: ";
                    cin >> start;
                    g.BFS(start);
                }
                else if (graphOption == 4) {
                if (V < 2) {
                cout << "Need at least 2 vertices to create edges.\n";
                continue;
            }

            srand(time(0)); // seed randomness

            int maxEdges = V * (V - 1) / 2;           // maximum edges for undirected graph without self-loops
            int E = rand() % maxEdges + 1;            // random number of edges (1 to maxEdges)

            vector<vector<bool>> exists(V, vector<bool>(V, false)); // track existing edges

            for (int i = 0; i < E;) {
                int u = rand() % V;
                int v = rand() % V;

                if (u != v && !exists[u][v]) { // avoid self-loop and duplicate
                    g.addEdge(u, v);
                    exists[u][v] = exists[v][u] = true; // mark as added
                    i++; // increment only if edge added
                }
            }

            cout << E << " random edges added automatically.\n";
                    
                }
                else if (graphOption == 5) {
                    g.displayGraph();
                    break;  
                }
                else if (graphOption == 6) {
                    cout << "Returning to main menu...\n";
                    break;  
                }
                else {
                    cout << "Invalid option!";
                }
            }
        }

      
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 'e' && choice != 'E');

    return 0;
}
