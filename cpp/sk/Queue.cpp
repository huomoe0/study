#include <iostream>
#include <assert.h>
using namespace std;
const int maxn = 100;
class Queue
{
public:
    Queue();
    void push(int a);
    void pop();
    int front();
    bool empty();
    int size();
private:
    int hh, tt;
    int data[maxn];
};
Queue::Queue()
{
    this->hh = this->tt = 0;
}
void Queue::push(int a)
{
    if((this->tt+1)%maxn == this->hh)   return;
    this->data[this->tt] = a;
    this->tt = (this->tt+1)%maxn;
}
void Queue::pop()
{
    if(this->hh == this->tt)   return;
    this->hh = (this->hh+1)%maxn;
}
int Queue::front()
{
    assert(hh != tt);
    return this->data[hh];
}
int Queue::size()
{
    return (tt - hh + maxn) % maxn;
}
bool Queue::empty()
{
    if(hh == tt)    return true;
    return false;
}
int main()
{
    Queue q;
    int n, t, m;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> t;
        q.push(t);
    }
    cin >> m;
    while(m--)  q.pop();
    cout << "length = " << q.size() << "\n";
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}