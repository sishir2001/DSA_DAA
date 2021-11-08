// diagnal matrix in 1D array.
#include<iostream>

class Diagnal{
    private:
        int n;
        int *A;
    public:
        Diagnal(){
            n = 5;
            A = new int[5];
        }
        Diagnal(int n){
            this->n = n;
            A = new int[n];
        }
        ~Diagnal(){
            delete []A;
        }
        void set(int i,int j,int x);
        void get(int i,int j);
        void display();

};

void Diagnal::set(int i,int j,int x){
    if((i>=0 && j>=0) && (i<n && i<n)){
        if(i == j)
        A[i] = x;
    }
    
}

void Diagnal::get(int i,int j){
    if((i>=0 && j>=0) && (i<n && i<n)){
        if(i == j)
        std::cout<<A[i]<<std::endl;
        else
        {
            std::cout<<"0\n";
        }
        
    }
}

void Diagnal::display(){
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            if(i == j)
            std::cout<<A[i]<<" ";
            else
            {
                std::cout<<"0 ";
            }
            
        }
        std::cout<<"\n";
    }
}

int main(){
    Diagnal *p = new Diagnal(3);
    p->set(0,0,4);
    p->set(1,1,1);
    p->set(2,2,2);
    p->get(0,0);
    p->get(1,1);
    p->get(2,2);
    p->display();


}
