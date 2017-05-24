#ifndef MOVEWIDGET_H
#define MOVEWIDGET_H


class MoveWidget
{
public:
    MoveWidget();
    MoveWidget(int _btnWidth, int _btnHeight, int _trickyOffset);
    virtual void move(int btnX, int btnY, int *res) = 0;
protected:
    int btnX;
    int btnY;
    int btnWidth;
    int btnHeight;
    int trickyOffset;
};

class MoveLeft: public MoveWidget
{
public:
    MoveLeft(int _btnWidth, int _btnHeight, int _trickyOffset);
    void move(int btnX, int btnY, int *res);
};

class MoveRight: public MoveWidget
{
public:
    MoveRight(int _btnWidth, int _btnHeight, int _trickyOffset);
    void move(int btnX, int btnY, int *res);
};

class MoveUp: public MoveWidget
{
public:
    MoveUp(int _btnWidth, int _btnHeight, int _trickyOffset);
    void move(int btnX, int btnY, int *res);
};

class MoveDown: public MoveWidget
{
public:
    MoveDown(int _btnWidth, int _btnHeight, int _trickyOffset);
    void move(int btnX, int btnY, int *res);
};

class MoveTopRight: public MoveWidget
{
public:
    MoveTopRight(int _btnWidth, int _btnHeight, int _trickyOffset);
    void move(int btnX, int btnY, int *res);
};

class MoveTopLeft: public MoveWidget
{
public:
    MoveTopLeft(int _btnWidth, int _btnHeight, int _trickyOffset);
    void move(int btnX, int btnY, int *res);
};

class MoveBottomRight: public MoveWidget
{
public:
    MoveBottomRight(int _btnWidth, int _btnHeight, int _trickyOffset);
    void move(int btnX, int btnY, int *res);
};

class MoveBottomLeft: public MoveWidget
{
public:
    MoveBottomLeft(int _btnWidth, int _btnHeight, int _trickyOffset);
    void move(int btnX, int btnY, int *res);
};

class MoveNull: public MoveWidget
{
public:
    MoveNull(int _btnWidth, int _btnHeight, int _trickyOffset);
    void move(int btnX, int btnY, int *res);
};

#endif // MOVEWIDGET_H
