
// �Զ����ɣ�/make/item/make49

inherit ITEM;
    inherit COMBINED;

// ��������������
//  int get_max_combined() { return 30; }

// ���������촦��
void create()
{
        set_name("����");
        set_picid_1(4901);
        set_picid_2(4901);
        set_unit("��");
        set_value(40);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "����";
}
