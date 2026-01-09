//LIM LI JING A25CS0248
//LIM LI NING A25CS0249
#include<iostream>
#include <fstream>
#include<iomanip>
using namespace std;
void displayLine();
int findIndWinner(int[]);
void  findTeamWinner(int []);
int main(){
    int marks[12][7];
    int total[12]={0};
    int teamtotal[3]={0};
    fstream infile("input.txt",ios::in);
    if(!infile.is_open()){
        cout<<"Sorry, input file does not exist! "<<endl;
        cout<<"Press any key to continue ..."<<endl;
        return 0;
    }
    for(int i=0;i<12;i++){
        for(int j=0;j<7;j++){
            infile>>marks[i][j];
        }
    }
    infile.close();
   
    displayLine();
    cout<<"Id"<<setw(8)<<"E1"<<setw(8)<<"E2"<<setw(8)<<"E3"<<setw(8)<<"E4"<<setw(8)<<"E5"<<setw(10)<<"Total"<<endl;
    displayLine();
    for(int t=0;t<3;t++){
        cout << "TEAM " << (t+1) << endl;
        for (int i = 0; i < 12; i++)
        {
            if (marks[i][0] == (t+1))
            {
                cout<<left<< setw(8)<<marks[i][1];
                for (int j = 2; j < 7; j++){
                    cout <<setw(8)<< marks[i][j];
                    total[i]=total[i]+marks[i][j];
                }
                teamtotal[t]=teamtotal[t]+total[i];
                cout<< total[i]<< endl;
            }
        }
        cout<<right<<"TOTAL                                          "<<teamtotal[t]<<endl;
       
displayLine();
    }
        int max= findIndWinner(total);
        cout<<"Winner for Individual Category: "<<marks[max][1]<<" (Team "<<marks[max][0]<< " )"<<endl;
        findTeamWinner(teamtotal);
        cout<<endl;
        cout<<"Press any key to continue ..."<<endl;
}
void displayLine(){
    for(int i=0;i<52;i++)
    cout<<"-";
    cout<<endl;
}
int findIndWinner(int total[]){
    int max=0;
    int maxvalue=total[0];
    for(int i=0;i<12;i++){
        if(total[i]>maxvalue){
        maxvalue=total[i];
        max=i;
        }
    }
    return max;
}
void findTeamWinner(int teamTotal[])
{
    int max = teamTotal[0];
    int team = 0;

    for (int i = 0; i < 3; i++)
    {
        if (teamTotal[i] > max)
        {
            max = teamTotal[i];
            team = i;
        }
    }

    cout << "Winner for Group Category: Team "<<(team + 1)<< " (Score = " << max << ")" << endl;
}