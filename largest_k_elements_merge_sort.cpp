#include <iostream>
using namespace std;

void merge(long arr[], long l, long m, long r) {
    long i, j, k; 
    long n1 = m - l + 1; 
    long n2 =  r - m; 
  
    /* create temp arrays */
    long L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] >= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void mergeSort(long arr[], long l, long r) {
    if (r > l) {
        long m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {
	//code
	int test_cases;
	cin >> test_cases;
	long len; long k;
	for (long i = 0; i < test_cases; i++) {
	    cin >> len >> k;
	    long arr[len] = {0};
	    for (long j = 0; j < len; j++) {
	        cin >> arr[j];
	    }
	    mergeSort(arr, 0, len-1);
	    for (long count = 0; count < k; count++) {
	        cout << arr[count] << " ";
	    }
	    cout << "\n";
	}
	return 0;
}