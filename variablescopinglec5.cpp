#include<iostream>
using namespace std;
int main()
{
    int a=3;
    cout<<a<<endl;
    if(true)
    {
        cout<<a<<endl;//will print 3 as line 5 a is available throughout the main block.
    }
    //-------
    int a=3;
    cout<<a<<endl;
    if(true)
    {
        int a=5;//this will not give error as this a is declared in a different block.
        cout<<a<<endl;//will print 5 as 5 is more local here.
    }
    cout<<a<<endl;//this will print 3 and not 5 as 5 wala a is only available for the if block.
    //--------
       int a=3;
    cout<<a<<endl;
    if(true)
    {
        int b=5;
        cout<<b<<endl;
    }
    cout<<b<<endl;//this will give error as 5 wala b is only available for the if block.
    //--------
      int a=3;
    cout<<a<<endl;
    if(true)
    {
        int b=5;
        cout<<b<<endl;
    }
    int b=1;
    cout<<b<<endl;//will print 1.
    //-----
    int a=3;
    cout<<a<<endl;
    if(true)
    {
        int b=5;
        cout<<b<<endl;
    }
    int b=1;
    cout<<b<<endl;
    int b=3;//we will get error as there cant be two b in the same scope.
    cout<<b<<endl;
    //------
    int i=7;
    for(int i=0;i<8;i++)//here 0 wala i will be used and not 7 wala i kyuki for loop mein initialization hai toh wahi use hoga na bhai.
    {
        cout<<i<<endl;
    }
    
    //-----
    if(1)
    {
        int b;
        if(1)
        {
            int b;
            if(1)
            {
                int b;
                if(1)
                {
                    int b;//agar ye wala b nahi hota toh line no 67 wala b use hota in this block as it is more local as compared to other b.
                    cout<<b<<endl;
                }
            }
        }
    }
    //the above code will work as every b is declared in a different block.
    
    
}