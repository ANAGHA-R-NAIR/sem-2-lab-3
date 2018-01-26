    #include <iostream>
    using namespace std;
    struct node // creating a structure for new node  
    {
    int data;// data of the node
    node *next;// pointer of the node
    };	
    class linkedList // creating a class for linkedlist
    {
    private:
    node *head, *tail; // creating head pointer and tail pointer
    public:
    linkedList() // creating a constructor of class linkedlist
    {
    head=NULL; // assigning null values to head and tail
    tail=NULL;
    }
    void insert(int value)// creating a function in class linkedlist to insert a value at the end
    {
    node *temp=new node;
    temp->data=value;
    temp->next=NULL;
    if(head==NULL)
    {
    head=temp;
    }
    else
    {
    temp->next=head;	
    tail->next=temp;
    }
    tail=temp;
    }
    void insertAt(int pos,int value) // creating another function to insert a value at a particular position.pos=position,value=value to be inserted
    {
    node *current=new node;
    node *previous=new node;
    node *temp= new node;
    current= head;
    temp->data=value;
    if(pos<=countItems()) // if loop is created so as to check whether there exists enough nodes in the list for the particular position to exist and executes iff it exists
    {
    for(int i=1;i<pos;i++)
    {
    previous= current;
    current=current->next;	
    }
    previous->next=temp;
    temp->next=current;	
    }
    else// if there are not enough nodes
    {
    cout<<"Linkedlist does not have that many elements.\n";
    }
    }
    void Delete()// creating a function to delete the item at last
    {
    node*current=new node;
    node*previous=new node;
    current=head;
    while(current->next!=head)
    {
    previous=current;
    current=current->next;
    }
    tail=previous;
    previous->next=head;
    delete current;
    }
    void deleteAt(int pos)// creating a function to delete element at a certain position.pos=position
    {
    node *current=new node;
    node *previous=new node;
    node *nextt=new node;
    current=head;
    if(pos<=countItems())// if loop is created to check whether there are enough nodes for the particular position to exist and executes iff there exists enough nodes 
    {
    for(int i=1;i<pos; i++)
    {
    previous=current;
    current=current->next;
    nextt=current->next;
    }
    previous->next=nextt;
    delete current;
    }
    else
    cout<<"Linkedlist does not have that many elements\n.";
    }
    int countItems()// creating a function to count the number of elements in the linkedlist
    {
    int count=0;// assigning initial value to count as zero
    node *temp=new node;
    temp= head;
    do// creating a loop so as to increase count by one for each element	
    {
    temp=temp->next;
    count++;
    }
    while(temp!=head);
    cout<<"Number of elements= "<<count<<endl;
    return count;
    }
    void display()// creating a function to display the elements
    {
    node*temp= new node;
    temp=head;
    do
    {
    cout<<temp->data<<"->";
    temp=temp->next;
    }
    while(temp!=head);
    cout<<endl;
    }
    };	
    int main() 
    {
     linkedList a; // Declaring object of class linkedList
     a.insert(1);
     a.insert(2);
     a.countItems();
     a.display();
     a.insertAt(1,1);
     a.display();
     a.Delete();
     a.display();
     a.insertAt(2,2);
     a.display();
     a.countItems();
     a.deleteAt(2);
     a.display();
     a.countItems();
    return 0;
    }