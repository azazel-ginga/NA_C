 /* c10-2.h ��̬�������� */
 #define SIZE 100 /* ��̬�������� */
 typedef int KeyType; /* ����ؼ�������Ϊ���� */

 typedef struct
 {
   KeyType key; /* �ؼ����� */
   InfoType otherinfo; /* ������������������������ж��� */
 }RedType; /* ��¼���� */

 typedef struct
 {
   RedType rc; /* ��¼�� */
   int next; /* ָ���� */
 }SLNode; /* ��������� */

 typedef struct
 {
   SLNode r[SIZE]; /* 0�ŵ�ԪΪ��ͷ��� */
   int length; /* ������ǰ���� */
 }SLinkListType; /* ��̬�������� */