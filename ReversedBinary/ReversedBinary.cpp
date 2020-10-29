#include <iostream>
using namespace std;

template <bool...sequence>
int reversed_binary_value()
{
	auto vb = { sequence... };
	int r = 0, i = 0;
	for (int b : vb)
		r += (b << i++);
	return r;
}

template <int n, bool...digits>
struct CheckValues {
	static void check(int x, int y)
	{
		CheckValues<n - 1, 0, digits...>::check(x, y);
		CheckValues<n - 1, 1, digits...>::check(x, y);
	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
	static void check(int x, int y)
	{
		int z = reversed_binary_value<digits...>();
		std::cout << (z + 64 * y == x);
	}
};

int main()
{
	int t; std::cin >> t;

	for (int i = 0; i != t; ++i) {
		int x, y;
		cin >> x >> y;
		CheckValues<6>::check(x, y);
		cout << "\n";
	}
}
