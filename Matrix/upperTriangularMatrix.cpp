// same as lower triangular matrix 
// condition for non - zero is j>=i
// index in row major is n*(i-1) - (i-2)(i-1)/2 + j-i
// index in column major is j*(j-1)/2 + i-1

#include<iostream>

class UpperTri{
    private:
        int n;
        int *A;
    public:
        UpperTri(){
            n = 5;
            A = new int[15];
        }
        UpperTri(int n){
            this->n = n;
            A = new int[n*(n+1)/2];
        }
        ~UpperTri(){
            delete []A;
        }
        void set(int i,int j,int x);
        void get(int i,int j);
        void display();

};

void UpperTri::set(int i,int j,int x){
    if((i>0 && j>0) && (i<=n && i<=n)){
        if(i <= j)
        A[j*(j-1)/2 + i-1] = x;
    }
    
}

void UpperTri::get(int i,int j){
    if((i>0 && j>0) && (i<=n && i<=n)){
        if(i <= j)
        std::cout<<A[j*(j-1)/2 + i-1]<<std::endl;
        else
        {
            std::cout<<"0\n";
        }
        
    }
}

void UpperTri::display(){
    for(int i=1;i<=n;i++){
        for(int j =1;j<=n;j++){
            if(i <= j)
            std::cout<<A[j*(j-1)/2 + i-1]<<" ";
            else
            {
                std::cout<<"0 ";
            }
            
        }
        std::cout<<"\n";
    }
}

int main(){
    UpperTri *p = new UpperTri(3);
    p->set(1,1,10);
    p->set(1,2,10);
    p->set(1,3,10);
    p->set(2,2,10);
    p->set(3,3,10);
    p->set(2,3,10);
    
    p->display();


}
