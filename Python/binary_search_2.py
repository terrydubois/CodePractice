def binary_search(list, target, l, r):

    if l > r:
        return -1
    
    mid = (l + r) // 2
    if list[mid] == target:
        return mid
    elif list[mid] < target:
        return binary_search(list, target, mid + 1, r)
    else:
        return binary_search(list, target, l, mid - 1)

if __name__ == "__main__":

    input = [2, 3, 4, 6, 8, 10]
    output = binary_search(input, 4, 0, len(input) - 1)
    print(f"result: {output}")