
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int PartSort(int *arr,int left,int right)
{
    int Key=left;
    while(left<right)
    {
        while(left<right&&arr[right]>=arr[Key])
        {
            right--;
        }
        while(left<right&&arr[left]<=arr[Key])
        {
            left++;
        }
        if(left<right)
        {
            swap(&arr[left],&arr[right]);
        }
    }
    swap(&arr[Key],&arr[left]);
    return left;

}

void QuickSort(int *arr,int left,int right)
{
    if(left>=right)
    {
        return;
    }
    int div=PartSort(arr,left,right);
    QuickSort(arr,left,div-1);
    QuickSort(arr,div+1,right);
}

int main()

{
 int arr[]={6 ,10, 7};
 int *a = arr;
 int *b = arr+1;
    int *c = arr+2;
    QuickSort(arr,0,2);
    return 0;

}