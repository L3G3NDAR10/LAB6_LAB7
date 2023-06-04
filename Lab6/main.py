import ctypes
import random

libsort = ctypes.CDLL('./libsort.so')

libsort.sortArray.argtypes = (ctypes.POINTER(ctypes.c_double), ctypes.c_int)
libsort.sortArray.restype = None

while True:
    try:
        length = int(input("Input number of elements: "))
        
        if length < 0:
            print("Error: Number must be positive.\n")
            continue

        arr = [round(random.uniform(0, 100), 2) for _ in range(length)]
        
        arr_c = (ctypes.c_double * length)(*arr)
        
        libsort.sortArray(arr_c, length)
        
        sorted_arr = [arr_c[i] for i in range(length)]
        print("Sorted array: \n", sorted_arr)
        
        break
    
    except ValueError:
        print("Error. Make sure you enter a number.\n")
