#include <stdio.h>

// 定义状态枚举
typedef enum {
    STATE_START,
    STATE_A,
    STATE_AB,
    STATE_ABC,
    STATE_ABCD,
    STATE_ERROR
} State;

// 状态转换函数
State nextState(State currentState, char input) {
    switch (currentState) {
        case STATE_START:
            if (input == 'A') return STATE_A;
            else return STATE_ERROR;
        case STATE_A:
            if (input == 'B') return STATE_AB;
            else return STATE_ERROR;
        case STATE_AB:
            if (input == 'C') return STATE_ABC;
            else return STATE_ERROR;
        case STATE_ABC:
            if (input == 'D') return STATE_ABCD;
            else return STATE_ERROR;
        case STATE_ABCD:
            // 一旦匹配完成，可以选择重置或停留在当前状态
            if (input == 'A') return STATE_A;
            else return STATE_ABCD;
        case STATE_ERROR:
            // 错误状态下，可以选择重置或保持错误状态
            if (input == 'A') return STATE_A;
            else return STATE_ERROR;
        default:
            return STATE_ERROR;
    }
}

int main() {
    State currentState = STATE_START;
    const char *inputString = "XABCDABCD";  // 测试输入字符串

    // 处理输入字符串的每个字符
    for (int i = 0; inputString[i] != '\0'; ++i) {
        currentState = nextState(currentState, inputString[i]);
        printf("当前状态: %d\n", currentState);
    }

    // 检查是否成功匹配了模式
    if (currentState == STATE_ABCD) {
        printf("找到模式 'ABCD'.\n");
    } else {
        printf("未找到模式.\n");
    }

    return 0;
}