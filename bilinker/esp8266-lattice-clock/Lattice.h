#ifndef LATTICE_H
#define LATTICE_H

#include <LedControl.h>
#include "EEPROMTool.h"

const uint8_t rowLength = 8;
const uint8_t columnLength = 4;

const int DIN = D7;
const int CS = D6;
const int CLK = D5;

const unsigned char number_font_small[11][rowLength] = {
    {0x0, 0xE0, 0xA0, 0xA0, 0xA0, 0xE0, 0x0, 0x0}, // 0
    {0x0, 0x40, 0xC0, 0x40, 0x40, 0xE0, 0x0, 0x0}, // 1
    {0x0, 0xE0, 0x20, 0xE0, 0x80, 0xE0, 0x0, 0x0}, // 2
    {0x0, 0xE0, 0x20, 0xE0, 0x20, 0xE0, 0x0, 0x0}, // 3
    {0x0, 0xA0, 0xA0, 0xE0, 0x20, 0x20, 0x0, 0x0}, // 4
    {0x0, 0xE0, 0x80, 0xE0, 0x20, 0xE0, 0x0, 0x0}, // 5
    {0x0, 0xE0, 0x80, 0xE0, 0xA0, 0xE0, 0x0, 0x0}, // 6
    {0x0, 0xE0, 0x20, 0x20, 0x20, 0x20, 0x0, 0x0}, // 7
    {0x0, 0xE0, 0xA0, 0xE0, 0xA0, 0xE0, 0x0, 0x0}, // 8
    {0x0, 0xE0, 0xA0, 0xE0, 0x20, 0xE0, 0x0, 0x0}, // 9
    {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}       // null
};

const unsigned char number_font_middle[10][rowLength] = {
    {0x0, 0xF0, 0x90, 0x90, 0x90, 0x90, 0x90, 0xF0}, // 0
    {0x0, 0x40, 0xc0, 0x40, 0x40, 0x40, 0x40, 0xe0}, // 1
    {0x0, 0xf0, 0x10, 0x10, 0xf0, 0x80, 0x80, 0xf0}, // 2
    {0x0, 0xf0, 0x10, 0x10, 0xf0, 0x10, 0x10, 0xf0}, // 3
    {0x0, 0x90, 0x90, 0x90, 0xf0, 0x10, 0x10, 0x10}, // 4
    {0x0, 0xf0, 0x80, 0x80, 0xf0, 0x10, 0x10, 0xf0}, // 5
    {0x0, 0xf0, 0x80, 0x80, 0xf0, 0x90, 0x90, 0xf0}, // 6
    {0x0, 0xf0, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10}, // 7
    {0x0, 0xf0, 0x90, 0x90, 0xf0, 0x90, 0x90, 0xf0}, // 8
    {0x0, 0xf0, 0x90, 0x90, 0xf0, 0x10, 0x10, 0xf0}  // 9
};

const unsigned char number_font_animations[10][16] = {
    {0x40, 0x30, 0x20, 0x10, 0x11, 0x12, 0x22, 0x32, 0x42, 0x52, 0x51, 0x50,
     0x0, 0x0, 0x0, 0x0},
    {0x20, 0x11, 0x21, 0x31, 0x41, 0x50, 0x51, 0x52, 0x0, 0x0, 0x0, 0x0, 0x0,
     0x0, 0x0, 0x0},
    {0x10, 0x11, 0x12, 0x22, 0x32, 0x31, 0x30, 0x40, 0x50, 0x51, 0x52, 0x0, 0x0,
     0x0, 0x0, 0x0},
    {0x10, 0x11, 0x12, 0x22, 0x32, 0x31, 0x30, 0x42, 0x50, 0x51, 0x52, 0x0, 0x0,
     0x0, 0x0, 0x0},
    {0x10, 0x20, 0x30, 0x31, 0x12, 0x22, 0x32, 0x42, 0x52, 0x0, 0x0, 0x0, 0x0,
     0x0, 0x0, 0x0},
    {0x12, 0x11, 0x10, 0x20, 0x30, 0x31, 0x32, 0x42, 0x52, 0x51, 0x50, 0x0, 0x0,
     0x0, 0x0, 0x0},
    {0x12, 0x11, 0x10, 0x20, 0x30, 0x40, 0x50, 0x51, 0x52, 0x42, 0x32, 0x31,
     0x0, 0x0, 0x0, 0x0},
    {0x10, 0x11, 0x12, 0x22, 0x32, 0x42, 0x52, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
     0x0, 0x0, 0x0},
    {0x31, 0x30, 0x20, 0x10, 0x11, 0x12, 0x22, 0x32, 0x42, 0x52, 0x51, 0x50,
     0x40, 0x0, 0x0, 0x0},
    {0x31, 0x30, 0x20, 0x10, 0x11, 0x12, 0x22, 0x32, 0x42, 0x52, 0x51, 0x50,
     0x0, 0x0, 0x0, 0x0}};

