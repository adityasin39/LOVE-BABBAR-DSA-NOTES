// Selection sort is one of the sorting algorithms that works by repeatedly finding the minimum element from the unsorted part and putting it at the beginning of the unsorted part of the array.
//In this algorithm, two parts are created , first is the sorted part and the other is the unsorted part.We iterate over the array and on each iteration ,we find the minimum element from the unsorted subarray and then swap the two elements.
//In this way, for a size n array,we have total n-1 rounds/passes to get the array sorted.
// e.g.  6 2 8 4 10
//       i          1st pass
//       After swap
//       2 6 8 4 10
//         i        2nd pass
//       After swap
//       2 4 8 6 10
//           i      3rd pass
//      After swap
//      2 4 6 8 10
//            i     4th pass
//      After swap
//      2 4 6 8 10 5th pass is not required as it is already sorted.
         
#include <bits/stdc++.h> 
void selectionSort(vector<int>& arr, int n)
{   
    for(int i=0;i<n-1;i++)
    {
        int minindex=i;// iss solution mein humne sirf variables hi create kiye hain aur sirf variables koi extra space nahi lete so O(1) is the space complexity.
// now lets discuss time complexity, if the size of the array is for e.g. 5 then we will have 4 passes and 4,3,2,1 comparisons will be made respectively so n-1,n-2,...1 comparisons will be made i.e.O(n(n-1)/2) i.e. O(n^2) will be the time complexity.
// Best case: When the array is already sorted. Here too the same comparisons will be made so O(n^2) will be best case TC.
// worst case: 4 3 2 1 like array and the TC will be O(n^2)        
        for(int j=i+1;j<n;j++)
        {
            if(arr[minindex]>arr[j]) minindex=j;
        }
     swap(arr[i],arr[minindex]);
    }
}
// Selection sort can be used when the size of the array/vector/list is small.
//Selection sort is a unstable algorithm.
// An algorithm is said to be stable if the duplicate elements in the output appear in the same relative order as in input unsorted array.
// That is if the array is 4a 1 4b 3 2 5 and if the output is 1 2 3 4a 4b 5 then we will say that the sort is stable as the duplicate number 4 is in the same relative order.
// 1 2 3 4b 4a 5 would be unstable sort.
// Selection sort can be stable as well as unstable so it is a unstable algorithm.