#include <iostream>

#include<string>

using namespace std;

bool isSorted(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int binSearch(int arr[], int size, int key)
{
    int l = 0, r = size - 1, m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (arr[m] == key)
        {
            return m;
        }
        else if (arr[m] > key)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return -1;
}

int partition(int arr[], int low, int high)
{
    int i = low, j = high - 1;
    int pivot = arr[low];
    while (i < j)
    {
        while (arr[i] <= pivot && i < j)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p);
        quickSort(arr, p + 1, high);
    }
}

void selectionSort(int arr[], int size)
{
    int minIndex;
    for (int i = 0; i < size; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }


}

void bubbleSort(int arr[], int n)
{
    bool isSorted = true;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSorted = false;
            }
        }
        if (isSorted)
        {
            break;
        }
    }

}

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

struct Node
{
    int val;
    Node* next;

};

class LinkedList
{
    Node* head;
    Node* tail;


public:
    LinkedList()
    {
        head = tail = NULL;
    }

    ~LinkedList()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            delete head;
            head = temp;
        }
    }

    void addToTail(int data)
    {
        Node* newNode = new Node;
        newNode->val = data;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void addToHead(int data)
    {
        Node* newNode = new Node;
        newNode->val = data;
        newNode->next = head;
        if (head == NULL)
        {
            tail = newNode;
        }
        head = newNode;
    }

    void remove(int data)
    {
        Node* temp, * prev;
        temp = prev = head;
        if (head == NULL)
        {
            return;
        }
        if (temp->val == data)
        {
            head = temp->next;
            delete temp;
            return;
        }
        while (temp != NULL && temp->val != data)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            return;
        }
        else
        {
            prev->next = temp->next;
            if (prev->next == NULL)
            {
                tail = prev;
            }
            delete temp;
        }

    }
    void removeFromTail()
    {
        if (head == NULL)
        {
            return;
        }
        Node* temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void removeFromHead()
    {
        if (head == NULL)
        {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void insert(int data, int value)
    {
        Node* newNode = new Node;
        newNode->val = data;
        newNode->next = NULL;
        if (head == NULL)
        {
            addToHead(data);
            return;
        }
        Node* temp = head;
        while (temp->val != value)
        {
            if (temp->next == NULL)
            {
                break;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == NULL)
        {
            tail = newNode;
        }
    }

    int Search(int key)
    {
        if (head == NULL)
        {
            return -1;
        }
        int counter = 1;
        Node* temp = head;
        while (temp->val != key)
        {
            if (temp->next == NULL)
            {
                counter = -1;
                break;
            }
            counter++;
            temp = temp->next;
        }
        return counter;

    }

    void display()
    {
        Node* temp = head;
        cout << "Your linked list is [ ";
        while (temp != NULL)
        {
            cout << temp->val;
            if (temp->next != NULL)
            {
                cout << ", ";
            }
            temp = temp->next;
        }
        cout << " ]" << endl;
    }
};

class Stackll
{
    Node* head;
    Node* tail;


public:
    Stackll()
    {
        head = tail = NULL;
    }

    ~Stackll()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void push(int data)
    {
        Node* newNode = new Node;
        newNode->val = data;
        newNode->next = head;
        if (isEmpty())
        {
            tail = newNode;
        }
        head = newNode;
    }


    void pop()
    {
        if (isEmpty())
        {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int top()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return head->val;
        }
    }
    void display()
    {
        Node* temp = head;
        cout << "Your Stack is [ ";
        while (temp != NULL)
        {
            cout << temp->val;
            if (temp->next != NULL)
            {
                cout << ", ";
            }
            temp = temp->next;
        }
        cout << " ]" << endl;
    }
};

struct Stackarr {
private:
    int arr[1000] = { 0 };
    int topInd = -1;
public:
    void push(int val)
    {
        if (topInd == 999)
        {
            cout << "Full capacity" << endl;
            return;
        }
        topInd++;
        arr[topInd] = val;
    }
    void pop()
    {
        if (isEmpty())
        {
            return;
        }
        topInd--;
    }
    int top()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[topInd];
    }
    bool isEmpty()
    {
        if (topInd == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void display()
    {
        cout << "Your stack is [ ";
        for (int i =  topInd ; i >=0; i--)
        {
            if (isEmpty())
            {
                break;
            }
            cout << arr[i];
            if (i >0)
            {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
};

struct Queuearr {
private:
    int arr[1000] = { 0 };
    int front = -1, back = -1;
public:
    bool isEmpty()
    {
        if (front == -1 && back == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (back == 999)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(int val)
    {
        if (isFull())
        {
            return;
        }
        if (isEmpty())
        {
            front = back = 0;
        }
        else
        {
            back++;
        }
        arr[back] = val;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            return;
        }
        else if (front == back)
        {
            front = back = -1;
        }
        else
        {
            front++;
        }
    }
    int frontVal()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
    void display()
    {
        cout << "Your queue is [ ";
        for (int i = front; i <= back; i++)
        {
            if (isEmpty())
            {
                break;
            }
            cout << arr[i];
            if (i != back)
            {
                cout << ", ";
            }
        }
        cout << " ]" << endl;
    }
};

class Queuell {
private:

    Node* head = NULL;
    Node* tail = NULL;
public:
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else return false;
    }
    void enqueue(int val)
    {
        Node* newNode = new Node;
        newNode->val = val;
        newNode->next = NULL;
        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            return;
        }
        else
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    int frontVal()
    {
        if (isEmpty())
        {
            return -1;
        }
        return head->val;
    }
    void display()
    {
        Node* temp = head;
        cout << "Your Queue is [ ";
        while (temp != NULL)
        {
            cout << temp->val;
            if (temp->next != NULL)
            {
                cout << ", ";
            }
            temp = temp->next;
        }
        cout << " ]" << endl;
    }
};

int main()
{
    int choice;
    cout << "Welcome to simple data structure project ! :)\nDo u want to deal with array, LinkedList, stack, queue or tree !\n";
    cout << "Type\t 1-> to enter and array.\n\t 2-> to enter a LinkedList.\n\t 3-> to enter a stack.\n\t 4-> to enter a queue.\n\t 5-> to enter a tree.\n";
    cout << "------------------------------------" << endl;
    cin >> choice;
    if (choice == 1)
    {
        int size;
        cout << "Array is activated successfuly !\nPlease, enter the size of the array\n";
        cin >> size;
        int* arr = new int[size];
        cout << "Please, enter the array's elements\n";
        for (int i = 0; i < size; i++)
        {
            cout << "Please enter the element at index " << i << " : ";
            cin >> arr[i];
        }
        cout << "Your array is " << "[ ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i];
            if (i != size - 1)
            {
                cout << ", ";
            }
            else
            {
                cout << " ]" << endl;
            }
        }
        cout << "----------------------------------------\n";
        cout << "Checking if the array is sorted or not ......." << endl;
        if (isSorted(arr, size))
        {
            int numToSearch, idx;
            string ans;
            do
            {
                cout << "This array is sorted !\n The operations available on sorted array are: \n";
                cout << "Type\t 1-> to make a linear search.\n\t 2-> to make a binary search.\n";
                cin >> choice;
                if (choice == 1)
                {
                    cout << "Linear search is activated!\nEnter any number to search in the array\n";
                    cin >> numToSearch;
                    idx = linearSearch(arr, size, numToSearch);
                    if (idx != -1)
                    {
                        cout << "The element " << numToSearch << " is found at index : " << idx << endl;
                    }
                    else
                    {
                        cout << "The number isn't found" << endl;
                    }
                }
                else
                {
                    cout << "Binary search is activated!\nEnter any number to search in the array\n";
                    cin >> numToSearch;
                    idx = binSearch(arr, size, numToSearch);
                    if (idx != -1)
                    {
                        cout << "The element " << numToSearch << " is found at index : " << idx;
                    }
                    else
                    {
                        cout << "The number isn't found" << endl;
                    }
                }
                cout << "-------------------------------------\n";
                cout << "Do u want to perform another operation on this array?\n";
                cout << "Type Yes or yes if u want\n";
                cin >> ans;
            } while (ans == "Yes" || ans == "yes");

        }
        else
        {
            int numToSearch, idx;
            string ans;
            do
            {
                int* arr2 = new int[size];
                for (int i = 0; i < size; i++)
                {
                    arr2[i] = arr[i];
                }
                cout << "This array is not sorted !\n The operations available on unsorted array are: \n";
                cout << "Type\t 1-> to make a linear search.\n\t 2-> to make a binary search.\n\t 3-> to make a quick sort.\n\t 4-> to make a bubble sort\n\t 5-> to make an insertion sort \n\t 6-> to make a selection sort\n";
                cin >> choice;
                if (choice == 1)
                {
                    cout << "Linear search is activated!\nEnter any number to search in the array\n";
                    cin >> numToSearch;
                    idx = linearSearch(arr, size, numToSearch);
                    if (idx != -1)
                    {
                        cout << "The element " << numToSearch << " is found at index : " << idx << endl;
                    }
                    else
                    {
                        cout << "The number isn't found" << endl;
                    }
                }
                else if(choice == 2)
                {
                    cout << "Binary search is activated! but this array is unsorted u need to sort it first\n";
                    cout << "Type\t 1-> to make a quick sort.\n\t 2-> to make a bubble sort.\n\t 3-> to make an insertion sort.\n\t 4-> to make a selection sort\n";
                    cin >> choice;
                    if (choice == 1)
                    {
                        cout << "Quick sort is activated successfully" << endl;
                        quickSort(arr2, 0, size);
                    }
                    else if (choice == 2)
                    {
                        cout << "Bubble sort is activated successfully" << endl;
                        bubbleSort(arr2, size);
                    }
                    else if (choice == 3)
                    {
                        cout << "Insertion sort is activated successfully" << endl;
                        insertionSort(arr2, size);
                    }
                    else
                    {
                        cout << "Selection sort is activated successfully" << endl;
                        selectionSort(arr2, size);
                    }
                    cout << "The sorted array is " << "[ ";
                    for (int i = 0; i < size; i++)
                    {
                        cout << arr2[i];
                        if (i != size - 1)
                        {
                            cout << ", ";
                        }
                        else
                        {
                            cout << " ]" << endl;
                        }
                    }
                    cout << "-----------------------------------\n";
                    cout << "Enter number to search for in the sorted array using binary search" << endl;
                    cin >> numToSearch;
                    idx = binSearch(arr2, size, numToSearch);
                    if (idx != -1)
                    {
                        cout << "The element " << numToSearch << " is found at index : " << idx << endl;
                    }
                    else
                    {
                        cout << "The number isn't found" << endl;
                    }
                }
                else
                {
                    if (choice == 3)
                    {
                        cout << "Quick sort is activated successfully" << endl;
                        quickSort(arr2, 0, size);
                    }
                    else if (choice == 4)
                    {
                        cout << "Bubble sort is activated successfully" << endl;
                        bubbleSort(arr2, size);
                    }
                    else if (choice == 5)
                    {
                        cout << "Insertion sort is activated successfully" << endl;
                        insertionSort(arr2, size);
                    }
                    else
                    {
                        cout << "Selection sort is activated successfully" << endl;
                        selectionSort(arr2, size);
                    }
                    cout << "The sorted array is " << "[ ";
                    for (int i = 0; i < size; i++)
                    {
                        cout << arr2[i];
                        if (i != size - 1)
                        {
                            cout << ", ";
                        }
                        else
                        {
                            cout << " ]" << endl;
                        }
                    }
                }
                cout << "-------------------------------------\n";
                cout << "Do u want to perform another operation on this array?\n";
                cout << "Type Yes or yes if u want\n";
                cin >> ans;
            } while (ans == "Yes" || ans == "yes");
        }
    }
    else if (choice == 2)
    {
        int el, el1;
        LinkedList ll;
        cout << "LinkedList is activated successfuly!\n";
        string ans;
        do
        {

            cout << "Type\t 1-> to insert from end.\n\t 2-> to insert from beginning.\n\t 3-> to insert after node.\n\t 4-> delete from beginning.\n\t 5-> to delete from end.\n\t 6-> to delete node with an entered value\n\t 7-> to make linear search.\n";
            cin >> choice;
            if (choice == 1)
            {
                cout << "How many elements do u want to insert at the end of this linkedlist?" << endl;
                cin >> choice;
                for (int i = 0; i < choice; i++)
                {
                    cout << "Please, insert element " << i + 1 << " : ";
                    cin >> el;
                    ll.addToTail(el);
                }
                ll.display();
            }
            else if (choice == 2)
            {
                cout << "How many elements do u want to insert at the beginning of this linkedlist?" << endl;
                cin >> choice;
                for (int i = 0; i < choice; i++)
                {
                    cout << "Please, insert element " << i + 1 << " : ";
                    cin >> el;
                    ll.addToHead(el);
                }
                ll.display();
            }
            else if (choice == 3)
            {
                cout << "please, Enter the element that u want to insert to the linked list : ";
                cin >> el;
                cout << "Please, enter the element that u want to insert after : ";
                cin >> el1;
                ll.insert(el, el1);
                ll.display();
            }
            else if (choice == 4)
            {
                ll.removeFromHead();
                ll.display();
            }
            else if (choice == 5)
            {
                ll.removeFromTail();
                ll.display();
            }
            else if (choice == 6)
            {
                cout << "Please, enter the value that u want to delete : ";
                cin >> el;
                ll.remove(el);
                ll.display();
            }
            else if (choice == 7)
            {
                cout << "Enter the value that u want to search in the linked list : ";
                cin >> el;
                int idx = ll.Search(el);
                if (idx == -1)
                {
                    cout << "The number isn't found" << endl;
                }
                else
                {
                    cout << "The number is found at the node number : " << idx << endl;
                }
            }
            cout << "do u want to perform another operation?\n";
            cout << "type\t yes or Yes to continue\n";
            cin >> ans;
        } while (ans == "yes" || ans == "Yes");
    }
    else if (choice == 3)
    {
        string ans;
        int el;
        cout << "Stack is activated successfully!\n";
        cout << "Type\t 1-> to implement stack sith array.\n\t 2-> to implement stack with a LinkedList.\n";
        cin >> choice;
        if (choice == 1)
        {
            Stackarr st;

            cout << "How many elements do u want to push them into stack with array?" << endl;
            cin >> choice;
            for (int i = 0; i < choice; i++)
            {
                cout << "Please, enter the element number " << i + 1 << " : ";
                cin >> el;
                st.push(el);
            }
            st.display();
            cout << "--------------------------\n";
            do
            {
                cout << "Type\t 1-> to pop an element from the stack with array.\n\t 2-> get the top of this stack with array.\n\t 3-> to display this stack with array\n";
                cin >> choice;
                if (choice == 1)
                {
                    st.pop();
                    st.display();
                }
                else if (choice == 2)
                {
                    if (st.isEmpty())
                    {
                        cout << "The stack is empty" << endl;
                    }
                    else
                    {
                        cout << "The top of the stack is: " << st.top() << endl;
                    }
                }
                else
                {
                    st.display();
                }
                cout << "------------------------------------" << endl;
                cout << "Do you want to perform another operation on this stack with array?\n";
                cout << "Type\t Yes or yes to continue\n";
                cin >> ans;
            } while (ans == "yes" || ans == "Yes");

        }
        else
        {
            Stackll st;

            cout << "How many elements do u want to push them into stack with LinkedList?" << endl;
            cin >> choice;
            for (int i = 0; i < choice; i++)
            {
                cout << "Please, enter the element number " << i + 1 << " : ";
                cin >> el;
                st.push(el);
            }
            st.display();
            cout << "--------------------------\n";
            do
            {
                cout << "Type\t 1-> to pop an element from the stack with LinkedList.\n\t 2-> get the top of this stack with LinkedList.\n\t 3-> to display this stack with LinkedList\n";
                cin >> choice;
                if (choice == 1)
                {
                    st.pop();
                    st.display();
                }
                else if (choice == 2)
                {
                    if (st.isEmpty())
                    {
                        cout << "The stack is empty" << endl;
                    }
                    else
                    {
                        cout << "The top of the stack is: " << st.top() << endl;
                    }

                }
                else
                {
                    st.display();
                }
                cout << "------------------------------------" << endl;
                cout << "Do you want to perform another operation on this stack with LinkedList?\n";
                cout << "Type\t Yes or yes to continue\n";
                cin >> ans;
            } while (ans == "yes" || ans == "Yes");

        }
    }
    else if (choice == 4)
    {
    string ans;
    int el;
    cout << "Queue is activated successfully!\n";
    cout << "Type\t 1-> to implement queue sith array.\n\t 2-> to implement queue with a LinkedList.\n";
    cin >> choice;
    if (choice == 1)
    {
        Queuearr q;

        cout << "How many elements do u want to enqueue into queue with array?" << endl;
        cin >> choice;
        for (int i = 0; i < choice; i++)
        {
            cout << "Please, enter the element number " << i + 1 << " : ";
            cin >> el;
            q.enqueue(el);
        }
        q.display();
        cout << "--------------------------\n";
        do
        {
            cout << "Type\t 1-> to dequeue an element from the queue with array.\n\t 2-> get the top of this queue with array.\n\t 3-> to display this queue with array\n";
            cin >> choice;
            if (choice == 1)
            {
                q.dequeue();
                q.display();
            }
            else if (choice == 2)
            {
                if (q.isEmpty())
                {
                    cout << "The queue is empty" << endl;
                }
                else
                {
                    cout << "The top of the queue is: " << q.frontVal() << endl;
                }
            }
            else
            {
                q.display();
            }
            cout << "------------------------------------" << endl;
            cout << "Do you want to perform another operation on this queue with array?\n";
            cout << "Type\t Yes or yes to continue\n";
            cin >> ans;
        } while (ans == "yes" || ans == "Yes");

    }
    else
    {
        Queuell q;

        cout << "How many elements do u want to enqueue into queue with LinkedList?" << endl;
        cin >> choice;
        for (int i = 0; i < choice; i++)
        {
            cout << "Please, enter the element number " << i + 1 << " : ";
            cin >> el;
            q.enqueue(el);
        }
        q.display();
        cout << "--------------------------\n";
        do
        {
            cout << "Type\t 1-> to dequeue an element from the queue with LinkedList.\n\t 2-> get the top of this queue with LinkedList.\n\t 3-> to display this queue with LinkedList\n";
            cin >> choice;
            if (choice == 1)
            {
                q.dequeue();
                q.display();
            }
            else if (choice == 2)
            {
                if (q.isEmpty())
                {
                    cout << "The queue is empty" << endl;
                }
                else
                {
                    cout << "The top of the queue is: " << q.frontVal() << endl;
                }
            }
            else
            {
                q.display();
            }
            cout << "------------------------------------" << endl;
            cout << "Do you want to perform another operation on this queue with LinkedList?\n";
            cout << "Type\t Yes or yes to continue\n";
            cin >> ans;
        } while (ans == "yes" || ans == "Yes");
    }
 }
    else
    {
        cout << "To be continued :v" << endl;
    }
}

