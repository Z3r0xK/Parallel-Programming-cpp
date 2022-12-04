#include<iostream>
#include <omp.h>
using namespace std;
#define SIZE 10000000
#define NoTh 6  
int main(){
    int *arr = new int [SIZE];
    long int sum = 0; 

    //fill the array
    for(int i=0 ; i < SIZE ; i++){
        arr[i] = 1;
    }
    double w1 = omp_get_wtime();
    //Parallel region
    #pragma omp parallel num_threads(NoTh) shared(sum)
    {
        #pragma omp single
        {
            #pragma omp taskloop
            for(int i=0 ; i<SIZE ; i++)
            {
                    #pragma omp atomic
                    sum += arr[i];
            }   
        }
    }
    double w2 = omp_get_wtime();
    cout<<"Sum: "<<sum<<endl;
    cout<<"Time: "<<(w2 - w1)<<endl;
    return 0;
}