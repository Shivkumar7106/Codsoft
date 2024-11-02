#include<iostream>

using namespace std;

int main() 
{
  srand((unsigned int)time(NULL));
  int sNumber= (rand()%100)+1;
  int guessNumber=0;
  
  cout<<"Guess a number between 1 and 100: ";

  while(guessNumber!=sNumber){
    
    cin>>guessNumber;
    
    if(guessNumber>sNumber){
      cout<<"Too high.Guess again: "<<endl;
    }
    else if(guessNumber<sNumber){
      cout<<"Too low.Guess again: "<<endl;
    }
    else cout<<"You guessed it! The number was "<<sNumber<<endl;
  }
  return 0;
}
