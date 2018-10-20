#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

int getChanges(int arr[], int size){
    int quantity_of_changes = 0;
    int arrGrades[size];

    for(int i = 0; i < size; i++){
        arrGrades[i] = arr[i];
    }

    sort(arrGrades, arrGrades+size, std::greater<int>());

    for(int i = 0; i < size; i++){
        if(arrGrades[i] != arr[i]){
            quantity_of_changes++;
        }
    }

    return size - quantity_of_changes; // Numero que não precisou ser trocado
}

int main(){
    int tests, nStudents;

    scanf("%d", &tests);

    for(int i = 0; i < tests; i++){
        scanf("%d", &nStudents);

        int grades[nStudents];

        for(int x = 0; x < nStudents; x++){
            scanf("%d", &grades[x]);
        }

        printf("%d\n", getChanges(grades, nStudents));
    }

    return 0;
}
