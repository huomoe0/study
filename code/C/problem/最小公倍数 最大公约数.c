int gcd(int a,int b)
{
	int r;
	r = a % b;
	while (r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	printf("%d", b);
}

int lcm(int a,int b)
{
	return a * b / gcd(a,b);
}