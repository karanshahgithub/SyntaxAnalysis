#include <stdio.h>

#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//1st array//
//function call//

char g[3][15] = {
  {
    'S',
    '-',
    'B',
    'c',
    '|',
    'D',
    'B',
    '\0',
    '\0',
    '\0',
    '\0',
    '\0',
    '\0'
  },
  {
    'B',
    '-',
    'a',
    'b',
    '|',
    'c',
    'S',
    '\0'
  },
  {
    'D',
    '-',
    'd',
    '|',
    'l',
    '\0',
    '\0',
    '\0'
  }
};
/*	 {'B','-','b','\0','l','\0','\0','\0'},
				 {'C','-','g','\0','l','\0','\0','\0'}}; 
            /*  {'C','-','g','\0','\0','\0','\0','\0'}
              };*/

char f[8][13];
char fo[8][15];
char fo1[8][8];
int x;

void first(int i, int j, int m, int n) {
  int check = 0, checkl = 0, k, l;
  if (f[i][j] == '\0') {

    while (g[i][j] != '\0') {
      if (g[i][j] >= 'A' && g[i][j] <= 'Z') {
        for (k = 0; k < x; k++) {
          n = 2;
          if (g[i][j] == f[k][0]) {
            if (f[k][2] != '\0') {
              while (f[k][n] != '\0') {

                while (f[i][m] != '\0') {
                  m++;
                }

                if (f[k][n] == 'l') {
                  checkl = 1;
                  break;
                }

                for (l = 2; l < m; l++) {

                  if (f[i][l] == f[k][n]) {
                    check = 1;
                    break;
                  }
                }

                if (check == 0) {
                  f[i][m] = f[k][n];
                  m++;
                }
                n++;
                check = 0;

              }

              if (checkl == 0) {
                while (g[i][j] != '\0') {
                  if (g[i][j] == '|') {
                    j++;
                    break;
                  }
                  j++;
                }

              } else {
                checkl = 0;
                if (g[i][j + 1] == '|' || g[i][j + 1] == '\0') {
                  f[i][m] = 'l';
                  m++;

                  if (g[i][j + 1] == '|') {
                    j++;
                    j++;
                  } else
                    j++;

                } else {
                  j++;

                }

              }
            } else {
              first(k, 2, 2, 2);

              n = 2;

              while (f[k][n] != '\0') {

                while (f[i][m] != '\0') {
                  m++;
                }

                if (f[k][n] == 'l') {
                  checkl = 1;
                  break;
                }

                for (l = 2; l < m; l++) {

                  if (f[i][l] == f[k][n]) {
                    check = 1;
                    break;
                  }
                }
                if (check == 0) {
                  f[i][l] = f[k][n];
                  m++;

                }
                n++;
                check = 0;

              }

              if (checkl == 0) {
                while (g[i][j] != '\0') {
                  if (g[i][j] == '|') {
                    j++;
                    break;
                  }
                  j++;

                }
              } else {
                checkl = 0;
                if (g[i][j + 1] == '|' || g[i][j + 1] == '\0') {
                  f[i][m] = 'l';
                  m++;

                  if (g[i][j + 1] == '|') {
                    j++;
                    j++;
                  } else
                    j++;

                } else

                  j++;

              }

            }

          }

        }
      } else {
        for (l = 2; l < m; l++) {
          if (f[i][l] == f[k][n]) {
            check = 1;
            break;
          }
        }

        if (check == 0) {
          f[i][m] = g[i][j];
        }

        check = 0;

        while (g[i][j] != '\0') {

          if (g[i][j] == '|') {
            j++;
            break;
          }

          j++;
        }
        m++;

      }

    }

  }

  return;

}

