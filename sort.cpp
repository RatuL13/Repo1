#include<iostream>
using namespace std;
void SelectionSort(int arr[], int n){
    for (int i=0;i<n-1;i++){
        int smallest=i;
        for (int j=i+1;j<n;j++){
            if (arr[j]<arr[smallest]) smallest=j;
        }
        swap(arr[i],arr[smallest]);
    }
}
void BubbleSort(int arr[], int n){
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}
void InsertionSort(int arr[], int n){
    for (int i=1;i<n;i++){
        int temp=arr[i],j;
        for (j=i-1;j>=0 && arr[j]>temp;j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=temp;
    }
}
void Merge(int arr[],int s,int e)
{
  int mid=(s+e)/2;
  int i=s;
  int j=mid+1;
  int k=s;
  int temp[100];
  while(i<=mid&&j<=e)
  {
    if(arr[i]<arr[j])
    temp[k++]=arr[i++];
    else
    temp[k++]=arr[j++];
  }
  while(i<=mid)
  {
    temp[k++]=arr[i++];
  }
  while(j<=e)
  {
    temp[k++]=arr[j++];
  }
  for(i=s;i<=e;i++)
  {
    arr[i]=temp[i];
  }
}
void MergeSort(int arr[],int s,int e)
{
  if(s==e) return;
  int mid=(s+e)/2;
  MergeSort(arr,s,mid);
  MergeSort(arr,mid+1,e);
  Merge(arr,s,e);
}
void printArray(int arr[], int n){
    int i;
    for (i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}
void ExchangeSort(int arr[],int n)
{
  int i,j;
  for(i=0;i<n-1;i++)
  {
    for(j=i+1;j<n;j++)
    if(arr[i]>arr[j])
    swap(arr[i],arr[j]);
  }
}
int main()
{
  int size,i;
    cout<<"Enter no. of elements in array : ";
    cin>>size;
    int arr[size],ch;
    for(i=0;i<size;i++){
        cin>>arr[i];
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Chooose a sorting method:\n1. Insertion Sort\n2. Selection Sort\n3. Exchange Sort\n";
    cout<<"4. Merge Sort\n5. Bubble sort\nEnter your choice : ";
    cin>>ch;
    switch(ch){
      case 1 :
          InsertionSort(arr, n);
          printArray(arr, n);
          break;
      case 2 :
          SelectionSort(arr, n);
          printArray(arr, n);
          break;
      case 3 :
          ExchangeSort(arr,n);
          printArray(arr, n);
          break;
      case 4 :
          MergeSort(arr, 0, n-1);
          printArray(arr, n);
          break;
      case 5 :
          BubbleSort(arr, n);
          printArray(arr, n);
    }
    return 0;
}