/**
 * WiFi连接图标
 */
const unsigned char wifiicon[columnLength][rowLength] = {
    {0x0, 0xba, 0x20, 0xba, 0xa2, 0xa2, 0x0, 0x0},
    {0x0, 0x22, 0x22, 0x2a, 0x2e, 0x14, 0x0, 0x0},
    {0x0, 0x48, 0x68, 0x79, 0x58, 0x48, 0x0, 0x0},
    {0x0, 0x37, 0x45, 0x45, 0x45, 0x37, 0x0, 0x0}};

/**
 * 没有wifi的图标
 */
const unsigned char nowifiicon[columnLength][rowLength] = {
    {0x0, 0x74, 0x40, 0x74, 0x44, 0x44, 0x0, 0x0},
    {0x0, 0x45, 0x44, 0x55, 0x55, 0x29, 0x0, 0x0},
    {0x0, 0xc0, 0x40, 0x4e, 0x40, 0xc0, 0x0, 0x0},
    {0x0, 0x25, 0x35, 0x3d, 0x2d, 0x25, 0x0, 0x0}};

/**
 * 更新数据字符
 */
const unsigned char updateClock[columnLength][rowLength] = {
    {0x0, 0x0, 0x0, 0xa8, 0x0, 0x0, 0x0, 0x0},
    {0x0, 0xd4, 0x18, 0x10, 0x18, 0xd4, 0x0, 0x0},
    {0x0, 0x1d, 0x15, 0x15, 0x15, 0xdd, 0x0, 0x0},
    {0x0, 0x1d, 0x11, 0x11, 0x11, 0x1d, 0x0, 0x0}};

/**
 * ota 更新图标
 */
const unsigned char otaicon[columnLength][rowLength] = {
    {0x0, 0x24, 0x8, 0x10, 0x20, 0x48, 0x0, 0x0},
    {0x0, 0xee, 0xaa, 0xaa, 0xaa, 0xee, 0x0, 0x0},
    {0x0, 0x90, 0x2a, 0x28, 0x3a, 0x28, 0x0, 0x0},
    {0x0, 0x3b, 0x29, 0x29, 0x29, 0x39, 0x0, 0x0}};

/**
 * 更新完成
 */
const unsigned char otaokicon[columnLength][rowLength] = {
    {0x0, 0x80, 0x0, 0x2a, 0x0, 0x80, 0x0, 0x0},
    {0x0, 0x3a, 0x2b, 0x2a, 0x2b, 0x3a, 0x0, 0x0},
    {0x0, 0x90, 0x29, 0x28, 0x39, 0x28, 0x0, 0x0},
    {0x0, 0x3b, 0x29, 0x29, 0x29, 0x39, 0x0, 0x0}};

/**
 * 更新失败
 */
const unsigned char otafailicon[columnLength][rowLength] = {
    {0x0, 0x28, 0x88, 0xa8, 0xa8, 0xae, 0x0, 0x0},
    {0x0, 0x39, 0x22, 0x3b, 0x22, 0x22, 0x0, 0x0},
    {0x0, 0x90, 0x29, 0x28, 0x39, 0x28, 0x0, 0x0},
    {0x0, 0x3b, 0x29, 0x29, 0x29, 0x39, 0x0, 0x0}};

/**
 * 没有设置任何数据
 */
const unsigned char noseticon[32] = {
    0x0, 0xbe, 0x8, 0x8, 0x88, 0x8, 0x8, 0x88, 0x0, 0xef, 0x8,
    0x8, 0xef, 0x28, 0x28, 0xef, 0x0, 0xe3, 0x22, 0x22, 0x23, 0x20,
    0x20, 0xe3, 0x0, 0x45, 0x45, 0x65, 0x75, 0x5d, 0x4d, 0x45};

/**
 * 图标集合
 */
const unsigned char icons[4][rowLength] = {
    {0x3C, 0x42, 0x85, 0x89, 0x81, 0x81, 0x42, 0x3C}, // 时钟图标
    {0x0, 0xCE, 0xD1, 0x10, 0x10, 0x11, 0xE, 0x0},    // 温度图标
    {0x42, 0x24, 0xFF, 0x81, 0xA5, 0x99, 0xFF, 0x42}, // Bilibili图标
    {0x3C, 0x42, 0x81, 0xA5, 0x81, 0x99, 0x42, 0x3C}  // 微笑
};

struct LatticeSetting
{
    /**
     * 点阵屏幕是否显示
     */
    bool isShutdown = false;

