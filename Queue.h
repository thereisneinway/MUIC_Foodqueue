using namespace std;
typedef struct QNODE{
    QNODE * next;
    int order_number;  // 1.Chicken(20) 2.Pork(30) 3.Beef(50) 4.Duck(40) 5.Shrimp(60)
    int order_qty;
}order;
typedef QNODE* QNodePtr;

typedef struct {
	QNodePtr headPtr,tailPtr;
	int size;
}Queue;

string menu[] = {"Chicken","Pork","Beef","Duck","Shrimp"};
int menuPrice[] = {20,30,50,40,60};

void enqueue_struct(Queue&,int,int);
int dequeue_struct(Queue&);//return price
//Finish this 2 functions
/*

void enqueue(QNodePtr &head, QNodePtr &tail, int x){
  QNodePtr new_node= new QNODE;
if(new_node){ 
   	new_node->data=x;
		new_node->nextPtr=NULL;
    if(head==NULL) head=new_node;
    else tail->nextPtr=new_node    ;          
	   tail=new_node;
 }
}

int dequeue(QNodePtr &head,QNodePtr &tail){
  if(head!=NULL){
     QNodePtr t=head;
     int value= t->data;
    //
     head= t->nextPtr;
     if(head==NULL) tail=NULL;
     delete t;
     return value;
  }
  cout<<"The queue is empty ";
  return -1;
}

*/


void enqueue_struct(Queue& q,int order_number,int order_qty) {
  QNODE* new_node= new QNODE;
  if(new_node){ 
    new_node->order_number = order_number;
    new_node->order_qty = order_qty;
    new_node->next = NULL;
    if(q.headPtr == NULL) q.headPtr = new_node;
    else q.tailPtr->next = new_node;          
	  q.tailPtr = new_node;
    q.size++;
    cout<<"Order noted: "<<menu[order_number]<<" x"<<order_qty<<endl;
  }
}

int dequeue_struct(Queue& q){
  if(q.size>0){
    QNodePtr node = q.headPtr;
    int order_number = node->order_number;
    int order_qty = node->order_qty;
    q.headPtr = node->next;
    if(q.headPtr == NULL) q.tailPtr = NULL;
    delete node;
    q.size--;
    cout<<"Order arrived: "<<menu[order_number]<<" x"<<order_qty;
    return menuPrice[order_number] * order_qty;
  }
  cout<<"No order found!"<<endl;
  return -1;
}