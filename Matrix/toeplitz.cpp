// Toeplitz matrix is a square matrix, where elements in a diagnal are equal M[i][j] = M[i-1][j-1].This matrix can be stored inside a 1D array by taking only the first row and column.
// if the size of the toeplitz matrix is nxn then size of the 1D array is n(first row)+n-1(first column excluding the 1st element)
// Storing the row first in the 1D array.The row represents the data of the upper triangular matrix. j-i >=0 is the condition and index in the 1D array is j-i
// The column represents the strictly lower triangular matrix.Index of the 1D array is n + i-j-1

#include<iostream>
class Toeplitz{
    private:
        int n;
        int *A;
    public:
        Toeplitz(){
            // no arg constructor
            n = 5;
            A = new int[2*5 -1];
        }
        Toeplitz(int n){
            this->n = n;
            A = new int[2*n-1];
        }
        ~Toeplitz(){
            delete []A;
        }
        void set(int i,int j,int x);
        void get(int i,int j);
        void display();

};

void Toeplitz::set(int i,int j,int x){
    if((i>0 && j>0) && (i<=n && j<=n)){
        if(i<=j){
            // represents the row which represents the upper triangular matrix.
            A[j-i] =x;
        }
        else if(i>j){
            A[n+i-j-1] = x;
        }
    }
}

void Toeplitz::get(int i,int j){
    if((i>0 && j>0) && (i<=n && j<=n)){
        if(i<=j){
            // represents the row which represents the upper triangular matrix.
            std::cout<<A[j-i];
        }
        else if(i>j){
             std::cout<<A[n+i-j-1];
        }
    }
}

void Toeplitz::display(){
    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++){
            get(i,j);
            std::cout<<" ";
        }
        std::cout<<std::endl;
    }
}

int main(){
    int n,m;
    std::cout<<"Enter the size of the toeplitz matrix :";
    std::cin>>n>>m;
    if(n == m){
        Toeplitz *p = new Toeplitz(n);
        std::cout<<"Enter the elements of toeplitz matrix:\n";
        for(int i =1;i<=n;i++){
            for(int j =1;j<=n;j++){
                int num =-1;
                std::cin>>num;
                p->set(i,j,num);
            }
        }
        // printing the array.
        std::cout<<std::endl;
        p->display();
    }
}
