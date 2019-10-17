def kthSmallestLargest(arr, n, k): 
    max_val = arr[0] 
    for i in range(len(arr)): 
        if (arr[i] > max_val): 
            max_val = arr[i] 
    hash = [0 for i in range(max_val + 1)]  
  
    # Storing counts of elements 
    for i in range(n): 
        hash[arr[i]] += 1
      
    # Traverse hash array build above until 
    # we reach k-th smallest element. 
    count = 0
    for i in range(max_val + 1): 
        while (hash[i] > 0): 
            count += 1
            if (count == k): 
                return i 
            hash[i] -= 1
          
    return -1
  
# Driver Code 
if __name__ == '__main__': 
    arr = [3, 2, 5, 1, 8, 9]
    n = len(arr) 
    k = 2
    print("kth smallest number is:", 
           kthSmallestLargest(arr, n, k)) 

