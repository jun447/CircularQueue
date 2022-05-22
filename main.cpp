#include <iostream>

using namespace std;
class CircularQueue{
	  int *arr;
      int front;
      int rear;
      int size;
    public:

	CircularQueue(int n){
          size=n;
          arr=new int [size];
          front= -1;
          rear =-1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if (front==0 && rear==size-1 || rear==(front-1)%(size-1)){// checking for queue is full or not
            return false;
        }else if(front==-1){//checking if we are inserting at first time
            front=0;
            rear=0;
            arr[rear]=value;
        }else if(rear==size-1 && front!=0){// checking if our rear is at end and front is in between
            rear=0;                        // maintaining cyclic nature
            arr[rear]=value;
        }else{//normal case insertion
            rear++;
            arr[rear]=value;
        }
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if (front==-1){// queue is empty
            return -1;
        }
        int ans=arr[front];
        arr[front]=-1;
        if(front==rear){
            front=-1;
            rear=-1;
        }else if(front==size-1){
            front=0;//to maintain cyclic nature
        }else{
            front++;
        }
        return ans;
    }
    void print(){
        if(front==-1){
            cout<<"Queue is empty"<<endl;
        }else{
            int i=front;
            while(i!=rear){
                cout<<arr[i]<<" ";
                i=(i+1)%(size);
            }
           cout<<arr[i]<<endl;
        }
    }
};
int main() {
     CircularQueue q(4);
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
        q.print();
        cout<<"==========Testing Circular nature======="<< endl;
        q.dequeue();
        q.dequeue();
        q.print();
        cout<<"========Testing Circular nature========="<< endl;
        q.enqueue(1);
        q.enqueue(2);
        q.print();
    return 0;
}
