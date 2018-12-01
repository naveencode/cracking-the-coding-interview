def pretty_print(arr):
    for i in arr:
        print(i)


def zeroify(arr):
    zero_rows = set()
    zero_cols = set()
    for row_index, row in enumerate(arr):
        for col_index, val in enumerate(row):
            if val == 0:
                zero_rows.add(row_index)
                zero_cols.add(col_index)

    row_length = len(arr)
    col_length = len(arr[0])


    for i in range(0, row_length):
        for j in range(0, col_length):
            if i in zero_rows or j in zero_cols:
                arr[i][j] = 0

    
    
    
def main():
    input_arr = [[1, 1, 1],
                [1, 0, 1],
                [0, 1, 1]]
    print("Input array: ")
    pretty_print(input_arr)


    zeroify(input_arr)

    print("Zeroified array: ")
    pretty_print(input_arr)


if __name__ == '__main__':
    main()