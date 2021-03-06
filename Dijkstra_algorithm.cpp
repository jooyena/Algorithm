#include <iostream>
#include <vector>

#define INF 987654321

using namespace std;

int V, E, K; // 정점의 수, 간선의 수, 시작 정점 번호

vector<vector<int>> graph; // 간선 가중치. 그래프의 인접 리스트.

vector<int> dijkstra()
{
    vector<int> s,d; // 방문 여부, 최단 경로

    s.assign(V,false);
    d.assign(V,INF);
    d[K-1] = 0; //자기 자신까지 가는 거리는 0

    while(true)
    {
        int m = INF, N=-1;

        //최소 N번째 노드를 찾는다.
        for(int j=0;j<V; j++)
        {
            if(!s[j] && (m>d[j]))
            {
                m = d[j];
                N = j;
            }
        }

        // m이 INF라는 얘기는 방문하지 않은 노드들의 d값이 전부 INF라는 뜻입니다.
        if(m == INF)
            break;

        s[N] = true; // N번째 노드를 방문.

        //d를 탐색하며 N번째 노드를 통해서 가는 길이 더 짧은 길이면 d를 더 짧은 길로 업데이트 한다.
        for(int j=0;j<V;j++)
        {
            //j번째 노드가 이미 방문되었다면 d[j]는 이미 결정된 최소값이므로 변경하면 안된다.
            if(s[j]) continue;

            //N번째 노드와 인접 노드들을 돌며, N을 통해서 가는 거리를 via에 저장한다.
            unsigned int via = d[N] + graph[N][j];

            //N을 통해서 가는 거리가 더 짧으면, 그 인접 노드의 d[j](d까지 가는 거리의 최소거리)를 N을 통해서 가는 거리로 바꿔준다.
            if(d[j] > via)
                d[j] = via;
        }
    }
    return d;
}
int main()
{
    cin>>V>>E;
    cin>>K;

    graph.assign(V, vector<int>(V,INF));

    while(E--)
    {
        int u,v,w;

        cin>>u>>v>>w;

        // 가중치 초기화
        graph[u-1][v-1] = w;
        //graph[v-1][u-1] = w; //무방향성 그래프일 경우 다음 코드를 추가한다.
    }

    vector<int> d = dijkstra();

    for(int i=0;i<d.size();i++)
    {
        if(d[i] == INF)
            cout<<"INF"<<endl;
        else
            cout<<d[i]<<endl;
    }

    return 0;
}
