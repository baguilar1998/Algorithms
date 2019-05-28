
public class MatrixMultiplication {
	
	/**
	 * Strassen Algorithm for matrix multiplication
	 * using sub-matrices
	 * @param A an nXn matrix
	 * @param B an nXn matrix
	 * @return a matrix that holds the result of AxB
	 */
	public static int[][] strassenAlgorithm(int [][] A, int [][] B) {
		// Get the row size of the matrix
		int n = A.length;
		
		// Let C be a new NxN matrix that will hold AxB
		int [][] C = new int[n][n];
		
		// If the matrices that we have are 1x1 matrices, just solve the problem
		if(n==1) {
			C[0][0] = A[0][0] * B[0][0];
		// Else partition matrix A, B, and C to four (n/2)*(n/2) matrices
		} else {
			
			// Get the sub-matrix length
			int subLength = n/2;
			
			// Break A into four new matrices
			int [][] A11 = new int[subLength][subLength];
			int [][] A12 = new int[subLength][subLength];
			int [][] A21 = new int[subLength][subLength];
			int [][] A22 = new int[subLength][subLength];
			
			// Break B into four new matrices
			int [][] B11 = new int[subLength][subLength];
			int [][] B12 = new int[subLength][subLength];
			int [][] B21 = new int[subLength][subLength];
			int [][] B22 = new int[subLength][subLength];
			
			// Break C into four new matrices
			int [][] C11 = new int[subLength][subLength];
			int [][] C12 = new int[subLength][subLength];
			int [][] C21 = new int[subLength][subLength];
			int [][] C22 = new int[subLength][subLength];
			
			// Copying elements in matrices A11 and B11
			for(int i = 0; i < subLength; i++) {
				for(int j = 0; j < subLength; j++) {
					A11[i][j] = A[i][j];
					B11[i][j] = B[i][j];
				}
			}
			
			
			// Copy elements in matrices A12 and B12
			for(int i = 0; i < subLength ; i++) {
				for(int j = subLength; j < n; j++) {
					A12[i][j-subLength] = A[i][j];
					B12[i][j-subLength] = B[i][j];
				}
			}
			
			// Copying elements in matrices A21 and B21
			for(int i = subLength; i < n; i++) {
				for(int j = 0; j < subLength; j++) {
					A21[i-subLength][j] = A[i][j];
					B21[i-subLength][j] = B[i][j];
				}
			}
			
			// Copy elements in matrices A22 and B22
			for(int i = subLength; i < n; i++) {
				for(int j = subLength; j < n; j++) {
					A22[i-subLength][j-subLength] = A[i][j];
					B22[i-subLength][j-subLength] = B[i][j];
				}
			}
			
			// Calculating matrix C11
			int[][] C1 = strassenAlgorithm(A11,B11);
			int[][] C2 = strassenAlgorithm(A12,B21);

			for(int i=0; i < C1.length; i++) {
				for(int j=0; j< C1[i].length; j++) {
					C11[i][j] = C1[i][j] + C2[i][j];
				}
			}
			
			// Calculating matrix C12
			C1 = strassenAlgorithm(A11,B12);
			C2 = strassenAlgorithm(A12,B22);

			for(int i=0; i < C1.length; i++) {
				for(int j=0; j< C1[i].length; j++) {
					C12[i][j] = C1[i][j] + C2[i][j];
				}
			}
			
			// Calculating matrix C21
			C1 = strassenAlgorithm(A21,B11);
			C2 = strassenAlgorithm(A22,B21);

			for(int i=0; i < C1.length; i++) {
				for(int j=0; j< C1[i].length; j++) {
					C21[i][j] = C1[i][j] + C2[i][j];
				};
			}
			
			// Calculating matrix C22
			C1 = strassenAlgorithm(A21,B12);
			C2 = strassenAlgorithm(A22,B22);

			for(int i=0; i < C1.length; i++) {
				for(int j=0; j< C1[i].length; j++) {
					C22[i][j] = C1[i][j] + C2[i][j];
				}
			}
			
			// Copying elements in matrices A11 and B11 to C
			for(int i = 0; i < subLength; i++) {
				for(int j = 0; j < subLength; j++) {
					C[i][j] = C11[i][j];
				}
			}
			
			// Copy elements in matrices A12 and B12 to C
			for(int i = 0; i < subLength ; i++) {
				for(int j = subLength; j< n; j++) {
					C[i][j] = C12[i][j-subLength];
				}
			}
			
			// Copying elements in matrices A21 and B21 to C
			for(int i = subLength; i < n; i++) {
				for(int j = 0; j < subLength; j++) {
					C[i][j] = C21[i-subLength][j];
				}
			}
			
			// Copy elements in matrices A22 and B22 to C
			for(int i = subLength; i < n; i++) {
				for(int j = subLength; j < n; j++) {
					C[i][j] = C22[i-subLength][j-subLength];
				}
			}
		}
		
		return C;
	}
	
	public static void main(String [] args) {
		int [][] A = {{1,3},{7,5}};
		int [][] B = {{6,8},{4,2}};
		
		int [][] C = strassenAlgorithm(A,B);
		
		for(int r = 0; r < C.length; r++) {
			for(int c = 0; c < C[r].length; c++) {
				System.out.print(C[r][c] + " ");
			}
			System.out.println();
		}
	}
}
