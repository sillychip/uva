#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > graph;
bool result[100][100];
bool visited[100];
int print_plus(int n){
    cout<<"+";
    for(int i=1;i< 2*n;i++)cout<<"-";
    cout<<"+"<<endl;
    return 0;
}
int print_result(int n){
    print_plus(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(result[i][j])cout<<"|Y";
            else cout<<"|N";
        }
        cout<<"|"<<endl;
        print_plus(n);
    }
    return 0;

}
int dfs1(int source){
    stack<int> stck;
    int top;
    stck.push(source);
    if(result[0][source])result[source][source]=true;
    while(!stck.empty()){
        top=stck.top();
        stck.pop();
        if(visited[top] || !result[0][source])continue;
        visited[top]=true;
        for(int i=0;i<graph[top].size();i++){
            if(!visited[graph[top][i]]){
                stck.push(graph[top][i]);
                result[source][graph[top][i]]=true;
            }

        }

    }
    return 0;
}
int dfs2(int source){
    stack<int> stck;
    int top;
    stck.push(0);
    result[source][0]=false;
    while(!stck.empty()){
        top=stck.top();
        stck.pop();
        if(visited[top])continue;
        visited[top]=true;
        for(int i=0;i<graph[top].size();i++){
            if(graph[top][i]==source)continue;
            if(!visited[graph[top][i]]){
                stck.push(graph[top][i]);
                result[source][graph[top][i]]=false;
            }
        }
    }
    return 0;
}
int get_result(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)result[i][j]=false;
    }
    result[0][0]=true;
    for(int i=0;i<n;i++){
        memset(visited,0,sizeof visited);
        dfs1(i);
    }
    for(int i=1;i<n;i++){
        memset(visited,0,sizeof visited);
        dfs2(i);
    }
    return 0;
}


int main(){
    freopen("C:\\Users\\Sabera Sultana\\ClionProjects\\TestProject\\in.txt","r",stdin);
    freopen("C:\\Users\\Sabera Sultana\\ClionProjects\\TestProject\\out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc,n,dummy;
    cin>>tc;
    for(int cas=0;cas<tc;){
        cin>>n;
        graph.assign(n,vector<int>());
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>dummy;
                if(dummy)graph[i].push_back(j);
            }
        }
        get_result(n);
        cout<<"Case "<<++cas<<":"<<endl;
        print_result(n);
    }
    return 0;
}