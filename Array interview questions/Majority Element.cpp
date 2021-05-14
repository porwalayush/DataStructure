/*  Given an array A of N elements.
 Find the majority element in the array.
 A majority element in an array A of size N is an element that appears
  more than N/2 times in the array. if their is no majority element return -1  */


//Moore’s Voting Algorithm
//o(n) time o(1)space

int find_candidate(int a[],int size)
{
    int count=1,pos=0;
    for(int i=1;i<size;i++)
    {
        if(a[i]==a[pos])
        count++;
        else
        count--;
        if(count==0)
        {
            pos=i;
            count=1;
        }
    }
    return a[pos];
}
bool check_candidate(int a[],int size,int can)
{
    int cnt=0;
    for(int i=0;i<size;i++)
    if(a[i]==can)
    cnt++;
    if(cnt>(size/2))
    return true;
    else
    return false;
}
int majorityElement(int a[], int size)
{
        
    // your code here
    int can=find_candidate(a,size);
    if(check_candidate(a,size,can))
    return can;
    else
    return -1;
}

//can also solve using count bit at every position