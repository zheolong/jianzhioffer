#include<stdio.h>
#include<stack>
bool is_pop_order(int arr1[], int len1, int arr2[], int len2);
int main(void)
{
    int a[] = {1,2,3,4,5}; 
    int b[] = {4,5,2,3,1}; 
    printf("%d", is_pop_order(a,5,b,5));
}

bool is_pop_order(int arr1[], int len1, int arr2[], int len2)
{
    int index1 = 0;
    int index2 = 0;
    std::stack<int> s;

    bool valid = true;
    while (index2 < len2) {
        if (!s.empty()) {
            int tmp_index = s.top();
            if (arr1[tmp_index] == arr2[index2]) {
                s.pop();
                index2++;
                continue;
            }
        }

        while (index1 < len1 && (arr1[index1] != arr2[index2])) {
            s.push(index1);
            index1++;
        }

        if (index1 < len1) {
            index1++;
            index2++;
        } else {
            valid = false;
            break;
        }
    }

    return valid;
}
