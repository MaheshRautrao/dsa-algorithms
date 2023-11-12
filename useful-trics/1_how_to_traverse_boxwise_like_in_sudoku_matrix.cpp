#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  // input the matrix
  vector<vector<char>> mat(9, vector<char>(9));
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      cin >> mat[i][j];
      // cout<<mat[i][j]<<" ";
    }
    // cout << endl;
  }

  //   traverse boxwise first approach
  // for (int i = 0; i < 3; i++)
  // {
  //   for (int j = 0; j < 3; j++)
  //   {
  //     int count = 0;
  //     for (int k = 0; k < 9; k++)
  //     {
  //       count++;

  //       // main thing is this
  //       cout << mat[3 * i + k / 3][3 * j + k % 3] << " ";

  //       if (count == 3)
  //       {
  //         cout << endl;
  //         count = 0;
  //       }
  //     }
  //     cout << endl;
  //   }
  //   cout << endl;
  // }

  // second approach
  for (int i = 0; i < 9; i += 3)
  {
    for (int j = 0; j < 9; j += 3)
    {

      for (int x = i; x < i + 3; x++)
      {
        for (int y = j; y < j + 3; y++)
        {
          cout << mat[x][y] << " ";
        }
        cout << endl;
      }
      cout << endl;
    }
    }

  return 0;
}
