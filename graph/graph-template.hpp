#pragma once

/**
 * @brief Graph Template
 */
template <typename T = int>
struct Edge {
  int from, to;
  T cost;
  int idx;

  Edge() = default;

  Edge(int u, int v, T c = 1, int i = -1) : from(u), to(v), cost(c), idx(i) {}

  operator int() const { return to; }
};

template <typename T = int>
struct Graph {
  vector<vector<Edge<T>>> g;
  int es;

  Graph() = default;

  explicit Graph(int n) : g(n), es(0) {}

  size_t size() const { return g.size(); }

  void add_directed_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es++); }

  void add_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es);
    g[to].emplace_back(to, from, cost, es++);
  }

  void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
    for (int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      a += padding;
      b += padding;
      T c = T(1);
      if (weighted) cin >> c;
      if (directed)
        add_directed_edge(a, b, c);
      else
        add_edge(a, b, c);
    }
  }

  inline vector<Edge<T>>& operator[](const int& k) { return g[k]; }

  inline const vector<Edge<T>>& operator[](const int& k) const { return g[k]; }
};

template <typename T = int>
using Edges = vector<Edge<T>>;
