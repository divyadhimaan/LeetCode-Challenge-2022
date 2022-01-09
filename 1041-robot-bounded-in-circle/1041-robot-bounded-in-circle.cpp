class Solution {
public:
    bool isRobotBounded(string instructions) {
         int x=0, y=0;
        int dir = 0; // 0 representing north, 1 representing east, 2 representing south, 3 representing west. A concept similar to the Spiral Matrix II problem.
        for (int i = 0; i < instructions.size(); ++i) {
            if (instructions[i]=='G') {
                if (dir==0) y++;
                if (dir==1) x++;
                if (dir==2) y--;
                if (dir==3) x--;
            }
            else if (instructions[i]=='L') {
                dir--;
                dir = (dir+4)%4; // So that direction is positive after taking mod
            }
            else {
                dir++;
                dir %= 4;
            }
        }
        return dir!=0 || (x==0 & y==0);
    }
};