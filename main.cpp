#include <iostream>
#include <fstream>

using namespace std;

class numbers{
  public:  
    void num(int number, int line_num){
      string line;
      int i = 1;
      ifstream numbers("numbers/" + to_string(number) + ".txt");
      if (numbers.is_open())
      {
        while (! numbers.eof())
        {
            getline(numbers,line);
            if(i==line_num){
                cout << line;
                numbers.close();
                return;
            }
            i++;
        }
        numbers.close();
      }
      else{
          cout << "Numbers Don't exist" << endl;
          exit(-1);
      }
    }
}; numbers n;
int main(){
    srand(time(NULL)); 
    int balance, initial_bet, times_betted;
    cout << "Enter Initial amount to bet: ";
    cin >> initial_bet;
    balance = initial_bet;
    while(1){
        cout << string(500, '\n') << endl; // lol endl
        string yorn;
        int one = (rand()%10);
        int two = (rand()%10);
        int three = (rand()%10);
        cout << "+----------------------------+" << endl;
        for(int i=1; i <= 6; i++){
            cout << "| ";
            n.num(one, i);
            cout << " ";
            n.num(two, i);
            cout << " ";
            n.num(three, i);
            cout << " |";
            cout << endl;
        } 
        cout << "+----------------------------+" << endl;
        if(one==two || two==three || one==three){
            cout << "Nice 2 matches! adding 15% to your balance" << endl;
            cout << "[+] Adding " << (balance*.15) << " to the remaining balance" << endl;
            balance = balance+(balance*.15);
        }
        else if(one==two && one==three){
            cout << "WOW all 3? thats amazing giving you a 50% increase" << endl;
            cout << "[+] Adding " << (balance*.50) << " to the remaining balance" << endl;
            balance = balance+(balance*.50);
        }
        else{
            cout << "You win nothing Removing 10% of your balance" << endl;
            cout << "[-] Deducting " << (balance*.10) << " From the remaining balance" << endl;
            balance = balance-(balance*.10);
        }
        times_betted++;
        if(balance <= 0){
            cout << "you've lost! you're not lucky!" << endl;
            cout << "You rolled " << times_betted << " Times before losing!" << endl;
            exit(0);
        }
        else{
          cout << "Remaining Balance: " << balance << endl;
          cout << "Roll again (Y or N)? ";
          cin >> yorn;
          if(yorn=="y" || yorn=="yes"){
              continue;
          }
          else{
              cout << "exiting! your starting balance was " << initial_bet << " Your ending balance is " << balance << endl;
              cout << "You rolled " << times_betted << " Times" << endl;
              exit(0);
          }
        }
    };
    return 0;
}