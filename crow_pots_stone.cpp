/*
There are N pots. Every pot has some water in it.
They may be partially filled.
Every pot is associated with overflow number O which tell how many minimum no. of stones required for that pot to overflow.
The crow knows O1 to On(overflow no. for all the pots). Crow wants some K pots to be overflow.
So the task is the minimum number of stones he can make K pots overflow in the worst case.
An array of overflow no--. {1,...On}
Number of pots--n
No of pots to overflow-- k
Let say two pots are there with overflow no.s {5,58}, and the crow has to overflow one pot(k=1).
So crow will put 5 stones in the pot with overflow no.(58), it will not overflow, then he will put them in the pot with overflow no.(5),
hence the total no. of stones to make overflow one pot is=10.
What is the best algorithm to do it?
*/
#include <iostream>
using namespace std;

int n, k;
int arr[1000];
int dp[1000][1000];

int ans = 100000;

void merge(int arr[], int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  int fh[n1], sh[n2];

  for (i = 0; i < n1; i++)
  {
    fh[i] = arr[l + i];
  }
  for (j = 0; j < n2; j++)
  {
    sh[j] = arr[m + 1 + j];
  }

  i = 0, j = 0, k = l;

  while (i < n1 && j < n2)
  {
    if (fh[i] <= sh[j])
    {
      arr[k] = fh[i];
      i++;
    }
    else
    {
      arr[k] = sh[j];
      j++;
    }
    k++;
  }
  while (i < n1)
  {
    arr[k] = fh[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    arr[k] = sh[j];
    j++;
    k++;
  }
}

void mergesort(int arr[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;
    mergesort(arr, l, m);
    mergesort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

int solve()
{
  for (int i = 1; i <= n; i++)
  {
    dp[i][1] = (n - i + 1) * arr[i];
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 2; j <= k; j++)
    {
      for (int p = i + 1; p <= n; p++)
      {
        dp[i][j] = min(dp[i][j], dp[p][j - 1] + (p - i) * arr[i]);
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    ans = min(ans, dp[i][k]);
  }
  return ans;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
      cin >> arr[i];
    }

    mergesort(arr, 1, n);

    for (int i = 0; i < 1000; i++)
    {
      for (int j = 0; j < 1000; j++)
      {
        dp[i][j] = 100000;
      }
    }
    cout << solve() << endl;
  }

  return 0;
}
