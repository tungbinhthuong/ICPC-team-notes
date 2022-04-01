int Num[200005], Low[200005], Time = 0;
int Count = 0;
stack<int> st;

void tarjan(int u) {
    Low[u] = Num[u] = ++Time;
    st.push(u);
    for (int v : ed[u]){
        if (Num[v] != 0)
            Low[u] = min(Low[u], Num[v]);
        else {
            tarjan(v);
            Low[u] = min(Low[u], Low[v]);
        }
    }
    if (Num[u] == Low[u]) {  // found one
        Count++;
        int v;
        do {
            v = st.top();
            st.pop();
            Num[v] = Low[v] = ooii;  // remove v from graph
        } while (v != u);
    }
}