class Solution {
    double circlex(int r, int cx , int cy , int y){
        return sqrt((double)(r*r-pow(y-cy,2))) + cx;
    }
    double circley(int r, int cx , int cy , int x){
        return sqrt((double)(r*r-pow(x-cx,2))) + cy;
    }
    int point(int cx ,int cy , int x , int y){
        return pow(x-cx,2) + pow(y-cy,2);
    }
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int r=radius;
        double lx1y=circley(r,xCenter,yCenter,x1);
        if(lx1y>=y1 && lx1y<=y2) return true;
        double ly1x=circlex(r,xCenter,yCenter,y1);
        if(ly1x>=x1 && ly1x<=x2) return true;
        double lx2y=circley(r,xCenter,yCenter,x2);
        if(lx2y>=y1 && lx2y<=y2) return true;
        double ly2x=circlex(r,xCenter,yCenter,y2);
        if(ly2x>=x1 && ly2x<=x2) return true;
        if(xCenter>=x1 && yCenter>=y1 && xCenter<=x2 && yCenter<=y2) return true;
        if(point(xCenter,yCenter,x1,y1)<=radius*radius) return true;
        if(point(xCenter,yCenter,x1,y2)<=radius*radius) return true;
        if(point(xCenter,yCenter,x2,y1)<=radius*radius) return true;
        if(point(xCenter,yCenter,x2,y2)<=radius*radius) return true;
        return false;
    }
};