// Submitted by GS Sasank, Kanishka Singh and Aniket Gupta
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int mod(int a, int b){
  // this function was added to prevent overflow since -1%3 is reported as -1 by the C++ language
  
  int r = a%b;
  return r<0?r+b:r;
}


int main(){
  int in,l,r,c,s,i,j,N;

  cout << "Enter Order of Cube:" << endl;
  scanf("%d",&N);

//memory initialisation of magic cube elements

  int ***magicCube = (int***)calloc(N,sizeof(int**));

  for (i = 0; i < N; i++) {
    // Assign to magicCube[i], not *magicCube[i] (that would dereference an uninitialized pointer)
    magicCube[i] = (int**)calloc(N,sizeof(int*));
    for (j = 0; j < N; j++) {
      magicCube[i][j] = (int*)calloc(N,sizeof(int));
    }
  }


  l=0;//layer
  r=N/2;//row
  c=N/2;//column

//[l,r,c]->[l-1,r,c-1]->[l-1,r-1,c]->[l+1,r,c]
// extended siamese method is used for the generation of magic cube.

  for(int s=1;s <= pow(N,3) ;s++){
    if(magicCube[l][r][c]){
      if(magicCube[mod(l-1,N)][r][mod(c-1,N)]){
        if(magicCube[mod(l-1,N)][mod(r-1,N)][c]){
          l=mod(l+1,N);
          magicCube[l][r][c]=s;
        }
        else{
          l=mod(l-1,N);
          r=mod(r-1,N);
          magicCube[l][r][c]=s;
        }
      }
      else{
        l=mod(l-1,N);
        c=mod(c-1,N);
        magicCube[l][r][c]=s;
      }
    }
    else
      magicCube[l][r][c]=s;
  }

//printing rhe magic cube elements

  for( l=0;l<N;l++){
    cout << "Layer: " << l+1 << endl;
    for(r=0;r<N;r++){
      for(c=0;c<N;c++)
        printf("%3d ",magicCube[l][r][c]);
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}
