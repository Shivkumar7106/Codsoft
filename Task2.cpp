#include<iostream>
#include<math.h>

using namespace std;

int main() 
{
  double num1,num2,result;
  int choice;
  
  cout<<"Enter the first number: ";
  cin>>num1;

  cout<<"Enter the second number: ";
  cin>>num2;

  cout<<"Chose the operation: "<<endl;
  cout<<"1. Addition"<<endl<<"2. Subtraction"<<endl<<"3. Multiplication"<<endl<<"4. Division"<<endl;
  cin>>choice;

  switch(choice){
    case 1: result=num1+num2;
            cout<<"The result of "<<num1<<"+"<<num2<<" = "<<result<<endl;
            break;
    case 2: result=num1-num2;
            cout<<"The result of "<<num1<<"-"<<num2<<" = "<<result<<endl;
            break;  
    case 3: result=num1*num2;
            cout<<"The result of "<<num1<<"*"<<num2<<" = "<<result<<endl;
            break;
    case 4: if(num2!=0){
                        result=num1/num2;
                        cout<<"The result of "<<num1<<"/"<<num2<<" = "<<result<<endl;}
            else cout<<"Cannot divide by zero"<<endl;
            break;
    default: cout<<"Invalid choice"<<endl;
    
  }
  return 0;
}
