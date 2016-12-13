#include <iostream>
#include <random>

using namespace std;

int partition(int a[], int low, int high)
{
    int pivot=a[high];
    int leftPivotindex=low;//for now

    for(int i=low;i<high;i++)
    {
        //if current element less than pivot then .. bubble-swap it
        if (a[i] <= pivot)
        {
            swap(a[leftPivotindex], a[i]);
            cout <<" print" << endl;
            for (int i=0;i<10;i++){ cout <<a[i] << endl ;}
            leftPivotindex +=1;
        }

        cout <<" print" << endl;
    }

    //PUT THE PIVOT..TO BE THE LAST ELEMENT OF THE FIRST LEFTMOST LIST
    //at last we swap the pivot with the leftPivotindex element, leftPivotindex element is the pivot now
    swap(a[leftPivotindex], a[high]);
    for (int i=0;i<10;i++){ cout <<a[i] << endl ;}

    cout <<" print" << endl;

    return leftPivotindex;
}

void quick_sort(int a[], int low, int high)
{
    int pivot=0;
    if (low < high)
    {
        pivot=partition(a, low, high);
        quick_sort(a, low,pivot-1);
        quick_sort(a, pivot + 1, high);
    }
}


int main()
{
    int arrayLength=10;
    srand (time(NULL));
    int a[arrayLength];
    for (int i=0;i<arrayLength;i++)
    {
        a[i]= (rand() / double(RAND_MAX))  * (i+arrayLength*arrayLength);
    }
    for (int i=0;i<arrayLength;i++)
    {
        cout <<a[i] << endl;
    }

    quick_sort(a,0,arrayLength-1);

    for (int i=0;i<arrayLength;i++)
    {
        cout <<a[i] << endl;
    }

    return 0;
}

