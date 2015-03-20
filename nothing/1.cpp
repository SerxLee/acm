#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

const int N = 110;

vector<int> e[N];
bool v[N];
int p[N];

bool dfs(int x, pii &q) {
  v[x] = true;
  vector<pii> V;
  for (int y : e[x])
    if (!v[y]) {
      pii g;
      if (!dfs(y, g)) return false;
      if (~g.first) V.push_back(g);
    }
  sort(V.begin(), V.end());
  q = { p[x], p[x] };
  for (pii g : V) {
    if (!~q.first)
      q = g;
    else if (q.second + 1 == g.first)
      q.second = g.second;
    else
      return false;
  }
  return true;
}