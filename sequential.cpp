#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
struct student{
    int rollNo;
    string name;
    string division;
    string address;
    student(int rollNo, const string &name, const string &division, const string &address){
        this->name = name;
        this->rollNo = rollNo;
        this->division = division;
        this->address = address;
    }
};
const string FILE_PATH="student_data.txt";
void addstudent(const student&data){
    ofstream outfile(FILE_PATH,ios::app);
    if(outfile.is_open()){
        outfile<<data.rollNo<<","<<data.name<<","<<data.rollNo<<","<<data.division<<","<<data.address<<endl;
        outfile.close();
    }
    else{
        cerr<<"not open\n";
    }
}
vector<student>readfromfile(){
    vector<student>v;
    ifstream infile(FILE_PATH);
    if(infile.is_open()){
        string line;
        while(getline(infile,line)){
            stringstream ss(line);
            string token;
            vector<string>tokens;
            while(getline(ss,token,',')){
                tokens.push_back(token);
            }
            v.push_back(student(stoi(tokens[0]), tokens[1], tokens[2], tokens[3]));
        }
    }
    else{
        cerr<<"not open\n";
    }
    return v;
}
void dispstudent(const student&data){
    cout<<"rollno : "<<data.rollNo<<endl<<"name : "<<data.name<<endl<<"division : "<<data.division<<endl<<"address : "<<data.address<<endl;
}
void dispall(){
    vector<student>v=readfromfile();
    cout<<"list-:\n";
    for(int i=0;i<v.size();i++){
        dispstudent(v[i]);
    }
}
int main(){
    cout<<"\n1. Add Student\n2. Display All Students\n3. Exit\nEnter your choice: ";
    while(1){
        int choice;
        cout<<"enter choice : ";
        cin>>choice;
        if(choice==1){
            int rollNo;
            string name, division, address;
            cout << "Enter Roll No: ";
            cin >> rollNo;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Division: ";
            cin >> division;
            cout << "Enter Address: ";
            cin >> address;
            addstudent(student(rollNo, name, division, address));
        }
        else if(choice==2){
            dispall();
        }
        else if(choice==3){
            cout << "Exiting..." << endl;
            return 0;
        }
        else{
            cout<<"invalid\n";
        }
    }
}