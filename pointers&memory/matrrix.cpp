# include <iostream>
# include <string>
using namespace std;
struct matrix{
	int** data;
	int rows;
	int cols;
};
void createMatrix (matrix &m, int r, int c){
	m.cols = c;
	m.rows = r;
	m.data = new int*[r];
	for(int i=0; i<r; i++){
		m.data[i] = new int[c];
	}
}
void inputMatrix (matrix &m){
	for(int i=0; i<m.rows;i++){
		for(int j=0; j<m.cols; j++){
			cin>>m.data[i][j];
		}
	}
}
void displayMatrix (matrix &m){
	for(int i=0; i<m.rows;i++){
		for(int j=0; j<m.cols; j++){
			cout<<m.data[i][j]<<" ";
		}
		cout<<endl;
	}
}
matrix addMatrix (matrix &a, matrix &b){
	matrix m;
	createMatrix(m,a.rows, a.cols);
	for(int i=0; i<a.rows; i++){
		for(int j=0;  j<a.cols; j++){
			m.data[i][j] = a.data[i][j]+ b.data[i][j];
		}
	}
	return m;
}
void deleteMatrix (matrix &m){
	for(int i=0; i<m.rows; i++){
		delete []m.data[i];
	}
	delete []m.data;
}
void transposeMatrix (matrix &m, matrix &t){
	createMatrix(t, m.cols, m.rows);

	for(int i=0; i<m.rows; i++){
		for(int j=0; j<m.cols; j++){
			t.data[j][i] = m.data[i][j];
		}
	}
}
void multiplyMatrix (matrix &a, matrix &b, matrix &m){
	if(a.cols != b.rows){
        cout << "Multiplication not possible";
        return;
    }
	createMatrix(m,a.rows,b.cols);
	for(int i=0; i<a.rows; i++){
		for(int j=0; j<b.cols; j++){
			m.data[i][j]=0;
			for(int k=0; k<a.cols; k++){
				m.data[i][j] += a.data[i][k]*b.data[k][j];
			}
		}
	}
}
void resize (matrix &m, int nrows, int ncols){
	int** newdata = new int *[nrows];
	for(int i=0; i<nrows; i++){
		newdata[i] = new int [ncols];
		for(int j=0; j<ncols; j++){
		if(i < m.rows && j < m.cols)
                newdata[i][j] = m.data[i][j]; 
            else
                newdata[i][j] = 0;           
        }
	}
	for(int i=0; i<m.rows; i++){
		delete[] m.data[i];
	}
	delete [] m.data;
	m.rows = nrows;
	m.cols = ncols;
	m.data = newdata;
}
void addValue (matrix &m, int row, int col, int val){
	if(row <0 || col<0){
		return ;
	}
		int newrow = m.rows;int newcol = m.cols;
	if(row >=m.rows){
		 newrow = m.rows+1;
	}
	if(col>=m.cols){
		 newcol = m.cols+1;
	}
	resize(m, newrow, newcol);
	m.data[row][col] = val;
}
void removeValue (matrix &m, int val){
	for(int i=0; i<m.rows; i++){
		for(int j=0; j<m.cols; j++){
			if(m.data[i][j] == val){
				for(int x=i; x<m.rows; x++){
					int startcol = (x==i)?j:0;
					for(int y=startcol; y<m.cols; y++){
						if(x == m.rows-1&& y== m.cols-1){
							m.data[x][y] = 0;
						}
						else if(y==m.cols-1){
							m.data[x][y] = m.data[x+1][0];
						}
						else{
							m.data[x][y] = m.data[x][y+1];
						}
					}
					return;
				}
			}
		}
	}
}
bool diagonal(matrix &m){
	for(int i=0; i<m.rows; i++){
		for(int j=0; j<m.cols; j++){
			if(i!=j && m.data[i][j] != 0){
				return false;
			}
		}
	}
	return true;
}
bool symmetric (matrix &m){
		for(int i=0; i<m.rows; i++){
		for(int j=0; j<m.cols; j++){
			if(m.data[i][j]!=m.data[j][i]){
				return false;
			}
		}
	}
	return true;
}

int main() {
    matrix m1;
    createMatrix(m1, 2, 2);

    cout << "Enter 2x2 matrix 1:\n";
    inputMatrix(m1);

    cout << "\nOriginal matrix 1:\n";
    displayMatrix(m1);

    // Test addValue
    

    // Test diagonal
    cout << "\nIs matrix diagonal? ";
    if(diagonal(m1)) cout << "Yes\n";
    else cout << "No\n";

    // Test symmetric
    cout << "\nIs matrix symmetric? ";
    if(symmetric(m1)) cout << "Yes\n";
    else cout << "No\n";

    // Test addition and multiplication
    matrix m2;
    createMatrix(m2, 2, 2);
    cout << "\nEnter 2x2 matrix 2:\n";
    inputMatrix(m2);

    matrix sum = addMatrix(m1, m2);
    matrix product;
    multiplyMatrix(m1, m2, product);

    cout << "\nSum of matrices:\n";
    displayMatrix(sum);

    cout << "\nProduct of matrices:\n";
    displayMatrix(product);

    // Test transpose
    matrix tran;
    transposeMatrix(m1, tran);
    cout << "\nTranspose of matrix 1:\n";
    displayMatrix(tran);
cout << "\nAdding value 99 at (1,2)...\n";
    addValue(m1, 1, 2, 99);  // This will expand the matrix if needed
    displayMatrix(m1);

    // Test removeValue
    cout << "\nRemoving value 99...\n";
    removeValue(m1, 99);
    displayMatrix(m1);
    // Clean up memory
    deleteMatrix(m1);
    deleteMatrix(m2);
    deleteMatrix(sum);
    deleteMatrix(product);
    deleteMatrix(tran);

    return 0;

}
