//Standard Template Library
// stl is basically a compilation of pre defined functions, iterators, algorithms ,containers
#include<bits/stdc++.h> // include this to use stl and you dont need to include iostream. Also stdc++ includes all the header files like math.h,string.h so you dont need to include them individually.
// stl is divided into 4 parts: algorithms,containers,functions,iterators.
// containers are data structures which hold data like vector,set,map,etc.
using namespace std;
// array
void explainArray()
{
    // this stl array is implemented through the same classical array and hence stl array also cant be modified in terms of size.
    // to use array stl functions, write #include<array> , bits/stdc++ is slower so if a single stl is to be used then its better to include only that stl.
    array<int,3> a={1,2,3};// 3 is the size 
    // Accessing the elements
    cout<<a[2];// O(1)
    cout<<a.at(2);  // O(1)
    cout<<a.front(); // O(1)
    cout<<a.back(); //O(1)
    cout<<a.size(); // O(1)
    cout<<a.empty(); // O(1)
    a.fill(10); // all elements become 10
    // swap is same as vector

}
//pairs 
// pairs lie in the utility library.
void explainPair()
{
    // this can be used to return multiple values from the function.
    //pairs are used to store a couple of data like a couple of integers,couple of double, couple of vector,couple of string,couple of char or any other datatype
    pair<int,int> p1={1,3};// here we have made a pair of 1 and 3.
    //now, after making a pair, if we want to access 1 then we can simply do by using first and to access 3 we can use second.
    cout<<p1.first<<" "<<p1.second; // will print 1 3
    // but what if you want to store 3 variables, 4 variables or more , then you can use the nested property of pairs.
    pair<int,pair<int,int>> p2={1,{3,4}}; // to store 1,3,4
    cout<<p2.first<<" "<<p2.second.first<<" "<<p2.second.second;// will print 1 3 4
    // now lets make a pair array
    pair<int,int> p3[]={{1,3},{2,4},{5,7}};
    cout<<p3[1].second;//will print 4
}
void explainVector()
{
    // vector also stores contiguously like an array but as soon as the vector gets full and if more elements are pushed in it then it makes a new vector double the size of the current full vector and copies the elements in it.
    // capacity function gives the total number of elements that can be stored whereas size gives total number of elements present.
    // For e.g. if the vector has 1 element then the capacity will be 1 but when you add 1 more element then the capacity gets doubled and becomes 2 then on adding the 3rd element, the capacity becomes 4 whereas the size is 3.
    // push_back-O(1)
    // pop_back-O(1)
    // size-O(1)
    // clear-O(n)
    // size of a vector can be increased or decreased.
    // if you want to store 8 variables then we would make an array but if i want to add one more element to the array then i cant so here vector comes into picture as vector is dynamic in nature and thus can increase its size on addition whereas the array is constant in size.
    //so if you dont know the size of the array to be declared then its better to use a vector.
    vector<int> v;// here instead of int , the datatype can be anything. This is a 0 size vector.//an empty vector {}
    v.push_back(1); // increases the size of the vector by 1 and inserts 1 in the vector. {1}
    v.emplace_back(2);// increases the size of the vector by 1 and inserts 2 at the back. {1,2}
    //emplace_back is similar to push_back but it is faster than push_back.
    vector<pair<int,int>> v1;
    v1.push_back({1,2});// so here we have given curly braces to indicate that its a pair and we want to insert a pair.
    v1.emplace_back(1,2);// but here you dont need curly braces, emplace_back automatically assumes that this is a pair.
    vector<int> v2(5,100);//this creates a vector of size 5 and all the values in the vector will be 100 so here we have already given the size of the vector but it does not mean that you cant change the size. Vector is dynamic.
    vector<int> v3(5);// vector of size 5 and all the 5 blocks will have 0 i.e. {0,0,0,0,0}
    vector<int> v4(5,20); // {20,20,20,20,20}
    vector<int> v5(v4); // {20,20,20,20,20} so v5 will be a copy of v4.
    // Accessing the elements of a vector
    //suppose you have a vector {20,10,25,15} then similar to array you can access the vector like v[0]=20 or you can use v.at(0) v[1]=10 or v.at(1) v[2]=25 and so on
    // the other way to access a vector is using an iterator. Iterator is just like a pointer and contains the address of the element.
    vector<int> v6{1,2,3,5}; // this is also a way to initialize a vector just like an array int arr[]={1,2,3,5} or vector<int> v6={1,2,3,5}
    vector<int>:: iterator it=v6.begin();// this is the syntax to declare an iterator and here the iterator is pointing to begin i.e. 1
    // similar to poiners, to get the element i.e. 1 we use * so *it will give 1 and it will give address. v6.begin() will give the address of 1 and *(v6.begin) will give 1
    it++;// it will now point to 2
    cout<<*(it)<<" ";//will print 2
    it=it+2;// it will now point to 5
    cout<<*(it);//will print 5
    vector<int>:: iterator it1=v6.end();// this iterator will not point to 5 instead it will point to a location which is right after 5.
    it1--;
    cout<<*(it1);// will print 5
    //vector<int>:: iterator it2=v6.rend();// it will point to a location just before 1
    //vector<int> :: iterator it3=v6.rbegin(); it will point to 5
    //now on doing it3++; it3 will point to 3
    cout<<v6.back()<<" ";//5 will get printed.
    cout<<v6.front();
    //now if i want to print the entire vector then i have two ways.
    // 1st way normal for loop
    for(int i=0;i<v6.size();i++) cout<<v6[i]<<" "; // direct access is O(1)
    // 2nd way the iterator way
    for(vector<int>:: iterator it=v6.begin();it!=v6.end();it++) cout<<*(it)<<" ";
    // 2nd way but a bit more confined 
    for(auto it=v6.begin();it!=v6.end();it++) cout<<*(it)<<" ";
    // 2nd way but a bit more confined than the previous one with a for each loop
    for(auto it: v6) cout<<it<<" ";// here * will not be used.
    //now lets come to the deletion part.
    vector<int> vec{10,20,30,40,50};
    // To delete a single element 
    vec.erase(vec.begin()+2);// will delete 30 vec={10,20,40,50}
    // To delete more than one element, give the start and end iterator and end iterator should be 1 greater than the end element that you want to delete.
    vec.erase(vec.begin()+1,vec.begin()+4);//will delete 20,30,40 so vec will become {10,50}
    //Insert function
    vector<int> vec(2,100); //{100,100}
    vec.insert(vec.begin(),300); // {300,100,100}
    vec.insert(vec.begin()+1,2,10);//{300,10,10,100,100}
    vector<int> copy(3,50);//{50,50,50}
    vec.insert(vec.begin(),copy.begin(),copy.end()-1);//vec={50,50,300,10,10,100,100} in this way way we can insert a full vector or a portion of it into another vector.
   cout<<vec.size();//gives the number of elements of a vector which is 7 right now.
    vec.pop_back();// removes the last element so vec={50,50,300,10,10,100}
    // v1={10,20,50} v2={30,40}
    // v1.swap(v2); v1={30,40} v2={10,20,50} size kuch bhi ho swap ho jaata hai.
    vec.clear();//erases the entire vector {} and size becomes 0 but capacity is still same.
    cout<<vec.empty();//will give true if vector is empty otherwise will give 0
    // Q. given n numbers in input, print 2 lines,in first line , all even integers in sorted order, in second line, all odd integers in sorted order
    //Ans: make 2 vectors, one for even and the other for odd, push_back the elements in the correct vector then sort both vectors.
    // this problem can be done without vectors too but then it becomes difficult.
}
void explainList()
{
    // list is similar to vector with the only difference that it has front operations too.Just like a vector, a list is also dynamic in nature.
    // a doubly linked list is maintained in a list whereas a singly linked list is maintained in a vector internally. Thus push_front function of a list takes lesser time.
    list<int> ls; // empty list
    // list<int> l(ls) ls is copied into l, like vector we can do the following in list too list<int> ls(5,100) // {100,100,100,100,100}
    ls.push_back(3);// {3}
    ls.emplace_back(4);//{3,4}
    ls.push_front(5);//{5,3,4} , in the case of a vector to push in front we need to use insert function which definitely takes more time when compared to push_front
    ls.emplace_front(6);//{6,5,3,4}
    ls.pop_back();//{6,5,3}
    ls.pop_front();//{5,3}
    cout<<ls.back(); // prints 3
    cout<<ls.front(); // prints 5
    //accessing in a list cannot be done directly ie. ls[4] or ls.at(4) wont work.
    // TC of every function is O(1) except erase which has O(n).
    // rest functions are same as vector - begin,end,rbegin,rend,clear,insert,swap,size,empty
}
void explainDeque()
{
    // deque is similar to list and vector and is dynamic, insertion and deletion can occur from both ends.
    // random access is also possible. dq[2] or dq.at(2)
    deque<int> dq; //{}
    dq.push_back(3); // {3}
    dq.emplace_back(4); // {3,4}
    dq.push_front(1); // {1,3,4}
    dq.emplace_front(2); // {2,1,3,4}
    dq.pop_back(); // {2,1,3}
    dq.pop_front(); // {1,3}
    cout<<dq.back();// prints 3
    cout<<dq.front(); // prints 1
    //accessing is same as vector.
    // on erasing all the elements, size becomes 0 but the max size is still equal to the initial size allocated to dq.
    // rest functions are same as vector - begin,end,rbegin,rend,clear,insert,swap,size,empty
}
void explainStack()
{
    // stack follows lifo
    // stack has primarily only 3 operations push , pop and top and all the three have TC as O(1)
    stack<int> st; //empty stack
    st.push(1); 
    st.push(2);
    st.push(3);
    st.push(3);
    st.emplace(4);
    cout<<st.top(); // will print 4 . In stack, we cant access an element directly like an array so st[3] is not valid
    st.pop(); // removes 4
    cout<<st.top(); // prints 3
    cout<<st.size(); // prints 4
    cout<<st.empty(); // prints 0
    stack<int> s1,s2;
    s1.swap(s2);
    // clear is not available in stack.
}
void explainQueue()
{
    // queue follows fifo and insertion in queue takes place from the back and deletion takes place from the front.
    // all the operations are O(1);
    queue<int> q; // empty queue
    q.push(1); // q= {1}
    q.push(2); // q= {1,2}
    q.emplace(3); // q={1,2,3}
    q.back()+=5;
    cout<<q.back(); // prints 8
    cout<<q.front(); // prints 1
    q.pop(); // q={2,8}
    cout<<q.front(); // prints 2
    //size ,swap,empty same as stack
}
void explainPQ()
{
    // use #include<queue>
    // pq is not a linear data structure , a tree data structure is maintained internally.
    // push,top,pop are the main functions.
    // the element which has larger value will have more priority and so the largest element will stay at the top.
    // Also called as maximum heap.
    // push and pop-O(logn), top-O(1)
    priority_queue<int> pq;// empty pq
    pq.push(5); //{5}
    pq.push(2); //{5,2}
    pq.push(8); //{8,5,2}
    pq.emplace(10); // {10,8,5,2}
    cout<<pq.top();// prints 10
    pq.pop(); // removes 10
    cout<<pq.top(); //prints 8
    pq.push(3); // {8,5,3,2}
    // size,swap,empty same as others
    //But what if i want to have a priority queue which stores the minimum element at the top.
    // for this i have minimum heap.
    priority_queue<int,vector<int>,greater<int>> pq;//syntax for minimum heap.
    pq.push(5);// {5}
    pq.push(2); // {2,5}
    pq.push(8); // {2,5,8}
    pq.emplace(10); // {2,5,8,10
    cout<<pq.top(); //prints 2
    // size is also available.
    }
