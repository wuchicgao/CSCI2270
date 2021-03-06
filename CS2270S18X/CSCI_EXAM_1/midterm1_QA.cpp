#include <iostream>

using namespace std;

/** problem 1**/
/*
Write a C++ function that removes all products in the array of structs with price that matches with given argument 'target'.
Each time an element is removed, the array should be shifted to fill the gap. The function should return the size of the array
after removing the matches.
GIVEN:

struct Product {
   string pname;
   int price;
};

Use the following function header:
int ShiftArray(Product arr[],int size,int target)

int ShiftArray(Product arr[],int size,int target)
{
    for(int j = size-1;j>=0;j--)
    {
        if(arr[j].price ==  target)
        {
            if(j!= size-1)
            {
                for(int i=j+1;i<size;i++)
                    arr[i-1] = arr[i];
            }
            size = size-1;
        }
    }
    return size;
}
*/

/** problem2**/
/*
Write a C++ function that returns the most common repeating element in an array of structs.
The function takes two arguments - the input array of structs and the size of the array, and returns the most common product name.
GIVEN:
struct Product {
    string pname;
    int price;
};
Use the following function header:
string commonRepeatingElement(Product arr[],int length)

struct Count{
    string pname;
    int count;
};

string commonRepeatingElement(Product arr[],int length)
{
    Count* cArr = new Count[length];
    int uniqueItm = 0;
    int max =-1;
    string maxItem;
    //iterate over the array
    for(int i=0; i<length;i++)
    {
        int j=0;
            //check whether it has already in the array.
                //update only the count
            for( j=0;j<uniqueItm;j++)
            {
                if(cArr[j].pname == arr[i].pname)
                {
                    cArr[j].count+= 1;
                    if(max<cArr[j].count)
                    {
                        max = cArr[j].count;
                        maxItem = arr[i].pname;
                    }
                }
            }
            //for the first time we are discovering it
            if(j == uniqueItm)
            {
                cArr[j].pname = arr[i].pname;
                cArr[j].count = 1;
                uniqueItm++;
                if(max<cArr[j].count)
                    {
                        max = cArr[j].count;
                        maxItem = arr[i].pname;
                    }
            }
    }
    return maxItem;
}
*/

/** problem 3**/
/*
//Write a C++ function to copy all elements of an array to a new array, except for a specified value, and return the new array.
//Use the following function header: int *CopyArray(int array[], int length, int value)

int *CopyArray(int array[], int length, int value)
{
    int repeat = 0;
    //look for the value
    for(int i=0;i<length;i++)
    {
        if(array[i] == value)
            repeat++;
    }
    //if no occurance
    if(repeat<1)
        return &array[0];
    else{
        int newSize = length - repeat;// new array size
        int* newArr = new int [newSize];// new array
        int count = 0;
        //copy from old array to new array
        for(int i=0;i<length;i++)
        {
            if(array[i]!=value)
            {
                newArr[count++] =  array[i];
            }
        }
      return newArr;
    }
    return NULL;
}
*/

/** problem 4 **/
/*
//Write a C++ function to find the second largest element in an array.
//The function takes two arguments - the input array and the size of the array, and returns the second largest element.
//Use the following function header:int secondLargest(int arr[],int size);

int secondLargest(int a[],int size)
{
    int max = -999; //largest
    int max2 = -999;//second largest

    for(int i=0;i<size;i++) //iterate over the array
    {
        if(a[i]>max){ //current element is larger than max
            max2 = max;
            max = a[i];
        }
        else if(a[i]> max2 && a[i]<=max ) //current element is smaller than max but larger than second largest
        {
            max2 = a[i];
        }
    }
    return max2;
}
*/

/** problem 5**/
/*
//Write a function called findMax that prints the maximum value in a linked list.
//The function header should be void findMax() not void LinkedList::findMax()
//The linked list class definition is provided as follows:

struct Node{
   int key;
   Node *next;
   Node *previous;
   Node(int k, Node *n, Node *p){
       key = k;
       next = n;
       previous = p;
   }
};
class LinkedList{
private:
   Node *head;
   Node *search(int value);
public:
   LinkedList(){head = NULL;};
   void addNode(int value, int newVal);
   void printList()
   void findMax();
};
void findMax()
{
    Node* temp = head;
    int max = -999;
    while(temp)
    {
        if(temp->key > max)
            max = temp ->key;
        temp = temp->next;
    }
    if(max!=-999)
        cout<<max;
}
*/

/** problem 6**/
/*
//Write a function that enqueues a node to a singly linked list.
//void Queue::enqueue(node *newNode);
//The function is a member of a class called Queue. Write the function definition only for enqueue. Given below is the class definition:
struct node
{
    int value;
    node *next;
};
class Queue
{
    public:
        Queue(node *, node *);
        virtual ~Queue();
        void enqueue(node *newNode);
        void displayQueue();
    protected:
    private:
        node *head;
        node *tail;
};

void Queue::enqueue(node *newNode)
{
    if(tail==NULL) //empty
    {
        head = newNode;
        tail = head;
    }
    else{
        tail->next = newNode;
        tail =newNode;
        tail->next = NULL;
    }
}
//deque
node* Queue::dequeue()
{
    if(head == NULL) //no element in the queue
    {
        tail = NULL;
        return NULL;
    }
    else if(head == tail) //only element in the queue
    {
        node* temp = head;
        head = NULL;
        tail = NULL;
        return temp;
    }
    else{
        node* temp = head;
        head = head->next;
        return temp;
    }
    return NULL;
}
*/

//SOLUTIONS:
//______________________________________________________________________________
/* problem 1:
For a doubly-linked list, write a C++ function to create a new node after a given node value.
The value of the new node should be the sum of the values that are immediately before and immediately after the given node value.
The function arguments are:
    head: head of the linked list
    value: value to search for in the linked list
You can assume the specified value will not be in the head or tail of the LL.
Your function should return the head of the linked list.
node* AddNewNodeSum(node* head, int value);
The linked list structure:
*/
/*
struct node
{
    int value;
    node* next;
    node* prev;
};

node* AddNewNodeSum(node* head, int value)
{
    node* temp=head;
    while(temp!=NULL) {
        if(temp->value==value){
            break;
        }else{
            temp=temp->next;
        }
    }
    //get sum of prev and next
    int newID=temp->prev->value+temp->next->value;
    //create new node
    node* newNode=new node;
    newNode->value=newID;
    newNode->prev=temp;
    newNode->next=temp->next;
    temp->next=newNode;

    return head;
}
*/

//////////////FIRST ONE//////////////////
//Write a function that takes an array, the size of the array, and a search integer
//as arguments and returns a pointer to a new array that contains only the numbers
//from the input array that are greater than the search integer. You need to use
//dynamic memory allocation to create the new array.
//Use the following function header: int* makeNewArray(int inputArray[], int arraySize, int compareNum)
/*
int* makeNewArray(int inputArray[], int arraySize, int compareNum)
{
    int newSize=1;
    for (int i=0; i<arraySize; i++)
    {
        if(inputArray[i]>compareNum)
        {
            newSize++;
        }
    }
    int* theNewArray=new int[newSize];
    int newArrayIndex=0;
    for(int i=0; i<arraySize; i++)
    {
        if(inputArray[i]>compareNum)
        {
            theNewArray[newArrayIndex]=inputArray[i];
            newArrayIndex++;
        }
    }
    return theNewArray;
}
*/
