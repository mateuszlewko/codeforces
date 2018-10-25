#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define st first
#define nd second

int n, L, WYNIK;
long long int S;

vector < int > graf [100007];
long long int w [100007];

vector < long long int > v;

int bin_search(int l, long long int s){ //zwraca krótoy licząc od u wzwyż jest najwyższym molziwym
    long long int wart =  S - s;

    int be = 0, kon = v.size() - 1, av;

    //zawsze wektor będzie miał rozmiar przynajmniej 2

    while(be < kon){
        av = (be + kon) / 2;

        if( v.back() - v[av] > wart ){
            be = av + 1;
        }
        else{
            kon = av;
        }

    }

    // printf("be: %d, v.back: %d, wart: %d\n", be, v.back(), wart);

    if( v.back() - v[be] <= wart) {
        // printf("l: %d, s: %d, be: %d, ret: %d\n", l, s, be, min(n - be, L-l));
        return min((int)v.size() - be - 1, L-l);
    }
    return 0;
}

pair < int, long long int > dfs(int u, int matka){
    v.push_back( w[u] + v.back() );

    pair < int, pair < int, long long int > >  wynik = {0, {-1, -1} }; //który wierzchołek, liczba wierzchołkow na sciezce, suma

    for(auto x : graf[u]){
        if(x == matka)
            continue;

        auto y = dfs(x, u);
        wynik = max( wynik, { bin_search(y.st, y.nd), y} );
    }

    pair < int, long long int > out;
    if(wynik.st == 0){
        out = {1,w[u]};
        // for (auto x : v) {
        //     printf("x: %d ", x);
        // }
        // puts("");
        // printf("y.st: %d\n", wynik.st);

        WYNIK++;
    }
    else{
        out = {wynik.nd.st + 1, wynik.nd.nd + w[u]};
    }

    v.pop_back();
    // printf("x: %d, returning: (%d, %d)\n", u, out.first, out.second);
    return out;
}

int main(){
    scanf("%d %d %lld",&n,&L,&S);

    for(int i = 1;i <= n; i++){
        scanf("%lld",&w[i]);
        if(w[i] > S){
            printf("-1\n");
            return 0;
        }
    }

    for(int i = 2;i <= n; i++){
        int x;
        scanf("%d",&x);
        graf[i].push_back(x);
        graf[x].push_back(i);
    }

    v.push_back(0);
    WYNIK = 0;
    dfs(1, 1);

    printf("%d\n",WYNIK);

    return 0;
}