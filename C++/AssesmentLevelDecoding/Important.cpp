// #include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
// 1
void solve()
{
    int first = 10, second = 20;
    int third = first + second;
    {
        int third = second - first;
        printf("%d ", third);
    }
    printf("%d\n", third);
}

void solve2()
{
    char c[] = "Hello";
    printf("%s", c);
}
int main()
{
    solve();
    solve2();
}