void explainSet()
{
    // internal implementation- binary search tree
    // insert -O(logn) find-O(logn) lowerbound-O(logn) upperbound-O(logn)
    // erase -O(logn) .begin,.end-O(1)
    // count -O(logn)
    // clear -O(n) size-O(1)
    // elements of a set cant be accessed like this s[1]
    // in a set, every function has O(logn) TC
    // not a linear data structure , a tree is maintained.
    // set is sorted and unique
    // in the case of set,we can only do it++, it--,++it,--it(all take logn time) and we cant do it=it+2 , to move forward multiple steps, we need to do it++ multiple times instead of it=it+2
    set<int> st; // empty set
    st.insert(1); // {1}
    // insert can be used in vector also, it only increases efficiency.
    st.insert(5); // {1,5}
    st.insert(2); // {1,2,5}
    st.insert(2); // {1,2,5}
    st.emplace(3); // {1,2,3,5}
    // begin(),end(),rbegin(),rend(),size(),empty and swap are same as above.
    auto it = st.find(3);// returns an iterator which points to 3.
    auto it = st.find(6);// as 6 is not present so st.end() will be returned i.e. interator pointing to a location right after the last element.
    st.erase(5); //{1,2,3} takes logarithmic time.
    int cnt=st.count(1); // if the element exists then due to set property, it will return 1 otherwise will return 0
    auto it=st.find(3);
    st.erase(it); // will remove 3 so {1,2} and this takes constant time so better than st.erase(5)
    // suppose you have a set s={1,2,3,4,5}
    //auto it1=s.find(2);
    // auto it2=s.find(4);
    // s.erase(it1,it2); the set becomes {1,4,5} so [first,last) 
    // lower bound and upper bound functions work in the same way as in vector.
    // Below is the syntax
    auto it=st.lower_bound(3);
    auto it=st.upper_bound(4);
    // empty is same as above and O(1)
   
}
void explainMultiSet()
{
    // Everything is similar to set but is stores duplicates also.
    multiset<int> ms; //{}
    ms.insert(1);// {1}
    ms.insert(1);// {1,1}
    ms.insert(1); // {1,1,1}
    ms.erase(1); // will erase all 1s
    // suppose you have the multiset as ms={1,1,1,1}
    int cnt=ms.count(1); // this can also give more than 1 as it is a multiset and in this case it is 4
    ms.erase(ms.find(1));// will erase the first occurrence of 1 
    ms.erase(ms.find(1),ms.find(1)+2); // the multiset becomes {1}
    //rest all functions are same as set.
}
void explainUnorderedSet()
{
    // everything is similar to set but does not store in sorted fashion.
    // the elements are stored in a random order which you never know.
    // most of the operations are O(1) so better complexity than set in most cases except some when collision happens.
    // all the operations are same as set.
    // only the lower bound and the upper bound functions do not work.
    // in worst case, the time complexity is O(n) 
}
void explainMap()
{
    // implemented through random black tree or balance tree.
    // insert,erase,find,count - O(logn)
    // map iterators too behave like set iterators.
    // common use case- count frequency of various objects.
    // a map has key and value. A key can be of any datatype and so is the value. A key is always unique.
    // map stores unique keys in sorted order.
    map<int,int> m; // key is int  and value is also int
    map<int,pair<int,int>> m; // key is int and value is pair<int,int>
    map<pair<int,int>,int> m; // key is pair<int,int> and value is int
    // the below 3 lines are for <int,int> map declaration.
    m[1]=2; //{{1,2}}
    m.emplace({3,1}); // {{1,2},{3,1}}
    m.insert({2,4}); // {{1,2},{2,4},{3,1}}
    m[{2,3}]=10; // for <pair<int,int>,int> map . {2,3} is the key and 10 is the value.
    // now our m={{1,2},{2,4},{3,1}}
    // To print all the elements of the map, 
    for(auto it: m)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<m[1];//prints 2 takes logn time
    cout<<m[5];// prints null or 0 as 5 is not present in the map but instantly creates the element
    auto it=m.find(3); // returns an iterator to {3,1}
    cout<<*(it).second;//prints 1 . can also be written as it->second
   auto it=m.find(5);// returns m.end()
    // auto it=m.lower_bound(3);
    // auto it=m.upper_bound(4);
    // erase, swap, size ,empty,count are same as above.
}
void explainMultiMap()
{
    // similar to map, but can store duplicate keys but in sorted order.
    // mpp[key] cant be used here.
}
void explainUnorderedMap()
{
    // implemented through hashtable
    // same as map but does not store the keys in sorted order.
    // time complexity is O(1) but in worst case it is O(n).
    // time complexity of map is O(logn).
}
bool comp(pair<int,int> p1,pair<int,int> p2)// take two arguments of the same datatype which is pair here and assume that the first argument appears before the second argument.