    /**
     * 屏幕亮度
     */
    uint8_t brightness = 0x0;

    /**
     * 显示方向, true: 正方向，false: 反方向
     */
    bool direction = false;

    /**
     * 用户自定义数据
     */
    uint8_t userData[32];

    /**
     * 速度
     */
    uint8_t speed = 1;
};

class Lattice
{
private:
    /**
     * lc对象
     */
    LedControl lc = LedControl(DIN, CLK, CS, columnLength);

    /**
     * 点阵显示屏个数
     */
    int latticeNums;

    int tempindex = 3;

    /**
     * 是否重置
     */
    bool isReset = true;

    /**
     * 实际显示的数组
     */
    unsigned char data[4][rowLength];

    /**
     * 缓冲数组
     */
    unsigned char buff[4][rowLength];
    /**
     * 初始化点阵
     */
    void initLattice();

    /**
     * 刷新显示
     */
    void refreshLed();

    /**
     * 显示数据内容
     */
    void showDataLed(const unsigned char (*arr)[rowLength]);

    /**
     * 获取需要显示数字的数据
     */
    unsigned char *getNumData(uint8_t nums, bool showzero);

    /**
     * 获取大号的数字
     */
    unsigned char *getBigNumData(uint8_t number, uint8_t offset);

    /**
     * 偏移缓存数组
     */
    void offsetBuff(uint8_t index, int8_t offset);

    /**
     * 偏移显示数组
     */
    void offsetData(uint8_t index, int8_t offset);

    /**
     * 左移显示内容
     */
    void rightMoveData(bool isright);

    /**
     * 左移显示缓冲数据
     */
    void rightMoveBuff();

    /**
     * 向下移动数据
     */
    void downMoveData(bool isdown);

    /**
     * 向下移动缓冲数据
     */
    void downMoveBuff();

    /**
     * 向下移动缓冲数据
     */
    void downMoveBuff(uint8_t *arr);

    /**
     * 测试功能
     */
    void progressBar(uint8_t offset);

    /**
     * 向上或者向下移动内容
     */
    void upOrDownMove(uint8_t index, uint8_t region, bool direction);

public:
    LatticeSetting latticeSetting;
    /**
     * 构造函数
     */
    Lattice();

    /**
     *  初始化
     */
    void init();

    /**
     * 重置
     */
    void reset();

    /**
     * 启用/停用点阵
     */
    void shutdown(bool down);

    /**
     * 设置显示亮度
     */
    void setBrightness(uint8_t bright,bool save);

    /**
     * 设置显示方向
     */
    void setDirection(bool direct);

    /**
     * 显示wifi图案
     */
    void showLongIcon(uint8_t index);

    /**
     * 显示数字
     */
    void showNum(uint8_t index, int nums);

    /**
     * 动态显示时间
     * 这里目前还没有好的解决方法, 所以就使用了一些简单粗暴的方式来做
     */
    void showTime(uint8_t *arr);

    /**
     * 显示时间模式2
     * 这里目前还没有好的解决方法, 所以就使用了一些简单粗暴的方式来做
     */
    void showTime2(uint8_t *arr);

    /**
     *显示时间模式2
     *这里目前还没有好的解决方法, 所以就使用了一些简单粗暴的方式来做
     */
    void showTime3(uint8_t *arr);

    /**
     * 显示倒计时
     */
    void showCountDownTime(long remain, uint8_t *arr, bool showmode, bool minutechange);

    /**
     * 显示长的数字
     * 这里目前还没有好的解决方法, 所以就使用了一些简单粗暴的方式来做
     */
    void showLongNumber(uint8_t *arr);

    /**
     * 显示数字和图标
     */
    void showNumAndIcon(uint8_t no, uint8_t *arr);

    /**
     * 显示日期2
     * 这里目前还没有好的解决方法, 所以就使用了一些简单粗暴的方式来做
     */
    void showDate2(uint8_t *arr);

    /**
     * 显示日期2
     * 这里目前还没有好的解决方法, 所以就使用了一些简单粗暴的方式来做
     */
    void showDate3(uint8_t *arr);

    /**
     * 显示温度
     */
    void showTemperature(uint8_t *arr);

    /**
     * 显示用户自定义数据
     */
    void showUserData(uint8_t mode);

    /**
     * 清空显示
     */
    void clearShow();

    /**
     * 全量显示
     */
    void showFull();

    /**
     * 左右翻转
     */
    void reversalLR(uint8_t index);

    /**
     * 上下翻转
     */
    void reversalUD(uint8_t index);

    /**
     * 闪
     */
    void lightning(uint8_t index);

    /**
     * OTA 更新
     */
    void showOtaUpdate(uint8_t num);
};

#endif
