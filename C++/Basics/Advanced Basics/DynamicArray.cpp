#include <iostream>

using namespace std;
int getSum(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    // char ch = 'q';
    // cout<<sizeof(ch) << endl;

    // char *c = &ch;
    // cout << sizeof(c) << endl;

    int n;
    cin >> n;

    // varirable size array
    int *arr = new int[n];
    char *ch = new char[20];

    for (int i = 0; i < 20; i++)
    {
        ch[i] = i + 'a';
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    for (int i = 0; i < 20; i++)
    {
        cout << ch[i] << " ";
    }

    // int ans = getSum(arr, n);
    // cout << "answer is " << ans << endl;

    return 0;
}