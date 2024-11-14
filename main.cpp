#include <stdio.h>

// ����״̬ö��
typedef enum {
    STATE_START,
    STATE_A,
    STATE_AB,
    STATE_ABC,
    STATE_ABCD,
    STATE_ERROR
} State;

// ״̬ת������
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
            // һ��ƥ����ɣ�����ѡ�����û�ͣ���ڵ�ǰ״̬
            if (input == 'A') return STATE_A;
            else return STATE_ABCD;
        case STATE_ERROR:
            // ����״̬�£�����ѡ�����û򱣳ִ���״̬
            if (input == 'A') return STATE_A;
            else return STATE_ERROR;
        default:
            return STATE_ERROR;
    }
}

int main() {
    State currentState = STATE_START;
    const char *inputString = "XABCDABCD";  // ���������ַ���

    // ���������ַ�����ÿ���ַ�
    for (int i = 0; inputString[i] != '\0'; ++i) {
        currentState = nextState(currentState, inputString[i]);
        printf("��ǰ״̬: %d\n", currentState);
    }

    // ����Ƿ�ɹ�ƥ����ģʽ
    if (currentState == STATE_ABCD) {
        printf("�ҵ�ģʽ 'ABCD'.\n");
    } else {
        printf("δ�ҵ�ģʽ.\n");
    }

    return 0;
}