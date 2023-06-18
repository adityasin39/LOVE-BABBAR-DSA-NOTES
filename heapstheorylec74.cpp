#include<bits/stdc++.h>
#include<queue>
using namespace std;
class MaxHeap
{
    public:
    int size;
    int arr[100];
    MaxHeap()
    {
    size=0;
    }
    void insert(int element)
    {
       size++;
       arr[size]=element;
       int index=size;
       int parentIndex=index/2;
       while(parentIndex>0 && arr[index]>arr[parentIndex])
       {
           swap(arr[index],arr[parentIndex]);
           index=parentIndex;
           parentIndex=index/2;
       } 
    }
    void printheap()
    {
        for(int i=1;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    void deletion()
    {
        if(size==0)
        {
            cout<<"Nothing to delete"<<endl;
        }
        arr[1]=arr[size];
        size--;
        int index=1;
        while(index<=size/2)
        {
             int leftindex=index*2;
             int rightindex=index*2+1;
             int finalindex=index;
             if(leftindex<=size && arr[leftindex]>arr[finalindex])
             {
                  finalindex=leftindex;
             }
             if(rightindex<=size && arr[rightindex]>arr[finalindex])
             {
                 finalindex=rightindex;
             }
             if(finalindex==index) return;
             else
             { swap(arr[index],arr[finalindex]);
              index=finalindex;
             }   
        }
    }
    void heapify(int arr[],int n, int index)
    {
             int leftindex=index*2;
             int rightindex=index*2+1;
             int finalindex=index;
             if(leftindex<=n && arr[leftindex]>arr[finalindex])
             {
                  finalindex=leftindex;
             }
             if(rightindex<=n && arr[rightindex]>arr[finalindex])
             {
                 finalindex=rightindex;
             }
             if(finalindex==index) return;
             else
             { swap(arr[index],arr[finalindex]);
              index=finalindex;
              heapify(arr,n,index);
             }   
    }
    void heapsort(int arr[],int n)
    {
         while(n>0)
         {
            swap(arr[1],arr[n]);
            n--;
            heapify(arr,n,1);
         }
    }
    // build heap takes O(n) time
    // heapsort-O(nlogn)
    // insertion,deletion-O(logn)

};
int main(){
      MaxHeap h;
      h.insert(40);
      h.insert(30);
      h.insert(20);
      h.insert(10);
      h.insert(15);
      h.insert(16);
      h.insert(17);
      h.insert(8);
      h.insert(4);
      h.insert(35);
      cout<<endl;
      h.printheap();
      h.deletion();
      cout<<endl;
      h.printheap();
      cout<<endl;
      int arr1[]={-1,11,7,23,55,2,1};
      int n=6;
      for(int i=n/2;i>=1;i--)
      {
        h.heapify(arr1,n,i);
      }
      for(int i=1;i<=n;i++)
      {
        cout<<arr1[i]<<" ";
      }
      h.heapsort(arr1,n);
      cout<<endl;
      for(int i=1;i<=n;i++)
      {
        cout<<arr1[i]<<" ";
      }
      cout<<endl;
      priority_queue<int> pq;// by default max heap
      pq.push(11);
      pq.push(7);
      pq.push(23);
      pq.push(55);
      pq.push(2);
      pq.push(1);
      cout<<pq.top()<<endl;
      pq.pop();
      cout<<pq.top()<<endl;
      cout<<pq.size()<<endl;
      priority_queue<int,vector<int>,greater<int>> pq;//min heap

    return 0;
}