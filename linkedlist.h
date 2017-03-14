/*
 * Node Declaration
 */
struct node
{
    int x,y;
    struct node *next;
}*start;
 
/*
 * Class Declaration
 */
class single_llist
{
    public:
        node* create_node(int,int);
        void insert_begin(int,int);
        bool search(int);
	bool searchwithrange(int,int,int,int);
        void insert_last(int,int); 
        void delete_pos(int);
        void display();
	void update();
        bool isempty();
        single_llist() 
        {
            start = NULL;
        }
};
  
extern single_llist mi;

/*
 * Creating Node
 */
node *single_llist::create_node(int a,int b)
{
    struct node *temp, *s;
    temp = new(struct node); 
    if (temp == NULL)
    {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }
    else
    {
	temp->x = a;
	temp->y = b;
        temp->next = NULL;     
        return temp;
    }
}
 
/*
 * Inserting element in beginning
 */
void single_llist::insert_begin(int a,int b)
{
    struct node *temp, *p;
    temp = create_node(a,b);
    if (start == NULL)
    {
        start = temp;
        start->next = NULL;          
    } 
    else
    {
        p = start;
        start = temp;
        start->next = p;
    }
    cout<<"Element Inserted at beginning"<<endl;
}
 
/*
 * Inserting Node at last
 */
void single_llist::insert_last(int a,int b)
{
    cout<<"Enter the value to be inserted: ";
    struct node *temp, *s;
    temp = create_node(a,b);
    if (start == NULL)
    {
        start = temp;
        start->next = NULL;          
    } 
    else
    {
     s = start;
     while (s->next != NULL)
      {         
        s = s->next;        
      }
     temp->next = NULL;
     s->next = temp;
     cout<<"Element Inserted at last"<<endl;  
    }
}
 
/*
 * Delete element at a given position
 */

bool single_llist::search(int value)
{
    int pos = 0;
    bool flag = false;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return flag;
    }
    struct node *s;
    s = start;
    while (s != NULL)
    {
        pos++;
        if (s->x == value)
        {
            flag = true;
	    delete_pos(pos);
            return true;
        }
        s = s->next;
    }
}

bool single_llist::searchwithrange(int l,int t,int r,int b)
{
    int pos = 0;
    bool flag = false;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return flag;
    }
    struct node *s;
    s = start;
    while (s != NULL)
    {
        pos++;
        if (s->x >=l && s->x <=r && s->y >=b && s->y <=t)
        {
            flag = true;
	    delete_pos(pos);
            return true;
        }
        s = s->next;
    }
}


void single_llist::update()
{
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    struct node *s, *ptr;
    s = start;
   while(s->next!=NULL)
        {
             s->x -= 1;  
              s = s->next;
        }
       s->x-=1;
    cout<<"Node Updated"<<endl;
} 

void single_llist::delete_pos(int pos)
{
    int i, counter = 0;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the position of value to be deleted: ";
    struct node *s, *ptr;
    s = start;
    if (pos == 1)
    {
        start = s->next;
    }
    else
    {
        while (s != NULL)
        {
            s = s->next;
            counter++;  
        }
        if (pos > 0 && pos <= counter)
        {
            s = start;
            for (i = 1;i < pos;i++)
            {
                ptr = s;
                s = s->next;
            }
            ptr->next = s->next;
        }
        else
        {
            cout<<"Position out of range"<<endl;
        }
        free(s);
        cout<<"Element Deleted"<<endl;
    }
}

bool single_llist::isempty()
{
if (start == NULL)
        return true;
else return false;   
}

/*
 * Display Elements of a link list
 */
void single_llist::display()
{
    struct node *temp;
    temp = start;
    cout<<"Elements of list are: "<<endl;
    while (temp != NULL)
    {
        cout<<temp->x<<" "<<temp->y<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
