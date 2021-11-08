#include<stdio.h>
int max(int x,int y){
	return (x>=y)?x:y;
}

int main(void){
	int T =0,p = 0,g= 0,n=0;
	scanf(" %d",&T);// for the test cases.
	
	for(int i=0;i<T;i++){
		scanf(" %d %d",&g,&p);// cost of green and purple balloons
		scanf(" %d",&n);// no of participants
		int a[n][2],sum0=0,sum1=0,maxi=0,min=0;
		// initailizing the array to 0.
		for(int i=0;i<n;i++){
			for(int j=0;j<2;j++){
			a[i][j] = 0;
			scanf(" %d",&a[i][j]);
			}
		}
		
		// calulating for the first question and second question
		for(int i =0;i<n;i++){
			sum0 +=a[i][0];
			sum1+=a[i][1];
		}
		maxi = max(sum0,sum1);
		min = sum0+sum1-maxi;
		printf("%d\n",(p>g)?(p*min+g*maxi):(p*maxi+g*min));

	}

}
