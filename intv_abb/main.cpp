#include <cstdlib>
#include <iostream>

int main(){
    int x = 0;
    size_t N = 10;

    std::cout<<"Enter x: "<<std::endl;
    std::cin>>x;

    int *sorted_array = new int[N];
    
    sorted_array[0] = rand() % N;
    std::cout<<sorted_array[0]<<" ";
    
    for (size_t i = 1; i < N; i++){
        sorted_array[i] = sorted_array[i - 1] + (rand() % N);
        std::cout<<sorted_array[i]<<" ";
    }

    std::cout<<'\n';

    if (x <= sorted_array[0] || x >= 2 * sorted_array[N-1]){
        std::cout<<"False"<<std::endl;
        return 0;
    }


    for (size_t i = 0; i < N; i++){
        for (size_t j = N; j > i; j--){

            if (sorted_array[i] > x){
                std::cout<<"False"<<std::endl;
                return 0;
            }

            if (sorted_array[j] > x){
                continue;
            }

            if ((sorted_array[i] + sorted_array[j]) == x){
                std::cout<<"True"<<std::endl;
                return 0;
            }

        }
    }

    delete [] sorted_array;
    
    return 0;
}
