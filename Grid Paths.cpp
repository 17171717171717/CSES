// https://www.youtube.com/watch?v=2maNV12bzJo
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
template <typename T>
using vec = vector<T>;
#define pb push_back
#define al(x) x.begin(), x.end()
using pii = pair<int, int>;
using ll = unsigned long long ;
using str = string;
#define f first
#define s second
const double eps = 1e-9;

bool visited[7][7];
int steps = 0;
int ans = 0;
int reserved[48];

void solve(int row, int col){

    if(row==6 && col== 0 && steps == 48){
        ans++;
        return;
    }

    if(visited[row][col])return;

    bool hitwall = ((col >= 1 && col <= 5 && !visited[row][col+1] && !visited[row][col-1]) && // 
        ((row == 0 && visited[row+1][col]) || (row == 6 && visited[row-1][col])))// snake, cant go right part and go back
        || ((row >= 1 && row <= 5 && !visited[row+1][col] && !visited[row-1][col]) && // 
        ((col == 0 && visited[row][col+1]) || (col == 6 && visited[row][col-1])));
    // cout << hitwall << endl;
    if (hitwall) return;

    bool split = (row >= 1 && row <= 5 && col >= 1 && col <= 5 && visited[row+1][col] && visited[row-1][col]
    && !visited[row][col+1] && !visited[row][col-1])
    || (row >= 1 && row <= 5 && col >= 1 && col <= 5 && visited[row][col+1] && visited[row][col-1]
    && !visited[row+1][col] && !visited[row-1][col]); // it must be two parts, come from left-up or down / right up or down
    
    if (split) return;



    visited[row][col] = true;

 
	if (reserved[steps] != -1) {
 
		switch (reserved[steps]) {
		case 0:
			if (row > 0 && !visited[row - 1][col]) {
				steps++;
				solve(row - 1, col); // up
				steps--;
			}
			break;
		case 1:
			if (row < 6 && !visited[row + 1][col]) {
				steps++;
				solve(row + 1, col);  //down
				steps--;
			}
			break;
		case 2:
			if (col > 0 && !visited[row][col - 1]) {
				steps++;
				solve(row, col - 1); //left
				steps--;
			}
			break;
		case 3:
			if (col < 6 && !visited[row][col + 1]) {
				steps++;
				solve(row, col + 1); // right
				steps--;
			}
			break;
        }
        visited[row][col] = false;
        return;
    }
 
    if (row > 0 && !visited[row - 1][col]) {
        steps++;
        solve(row - 1, col); // up
        steps--;
    }
    if (row < 6 && !visited[row + 1][col]) {
        steps++;
        solve(row + 1, col);  //down
        steps--;
    }
    if (col > 0 && !visited[row][col - 1]) {
        steps++;
        solve(row, col - 1); //left
        steps--;
    }
    if (col < 6 && !visited[row][col + 1]) {
        steps++;
        solve(row, col + 1); // right
        steps--;
    }


    visited[row][col] = false;
}


int main()
{
    #ifdef local
    #endif

    #ifdef local
    freopen("test_input.txt", "r", stdin);
    #endif

    #ifndef local
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #endif
    str ss ;
    cin >> ss;
	for (int i = 0; i < ss.size(); i++) {
		switch (ss[i]) {
		case '?':
			reserved[i] = -1;
			break;
		case 'U':
			reserved[i] = 0;
			break;
		case 'D':
			reserved[i] = 1;
			break;
		case 'L':
			reserved[i] = 2;
			break;
		case 'R':
			reserved[i] = 3;
			break;
 
		}
    }

    solve(0,0);
    cout << ans << endl;
    return 0;
}