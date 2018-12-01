#include <stdio.h>
#include <iostream>

using namespace std;
int main() {
	//code
	int t;
	cin >> t;
	while (t--) {
	    int n;
	    cin >> n;
	    int arr[n];
	    for (int i=0; i<n; i++) {
	        cin >> arr[i];
	    }
	    int sum;
	    cin >> sum;

        bool foundPair = false;
	    
	    // find pairs
	    for (int i=0; i<n; i++) {
	        for (int j=i+1; j<n; j++) {
	            if (arr[i] + arr[j] == sum) {
                    foundPair = true;
	                printf("%d %d %d\n", arr[i], arr[j], sum);
	            }
	            else if (arr[i] + arr[j] > sum){
	                break;
	            }
	        }
	    }

        if (!foundPair)
            printf("-1\n");
	    
	}
	return 0;
}