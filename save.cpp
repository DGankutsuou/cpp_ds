#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int width;
int height;
vector <string> map;

void find_s(vector <string> &map, int &x, int &y)
{
    size_t c;
    for (string it : map)
    {
        c = it.find('S');
        if (c != string::npos)
        {
            x = c;
            return ;
        }
        y++;
    }
}

void correct(int &x, int &y, char dir)
{
    if (dir == 'l')
        x--;
    else if (dir == 'r')
        x++;
    else if (dir == 'u')
        y--;
    else if (dir == 'd')
        y++;
}

bool is_valid(int &x, int &y, char dir)
{
    int c = x;
    int r = y;
    correct(x, y, dir);
    if (x >= 0 && y >= 0 && x < width && y < height && map[x][y] != '#')
        return true;

    return (x >= 0 && y >= 0 && x < width && y < height);
}

void flood(int steps, int x, int y)
{
    if (steps < 10 && (map[y][x] - '0') > steps)
        map[y][x] = '0' + steps;
    else if (steps > 9 && (map[y][x] - 'A') > (steps - 10))
        map[y][x] = 'A' + steps - 10;
    else
        return ;

    if (is_valid(x, y, 'l'))
        flood(steps + 1, x, y)
}

int main()
{
    int w;
    int h;
    cin >> w >> h; cin.ignore();
    width = w;
    height = h;
    for (int i = 0; i < h; i++) {
        string row;
        getline(cin, row);
        map.push_back(row);
    }
    int x = 0;
    int y = 0;
    find_s(map, x, y);
    cerr << x << " , " << y << endl;
    map[y][x] = '0';
    flood(0, x, y);
    for (int i = 0; i < h; i++) {

        // Write an answer using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cout << map[i] << endl;
    }
}