// A square matrix in which main diagnal, upper diagnal and lower diagnal is non -zero rest all the elements are zero
// Representing this diagnal in 1D array with size of 1D array will be n + n-1 + n-1 = 3n-2.
// Row-major and colum-major is not useful as there is no pattern. so we represent the tridiagnal according to the diagnals.
// order can be lower,main,upper or upper,main,lower .
// no single formula for index of 1D array, different for different diagnals.We can do this with the help of conditions.
// for the upper diagnal , i-j =-1
// main diagnal , i-j = 0
// lower diagnal i-j =1
// square band matrix is similar tridiagnal matrix , difference is that there are more than one diagnals below and above the main diagnals in case of square band matrix.same no of diagnals on the either side.
#include<iostream>
class TridiagnalMatrix{
    private:
        int n;
        int *A;
    public:
        TridiagnalMatrix(){
            n = 5;
            A = new int[3*5 -2];
        } 
        TridiagnalMatrix(int n){
            this->n = n;
            A = new int[3*n -2];
        }
        ~TridiagnalMatrix(){
            delete []A;
        }
        void set(int i,int j,int x);
        void get(int i,int j);
        void display();

};

void TridiagnalMatrix::set(int i,int j,int x){
    if((i>0 && j>0) && (i<=n && j<=n)){
        if(i-j == 1){
            A[i-2] = x;// index 
        }
        else if(i-j == 0){
            A[n-1+i-1] = x;// index
        }
        else if(i - j == -1){
            A[n-1 + n + i-1] = x; //index
        }
    }
}

void TridiagnalMatrix::get(int i,int j){
    if((i>0 && j>0) && (i<=n && j<=n)){
        if(i-j == 1){
            std::cout<<A[i-2];
        }
        else if(i-j == 0){
             std::cout<<A[n-1+i-1];
        }
        else if(i - j == -1){
             std::cout<<A[n-1 + n + i-1];
        }
        else
        {
            std::cout<<"0";
        }
        
    }
}
void TridiagnalMatrix::display(){
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            get(i,j);
            std::cout<<" ";
        }
        std::cout<<std::endl;
    }
}

int main(){
    int n,m;
    std::cout<<"Enter the size of the array:";
    std::cin>>n>>m;
    if(n == m){
        TridiagnalMatrix *p = new TridiagnalMatrix(n);
        std::cout<<"Enter the elements:"<<std::endl;
        for(int i = 1;i<=n;i++){
         for(int j = 1;j<=n;j++){
             int num =-1;
             std::cin>>num;
             p->set(i,j,num);
        }
     }
     std::cout<<std::endl;
     p->display();
    }
    else
    {
        std::cout<<"It should be a squared matrix";
    }
    
}
 
