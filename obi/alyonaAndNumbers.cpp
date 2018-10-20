#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	long long ans = 0;
	for(int val = 1; val <= x; ++val)
	{
		ans += (int) floor((y-(5 - (val%5)))/5.0) + 1;
	}
	cout << ans << endl;
	return 0;
}