void follow(int i, int j) {
  int k, q, l, p, n, check = 0, checkl = 0;

  while (g[i][j] != '\0') {
    if (g[i][j] >= 'A' && g[i][j] <= 'Z') {
      if (g[i][j + 1] == '\0' || g[i][j + 1] == '|') {
        for (k = 0; k < x; k++) {
          if (fo[k][0] == g[i][j])
            break;
        }

        q = 2;

        while (fo[i][q] != '\0') {
          n = 2;

          while (fo[k][n] != '\0') {
            check = 0;
            if (fo[k][n] == fo[i][q]) {
              check = 1;
              break;
            }
            n++;
          }

          if (check == 0) {
            fo[k][n] = fo[i][q];
          }

          q++;
          check = 0;
        }

        fo1[i + 1][k + 1] = 1;

        j++;
        if (g[i][j] == '|')
          j++;

      } else if (g[i][j + 1] != '\0' && g[i][j + 1] != '|') {
        for (k = 0; k < x; k++) {
          if (fo[k][0] == g[i][j])
            break;
        }

        l = j + 1;
        while (g[i][l] != '\0' && g[i][l] != '|') {
          if (g[i][l] <= 'A' || g[i][l] >= 'Z') {
            n = 2;
            while (fo[k][n] != '\0') {
              if (f[k][n] == g[i][l]) {
                check = 1;
                break;
              }
              n++;
            }

            if (check == 0)
              fo[k][n] = g[i][l];

            check = 0;
            break;
          } else if (g[i][l] >= 'A' && g[i][l] <= 'Z') {
            for (p = 0; p < x; p++) {
              if (g[i][l] == f[p][0])
                break;
            }

            q = 2;
            while (f[p][q] != '\0') {
              if (f[p][q] == 'l') {
                checkl = 1;
                q++;
                continue;
              }
              n = 2;
              while (fo[k][n] != '\0') {
                if (f[p][q] == fo[k][n]) {
                  check = 1;
                  break;
                }
                n++;
              }

              if (check == 0)
                fo[k][n] = f[p][q];

              q++;
              check = 0;
            }

            if (checkl == 1 && (g[i][l + 1] == '\0' || g[i][l + 1] == '|')) {
              q = 2;
              while (fo[i][q] != '\0') {
                n = 2;
                while (fo[k][n] != '\0') {

                  if (fo[k][n] == fo[i][q]) {
                    check = 1;
                    break;
                  }
                  n++;
                }
                if (check == 0)
                  fo[k][n] = fo[i][q];

                q++;
                check = 0;
              }

              fo1[i + 1][k + 1] = 1;
              l++;

            } else if (checkl == 1 && (g[i][l + 1] != '\0' && g[i][l + 1] != '|'))
              l++;

            else
              break;
          }

        }

        j++;

        if (g[i][j] == '|')
          j++;

      }
    } else
      j++;

  }
}

int main() {
  int i = 0, j = 0, q, n, check = 0;

  printf("\n enter no of production");
  scanf("%d", & x);

  printf("\n \n \n");

  printf("------grammar---------");
  printf("\n \n");

  for (i = 0; i < x; i++) {
    j = 0;
    while (g[i][j] != '\0') {
      printf("%c", g[i][j]);
      j++;
    }
    printf("\n");
  }

  for (i = 0; i < x; i++) {
    j = 0;
    f[i][j] = g[i][j];
    fo[i][j] = g[i][j];
    j++;
    f[i][j] = '-';
    fo[i][j] = '-';
  }
  fo[0][2] = '$';

  fo1[0][0] = '\0';
  for (i = 1; i <= x; i++) {
    fo1[i][0] = g[i - 1][0];

  }

  for (j = 1; j <= x; j++) {
    fo1[0][j] = g[j - 1][0];

  }

  for (i = 0; i < x; i++)
    first(i, 2, 2, 2);

  printf("\n \n \n");
  printf("---------first-------------");
  printf("\n");

  for (i = 0; i < x; i++) {
    for (j = 0; j < 12; j++) {
      printf("%c", f[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < x; i++)
    follow(i, 2);

  for (i = 1; i <= x; i++) {
    for (j = 1; j <= x; j++) {
      if (fo1[i][j] == 1) {
        q = 2;
        while (fo[i - 1][q] != '\0') {
          n = 2;
          while (fo[j - 1][n] != '\0') {
            if (fo[i - 1][q] == fo[j - 1][n]) {
              check = 1;
              break;
            }
            n++;
          }
          if (check == 0)
            fo[j - 1][n] = fo[i - 1][q];

          check = 0;
          q++;
        }

      }

    }

  }

  printf("\n \n \n ");
  printf("---------follow------------");
  printf("\n");
  for (i = 0; i < x; i++) {
    for (j = 0; j < 15; j++) {
      printf("%c", fo[i][j]);
    }
    printf("\n");
  }

  return 0;
}
