class MyCircularQueue {
public:
    vector<int> queue;
    int size=0, arraysize=0;
    int front=0,rear=0;
    MyCircularQueue(int k) {
        queue.resize(k);
        arraysize=k;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        
        else if(isEmpty())
        {
            front = rear = 0;
            queue[rear] = value;
            size++;
        }
        else{
            rear++;
            rear %= arraysize;
            queue[rear] = value;

            size++;
        }
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) 
            return false;
        
        front = (front + 1) % arraysize;
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        
        return queue[front];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        
        return queue[rear];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size == arraysize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */