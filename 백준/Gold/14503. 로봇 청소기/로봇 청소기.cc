#include <iostream>

using namespace std;

const int direction[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int N, M, xy[2], direc;
int **Area, circleCount = 0, cleanArea = 0;
bool STOP = false;

void circle (void) {
	if (direc)
		direc--;
	else
		direc = 3;
}

void clean (void) {
	Area[xy[0]][xy[1]] = -1; cleanArea++;
}

void move (int to, int go) { // forward : go = 1, backward : go = -1
    xy[0]+=go*direction[to][0]; xy[1]+=go*direction[to][1];
}

bool Lsearch(void) {
    int left_direc = (direc) ? direc-1 : 3; 
	if (!Area[xy[0]+direction[left_direc][0]][xy[1]+direction[left_direc][1]]) {
		circle();
		move(direc, 1);
		return true;
	}
	circle();
	circleCount++;
	return false;
}

bool backWall (void) {
	if (Area[xy[0]-direction[direc][0]][xy[1]-direction[direc][1]] == 1)
		return true;
	return false;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> N >> M >> xy[0] >> xy[1] >> direc;
    Area = new int*[N];
    for (int i = 0; i < N; i++) {
	    Area[i] = new int[M];
    }
	for (int i = 0; i < N; i++) {
	    for (int j = 0; j < M; j++) {
		    cin >> Area[i][j];
	    }
	}
	
	while (!STOP) {
        clean(); // Function 1
             
        circleCount = 0;
        while(!Lsearch()){ // Function 2 (a, b, c, d)
	        if (circleCount >= 4) {
                circleCount = 0;
		        if (backWall()) {
 			        STOP = true;
			        break;
		        }

		        else {
			        move(direc, -1);
		        }
            }
            
        }
	}
	
	cout << cleanArea << endl;
    for (int i = 0; i < N; i++)
        delete [] Area[i];
    delete [] Area;
        
    return 0;
}