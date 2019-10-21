 /* algo2-1.c ʵ���㷨2.1�ĳ��� */
 #include"c1.h"
 typedef int ElemType;
 #include"c2-1.h" /* �������Ա��Ķ�̬����˳��洢�ṹ */
 #include"bo2-1.c" /* ����ʹ��bo2-1.c�еĻ������� */

 Status equal(ElemType c1,ElemType c2)
 { /* �ж��Ƿ���ȵĺ�����Union()�õ� */
   if(c1==c2)
     return TRUE;
   else
     return FALSE;
 }

 void Union(SqList *La,SqList Lb) /* �㷨2.1 */
 { /* �����������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La�� */
   ElemType e;
   int La_len,Lb_len;
   int i;
   La_len=ListLength(*La); /* �����Ա��ĳ��� */
   Lb_len=ListLength(Lb);
   for(i=1;i<=Lb_len;i++)
   {
     GetElem(Lb,i,&e); /* ȡLb�е�i������Ԫ�ظ���e */
     if(!LocateElem(*La,e,equal)) /* La�в����ں�e��ͬ��Ԫ��,�����֮ */
       ListInsert(La,++La_len,e);
   }
 }

 void print(ElemType *c)
 {
   printf("%d ",*c);
 }

 void main()
 {
   SqList La,Lb;
   Status i;
   int j;
   i=InitList(&La);
   if(i==1) /* �����ձ�La�ɹ� */
     for(j=1;j<=5;j++) /* �ڱ�La�в���5��Ԫ�� */
       i=ListInsert(&La,j,j);
   printf("La= "); /* �����La������ */
   ListTraverse(La,print);
   InitList(&Lb); /* Ҳ�ɲ��ж��Ƿ񴴽��ɹ� */
   for(j=1;j<=5;j++) /* �ڱ�Lb�в���5��Ԫ�� */
     i=ListInsert(&Lb,j,2*j);
   printf("Lb= "); /* �����Lb������ */
   ListTraverse(Lb,print);
   Union(&La,Lb);
   printf("new La= "); /* ����±�La������ */
   ListTraverse(La,print);
 }