#include <stdio.h>
#include <stdlib.h>
int current_x = 1, current_y = 1;
int found_x, found_y;//searchlight found the snake
int snake_x = 1, snake_y = 1, snake_way = 1;//1 is right direction
int p[105][105] = {};
int vis[105][105] = {};
int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1};// left right up down up-left up-right down-left down-right
int dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int n, m, s;
void teleport() {
	int teleport_x = 1, teleport_y = 1, mx = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(!vis[i][j] && p[i][j] < p[current_x][current_y] && p[i][j] >= mx) {
				mx = p[i][j];
				teleport_x = i, teleport_y = j;
			}
		}
	}
	current_x = teleport_x, current_y = teleport_y;
	s--;
}
void snake_move() {
	if(snake_y + dy[snake_way] > m || snake_y + dy[snake_way] < 1) snake_way = (snake_way + 1) % 2;
	snake_y += dy[snake_way];
}
int search(int x, int y, int way) {
	if(x == snake_x && y == snake_y) return 1;
	else if(x > n || y > m || x < 1 || y < 1) return 0;
	else return search(x + dx[way], y + dy[way], way);
}
int road_roller(int state) {
	vis[current_x][current_y] = 1;
	if(current_x == snake_x && current_y == snake_y) return 1;
	if(s == 0) return 0;
	if(state == -1) {//emits searchlights
		for(int i = 0; i < 8; ++i) {
			if(search(current_x, current_y, i)) {
				found_x = snake_x, found_y = snake_y;
				return road_roller(i);
			}
		}
		return road_roller(8);
	}
	else if(state == 8) {//teleport
		teleport();
		snake_move();
		return road_roller(-1);
	}
	else {//state = 0 ~ 7, move in direction[state]
		if(current_x == found_x && current_y == found_y) {
			return road_roller(-1);
		}
		else {
			snake_move();
			current_x += dx[state], current_y += dy[state];
			s--;
			return road_roller(state);
		}
	}
}
int main() {
	scanf("%d %d %d", &n, &m, &s);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%d", &p[i][j]);
			if(p[i][j] > p[current_x][current_y]) current_x = i, current_y = j;
			if(p[i][j] < p[snake_x][snake_y]) snake_x = i, snake_y = j;
		}
	}
	if(road_roller(-1)) printf("%d\nGotcha!\n", s);
	else printf("0\nNO Snake QQ~\n");
}
