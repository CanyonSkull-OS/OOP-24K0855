#include <iostream>
using namespace std;

// I am Omer

class ReverseWords{

    public:
        int arrInput(char arr[100]){
            int count = 0;
            char ch;
            cout << "Enter your string: ";
            while(count <= 100){
                ch = getchar();

                if (ch == '\n')
                {
                    arr[count] = '\0';
                    break;
                }
                else{
                    arr[count] = ch;
                    count++;
                }
            }
            return count;
        }

        void display(char arr[100], int length){
            cout << "Your entered String: ";
            for (int i = 0; i < length; i++)
            {
               cout << arr[i];
            }
            cout << endl;
        }

        void reverseString(char arr[100], int length){
            for (int i = 0; i < length/2; i++)
            {
                char temp = arr[i];
                arr[i] = arr[length-i-1];
                arr[length-i-1] = temp;
            }
        }

        void reverseWords(char arr[100], int length){
            int start = 0;
            for (int i = 0; i <= length; i++)
            {
                if(arr[i] == ' ' || arr[i] == '\0'){
                    int end = i-1;
                    while (start < end){
                        char temp = arr[start];
                        arr[start] = arr[end];
                        arr[end] = temp;
                        start++;
                        end--;
                    }
                    start = i+1;
                }
            }
        }

};


int main(){

    ReverseWords r1;
    char arr[100];
    int length = r1.arrInput(arr);
    r1.display(arr, length);
    r1.reverseString(arr, length);
    r1.display(arr, length);
    r1.reverseWords(arr, length);
    r1.display(arr, length);

    return 0;
}