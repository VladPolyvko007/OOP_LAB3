#include <iostream>
#include <cmath>
#define N 8

using namespace std;

class integer
{
private:
    int value;
public:
    integer() { value == 0; };
    integer(int a) { value = a; };
    ~integer() {};

    int get_val() { return value; };
    void set_val(int a) { value = a; };
    int snumb();
    void sort_array(integer* arr);
    friend void operator<< (ostream& out, integer& integer);
    friend int operator~ (integer& integer);
    friend bool operator> (integer& left, integer& right);
};

int operator~ (integer& integer)
{
    int k = 0;

    for (int i = 1; i <= integer.get_val(); i++)
    {
        if (integer.get_val() % i == 0)
        {
            k++;
        }
    }
    return k;
}

bool operator> (integer& left, integer& right)
{
    return ~left > ~right;
}

void operator<< (ostream& out, integer& integer)
{
    out << integer.value << ".";
    if (integer.snumb() == 1)
    {
        cout << " Це число не є простим.\n";
    }
    else
    {
        cout << " Це число є простим.\n";
    }
}

int integer::snumb()
{
    for (int i = 2; i < sqrt(get_val()); i++)
    {
        if (get_val() % i == 0)
        {
            return 1;
        }
    }
    return 0;
}

void sort_array(integer* arr)
{
    integer* pb, numb;
    for (int k = 1; k < N; k++)
    {
        if (arr[k - 1] > arr[k])
            continue;
        numb = arr[k];
        pb = arr + k - 1;
        while (numb > * pb)
        {
            *(pb + 1) = *pb;
            if (arr > --pb)
                break;
        }
        *(pb + 1) = numb;
    }
}

int main()
{
    system("chcp 1251");

    integer array[N];

    array[0].set_val(24);
    array[1].set_val(5);
    array[2].set_val(72);
    array[3].set_val(81);
    array[4].set_val(23);
    array[5].set_val(47);
    array[6].set_val(39);
    array[7].set_val(102);

    for (int i = 0; i < N; i++)
    {
        cout << "Число № " << i + 1 << ": " << array[i];
    }

    sort_array(array);

    cout << "\nВідсортований масив:\n" << endl;

    for (int i = 0; i < N; i++)
    {
        if (~array[i] == 2)
            break;
        cout << "Число № " << i + 1 << ": " << array[i];
    }
}
