#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int game(int secret, int numberOfTrys);
int numberOfTrys(int dificult);
int dificultSelection(void);
int trys = 0;
double points = 1000;

int main(){
  cout << "*************************************" << endl;
  cout << "* Bem-vindos ao jogo da adivinhação *" << endl;
  cout << "*************************************" << endl;

  int choose = dificultSelection(); 
  const int Dificult = numberOfTrys(choose);  
  srand(time(NULL));
  const int SECRET_NUMBER = rand()%100;
  /* cout << "The secret number is: " << SECRET_NUMBER << endl; */
  cout << endl;
  game(SECRET_NUMBER, Dificult );
  return 0;
}

int numberOfTrys(int dificult){
  if(dificult == 1){
    return 20;
  }
  else if(dificult == 2) {
    return 10;
  }
  else if(dificult == 3) {
    return 5;
  }
  return 1;
}

int dificultSelection(void) {
  bool validDificult = false;
    cout << "Choose a dificult !!!" << endl;
    cout << "Easy(1) Normal(2) Dificult(3) " << endl;
  while(!validDificult){
    cout << "Enter the Dificult number : ";
    int choose;
    cin >> choose;
    if(choose == 1 || choose == 2 || choose == 3){
      validDificult = true;
      return choose;
    }
    else{
      cout << "Insert a Valid Dificult !!" << endl;
      cout << endl;
    }
  }
  return 120;
}

//game function//
int game(int secretNumber, int numberOfTrys){
  if(trys == numberOfTrys){
    cout << "**** You Lose !! ****" << endl;
    return 1;
  }
  trys++;
  int shot;
  cout << trys << " Try" << endl;
  cout << "Attempt the secret number with a shot: ";
  cin >> shot; 
   
  if(secretNumber == shot){
    cout << "**** You win!! ****" << endl;
    cout.precision(2);
    cout << fixed;
    cout << "Score: " << points << endl;
    return 0;
  }
  else if(shot < secretNumber){
    cout << "Your shot is to low. Try Higher." <<endl;
    points = points - ((secretNumber - shot)/2.0);
    game(secretNumber, numberOfTrys);
  }
  else if(shot > secretNumber){
    cout << "Your shot is to high. Try lower" << endl;
    points = points - ((shot - secretNumber)/2.0);
    game(secretNumber, numberOfTrys);
  }
  return 1;
}
