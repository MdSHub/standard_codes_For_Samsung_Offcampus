/*
There is one spaceship. X and Y coordinate of source of spaceship and destination spaceship is given.
There are N number of wormholes each wormhole has 5 values.
First 2 values are starting co-ordinate of wormhole and after that value no. 3 and 4 represents ending co-ordinate of wormhole
and last 5th value is represents cost to pass through this wormhole.
Now these wormholes are bi-direction.
Now the to go from (x1,y1) to (x2,y2) is abs(x1-x2)+abs(y1-y2).
The main problem here is to find minimum distance to reach spaceship from source to destination co-ordinate using any number of warm-hole.
It is ok if you wont use any wormhole.
Hint:
You can make graph which contain edge between all points and put cost of that edge.
Now apply djikstra algorithm to find minimum distance between source to destination co-ordinate of spaceship.
Here the main catch is that the cost to pass through wormhole can be zero so you have to take care while making graph matrix.
*/


#include <iostream>
using namespace std;

int n, ans;
struct point
{
  int x;
  int y;
};

struct wormhole
{
  point p1;
  point p2;
  int cost;
};

int vis[100] = {false};

int dist(point src, point dest)
{
  return (abs(src.x - dest.x) + abs(src.y - dest.y));
}

void solve(point src, point dest, int cost, wormhole worm[])
{
  int tempans = cost + dist(src, dest);
  ans = min(ans, tempans);

  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
    {
      vis[i] = true;

      int val = dist(src, worm[i].p1);
      solve(worm[i].p2, dest, cost + val + worm[i].cost, worm);

      val = dist(src, worm[i].p2);
      solve(worm[i].p1, dest, cost + val + worm[i].cost, worm);

      vis[i] = false;
    }
  }
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    point src, dest;
    cin >> src.x >> src.y >> dest.x >> dest.y;
    cin >> n;
    wormhole worm[n];
    for (int i = 0; i < n; i++)
    {
      cin >> worm[i].p1.x >> worm[i].p1.y >> worm[i].p2.x >> worm[i].p2.y >> worm[i].cost;
    }
    ans = 10000;
    solve(src, dest, 0, worm);
    cout << ans << endl;
  }

  return 0;
}
