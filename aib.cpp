#include <cstdio>
#define FIN "aib.in"
#define FOUT "aib.out"
#define DIM 100001

int N,
    M,
    AIB[ DIM ];

void update(int p, int val) {

    while(p<=N) {

         AIB[ p ] += val; 
         p += p & (-p); 
    }
};

int getSum(int p) {

    int S = 0;
    while(p) {

         S += AIB[ p ]; 
         p -= p & (-p); 
    }

  return S;
};

int main() {

 int op,el,a,b;

 freopen(FIN, "r", stdin);
 freopen(FOUT, "w", stdout);

 scanf("%d %d", &N, &M);

 for(int i = 1; i <= N; ++i) { 
         scanf("%d",&el); 
         update(i, el);
 }
 
 for( ;M--; ) {

       scanf("%d\n", &op);

 if(op == 0) {

    scanf("%d %d", &a, &b);

    update(a, b);

 } else if(op == 1) {

    scanf("%d %d", &a, &b);

    printf("%d\n", getSum(b) - getSum(a-1));

 } else {

    scanf("%d", &a);
 
    int left = 1, right = N, S, middle, k = -1;
    
    while(left <= right) {

          middle = (left + right) >> 1;
          S = getSum(middle);

          if(S == a) {
             k = middle;
             break;
          } else if(S < a){
                 left = middle + 1;
          } else { 
                 right = middle - 1; }
    } 
    printf("%d\n", k);        
 }

 };

 fclose( stdin );
 fclose( stdout );

 return(0);
};