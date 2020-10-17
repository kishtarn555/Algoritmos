
void tarjan(int cur, int prev, vector<vector<int> > &_scc,vector<int> * _adj, stack<int> & _st, int *lo, int *hi, int &dt) {
    lo[cur]=hi[cur]=dt++;
    _st.push(cur);
    vis[cur]=true;
    inStack[cur]=true;
    for (int ni:_adj[cur]) {
        if (vis[ni]) {
            if (inStack[ni])
                hi[cur]=min(hi[cur], lo[ni]);
        } else {
            tarjan(ni, cur,_scc,_adj,st,lo,hi,dt);
            hi[cur]=min(hi[cur], hi[ni]);
        }
    }
    if (lo[cur]==hi[cur]) {
    vector<int> next_cc;
        while (st.empty()==false && _st.top()!=cur) {
            next_cc.push_back(_st.top());
            inStack[st.top()]=false;
            _st.pop();
        }
        inStack[cur]=false;
        _st.pop();
        next_cc.push_back(cur);
        _scc.push_back(next_cc);
    }
}
