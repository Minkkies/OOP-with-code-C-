#include <iostream>
using namespace std;
const int n = 3;

template <class T>
class MyArray{
    T a[n];

    public:
        MyArray(){
            for (int i = 0; i < n; i++)
            {
                a[i] = 0;
            }
        }

        //set
        void setArray(int i, T data){
            a[i] = data;
        }
        
        //get
        T getArray(int i){
            return a[i];
        }
        //show
        void showArray(){
            cout << "\n----- show -----" <<endl;
            for (int i = 0; i < n; i++)
            {
                cout <<"a[" << i <<"] = "<< a[i] <<endl;
            }
            
        }

        T findMax(){
            T max = a[0]; // เริ่มต้นด้วยค่าตัวแรกของ array
            for (int i = 0; i < n; i++)
            {
                if (a[i] > max)
                {
                    max = a[i];
                }
            }
            return max;
        }

        T findMin(){
            T min = a[0]; // เริ่มต้นด้วยค่าตัวแรกของ array
            for (int i = 0; i < n; i++)
            {
                if (a[i] < min)
                {
                    min = a[i];
                }
            }
            return min;
        }
};

main(){
    MyArray<int> a1;
    cout <<"a1:"; a1.showArray();

    a1.setArray(0,5); 
    a1.setArray(1,9); 
    a1.setArray(2,1);
    cout << "----- get -----" <<endl;
    cout <<"a[0] = "<< a1.getArray(0) <<endl;
    cout <<"a[1] = "<< a1.getArray(1) <<endl;
    cout <<"a[2] = "<< a1.getArray(2) <<endl;

    cout << "\nMax of a1: " << a1.findMax() << endl;
    cout << "Min of a1: " << a1.findMin() << endl;

    MyArray<double> a2;
    cout <<"\na2:";a2.showArray();

    a2.setArray(0,5.5); 
    a2.setArray(1,8.4); 
    a2.setArray(2,10.2);
    cout << "----- get -----" <<endl;
    cout <<"a[0] = "<< a2.getArray(0) <<endl;
    cout <<"a[1] = "<< a2.getArray(1) <<endl;
    cout <<"a[2] = "<< a2.getArray(2) <<endl;

    cout << "\nMax of a2: " << a2.findMax() << endl;
    cout << "Min of a2: " << a2.findMin() << endl;
}