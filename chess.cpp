#include <iostream>

using namespace std;

void init_chess(int (&new_arr)[8][8]){
    for(int counter1=0;counter1<8;counter1++)
    {
        for(int counter2=0;counter2<8;counter2++)
        {
            if(counter1==0 || counter1==1 || counter1==6 || counter1==7)
            {
                new_arr[counter1][counter2] == 1;
            }
        }
    }
}

void print_board(int (&new_arr)[8][8])
{
    for(int counter1=0;counter1<8;counter1++)
    {
        for(int counter2=0;counter2<8;counter2++)
        {
            cout<<(new_arr[counter1][counter2]);
        }
        cout << endl;
    }

}
int main(){
    int new_arr[8][8] = {0};
    init_chess(new_arr);
    print_board(new_arr);
    
    return 0;
}