 /* bo2-4.c ����βָ��ĵ�ѭ������(�洢�ṹ��c2-2.h����)��12���������� */
 Status InitList_CL(LinkList *L)
 { /* �������������һ���յ����Ա�L */
   *L=(LinkList)malloc(sizeof(struct LNode)); /* ����ͷ���,��ʹLָ���ͷ��� */
   if(!*L) /* �洢����ʧ�� */
     exit(OVERFLOW);
   (*L)->next=*L; /* ָ����ָ��ͷ��� */
   return OK;
 }

 Status DestroyList_CL(LinkList *L)
 { /* ����������������Ա�L */
   LinkList q,p=(*L)->next; /* pָ��ͷ��� */
   while(p!=*L) /* û����β */
   {
     q=p->next;
     free(p);
     p=q;
   }
   free(*L);
   *L=NULL;
   return OK;
 }

 Status ClearList_CL(LinkList *L) /* �ı�L */
 { /* ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
   LinkList p,q;
   *L=(*L)->next; /* Lָ��ͷ��� */
   p=(*L)->next; /* pָ���һ����� */
   while(p!=*L) /* û����β */
   {
     q=p->next;
     free(p);
     p=q;
   }
   (*L)->next=*L; /* ͷ���ָ����ָ������ */
   return OK;
 }

 Status ListEmpty_CL(LinkList L)
 { /* ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ����򷵻�TRUE�����򷵻�FALSE */
   if(L->next==L) /* �� */
     return TRUE;
   else
     return FALSE;
 }

 int ListLength_CL(LinkList L)
 { /* ��ʼ������L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
   int i=0;
   LinkList p=L->next; /* pָ��ͷ��� */
   while(p!=L) /* û����β */
   {
     i++;
     p=p->next;
   }
   return i;
 }

 Status GetElem_CL(LinkList L,int i,ElemType *e)
 { /* ����i��Ԫ�ش���ʱ,��ֵ����e������OK,���򷵻�ERROR */
   int j=1; /* ��ʼ��,jΪ������ */
   LinkList p=L->next->next; /* pָ���һ����� */
   if(i<=0||i>ListLength_CL(L)) /* ��i��Ԫ�ز����� */
     return ERROR;
   while(j<i)
   { /* ˳ָ��������,ֱ��pָ���i��Ԫ�� */
     p=p->next;
     j++;
   }
   *e=p->data; /* ȡ��i��Ԫ�� */
   return OK;
 }

 int LocateElem_CL(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
 { /* ��ʼ���������Ա�L�Ѵ��ڣ�compare()������Ԫ���ж����� */
   /* �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ�� */
   /*           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
   int i=0;
   LinkList p=L->next->next; /* pָ���һ����� */
   while(p!=L->next)
   {
     i++;
     if(compare(p->data,e)) /* �����ϵ */
       return i;
     p=p->next;
   }
   return 0;
 }

 Status PriorElem_CL(LinkList L,ElemType cur_e,ElemType *pre_e)
 { /* ��ʼ���������Ա�L�Ѵ��� */
   /* �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ���� */
   /*           �������ʧ�ܣ�pre_e�޶��� */
   LinkList q,p=L->next->next; /* pָ���һ����� */
   q=p->next;
   while(q!=L->next) /* pû����β */
   {
     if(q->data==cur_e)
     {
       *pre_e=p->data;
       return TRUE;
     }
     p=q;
     q=q->next;
   }
   return FALSE;
 }

 Status NextElem_CL(LinkList L,ElemType cur_e,ElemType *next_e)
 { /* ��ʼ���������Ա�L�Ѵ��� */
   /* �����������cur_e��L������Ԫ��,�Ҳ������һ��,����next_e�������ĺ�̣� */
   /*           �������ʧ�ܣ�next_e�޶��� */
   LinkList p=L->next->next; /* pָ���һ����� */
   while(p!=L) /* pû����β */
   {
     if(p->data==cur_e)
     {
       *next_e=p->next->data;
       return TRUE;
     }
     p=p->next;
   }
   return FALSE;
 }

 Status ListInsert_CL(LinkList *L,int i,ElemType e) /* �ı�L */
 { /* ��L�ĵ�i��λ��֮ǰ����Ԫ��e */
   LinkList p=(*L)->next,s; /* pָ��ͷ��� */
   int j=0;
   if(i<=0||i>ListLength_CL(*L)+1) /* �޷��ڵ�i��Ԫ��֮ǰ���� */
     return ERROR;
   while(j<i-1) /* Ѱ�ҵ�i-1����� */
   {
     p=p->next;
     j++;
   }
   s=(LinkList)malloc(sizeof(struct LNode)); /* �����½�� */
   s->data=e; /* ����L�� */
   s->next=p->next;
   p->next=s;
   if(p==*L) /* �ı�β��� */
     *L=s;
   return OK;
 }

 Status ListDelete_CL(LinkList *L,int i,ElemType *e) /* �ı�L */
 { /* ɾ��L�ĵ�i��Ԫ��,����e������ֵ */
   LinkList p=(*L)->next,q; /* pָ��ͷ��� */
   int j=0;
   if(i<=0||i>ListLength_CL(*L)) /* ��i��Ԫ�ز����� */
     return ERROR;
   while(j<i-1) /* Ѱ�ҵ�i-1����� */
   {
     p=p->next;
     j++;
   }
   q=p->next; /* qָ���ɾ����� */
   p->next=q->next;
   *e=q->data;
   if(*L==q) /* ɾ�����Ǳ�βԪ�� */
     *L=p;
   free(q); /* �ͷŴ�ɾ����� */
   return OK;
 }

 Status ListTraverse_CL(LinkList L,void(*vi)(ElemType))
 { /* ��ʼ����:L�Ѵ��ڡ��������:���ζ�L��ÿ������Ԫ�ص��ú���vi()��һ��vi()ʧ��,�����ʧ�� */
   LinkList p=L->next->next;
   while(p!=L->next)
   {
     vi(p->data);
     p=p->next;
   }
   printf("\n");
   return OK;
 }