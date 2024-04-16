Approach

The approach to counting the number of subgrids with all 1s in the given matrix involves iterating through each row of the matrix and representing each row as an integer where each bit represents the presence of a 1 or 0 in the row. Then, for each pair of rows, we calculate the number of common set bits using bitwise AND operation and count the number of subgrids formed by these pairs.

Explanation

Matrix Representation:

We initialize two variables n and m to store the number of rows and columns in the matrix, respectively.
We create a vector row of size n to represent each row as an integer.
Conversion to Integer Representation:

We iterate through each row of the matrix.
For each row, we iterate through each column and set the corresponding bit in the integer representation of the row (row[i]) based on the value of the element in the matrix.
Counting Subgrids:

We initialize a variable ans to store the count of subgrids.
We iterate through each pair of rows (i and j) in the matrix.
We calculate the number of common set bits between the two rows using the bitwise AND operation (row[i] & row[j]) and the __builtin_popcount function to count the set bits.
We calculate the number of subgrids formed by the pair of rows using the formula count * (count - 1) / 2 and add it to ans.