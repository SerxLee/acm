void Tarjan(int u){  
    stack[Top++]= u;  
    instack[u]= 1;  
    low[u]= dfn[u]= ++Index;  
    for(int i=0; i<g[u].size(); ++i){  
        int v= g[u][i];  
        if( !dfn[v] ){  
            Tarjan(v);  
            low[u]= min( low[v], low[u] );  
        }  
        else if( instack[v] )  
            low[u]= min( low[u], dfn[v] );  
    }  
    if( low[u]==dfn[u] ){  
        ++Bcnt;  
        int v;  
        do{  
            v= stack[--Top];  
            instack[v]= 0;  
            belong[v]= Bcnt;  
        }while( u!=v );  
    }  
}  