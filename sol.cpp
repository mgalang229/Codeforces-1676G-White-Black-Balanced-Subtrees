#include <bits/stdc++.h>
using namespace std;

/*

root = vertex 1

1
7
1 1 2 3 3 5
WBBWWBW

2 3 4 5 6 7
1 1 2 3 3 5

1 2 3 4 5 6 7
W B B W W B W

start from the leaf node:
    W B
7 = 1 0
5 = 2 0
3 = 2 1
6 = 0 1
3 = 2 2 <-

4 = 1 0
2 = 1 1 <-

1 = 4 3

    1
   / \
  2   3
 /   / \
4   5   6
   /
  7

    W
   / \
  B   B
 /   / \
W   W   B
   /
  W

possible roots:
vertex 2 (1 black + 1 white)
vertex 3 (2 blacks + 2 whites)

balanced subtrees = 2

----------------------------------------

8
1 2 3 4 5 6 7
BWBWBWBW

2 3 4 5 6 7 8
1 2 3 4 5 6 7

                 1
                /
               2
              /
             3
            /
           4
          /
         5
        /
       6
      /
     7
    /
   8

                 B
                /
               W
              /
             B
            /
           W
          /
         B
        /
       W
      /
     B
    /
   W

1 2 3 4 5 6 7 8
B W B W B W B W

possible roots:
vertex 1
vertex 3
vertex 5
vertex 7

balanced subtrees = 4

*/

struct Subtree {
    int white, black;

    Subtree() {
        this->white = 0;
        this->black = 0;
    }

    void merge(Subtree other) {
        this->white += other.white;
        this->black += other.black;
    }

    void setbw(Subtree other) {
        this->white = other.white;
        this->black = other.black;
    }
};

void test_case() {
    int n;
    cin >> n;
    int parents[n];
    parents[0] = -1;
    for (int i = 1; i < n; i++)
        cin >> parents[i];
    string s;
    cin >> s;
    Subtree sb[n];
    bool vis[n];
    memset(vis, false, sizeof(vis));
    for (int u = 1; u <= n; u++) {
        int vertex = u;
        // cout << vertex << ": ";
        Subtree prev_sub;
        while (vertex != -1) {
            sb[vertex-1].merge(prev_sub);
            if (!vis[vertex-1]) {
                if (s[vertex-1] == 'W')
                    sb[vertex-1].white++;
                else
                    sb[vertex-1].black++;
                vis[vertex-1] = true;
                prev_sub.setbw(sb[vertex-1]);
            }
            vertex = parents[vertex-1];
            // cout << vertex << " ";
        }
        // cout << "\n";
    }
    // cout << "\n";
    // for (int i = 0; i < n; i++)
    //     cout << i + 1 << " = " << sb[i].white << " " << sb[i].black << "\n";

    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (sb[i].white == sb[i].black)
            cnt++;
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
        test_case();
}
