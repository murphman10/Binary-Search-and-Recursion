#include <iostream>
#include <vector>
#include <stdlib.h>
#include<iomanip>
#include <string>
using namespace std;

// Creating the Student Object with Attributes
struct student
{
    int id =0;
    string name = "Random Name";
    string address = "Student's Address";
    int score[10];
    int *arry_ptr =score;
};

int binSearch(vector<student>&, int num, int start, int fin, int cnt);

int main()
{
    vector<student> records(20);
    int indexFound=-1;
    int setwidth =20;
    int tempGrade;

// Filling the vector ID's and array grades.
//Starts at 1000 the id's increase by 50.
    for(int i=0; i<20; i++)
    {
        records[i].id = 1000 + (i*20);

        for(int j=0; j<10; j++)
        {
            tempGrade = (rand()%100)+30;
            if(tempGrade>100)
            {
                tempGrade=100;
            }
            records[i].score[j] = tempGrade;
        }
    }

    // Print out all the student records.
    cout << left<< setw(10) << " ID" << setw(setwidth) << " Name";
    cout << setw(setwidth) << " Address" << endl;

    for(int i =0; i<20; i++)
    {
        cout << setw(10) << records[i].id << setw(setwidth) << records[i].name;
        cout << setw(setwidth) << records[i].address << endl;

        cout << "Student grades : ";

        for (int j =0; j<10; j++)
        {
            cout << records[i].score[j] << " ";
        }
        cout << endl << endl;
    }

    // Search for 3 particular ID's in the vector.
    indexFound = binSearch(records, 1800, 0, 19, 0);
    cout << "Searching for id #1800..." << endl << "Found! At index : " << indexFound << endl;
    cout <<setw(10) << records[indexFound].id << setw(setwidth) << records[indexFound].name
         << setw(setwidth) << records[indexFound].address << endl;
    for (int j =0; j<10; j++)
    {
        cout << records[indexFound].score[j] << " ";
    }
    cout << endl << endl;

    indexFound = binSearch(records, 1340, 0, 19, 0);
    cout << "Searching for ID #1340..." << endl << "Found! At index : " << indexFound << endl;
    cout <<setw(10) << records[indexFound].id << setw(setwidth) << records[indexFound].name
         << setw(setwidth) << records[indexFound].address << endl;
    for (int j =0; j<10; j++)
    {
        cout << records[indexFound].score[j] << " ";
    }
    cout << endl << endl;

    indexFound = binSearch(records, 1360, 0, 19, 0);
    cout << "Searching for ID #1360..." << endl << "Found! At index : " << indexFound << endl;
    cout <<setw(10) << records[indexFound].id << setw(setwidth) << records[indexFound].name
         << setw(setwidth) << records[indexFound].address << endl;
    for (int j =0; j<10; j++)
    {
        cout << records[indexFound].score[j] << " ";
    }
    cout << endl << endl;


    //Searching for ID at the end of the vector.
    indexFound = binSearch(records, 1380, 0, 19, 0);
    cout << "Searching for ID #1380 which should be the last student record in the vector"
         << endl << "Found! At index : " << indexFound << endl;
    cout <<setw(10) << records[indexFound].id << setw(setwidth) << records[indexFound].name
         << setw(setwidth) << records[indexFound].address << endl;
    for (int j =0; j<10; j++)
    {
        cout << records[indexFound].score[j] << " ";
    }
    cout << endl << endl << endl;

    // Search for ID that doesn't exist in the vector.
    cout << "Searching for ID #432891 in the vector..." << endl;
    binSearch(records, 432891, 0, 19, 0);
    cout << endl << endl;

    return 0;
}

// Defining the binary search function.
int binSearch(vector<student> & records,int searchItem,int start,int fin,int cnt)
{
    int middle;

    if(start > fin)
    {
        cout << "ID is not found. Binary search has been called "
             << cnt << " times." << endl;
        return -1;
    }
    else
    {

        middle = (start + fin) / 2;

        if(records[middle].id == searchItem)
        {
            cout << "Binary search has been called "
                 << cnt << " times." << endl;
            return middle;
        }
        else if (searchItem > records[middle].id)
        {
            binSearch (records, searchItem, middle+1, fin, cnt+1);
        }
        else if (searchItem < records[middle].id)
        {
            binSearch (records, searchItem, start, middle-1, cnt+1);
        }
    }
}