# include <iostream>
# include <string>
using namespace std;
class Matrix{
	private:
		int**data;
		int row;
		int col;
	public:
		Matrix(int r, int c){
			row = r;
			col = c;
			data = new int*[row];
			for(int i=0; i<row; i++){
				data[i] = new int [col];
			}
		}
		Matrix(const Matrix& m){
			row = m.row;
			col=m.col;
			data = new int*[row];
			for(int i=0; i<row; i++){
				data[i] = new int[col];
				for(int j=0; j<col; j++){
					data[i][j] = m.data[i][j];
				}
			}
		}
		void input(){
			for(int i=0; i<row; i++){
				for(int j=0; j<col; j++){
					cin>>data[i][j];
				}
			}
		}
		void display(){
				for(int i=0; i<row; i++){
				for(int j=0; j<col; j++){
					cout<<data[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		Matrix addMatrix(Matrix& m){
			if(row != m.row || col != m.col) {
            cout << "Addition not possible";
            return Matrix(0,0);
        }
			Matrix m1(m.row, m.col);
			for(int i=0; i<row; i++){
				for(int j=0; j<col; j++){
					m1.data[i][j] = data[i][j]+m.data[i][j];
				}
			}
			return m1;
		}
		Matrix multiply(Matrix& m){
			if(col!=m.row){
				cout<<"multiplication not possible!";
				return Matrix(0,0);
			}
			Matrix result(row, m.col);
			for(int i=0; i<row; i++){
				for(int j=0; j<m.col; j++){
					result.data[i][j]=0;
					for(int k=0; k<col; k++){
						result.data[i][j] += data[i][k]*m.data[k][j];
					}
				}
			}
			return result;
		}
		 Matrix transpose(){
        Matrix t(col,row);

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                t.data[j][i] = data[i][j];
            }
        }

        return t;
    }
    bool identity(){
    	if(row!=col){
    		return false;
		}
		for(int i=0; i<row; i++){
			for(int j=0;j<col; j++){
				if(i==j && data[i][j]!= 1){
					return false;
				}
				if(i!=j&&data[i][j]!=0){
					return false;
				}
			}
		}
		return true;
	}
	bool isUpperTri(){
		for(int i=0; i<row; i++){
			for(int j=0; j<i; j++){
				if(data[i][j]!=0){
					return false;
				}
			}
		}
		return true;
	}
	bool islowerTri(){
		for(int i=0; i<row;i++){
			for(int j=i+1; j<col; j++){
				if(data[i][j]!=0){
					return false;
				}
			}
		}
		return true;
	}

		~Matrix(){
			for(int i=0; i<row; i++){
				delete[]data[i];
			}
			delete[]data;
			data= nullptr;
		}
};
int main() {
	Matrix m(3,3);
	m.input();
	m.display();
	Matrix m1 = m;
	Matrix m2 = m1.addMatrix(m);
	m2.display();
	Matrix m3 = m1.multiply(m2);
	m3.display();
	Matrix t = m.transpose();
	cout<<"identity: "<<m.identity();
	cout<<"lower tri:"<<m.islowerTri()<<endl;
	cout<<"upper tri: "<<m.isUpperTri()<<endl;
	return 0;
	   }
