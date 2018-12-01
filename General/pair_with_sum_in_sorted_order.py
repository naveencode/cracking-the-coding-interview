def find_pairs(arr, target):
    foundPair = False
    for i in arr:
        for j in arr:
            if i+j == target:
                print("%d %d %d" % (i, j, target))
                foundPair = True
            elif (i+j > target):
                break
    if not foundPair:
        print(-1)
    
def main():
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = [int(x) for x in input().split(' ')]
        target = int(input())
        find_pairs(arr, target)


if __name__=='__main__':
    main()




