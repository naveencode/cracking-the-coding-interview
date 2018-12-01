#include <iostream>
#include <set>

void display_arr(int arr[3][3]) {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void zeroify(int arr[3][3]) {
    std::set<int> zero_rows;
    std::set<int> zero_cols;

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (arr[i][j] == 0) {
                zero_rows.insert(i);
                zero_cols.insert(j);
            }
        }
    }

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (zero_rows.find(i) != zero_rows.end() ||
                zero_cols.find(j) != zero_cols.end())
                arr[i][j] = 0;
        }
    }

    
}

int main() {
    int arr[3][3] = {{1, 1, 1},
                    {1, 0, 1},
                    {0, 1, 1}};

    printf("Input array is: \n");
    display_arr(arr);

    zeroify(arr);
    printf("Zeroified array is: \n");
    display_arr(arr);

    return 0;
}