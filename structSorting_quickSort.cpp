#include <bits/stdc++.h>
using namespace std;

struct StudentInfo{
  int id;
  char name[20];
  double cg;
};

void swapInfo(int a, int b, struct StudentInfo arr[]){
    int temp = arr[a].id; 
    arr[a].id  = arr[b].id; 
    arr[b].id = temp;
    
    char tempName[20];
    strcpy(tempName, arr[a].name);
    strcpy(arr[a].name, arr[b].name);
    strcpy(arr[b].name, tempName);
    
    double tempCg = arr[a].cg; 
    arr[a].cg  = arr[b].cg; 
    arr[b].cg = tempCg;
}

int partition (struct StudentInfo arr[] , int left, int right){ 
    double pivot = arr[right].cg; 
    int i = left-1; 

    for(int k=left ; k<right ; k++){ 
        if(arr[k].cg < pivot){ 
          i++; 
          swapInfo(i,k,arr);
        } 
    } 
    
    i++; 
    swapInfo(i,right,arr);

    return i; 
} 

void quickSort (struct StudentInfo arr[] , int left , int right){ 
    
    if(left < right){ 
      int pivotIndex = partition(arr, left, right); 
      
      quickSort(arr, left, pivotIndex-1); 
      quickSort(arr, pivotIndex+1, right); 
    } 
} 

int main() 
{   
    int num;
    cout << "how many students' info do want to insert?" << endl;
    cin >> num;
    cout << endl << "insert info (id, name, cg):" << endl; 
    
    struct StudentInfo student[num];
    
    int ID;
    double CG;
    char NAME[20];
    for (int i = 0; i < num; i++){
        cin >> ID >> NAME >> CG;
        student[i].cg = CG;
        student[i].id = ID;
        strcpy(student[i].name, NAME);
    }
    
    int len = sizeof(student)/sizeof(student[0]);
    quickSort(student, 0, len-1);
    
    cout << endl << "list of students sorted by their cgpa: " << endl;
    for (int i = 0; i < len; i++) {
        cout << i+1 << ") CGPA: " << setprecision (2) << fixed << student[i].cg << "   ID: " << student[i].id << "   Name: " << student[i].name << endl;
    }
}