#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> room(n + 2, vector<int>(m + 2, -1));

      for (int i = 1; i <= n; ++i) {
        string line;
        cin >> line;

        for (int j = 1; j <= m; ++j) {
            if (line[j - 1] == '.') {
                room[i][j] = 0;
            }
        }
    }

        const int drow[] = { -1, 0, 1, 0 };
    const int dcol[] = { 0, 1, 0, -1 };

       int start_row, start_col;
    cin >> start_row >> start_col;

        int amount_moves;
    cin >> amount_moves;

       string moves;
    cin >> moves;

       int answer = 1;

        room[start_row][start_col] = 1;

      int robot_row = start_row;
    int robot_col = start_col;

     int direction = 0;

     for (char step : moves) {
        if (step == 'R') {
            direction = (direction + 1) % 4;
        }
        else if (step == 'L') {
            direction = (direction - 1 + 4) % 4;
        }
        else if (step == 'M') {
            int next_row = robot_row + drow[direction];
            int next_col = robot_col + dcol[direction];

            if (room[next_row][next_col] != -1) {
                if (room[next_row][next_col] == 0) {
                    room[next_row][next_col] = 1;
                    answer++;
                }

                robot_row = next_row;
                robot_col = next_col;
            }
        }
    }

    cout << answer << endl;

    return 0;
}