
// �Զ����ɣ�/make/item/make38a

inherit ITEM;
    inherit COMBINED;

// ��������������
    int get_max_combined() { return 5; }

// ���������촦��
void create()
{
        set_name("�����");
        set_picid_1(3809);
        set_picid_2(3809);
        set_unit("��");
        set_value(2);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�鼮��һ��";
}
