#include <bits/stdc++.h>
using namespace std;

const int maxN = 21;  // N은 최대 20이므로 N*N 최대 20*20 + 1 = 401
int N, num;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

struct Student {
    int id;
    bool nearStudentArr[401];  // 학생 ID 범위는 1 ~ N*N
};

struct Point {
    int y, x, zeroCnt, nearCnt;
};

bool cmp(Point a, Point b) {
    if (a.nearCnt == b.nearCnt) {
        if (a.zeroCnt == b.zeroCnt) {
            if (a.y == b.y) {
                return a.x < b.x;
            }
            return a.y < b.y;
        }
        return a.zeroCnt > b.zeroCnt;
    }
    return a.nearCnt > b.nearCnt;
}

vector<Student> studentVec;
int resultArr[maxN][maxN];

void getPoint(int id, bool nearStudentArr[401]) {
    vector<Point> possibleVec;
    
    int maxCnt = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (resultArr[y][x] != 0) continue;  // 이미 학생이 배정된 칸은 패스

            int nearCnt = 0;
            int zeroCnt = 0;
            for (int k = 0; k < 4; k++) {
                int ny = y + dy[k];
                int nx = x + dx[k];

                if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                int check = resultArr[ny][nx];
                if (check == 0) {
                    zeroCnt++;  // 인접한 빈 자리 개수
                }
                else if (nearStudentArr[check]) {
                    nearCnt++;  // 인접한 선호 학생 수
                }
            }
            Point p = {y, x, zeroCnt, nearCnt};
            possibleVec.push_back(p);
        }
    }

    sort(possibleVec.begin(), possibleVec.end(), cmp);  // 정렬
    Point p = possibleVec[0];  // 최적의 자리를 선택
    resultArr[p.y][p.x] = id;  // 선택된 자리에 학생 배정
}

int getWeight(int id, bool nearStudentArr[401]) {
    int curY, curX;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (resultArr[y][x] == id) {
                curY = y;
                curX = x;
                break;
            }
        }
    }

    int weightCnt = 0;
    
    for (int k = 0; k < 4; k++) {
        int ny = curY + dy[k];
        int nx = curX + dx[k];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        if (resultArr[ny][nx] != 0 && nearStudentArr[resultArr[ny][nx]]) {
            weightCnt++;
        }
    }

    if (weightCnt == 0) return 0;  // 만족도 계산: 0명일 때 0점
    return pow(10, weightCnt - 1);  // 1명: 1점, 2명: 10점, 3명: 100점, 4명: 1000점
}

int main() {
    cin >> N;
    for (int i = 0; i < N * N; i++) {
        cin >> num;
        Student student;
        student.id = num;
        memset(student.nearStudentArr, false, sizeof(student.nearStudentArr));
        for (int k = 0; k < 4; k++) {
            cin >> num;
            student.nearStudentArr[num] = true;  // 선호하는 학생들 설정
        }
        studentVec.push_back(student);
    }

    for (Student student : studentVec) {
        getPoint(student.id, student.nearStudentArr);  // 자리 배정
    }

    int rnt = 0;
    for (Student student : studentVec) {
        rnt += getWeight(student.id, student.nearStudentArr);  // 만족도 계산
    }

    cout << rnt;  // 최종 만족도 출력

    return 0;
}