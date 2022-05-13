/*
 Maximum Subarray Sum using divide and conquer
*/
#include<bits/stdc++.h>
using namespace std;
int Max_crossingsum(int arr[] , int l, int r, int mid);
int Max_subarraysum(int arr[],int l, int r);
int max(int a, int b, int c) { return max(max(a, b), c); }
int main()
{
 int n;
 cin>>n;
 int arr[n];
 for(int i=0;i<n;i++)
 {
   cin>>arr[i];
 }
 int M=Max_subarraysum(arr,0,n-1);
 cout<<"Max subarray sum is"<<M<<endl;


}
int Max_crossingsum(int arr[] , int l, int r, int mid)
{
  int sum=0,lsum=INT_MIN;
  for(int i=mid;i>=l;i--)
  {
    sum+=arr[i];
    if(lsum<sum)
        lsum=sum;
  }
  sum=0;
  int rsum=INT_MIN;
  for(int i=mid+1;i<=r;i++)
  {
    sum+=arr[i];
    if(sum>rsum)
    {
      rsum=sum;
    }
  }

 return max(lsum+rsum,lsum,rsum);
}
int Max_subarraysum(int arr[],int l, int r)
{
  if(l==r)
     return arr[0];

  int mid=(l+r)/2;

  return max(Max_subarraysum(arr,l,mid),Max_subarraysum(arr,mid+1,r),Max_crossingsum(arr,l,r,mid));

}
