// In bubble sort, if we have an array of size n then there will be n-1 passes.
// In each pass, we compare the neighbour elements and swap accordingly and then move forward by 1 and then again compare the neighbouring elements till the end of the pass.
// In each pass, an element is sorted at the end.
// In ith pass, ith largest element is placed at its right position.
// Thus it is guaranteed that at the end of every pass, one element will be placed at its correct position and that too one of the largest elements.
//The smallest element of the array will be sorted automatically.
// Lets take an example 6 2 8 4 10
// size is 5 so 4 passes.
// 1st pass 2 6 4 8 10 so at the end of 1st pass we have the 1st largest element 10 at its right place so in the next pass we will make 1 lesser comparison
// 2nd pass 2 4 6 8 10 so at the end of 2nd pass we have the 2nd largest element 8 at its right place
// 3rd pass 2 4 6 8 10 so at the end of 3rd pass we have the 3rd largest element 6 at its right place
// 4th pass 2 4 6 8 10 so at the end of 4th pass we have the 4th largest element 4 at its right place
// so after each pass, no of comparisons is decreased by 1.
#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n)
{   
    for(int i=0;i<n-1;i++)
    {
    for(int j=0;j<n-i-1;j++)
    {
         if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
    }
    }
}
// Similar to selection sort the TC of bubble sort will be O(n^2) as n-1,n-2....1 comparisons will be made in the consequent passes.
//Space complexity will be O(1) as only variables are created.
// Best case TC- best case is when the array is already sorted but can we optimize the algorithm to reduce the TC? the answer is yes.
// If in any of the passes, no element is swapped that means the array is now sorted so we can use break. In this way, we can optimize our algorithm for the best case scenario.
//Optimized code
#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n)
{   
    for(int i=0;i<n-1;i++)
    {
        bool swapped=false;
    for(int j=0;j<n-i-1;j++)
    {
         if(arr[j]>arr[j+1]) 
         {
            swap(arr[j],arr[j+1]);
            swapped=true;
         }
    }
    if(swapped==false) break;
    }
}
// So now for best case, n-1 comparisons will be made then the loop will break so O(n) is the best case TC.
// for worst case-O(n^2)
//Bubble sort is a stable algorithm as the same elements dont get swapped hence the order is retained.
// in place sorting algorithms are those algorithms which dont use extra space i.e. space complexity is O(1) i.e. modify the given array itself.
// Both selection and bubble are in place sorts.
//selection sort --  in every round the smallest value takes their correct place

// 