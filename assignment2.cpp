//Name: LIM LI JING MATRIC NO:A25CS0248
//Name: LIM LI NING MATRIC NO:A25CS0249
//dated: 11/12/2025

#include <iostream>//to allow use of count,cin and endl
#include <cmath>//to allow library function like round(),int()
#include<iomanip>// for manipulating output format like setprecision,setw
using namespace std;
// Function declarations (prototypes) used in the program
void GetAge(int&);
double Bmr(char,int,int,int);
string printWithCommas(int);
int main(){
    //declare variable which is age,gender,height,weight,
    char answer;
    int age,height,weight;
    char gender;
    // Loop continues as long as the user enters 'Y' or 'y'
    do{
    cout<<"Basal Metabolic Rate (BMR) Calculator"<<endl;
    cout<<"\n";
    // Call the GetAge function to prompt the user to enter their age
    GetAge(age);
    //do-while loop to ensure the user enters the correct gender which is f/F/M/
    do{
        cout<<"Gender [F @ M]: ";
        cin>>gender;
    }while(gender!='f'&& gender!='F' && gender!='m' && gender!='M');
    //display height
    cout<<"Height (cm): ";
    cin>>height;//user input height
    //display weight
    cout<<"Weight (kg): ";
    cin>>weight;//user input height
    double BMR=(Bmr(gender,weight,height,age));//call the Bmr function to get BMR
    cout << fixed << setprecision(2);//fixed 2 pointing
    cout<<"BMR = "<<BMR<<" Calories/ day (using Mifflin-St Jeor Equation)"<<endl;
    cout<<"\n";
    //calculate each activity level
    double seden=round(BMR*1.2);
    double exe1=round(BMR*1.375);
    int moderateEx = BMR * 1.465;
    int dailyEx = round(BMR * 1.55);
    int intenseEx = round(BMR* 1.725);
    int veryIntenseEx = round(BMR * 1.9);
    //display all the activity level
    cout<<"Activity Level"<<setw(57)<<"Calorie"<<endl;
    cout<<"Sedentary: little or no exercise "<<setw(36)<< printWithCommas(seden)<<endl;//use setw() to set the space
    cout<<"Exercise 1-3 times/week "<<setw(45)<< printWithCommas(exe1)<<endl;
    cout<<"Exercise 4-5 times/week "<<setw(45) <<printWithCommas(moderateEx)<<endl;
    cout<<"Daily exercise or intense exercise 3-4 times/week "<<setw(19) <<printWithCommas(dailyEx)<<endl;
    cout<<"Intense exercise 6-7 times/week "<<setw(37) <<printWithCommas(intenseEx)<<endl;
    cout<<"Very intense exercise daily,or physical job "<<setw(25)<< printWithCommas(veryIntenseEx)<<endl;
    cout<<"\n";
    cout<<"Exercise: 15-30 minutes of elevated heart rate activity."<<endl;
    cout<<"Intense exercise: 45-120 minutes of elevated heart rate activity."<<endl;
    cout<<"Very intense exercise: 2+ hours of elevated heart rate activity."<<endl;
    cout<<"\n";
    do{
    cout<<"Do you want to enter other data? [Y @ N]: ";
    cin>>answer;}while(answer!='n' && answer!='N'&& answer!='y' && answer!='Y');
    cout<<"\n";
    }while(answer=='y' ||answer=='Y');//loop again when enter other than 'N'/'n'/'Y'/'y'
    //display "Thank you :)"after loop finished
    cout<<"Thank you :)"<<endl;
    return 0;
}
//Prompt the user to enter their age and store it in the reference variable 'age'
void GetAge(int &age){
    //do-while loop to ensure the user enters the correct age between 15-80 and calling back to the main method
    do{
    cout<<"Age [15-80]: ";
    cin>>age;
    }while(age<15 ||age>80);
}
// Calculate and return the BMR 
double Bmr(char gender,int weight,int height,int age){
    double bmr;
    //check if the user is Female/Male and calculate BMR
    if(gender=='m'||gender=='M')
    {
        bmr=10*weight+6.25*height-5*age+5;
    }
    else{
        bmr=10*weight+6.25*height-5*age-161;
    }
    return bmr;
}
//return the comma when display the number
string printWithCommas(int value) {
    string result = "";// Initialize empty string to store formatted number
    int count = 0;//set count as 0
    //process each digit of the value
    while (value > 0) {
        // Check if we need to insert a comma every 3 digits
        if (count > 0 && count % 3 == 0) {
            result = "," + result;// add comma every 3 digits
        }
        char digit;//declare viarable as a character
        int remainder=value%10;//to got the smallest remainder of the value
        if(remainder==0)digit = '0'; 
        else if(remainder==1)digit = '1'; 
        else if(remainder==2) digit = '2';
        else if(remainder==3) digit = '3';
        else if(remainder==4) digit = '4';
        else if(remainder==5) digit = '5';
        else if(remainder==6) digit = '6';
        else if(remainder==7) digit = '7';
        else if(remainder==8) digit = '8';
        else digit = '9';
        result = digit + result;//add digit to front
        value /= 10;//remove last digit of value
        count++;//updating
    }
    
    return result;// return string with commas
}