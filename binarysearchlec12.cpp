#include<iostream>
using namespace std;
void printArray(int arr[],int size)
{
  cout<<" Printing the sorted array"<<endl;
  for(int i=0;i<size;i++)
    {
      cout<<arr[i]<<" ";
    }
  cout<<endl;
}
int binarysearch(int arr[],int size, int key)
{
  int start=0;
  int end=size-1;
  while(start<=end)
    {
      int mid=start+(end-start)/2; // we wont write mid=(start+end)/2 because if start = INT_MAX and end= INT_MAX then there will be an integer overflow for mid. Thus we are using this formuala.
      if(arr[mid]==key) return mid;
      else if(arr[mid]>key) end=mid-1;
      else start=mid+1; 
    }
  return -1;
}
int main()
{
  int n;
  cout<<"Enter the size of the array"<<endl;
  cin>>n;
   int arr[n];
  cout<<"Enter the elements of the array"<<endl;
  for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
  sort(arr,arr+n);
  printArray(arr, n);
  cout<<"Enter the value to be searched"<<endl;
  int key;
  cin>>key;
  int res;
  res=binarysearch(arr,n,key);
  if(res==-1) cout<<"Element not found"<<endl;
  else
  {
    cout<<"Element found at index "<<res<<endl;
  }
  return 0;
}