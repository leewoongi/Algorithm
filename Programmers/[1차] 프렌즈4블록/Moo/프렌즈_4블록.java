
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
class Solution {
    static char map[][];
    static boolean visit[][];

    public int solution(int m, int n, String[] board) {
        int answer = 0;

        // 2차원 배열로 board 값 받기
        map = new char[32][32];
        visit = new boolean[32][32];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = board[i].charAt(j);
            }
        }

        while(true) {

            boolean flag = false;
            // 완전탐색 같은게 있는지 검사
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n - 1; j++) {
                    if(map[i][j] != ' ') {
                        if (map[i][j] == map[i][j + 1] && map[i][j] == map[i + 1][j] && map[i][j] == map[i + 1][j + 1]) {

                            visit[i][j] = true;
                            visit[i][j + 1] = true;
                            visit[i + 1][j] = true;
                            visit[i + 1][j + 1] = true;
                            flag = true;
                        }

                    }
                }
            }

            if(flag == false) {
                break;
            }
            // 같은 그림을 없애기
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (visit[i][j] == true) {
                        map[i][j] = ' ';
                    }
                }
            }

            // 완전 탐색 없어진 그림위치로 자리 매꾸기
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (map[i][j] == ' ') {
                        // 위로 탐색해서 빈칸하고 동물들이 어디까지 있는지
                        int count = 0;

                        for (int k = i; k >= 0; k--) {
                            if (map[k][j] == ' ') {
                                count++;
                                continue;
                            } else if (map[k][j] != ' ') {
                                char save = map[k][j];
                                map[k + count][j] = save;
                                map[k][j] = ' ';
                                break;

                            }
                        }

                    }
                }

            }
            for(int i = 0; i<m; i++) {
                for(int j = 0; j<n; j++) {
                    visit[i][j] = false;
                }
            }           
        }
        for(int i =0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(map[i][j] == ' ') {
                    answer++;
                }
            }
        }

        return answer;
    }
}