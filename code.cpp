#include <string>
#include <iostream>

using namespace std; 
template <class T>
class deque { 
   private:
   T* arr;
    int front;
    int rear;
    int size;
    int curr_size;
  
public: 
 
deque() 
    { 
        arr = new T[1]; 
        front = -1; 
        rear = 0;
	size=0;
	curr_size=0;       
    } 

deque(int size,T x) 
	{ arr = new T[size];
	front = -1; 
        rear = 0;
	curr_size=0;    
	this->size = size;
	for(int i=0;i<size;i++)
	push_back(x);
}
bool empty()
{
if (front==-1)
return true;
else return false;
}
bool isFull() 
{ 
    if(front == 0 && rear == size-1)
	return true;
    else if (front == rear+1)
	return true;
 else return false;
} 
void push_back(T data)
{

    if (isFull()) 
    {   cout << " Overflow\n " << endl; 
        return; 
    } 
    if (rear == size-1) 
    rear = 0; 
    else if (front == -1) 
    {front = 0; 
     rear = 0; 
    } 
    else ++rear;
    arr[rear] = data;
	++curr_size;
}

void pop_back()
{
if(empty()) 
    {  cout << " Underflow\n"; 
        return; 
    } 
  if(rear==0) 
rear=size-1; 
else if (front==rear) 
    { front = -1; 
      rear = -1; 
    } 
  else --rear;
--curr_size;
}

void push_front(T data)
{
 if (isFull()) 
    {  cout << "Overflow\n" << endl; 
      return; 
    } 
    if(front==0) 
        front=size-1 ;
   else if (front == -1) 
  {    front = 0; 
        rear = 0; 
    } 

   else --front; 
arr[front] = data ; 
++curr_size;
}

void pop_front()
{
if (empty()) 
    {   cout << "Queue Underflow\n" << endl; 
        return ; 
    } 
    if(front==rear) 
    {   front = -1; 
        rear = -1; 
    } 
  else front == (front+1)%size;
--curr_size;
}
 
int get_size ()
{
	return ((size-front+rear)%size); 
}

T back()
{
return arr[size-1];
}

T get_front()
{
return arr[1];
}

void resize(int x,T d)
{
if(curr_size==x)
return;
else if(curr_size>x)
{
int i=curr_size-x;
while(i--)
pop_front();
}

else 
{int i=x-curr_size;
while(i--)
push_front(d);
size = (size-front+rear)%size;
}

}

T D(int n)
{
return arr[n];
} 

void clear()
{
        front = -1; 
        rear = 0;
	size=0;
	curr_size=0;       
}



void display()

	{
		if (front == -1) 
    { cout<<"Empty\n"; 
        return; 
    } 
    cout<<"\n Elements are: "; 
    if (rear>=front) 
    {  for (int i=front;i<=rear;i++) 
         cout<<arr[i]<<endl;
    } 
    else
    {  for(int i=front;i<size;i++) 
           cout<<arr[i];
       for (int i=0;i<=rear;i++) 
          cout<<arr[i]<<endl; 
    } 
  }
};

int main()
{ deque<string>* q;
    int Q,c,n;
    string x;
    cin>>Q;
    while (Q--){      
 
 cin>>c;

 switch (c)
 {
 case 1: cin>>x;
         q->push_front(x);  
         q->display();
		
         break;
 case 2: q->pop_front();
         q->display();
         break;
 
 case 3: cin>>x;
         q->push_back(x);
         q->display();
         break;
 
 case 4: q->pop_back();
         q->display();
         break;
 
 case 5: if(!q->empty())
         delete q;
         deque<string>* q;
         break;

 case 6: cin>>n>>x;
         if(q->arr!=NULL)
         delete q;
         deque<string>* q;
         q = new deque(n,x);
         q->display();
         break;

 case 7: cout<<q->get_front()<<endl;
         break;

 case 8: cout<<q->back()<<endl;
         break;
 
 case 9: if(q->empty())
          cout<<"true\n";
         else
          cout<<"false\n";
         break;

 case 10: cout<<q->get_size()<<endl;
          break;

 case 11: std::cin>>n>>x;
          q->resize(n,x);
          q->display();
          break;

 case 12: q->clear();
          break;
 
 case 13: cin>>n;
          cout<<q->arr[n]<<endl;
          break;

 case 14: q->display();
         break;

 default:
     break;
 }
    }


delete q;
return 0;
}