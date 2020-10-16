def checkPairSumExists(rows, cols, arr, sum):
    numset = set()
    for i in range(0, rows):
        for j in range(0, cols):
            ##If the set has a number that complements the current number to make the sum, return true.
            if sum - arr[i][j] in numset:
                return True
            else:
                ##Add number to set.
                numset.add(arr[i][j])
    return False


'''
Tests here because I did not want to make unit tests for one function.
'''
arr = [[1,2,3],[4,5,6],[7,8,9]]
if(checkPairSumExists(3,3,arr,10) and
   not checkPairSumExists(3,3,arr,19) and
   checkPairSumExists(3,3,arr,7)):
    print("Success")
else:
    print("Fail")
