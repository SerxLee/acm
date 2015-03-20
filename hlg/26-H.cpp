#include <cstdio>
int main()
{
	int n;
    int i, j ,k;
	scanf("%d", &n);
	int a[105][105];
    int max = 0, sum = 0;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			scanf("%d", &a[i][j]);
	for (i = 1; i <= n; i++){
	 	for (k = 1; k < i; k++)
			sum -= a[k][i];
		for (j = i + 1; j <= n; ++j){
			sum += a[i][j];
			if (sum > max)
				max = sum;
		}
	}
	sum = 0;
	for (i = n; i >= 1; i--){
	 	for (k = n; k > i; k--)
			sum -= a[k][i];
		for (j = i - 1; j >= 1; j--){
			sum += a[i][j];
			if (sum > max)
				max = sum;
		}
	}
    if (max % 36 == 0) {
        max = max / 36;
    }else{
        max = max / 36 + 1;
    }
	printf("%d\n", max);
	return 0;
}
