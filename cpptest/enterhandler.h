#ifndef ENTERHANDLER_H
#define ENTERHANDLER_H

class EnterHandler
{
public:
    EnterHandler();
    void moveAway(int x, int y, int _btnX, int _btnY, int _btnWidth, int _btnHeight,
                  int _widgetX, int _widgetY, int _widgetWidth, int _widgetHeight, int *res);

private:
    enum direction { STAY, LEFT, RIGHT, UP, DOWN, BOTTOMLEFT, BOTTOMRIGHT, TOPLEFT, TOPRIGHT};
    int trickyOffset;
    int btnX;
    int btnY;
    int btnWidth;
    int btnHeight;
    int widgetX;
    int widgetY;
    int widgetWidth;
    int widgetHeight;

    void topRight(int btnY, direction* finalDir, int btnX);
    void bottomRight(int btnY, direction* finalDir, int btnX);
    void bottomLeft(direction* finalDir, int btnX, int btnY);
    void topLeft(int btnX, int btnY, direction* finalDir);

    void chooseDestination(direction xDir, direction yDir, int btnX, int btnY, direction *finalDir);
    void chooseDirSimple(int rx, int ry, int btnX, int btnY, direction *resDirect);
    void moveToDir(int btnX, int btnY, direction finalDir, int *res);

    void moveOrtho(direction* finalDir, direction xDir, direction yDir);
    void moveDiag(direction* finalDir, direction yDir, direction xDir);
    void moveCorner(int btnX, direction xDir, int btnY, direction* finalDir, direction yDir);

    void testXaxis(direction *xDir, int rx, int btnX);
    void testYaxis(int ry, direction *yDir, int btnY);
};

#endif // ENTERHANDLER_H
