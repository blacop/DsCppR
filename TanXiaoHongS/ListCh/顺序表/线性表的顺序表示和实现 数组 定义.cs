		bool InitList(SqList &L);
        //�������������һ���յ����Ա�L��

        bool DestroyList(SqList &L);
        //��ʼ���������Ա�L�Ѵ��ڡ�
        //����������������Ա�L��

        bool ClearList(SqList &L);
        //��ʼ���������Ա�L�Ѵ��ڡ�
        //�����������L����Ϊ�ձ�

        bool ListEmpty(SqList L);
        //��ʼ���������Ա�L�Ѵ��ڡ�
        //�����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE��

        int ListLength(SqList L);
        //��ʼ���������Ա�L�Ѵ��ڡ�
        //�������������L������Ԫ�صĸ�����

        bool GetElem(SqList L, int i, ElemType &e);
        //��ʼ���������Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)��
        //�����������e����L�е�i������Ԫ�ص�ֵ��

        int LocateElem(SqList L, int e, bool(*equal)(ElemType, ElemType));
        //��ʼ���������Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�������
        //����L�е�һ����e�����ϵcompare()������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0.

        bool PriorElem(SqList L, ElemType cur_e, ElemType &pre_e);
        //��ʼ���������Ա�L�Ѵ��ڡ�
        //�����������cur_e��L�е�����Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶��塣

        bool NextElem(SqList L, ElemType cur_e, ElemType &next_e);
        //��ʼ���������Ա�L�Ѵ��ڡ�
        //�����������cur_e��L�е�����Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶��塣

        bool ListInsert(SqList &L, int i, ElemType e);
        //��ʼ���������Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)+1.
        //�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1.

        bool ListDelete(SqList &L, int i, ElemType &e);
        //��ʼ���������Ա�L�Ѵ����ҷǿգ�1<=i<=ListLength(L).
        //���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1.

        bool ListTraverse(SqList L, bool(*visit)(ElemType));
        //��ʼ���������Ա�L�Ѵ���
        //������������ζ�L��ÿ��Ԫ�ص��ú���visit().һ��visit()ʧ��,�����ʧ�ܡ�
        //SqList.h end