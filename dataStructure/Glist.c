#include "Common.h"
typedef enum {atom,list} NodeTag; // atom��ʾԭ�ӣ�list��ʾ�ӱ�
typedef struct GLNode {
    NodeTag tag;
    union
    {
        DataType data;
        struct GLNode* slink;
    };
    struct GLNode* link;
}GLNode;
typedef GLNode* Glist;

Glist createGlist(Glist GL) {
    char ch; scanf_s("%c", &ch);
    if (ch != ' ')
    {
        GL = (GLNode *)malloc(sizeof(GLNode));
    }
}
