 /* c9-6.h ���Ŷ�ַ��ϣ���Ĵ洢�ṹ */
 int hashsize[]={11,19,29,37}; /* ��ϣ��������������һ�����ʵ��������� */
 int m=0; /* ��ϣ��������ȫ�ֱ��� */
 typedef struct
 {
   ElemType *elem; /* ����Ԫ�ش洢��ַ����̬�������� */
   int count; /* ��ǰ����Ԫ�ظ��� */
   int sizeindex; /* hashsize[sizeindex]Ϊ��ǰ���� */
 }HashTable;

 #define SUCCESS 1
 #define UNSUCCESS 0
 #define DUPLICATE -1