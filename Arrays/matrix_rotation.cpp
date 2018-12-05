#include <iostream>

#define N 5
// Rotate matrix by 90 degree

void swap(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void make_incremental_array(int arr[][N], int n) {
    int counter = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            arr[i][j] = ++counter;
        }
    }
}

void display_arr(int arr[][N], int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

void rotate90(int a[][N], int n) {

    // Code to rotate just the outer array
    // for (int j=0; j<n-1; j++) {
    //     int temp = a[0+j][0];
    //     swap(&temp, &a[n-1][0+j]);
    //     swap(&temp, &a[n-1-j][n-1]);
    //     swap(&temp, &a[0][n-1-j]);
    //     swap(&temp, &a[0+j][0]);
    // }


    for (int i=0; i<n/2; i++) {
        for (int j=0; j<(n-1)/(i+1); j++) {
            int temp = a[0+j+i][0+i];
            swap(&temp, &a[n-1-i][0+j+i]);
            swap(&temp, &a[n-1-j-i][n-1-i]);
            swap(&temp, &a[0+i][n-1-j-i]);
            swap(&temp, &a[0+j+i][0+i]);
        }
    }
}

// void rotate360(int a[][N], int n) {
//     for (int i=0; i<4; i++) {
//         rotate90(a, n);
//     }
// }


int main() {
    int arr[N][N];
    make_incremental_array(arr, N);

    printf("Input array is: \n");
    display_arr(arr, N);

    rotate90(arr, N);
    // rotate360(arr, N);
    printf("Rotated array is: \n");
    display_arr(arr, N);

    return 0;   
}