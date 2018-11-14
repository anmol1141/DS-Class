#include <iostream>
using namespace std;

class p_queue {
    int save;
    int ele;
    int front;
    int rear;
    int temp;
    int *arr[2];
    int num;
    int i;
    int count;
public:
    p_queue() {
        cout << "constructor, enter the size of p_queue" << endl;
        cin >> ele;
        *arr = new int(ele);
        front = -1;
        rear = -1;
    }

    void Enqueue() {
        if (front < 0 && rear < 0) {
            cout << "Enter the first element of p_queue" << endl;
            cin >> num;
            front++;
            rear++;
            arr[rear][0] = num;
            cout << "Enter the priority of number added" << endl;
            cin >> arr[rear][1];
        } else if (rear == ele-1) {
            cout << "p_queue is full" << endl;
        } else {
            cout << "enter the element to push" << endl;
            rear++;
            cin >> arr[rear][0];
            cout << "Enter the priority of number added" << endl;
            cin >> arr[rear][1];
            insertion_sort();
        }
    }
    void insertion_sort(){
        temp = rear - 1;
        i = rear;
        do{
            if(arr[temp][1] < arr[i][1]){
                save = arr[temp][0];
                arr[temp][0] = num;
                arr[i][0] = save;
                temp --;
                i--;
            }
        }while(temp>=front);
    }
    void Dequeue(){
        if(rear < 0){
            cout << "Queue is Empty" << endl;
        }
        else if(front == rear) {
            cout << arr[front][0] << endl;
            rear = -1;
            front = -1;
            cout << "deleting the only remaining element" << endl;
            cout << "No element remains" << endl;
        }
        else{
            cout << arr[front][0] << endl;
            front ++;
        }
    }
    void is_empty(){
        if(front == -1 && rear == -1){
            cout << "TRUE" << endl;
        }
        else{
            cout << "FALSE" << endl;
        }
    }
    void size(){
        cout << rear-front;
    }
    void is_full(){
        if(rear == ele-1)
            cout << "queue is full" << endl;
        else
            cout << "Queue not full" << endl;
    }
    void display(){
        cout << endl;
        if(front < 0){
            cout << endl << "underflow" << endl;
        }
        while(front > -1){
            Dequeue();
        }
        cout << endl << "displayed all elements" << endl;
    }
};
int main()
{
    p_queue s1;
    int n;
    cout << "this program is for queue insertion and deletion" << endl;
    cout << "1. enqueue command" << endl << "2. dequeue command" << endl;
    cout << "3. check if empty" << endl <<"4. to check if queue is full" << endl;
    cout << "5. size of queue" << endl << "6. to display current queue " << endl;
    cout << "enter -1 to exit program" << endl;
    cin >> n;
    while(n!=-1) {
        switch (n) {
            case 1: {
                s1.Enqueue();
                break;
            }
            case 2: {
                s1.Dequeue();
                break;
            }
            case 3: {
                s1.is_empty();
                break;
            }
            case 4: {
                s1.is_full();
                break;
            }
            case 5: {
                s1.size();
                break;
            }
            case 6: {
                s1.display();
                break;
            }
            default: {
                cout << "invalid input" << endl;
            }
        }
        cout << "1. enqueue command" << endl << "2. dequeue command" << endl;
        cout << "3. check if empty" << endl << "4. to check if queue is full" << endl;
        cout << "5. size of queue" << endl <<"6. to display current queue " << endl;
        cout << "enter -1 to exit program" << endl;
        cin >> n;
    }
}
