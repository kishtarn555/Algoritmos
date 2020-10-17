
void tarjan(int cur, int prev, vector<vector<int> > &_scc,vector<int> * _adj, stack<int> & _st) {
    lo[cur]=hi[cur]=dt++;
    _st.push(cur);
    vis[cur]=true;
    inStack[cur]=true;
    for (int ni:_adj[cur]) {
        if (vis[ni]) {
            if (inStack[ni])
                hi[cur]=min(hi[cur], lo[ni]);
        } else {
            tarjan(ni, cur,_scc,_adj);
            hi[cur]=min(hi[cur], hi[ni]);
        }
    }
    if (lo[cur]==hi[cur]) {
    vector<int> next_cc;
        while (st.empty()==false && st.top()!=cur) {
            next_cc.push_back(st.top());
            inStack[st.top()]=false;
            st.pop();
        }
        inStack[cur]=false;
        st.pop();
        next_cc.push_back(cur);
        _scc.push_back(next_cc);
    }
}
