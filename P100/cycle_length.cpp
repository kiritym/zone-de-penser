#include <iostream>

using namespace std;
int cycleLength(int num);
int main(){
    int i=0;
    int arr1[10];
    int arr2[10];
    char ans;
    //Inputs from keyboard
    std::cout<<"Sample Input"<<"\n";
    do{
     std::cin>>arr1[i];
     std::cin>>arr2[i];
     std::cout<<"Want to continue? Y/N"<<"\n";
     cin>>ans;
     i++;
    }
   while((ans == 'Y')||(ans =='y')); 
   std::cout<<"---------------------------------------------------------"<<"\n";
   //Formatted input
   std::cout<< "Sample Input" <<"\n";
   for ( int j = 0; j < i; j++ ){
       std::cout<<arr1[j]<<" "<<arr2[j]<<"\n";
   }
   std::cout<< "\n"<<"\n"<<"\n";
   //Formatted Output
    std::cout<< "Sample Output" <<"\n";
     
     for ( int j = 0; j < i; j++ ){
     int maxCL = 0;
     for(int k=arr1[j]; k<=arr2[j]; k++){
        if(maxCL < cycleLength(k)){
            maxCL = cycleLength(k);
        }
      }
     std::cout<<arr1[j]<<" "<<arr2[j]<<" "<< maxCL<<"\n";
     }
return 0;

}

int cycleLength(int num){
    int counter = 0;
    while(num != 1){
        if (num % 2){
            num = 3*num + 1;
        }
        else{
            num = num/2;
        }
        counter ++;

    }

    return counter+1;
}
