#define lsb(n) (n & (-n))

int n, fen[1000000];

void update(int i, int add){
    while (i <= n)
        fen[i] += add, i += lsb(i);
}

int sum(int i){
    int ret = 0;
    while (i)
        ret += fen[i], i -= lsb(i);
    return ret;
}

void solve(){
    memset(fen, 0, sizeof(fen));
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        update(i, a[i]);
    for (int i = 1; i <= n; i++)
        cout << fen[i] << ' ';
}
