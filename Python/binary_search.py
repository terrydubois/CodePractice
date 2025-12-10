def binary_search(list, target, l, r):

    # check for target not found
    if l > r:
        return -1

    # using // for floor division
    mid = (l + r) // 2

    # if the middle index has the target, return middle index
    if list[mid] == target:
        return mid
    # if the middle index is lower than the target, chop off left side
    elif list[mid] < target:
        return binary_search(list, target, mid + 1, r)
    # if the middle index is higher than the target, chop off the right side
    else:
        return binary_search(list, target, l, mid - 1)

if __name__ == "__main__":

    input = [1, 2, 4, 6, 8, 9, 12, 15]
    output = binary_search(input, 13, 0, len(input) - 1)
    print(f"result: {output}")