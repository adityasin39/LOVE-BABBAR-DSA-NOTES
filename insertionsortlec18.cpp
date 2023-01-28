//insertion sort is just like arranging cards in the correct order.
// suppose we have 4 cards having numbers 6,5,2,4 then first if we get 6 in hand then we hold it without worrying about the order as there is only one card. Now, on getting 5 we will place it before 6 and then on getting 2 we will place before 5 and on getting 4 we will place it between 2 and 5. So in this way the cards ore sorted.
// In the same way insertion sort works.
// e.g. 6 5 4 3 2 1 
// similar to the card example, here we will consider 6 as sorted and will take i and iterate over the array from i=1 i.e. 5, now in pass 1 we will compare 5 and 6 and as 5 is smaller so we will shift 6 to the right by 1 and then copy 5 there.
// so the array becomes 5 6 4 3 2 1 and now in pass 2 ,4 will be compared to 6 and 6 will again be shifted by 1 to the right and then 4 will be compared to 5 and so 5 will also be shifted to right by 1.
// so the array becomes 4 5 6 3 2 1 and now similarly in the subsequent passes comparisons will be made for 3,then 2 then 1 in the subsequent iterations.
// so finally the array becomes 1 2 3 4 5 6 ,in this sorting too there are n-1 passes if the array size is n.
// if the array is 4 6 5 2 3 and in one of the passes i is on 5 then on comparing 5 and 6, 6 will be shifted by 1 and then on comparing 5 and 4 as these are in the correct order so the iteration will be broken.

#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
  for(int i=1;i<n;i++)// 1 se isliye chalaya kyoki 0th element ko sorted maan liya tha
  {
       int temp=arr[i];
      int j=i-1;
      for(;j>=0;j--)
      {
          if(arr[j]>temp) arr[j+1]=arr[j];
          else break;
      }
      arr[j+1]=temp;
  }
}
// for a n size array, 1,2,3,...n-1 comparisons will be made in the consequent passes so O(n^2) will be worst case TC
// for best case, the array will be already sorted so n-1 comparisons will be made so the best case TC will be O(n)
// space complexity-O(1)
// Insertion sort is a stable sorting algorithm.
// Insertion sort is inplace sort.
// Insertion sort is an adaptable algorithm as it does not compare for all values as soon as it finds that the array is sorted it breaks.
