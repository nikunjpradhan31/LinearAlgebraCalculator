import Matrix_Functions
from Matrix_Functions import Matrix
import numpy as np
import scipy.linalg

one = Matrix(3,3)
two = Matrix(3,1)
values = [2,3,-4,3,4,-2,5,7,-6]
one.fill(values)
values = [7,9,20]
two.fill(values)
one.display()
two.display()
solved = Matrix_Functions.gauss_jordan_elimination(one,two)
print(solved)
