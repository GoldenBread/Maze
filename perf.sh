#!/bin/bash
make re
make re -C generateur
echo =====================================
echo Génération labyrinthe parfait 200x200
echo =====================================
generateur/generateur 200 200 parfait > ./mazes/perf1.txt
echo =======================================
echo Génération labyrinthe imparfait 200x200
echo =======================================
generateur/generateur 200 200 > ./mazes/perf2.txt
echo ==============================================
echo Résolution du labyrinthe 200x200 parfait astar
echo ==============================================
time ./astar/solver ./mazes/perf1.txt > /tmp/tmp_outlaby_astar1
echo ================================================
echo Résolution du labyrinthe 200x200 imparfait astar
echo ================================================
time ./astar/solver ./mazes/perf2.txt > /tmp/tmp_outlaby_astar2
echo ==============================================
echo Résolution du labyrinthe 200x200 parfait DFS
echo ==============================================
time ./profondeur/solver ./mazes/perf1.txt > /tmp/tmp_outlaby_dfs1
echo ================================================
echo Résolution du labyrinthe 200x200 imparfait DFS
echo ================================================
time ./profondeur/solver ./mazes/perf2.txt > /tmp/tmp_outlaby_dfs2
echo ==============================================
echo Résolution du labyrinthe 200x200 parfait BFS
echo ==============================================
time ./largeur/solver ./mazes/perf1.txt > /tmp/tmp_outlaby_bfs1
echo ================================================
echo Résolution du labyrinthe 200x200 imparfait BFS
echo ================================================
time ./largeur/solver ./mazes/perf2.txt > /tmp/tmp_outlaby_bfs2
