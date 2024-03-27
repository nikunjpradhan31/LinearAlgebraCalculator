import numpy as np
import scipy.linalg

class Matrix:
    def __init__(self, rows, cols):
        self.rows = rows
        self.cols = cols
        self.matrix = np.zeros((self.rows, self.cols))
    def getRows(self):
        return self.rows
    def getCols(self):
        return self.cols
    def getMatrix(self):
        return self.matrix

    def fill(self, values):
        if len(values) != self.rows * self.cols:
            raise ValueError("Number of values provided does not match matrix dimensions")
        for i in range(self.rows):
            for j in range(self.cols):
                self.matrix[i][j] = values[i * self.cols + j]

    def display(self):
        print()
        for row in self.matrix:
            print(row)
        print()

    def transpose_matrix(self):
     self.matrix = np.transpose(self.matrix)
 

def gauss_jordan_elimination(A,B):
    row = A.getRows()
    augmented_matrix = np.concatenate((A.getMatrix(), B.getMatrix()), axis=1)

    # Perform forward elimination
    for i in range(row):

        pivot_row = i
        while pivot_row < row and augmented_matrix[pivot_row][i] == 0:
            pivot_row += 1

        # If no pivot in this column, move to the next column
        if pivot_row == row:
            continue

        # Swap pivot row with current row
        augmented_matrix[[i, pivot_row]] = augmented_matrix[[pivot_row, i]]

        # Make pivot element 1
        pivot_element = augmented_matrix[i][i]
        augmented_matrix[i] /= pivot_element

        # Eliminate non-diagonal elements
        for j in range(row):
            if i != j:
                multiplier = augmented_matrix[j][i]
                augmented_matrix[j] -= multiplier * augmented_matrix[i]

        if not row_consistent(augmented_matrix):
            print("The system is inconsistent")
            return None

    #solution_matrix = augmented_matrix[:, row:]
    return augmented_matrix

def row_consistent(aug):
    for row in range(len(aug)):
        consistent_row = False
        for col in range(len(aug[0])-1):
            if aug[row][col] != 0:
                consistent_row = True
                break  # Found a nonzero element, move to the next row
        if not consistent_row and aug[row][-1] != 0:
            return False  # Last element is nonzero but all other elements are zero, inconsistency found
    return True  # All rows are consistent
