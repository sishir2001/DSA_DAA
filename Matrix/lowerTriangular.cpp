// elemets where i>=j are non zero.Representing only non zero elements in a single array.
// if the matrix is nxn then non-zero elements are n(n+1)/2
// indexing of the matrix start from 1.
//if we want to find i,j elements in where i>=j then in the 1D array the index would be i*(i-1)/2 + j-1(row major). if i<j then return 0.
// for colum major index in 1D array is (n)*(j-1) - (j-2)(j-1)/2 + i-j
// LowerTri matrix in 1D array.
#include<iostream>

class LowerTri{
    private:
        int n;
        int *A;
    public:
        LowerTri(){
            n = 5;
            A = new int[15];
        }
        LowerTri(int n){
            this->n = n;
            A = new int[n*(n+1)/2];
        }
        ~LowerTri(){
            delete []A;
        }
        void set(int i,int j,int x);
        void get(int i,int j);
        void display();

};

void LowerTri::set(int i,int j,int x){
    if((i>0 && j>0) && (i<=n && j<=n)){
        if(i >= j)
        A[i*(i-1)/2 +j-1] = x;
    }
    
}

void LowerTri::get(int i,int j){
    if((i>0 && j>0) && (i<=n && j<=n)){
        if(i >= j)
        std::cout<<A[i*(i-1)/2 + j-1]<<std::endl;
        else
        {
            std::cout<<"0\n";
        }
        
    }
}

void LowerTri::display(){
    for(int i=1;i<=n;i++){
        for(int j =1;j<=n;j++){
            if(i >= j)
            std::cout<<A[i*(i-1)/2 + j-1]<<" ";
            else
            {
                std::cout<<"0 ";
            }
            
        }
        std::cout<<"\n";
    }
}

int main(){
    LowerTri *p = new LowerTri(3);
    p->set(1,1,10);
    p->set(2,1,10);
    p->set(3,1,10);
    p->set(2,2,10);
    p->set(3,3,10);
    p->set(3,2,10);
    
    p->display();
    



}
