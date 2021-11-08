// M[i,j] = M[j,i]. to represent symmetric matrix in 1D array we just need to store lower triangular matrix or upper triangular matrix in the 1D array
// In this program im going to store the symmetric matrix as lower triangular matrix in 1D array
// index in the 1D array for i,j where i<=j(lower triangular matrix) is i*(i-1)/2 + j-1.
// when asked for an element M[i][j] where i<j then we can return the element M[j][i] , whose index in 1D array will be j*(j-1)/2 + i-1.
// the size of 1D array will be n*(n+1)/2 if the size of symmetric matrix is nxn.
// the index is formulated considering the indexing of matrix starts from 1,1
#include<iostream>
class SymmetricMatrix{
    private:
        int n;
        int *A;
    public:
        SymmetricMatrix(){
            n = 5;
            A = new int[15];
        }
        SymmetricMatrix(int n){
            this->n = n;
            A = new int[n];
        }
        ~SymmetricMatrix(){
            delete []A;
        }
        void set(int i,int j,int x);
        void get(int i,int j);
        void Display();
};

void SymmetricMatrix::set(int i,int j,int x){
    if(i>=j && (i<=n && j<=n)){
        A[i*(i-1)/2 + j-1] = x;
    }
}

void SymmetricMatrix::get(int i,int j){
    if(i<=n && j<=n){
        if(i<=j){
            std::cout<<A[i*(i-1)/2 + j-1];
        }
        else
        {
            std::cout<<A[j*(j-1)/2 + i-1];
        }
        
    }
}

void SymmetricMatrix::Display(){
    for(int i=1;i<=n;i++){
        for(int j =1;j<=n;j++){
            get(i,j);
            std::cout<<" ";
        }
        std::cout<<std::endl;
    }
}

int main(){
    std::cout<<"Enter the sizes of the symmetric matrix:";
    int n,m;
    std::cin>>m>>n;
    if(n!=m){
        std::cout<<"it should be a square matrix";
        return 0;
    }
    SymmetricMatrix *p = new SymmetricMatrix(n);
    std::cout<<"Enter the elements of symmetric matrix:\n";
    for(int i =1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            int num = -1;
            std::cin>>num;
            p->set(i,j,num);
        }
    }
    std::cout<<std::endl;
    p->Display();
}
