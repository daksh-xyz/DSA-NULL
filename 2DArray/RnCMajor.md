# FINDING ADDRESS OF AN ELEMENT

#### Since an array is allotted contiguous memory, If we're given a base address just multiply the byte per element by the position of element 

## 1-D Array

    Base + ByteSize*(Reqd.Element - Lower Bound)

## 2-D Array

### Row Major

    Base + ByteSize*((I - LR)*TColumns + (J - LC))

#### EXAMPLE:
<code>Q1. Given an array, arr[1………10][1………15] with base value 100 and the size of each element is 1 Byte in memory. Find the address of arr[8][6] with the help of row-major order.</code>

    Address = Base + ByteSize*((I - LR)*TColumns + (J - LC))
    => 100 + 1((8-1)*15 + (6-1))
    => 100 + ((7)*15 + 5)
    => Address = 210

### Column Major

    Base + ByteSize*((J-LC)*TRows + (I - LR))

#### EXAMPLE:

<code>Q1. Given an array, arr[1………10][1………15] with base value 100 and the size of each element is 1 Byte in memory. Find the address of arr[8][6] with the help of column-major order.</code>

    Address = Base + ByteSize*((J-LC)*TRows + (I - LR))
    => 100 + 1*((6-1)*10 + (8-1))
    => 100 + 50 + 7
    => Address = 157