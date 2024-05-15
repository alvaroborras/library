// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_A

#include "../../template/template.hpp"

#include "../../graph/connected-components/articulation_points.cpp"

int main() {
  int n, m;
  cin >> n >> m;
  Graph<int> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g.add_edge(u, v);
  }
  ArticulationPoints ap(g);
  std::vector<size_t> articulationPoints = ap.getArticulationPoints();
  std::sort(articulationPoints.begin(), articulationPoints.end());
  for (size_t i = 0; i < articulationPoints.size(); ++i) {
    cout << articulationPoints[i] << "\n";
  }
  cout << "\n";
}