{
    if(p1.second>p2.second) return false;
    if(p1.second<p2.second) return true;
   //otherwise both would be equal
    if(p1.first>p2.first) return true;
    return false;
}
// Algorithms
// use #include<algorithm>
void explainAlgorithms()
{
    //Sorting.
    // Sorting in the case of pairs is done according to the first element and if the first elements are equal then the second elements are compared.
    // sort-O(nlogn) also called as gcc_sort
    //This function internally uses IntroSort. In more details it is implemented using hybrid of QuickSort, HeapSort and InsertionSort.By default, it uses QuickSort but if QuickSort is doing unfair partitioning and taking more than N*logN time, it switches to HeapSort and when the array size becomes really small, it switches to InsertionSort. 
    sort(a,a+n); // a is an array and a is the starting iterator and a+n is the iterator pointing to rightmost+1
    sort(v.begin(),v.end()); // v is a vector
    // sort cant be used with a map
    sort(a+2,a+4); // even a portion of an array or vector can be sorted.
    // To sort in descending order.
    sort(a,a+n,greater<int>); // sorts in descending order. greater<int> is an inbuilt comparator.
    pair<int,int> a[]={{1,2},{2,1},{4,1}};
    // sort the above pair array according to the second element in ascending order but if the second element is same then sort according to the first element but in descending order.
    sort(a,a+n,comp);// comp is a self written comparator. comparator is a bool function
    // finally {{4,1},{2,1},{1,2}}
    int num=7;
    int cnt=_builtin_popcount();// returns the number of set bits. here it is 3
    long long num=1111111111111111;
    int cnt=_builtin_popcountll(); // for long long
    string s="213";//here we are printing all the permutations but as s=213 so the next permutations would be 231 and 312 and 321 but we want all permutations starting from 123 so we need to sort the string.
    sort(s.begin(),s.end());
    do
    {
        cout<<s<<endl;
    } while (next_permutation(s.begin(),s.end()));// will print all the permutations
    int maxi = *max_element(a,a+n); // returns the iterator to the max element
    int mini = *min_element(a,a+n); 
    // a and b are two numbers
    int maxii=max(a,b);
    int minii=min(a,b);
    swap(a,b);// swaps values of a and b
    string s="abcd";
    reverse(s.begin(),s.end()); // s=dcba
    // to rotate an array or vector in the left side.
    // suppose v={1,2,3,4,5,6,7,8,9}
    rotate(v.begin(),v.begin()+3),v.end());// v.begin()+3 is the iterator pointing to the element which will become the first element after rotation.
    // 4,5,6,7,8,9,1,2,3

}
//Binary search.
// Q1. check if x exists in the sorted array or not
// a[]={1,4,5,8,9}
bool res=binary_search(a,a+n,3);// we are searching 3 here, this function is the same binary search algorithm and takes logn time
bool res=binary_search(a,a+n,4);
//lower bound
// lower bound is similar to binary search and works in logn time
// lower_bound returns an iterator which points to the first occurrence of the  element itself if it exists otherwise returns an iterator pointing to an element just greater than the given element.
// a[]={1,4,5,6,9,9}
int ind= lower_bound(a,a+n,4)-a;// as 4 is present so a+1-a=1 so ind=1
int ind= lower_bound(a,a+n,7)-a; // as 7 is not present so iterator pointing to 9 will be returned. index=4
int ind= lower_bound(a,a+n,10)-a; // iterator pointing to end will be returned. index=6
// in the case of vector int ind=lower_bound(v.begin(),v.end(),element)-v.begin()
// upper bound is similar to binary search and works in logn time
// upper_bound returns an iterator which points to an element just greater than the given element irrespective of the fact that the element is present or not.
//a[]={1,4,5,6,9,9}
int ind= upper_bound(a,a+n,4)-a; // ind=2
int ind= upper_bound(a,a+n,7)-a; // ind=4
int ind= upper_bound(a,a+n,10)-a; // ind=6
// in the case of vector int ind=upper_bound(v.begin(),v.end(),element)-v.begin()
// Q.find the first occurrence of x in a sorted array. If it does not exist , print -1
// a[]={1,4,4,4,4,9,9,10,11}
int ind=lower_bound(a,a+n,x)-a;
if(ind!=n && a[ind]==x) cout<<ind;
else cout<<-1;
// x=4 ind=1
// x=2 ans=-1 
// x=12 ans=-1
// Q. find the last occurrence of x in a sorted array. If it does not exist print -1
// a[]={1,4,4,4,4,9,9,10,11}
int ind=upper_bound(a,a+n,x)-a;
ind--;
if(ind>=0 && a[ind]==x) cout<<ind;
else cout<<-1;
// x=4 ind=4
// x=2 ind=-1
// x=0 ind=-1
// Q. find the largest number smaller than x in a sorted array. If no number exists, print -1
// a[]={1,4,4,4,4,9,9,10,11}
int ind=lower_bound(a,a+n,x)-a;
ind--;
if(ind>=0) cout<<a[ind];
else cout<<-1;
// x=4 ans=1
// x=2 ans=1
// x=1 ans=-1
// Q. find the smallest number greater than x in a sorted array. If no number exists, print -1
// a[]={1,4,4,4,4,9,9,10,11}
int ind=upper_bound(a,a+n,x)-a;
if(ind<n) cout<<a[ind];
else cout<<-1;
// x=4 ans=9
// x=2 ans=4
// x=1 ans=4
int main()
{
   return 0;
}