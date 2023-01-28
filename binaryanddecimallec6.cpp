//decimal to binary 1st logic.
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    // int t,bin;
    // int ans=0;
    // int i=0;
    // while(n)
    // {
    //     t=n/2;
    //     bin=n%2;
    //     ans=ans+pow(10,i)*bin;//agar 1,2,3 se 123 banana hai pehle 1 ko use karte hue then the formula will be ans= (ans*10)+digit
    //     i++;
    //     n=t;
    // }
    // cout<<ans<<endl;//now this ans is stored as int so 2^31-1 will be the max value that it can store hence on giving n as large as 100000 will give ans as a garbage value.To solve this problem , we can store ans as a string or an array.
int negativebinary;


    negativebinary=  ~(-n);
cout<<negativebinary<<endl;
   int t,bin;
    int ans=0;
    int i=0;
    while(negativebinary)
    {
        t=negativebinary/2;
        bin=negativebinary%2;
        ans=ans+pow(10,i)*bin;//agar 1,2,3 se 123 banana hai pehle 1 ko use karte hue then the formula will be ans= (ans*10)+digit
        i++;
        negativebinary=t;
    }
    cout<<ans<<endl;
}
//decimal to binary 2nd logic.
// #include<iostream>
// #include<cmath>
// using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
//     int ans=0;
//     int i=0;
//     while(n)
//     {
//         int bit=n&1;//1 se & karne par jo bit hoga n ka wohi bit mein aayega. if bit=1 then the number is odd and if the bit=0 then the number is even.
//         ans=ans+pow(10,i)*bit;
//         i++;
//         n=n>>1;//right shift means 2 se divide karna so both logics go well with each other.
//     }
//     cout<<ans;
// }
// //binary to decimal.
// #include<iostream>
// #include<cmath>
// using namespace std;
// int main()
// {
//     int n;//hum bhale hi binary number input mein denge but compiler ko decimal hi lagega, hence n%10 use karenge and not n&1 kyunki nahi toh uss n ka binary nikal dega woh. n%10 and n/10 will go hand in hand similarly n&1 and n=n>>1 will go hand in hand. 
//     cin>>n;
//     int i=0;
//     int ans=0;
//     while(n)
//     {
//         int bit=n%10;
//         if(bit==1)
//         {
            
        
//         ans=ans+pow(2,i);//this 2^i logic came from left shift.
//         }
//         i++;
//         n=n/10;
//     }
//     cout<<ans;
// }