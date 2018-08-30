/* Author: Natalya Ginzburg (naagi@mail.ru) */

#define PROBLEMNAME "counterquestion"

#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>

#define prev prev_we_love_stdlib

using namespace std;

const int MaxL = 256, MaxD = 16; //MaxD = 10 - max number of different letters
int u[26];
int g[MaxD][MaxD];
int dp[1 << MaxD][MaxD];
int prev[1 << MaxD][MaxD];
int answer[MaxL];


int main (void)
{
//  assert (freopen (PROBLEMNAME ".in", "r", stdin));
//  assert (freopen (PROBLEMNAME ".out", "w", stdout));

  unsigned char word[MaxL], letter[MaxL];
  int number[MaxL];
  
  while (scanf(" %s", word) != EOF)
  {
    int i, k = 0, n = strlen((char *) word);
    memset (u, 0, sizeof u);

    for (i = 0; i < n; i++)
    {
      u[word[i] - 'a']++;
      if (u[word[i] - 'a'] == 1)
      {
        number[word[i]] = k;
        letter[k] = word[i];
        k++;
        assert (k <= MaxD); 
      }
    }
    memset (g, 0, sizeof (g));
    for (i = 1; i < n; i++) if (word[i] != word[i-1])
    {
      g[number[word[i]]][number[word[i-1]]] = 1;
      g[number[word[i-1]]][number[word[i]]] = 1;
    }

    memset (dp, 0, sizeof dp);
    memset (prev, -1, sizeof prev);
    for (i = 0; i < k; i++)
    {
      dp[1 << i][i] = 1;
    }
    int mask, last, plast, start = -1;
    for (mask = 0; mask < (1 << k); mask++)
      for (last = 0; last < k; last++) if (mask & (1 << last))
        for (plast = 0; plast < k; plast++) 
          if ((mask ^ (1 << last)) & (1 << plast))
          if (g[last][plast])
          if (dp[mask ^ (1 << last)][plast])
          {
            dp[mask][last] = 1;
            prev[mask][last] = plast;
            if (mask == (1 << k) - 1)
              start = last;
          }
    if (start == -1)    
      printf ("Impossible\n");
    else
    {
      mask = (1 << k) - 1;
      int cur = 0;
      last = start; 
      while (mask != 0)
      {
        answer[letter[last]] = cur++;
        plast = prev[mask][last];
        mask ^= 1 << last;
        last = plast;
        
      }
  
      printf ("%c", word[0]);
      for (i = 1; i < n; i++)
        printf (" %c %c", answer[word[i-1]] < answer[word[i]] ? '<' :
                          answer[word[i-1]] > answer[word[i]] ? '>' :
                                                                '=', 
                          word[i]);
      printf ("\n");
    }
  }
  return 0;
}
